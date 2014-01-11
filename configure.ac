dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(MediaPi, 0.1, martek01@gmx.de)

AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE(foreign)

AC_PROG_CXX
AC_PROG_LIBTOOL

AC_SEARCH_LIBS(sqlite3_initialize, sqlite3) 

BOOST_REQUIRE
BOOST_FILESYSTEM

AC_CONFIG_FILES(Makefile src/Makefile)
AC_OUTPUT

