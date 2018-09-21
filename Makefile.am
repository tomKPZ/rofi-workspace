ACLOCAL_AMFLAGS=-I m4
plugindir=@rofi_PLUGIN_INSTALL_DIR@

plugin_LTLIBRARIES = workspace_mode.la

workspace_mode_la_SOURCES = src/workspace_mode.cpp src/workspace.h src/workspace.cpp
workspace_mode_la_CXXFLAGS = @rofi_CFLAGS@ @xcb_CFLAGS@
workspace_mode_la_LIBADD = @rofi_LIBS@ @xcb_LIBS@
workspace_mode_la_LDFLAGS = -module -avoid-version

bin_PROGRAMS = test_workspace

test_workspace_SOURCES = src/test_workspace.cpp src/workspace.h src/workspace.cpp
test_workspace_CXXFLAGS = @xcb_CFLAGS@
test_workspace_LDADD = @xcb_LIBS@
