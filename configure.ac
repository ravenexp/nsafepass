AC_INIT([nsafepass], [0.01])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_SRCDIR([src/nsafepass.c])
AM_INIT_AUTOMAKE([-Wall foreign subdir-objects])

AC_PROG_CC

AC_CHECK_PROGS([DOXYGEN], [doxygen])
if test -z "$DOXYGEN";
   then AC_MSG_WARN([Doxygen not found - continuing without Doxygen support])
fi
AM_CONDITIONAL([HAVE_DOXYGEN], [test -n "$DOXYGEN"])

PACKAGE_BRIEF='"Yet another password manager"'
AC_SUBST([PACKAGE_BRIEF])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile doxygen/Doxyfile])
AC_OUTPUT
