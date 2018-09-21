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

typedef struct xcb_connection_t xcb_connection_t;

class Workspace {
public:
  Workspace();
  ~Workspace();

private:
  Workspace(const Workspace&) = delete;
  Workspace& operator=(const Workspace&) = delete;

  xcb_connection_t* conn;
};
