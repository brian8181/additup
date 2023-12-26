# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

# License:    GPL
# File Name:  ./configure.ac
# Build Date: Tue Nov 14 04:08:48 PM CST 2023
# Version:    0.0.1

#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([additup], [0.01], [brian8181@gmail.com], [additup], [https://github.com/brian8181])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_CPP

# Initialize libtool
LT_PREREQ([2.2])
LT_INIT

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lcppunit':
AC_CHECK_LIB([CPPUNIT_TEST], [main])

# Checks for header files.
AC_CHECK_HEADERS([netinet/in.h termios.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T

AM_INIT_AUTOMAKE
# Checks for library functions.
AC_CONFIG_FILES([Makefile
                  src/Makefile])
AC_OUTPUT
