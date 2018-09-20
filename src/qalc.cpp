// rofi-qalc: A qalculator plugin for rofi
// Copyright (C) 2018 <tomKPZ@gmail.com>
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA

#include <rofi/mode.h>

// TODO: Sort includes once the below change lands:
// https://github.com/DaveDavenport/rofi/pull/848
#include <rofi/mode-private.h>

#include <libqalculate/Calculator.h>
#include <iostream>
#include <memory>
#include <optional>
#include <string>

namespace {

class Qalc {
 public:
  Qalc() {
    calculator.loadGlobalDefinitions();
    calculator.loadLocalDefinitions();
  }

  ~Qalc() {}

  static int ModeInit(Mode* sw) {
    Qalc* pd = GetInstance(sw);
    if (!pd)
      mode_set_private_data(sw, reinterpret_cast<void*>(new Qalc()));
    return true;
  }

  static void ModeDestroy(Mode* sw) {
    Qalc* pd = GetInstance(sw);
    if (pd) {
      delete pd;
      mode_set_private_data(sw, nullptr);
    }
  }

  static unsigned int ModeGetNumEntries(const Mode* sw) { return 1; }

  static ModeMode ModeResult(Mode* sw,
                             int menu_entry,
                             char** input,
                             unsigned int selected_line) {
    return MODE_EXIT;
  }

  static int TokenMatch(const Mode* sw,
                        rofi_int_matcher** tokens,
                        unsigned int index) {
    return GetInstance(sw)->TokenMatch();
  }

  static char* GetDisplayValue(const Mode* sw,
                               unsigned int selected_line,
                               int* state,
                               GList** attr_list,
                               int get_entry) {
    return GetInstance(sw)->GetDisplayValue();
  }

  static char* PreprocessInput(Mode* sw, const char* input) {
    return GetInstance(sw)->PreprocessInput(input);
  }

 private:
  static Qalc* GetInstance(const Mode* sw) {
    return reinterpret_cast<Qalc*>(mode_get_private_data(sw));
  }

  int TokenMatch() { return result.has_value(); }

  char* GetDisplayValue() const {
    return strdup(result.has_value() ? result.value().c_str() : "");
  }

  char* PreprocessInput(const char* input) {
    if (input && input[0])
      result = calculator.calculateAndPrint(input, 100);
    CalculatorMessage* message;
    while (message = calculator.message()) {
      calculator.nextMessage();
      if (message->type() == MESSAGE_WARNING ||
          message->type() == MESSAGE_ERROR) {
        result = std::nullopt;
      }
    }
    return GetDisplayValue();
  }

  Calculator calculator;
  std::optional<std::string> result;
};

}  // namespace

Mode mode{
    ABI_VERSION,
    const_cast<char*>(&"qalc"[0]),
    "display-qalc",
    const_cast<char*>(&"qalc"[0]),
    Qalc::ModeInit,
    Qalc::ModeDestroy,
    Qalc::ModeGetNumEntries,
    Qalc::ModeResult,
    Qalc::TokenMatch,
    Qalc::GetDisplayValue,
    nullptr,
    nullptr,
    Qalc::PreprocessInput,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
};
