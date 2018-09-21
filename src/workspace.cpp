// rofi-workspace: An X11 workspace plugin for rofi
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

#include "workspace.h"

#include <xcb/xcb.h>

#include <cstdio>
#include <cstring>

namespace {

xcb_screen_t* screen_of_display(xcb_connection_t* c, int screen) {
  xcb_screen_iterator_t iter;

  iter = xcb_setup_roots_iterator(xcb_get_setup(c));
  for (; iter.rem; --screen, xcb_screen_next(&iter))
    if (screen == 0)
      return iter.data;

  return nullptr;
}

}  // namespace

Workspace::Workspace() {
  int screen_number;
  connection = xcb_connect(nullptr, &screen_number);
  xcb_screen_t* screen = screen_of_display(connection, screen_number);
  root_window = screen ? screen->root : XCB_WINDOW_NONE;
  if (!root_window)
    return;

  xcb_intern_atom_cookie_t number_of_desktops_cookie =
      xcb_intern_atom_unchecked(connection, false,
                                strlen("_NET_NUMBER_OF_DESKTOPS"),
                                "_NET_NUMBER_OF_DESKTOPS");
  xcb_intern_atom_reply_t* number_of_desktops_reply =
      xcb_intern_atom_reply(connection, number_of_desktops_cookie, nullptr);
  printf("atom is %d\n", number_of_desktops_reply->atom);
}

Workspace::~Workspace() {}
