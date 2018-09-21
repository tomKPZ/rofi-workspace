ACLOCAL_AMFLAGS=-I m4
plugindir=@rofi_PLUGIN_INSTALL_DIR@

plugin_LTLIBRARIES = workspace.la

workspace_la_SOURCES= src/workspace.cpp

workspace_la_CXXFLAGS= @rofi_CFLAGS@ @xcb_CFLAGS@
workspace_la_LIBADD= @rofi_LIBS@ @xcb_LIBS@
workspace_la_LDFLAGS= -module -avoid-version
