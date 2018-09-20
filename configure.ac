AC_INIT([rofi-qalc], [0.0.1], [https://github.com/tomKPZ/rofi-qalc/issues],[],[https://github.com/tomKPZ/rofi-qalc])

AC_CONFIG_HEADER([config.h])

AC_USE_SYSTEM_EXTENSIONS
AC_CONFIG_MACRO_DIRS([m4])
AM_INIT_AUTOMAKE([-Wall -Werror subdir-objects dist-xz])

dnl ---------------------------------------------------------------------
dnl  Check for compiler
dnl ---------------------------------------------------------------------
AC_PROG_CC([clang gcc cc])

dnl ---------------------------------------------------------------------
dnl  C++17 standard
dnl ---------------------------------------------------------------------
AX_CXX_COMPILE_STDCXX_17([noext], [mandatory])

dnl ---------------------------------------------------------------------
dnl C to Object rules.
dnl ---------------------------------------------------------------------
AM_PROG_CC_C_O

dnl ---------------------------------------------------------------------
dnl System extensions
dnl ---------------------------------------------------------------------
AC_USE_SYSTEM_EXTENSIONS

dnl ---------------------------------------------------------------------
dnl Static libraries programs
dnl ---------------------------------------------------------------------
AM_PROG_AR

dnl ---------------------------------------------------------------------
dnl Base CFLAGS
dnl ---------------------------------------------------------------------
AM_CFLAGS="-Wall -Wextra -Wparentheses -Winline -pedantic  -Wunreachable-code"


dnl ---------------------------------------------------------------------
dnl Check dependencies
dnl ---------------------------------------------------------------------
PKG_PROG_PKG_CONFIG


dnl ---------------------------------------------------------------------
dnl PKG_CONFIG based dependencies  
dnl ---------------------------------------------------------------------
PKG_CHECK_MODULES([rofi], [rofi])
PKG_CHECK_MODULES([QALCULATE], [libqalculate >= 1.0.0])

[rofi_PLUGIN_INSTALL_DIR]="`$PKG_CONFIG --variable=pluginsdir rofi`"
AC_SUBST([rofi_PLUGIN_INSTALL_DIR])

LT_INIT([disable-static])

dnl ---------------------------------------------------------------------
dnl Add extra compiler flags
dnl ---------------------------------------------------------------------
AC_SUBST([AM_CFLAGS])

AC_CONFIG_FILES([Makefile ])
AC_OUTPUT
