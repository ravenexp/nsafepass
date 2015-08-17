bin_PROGRAMS = nsafepass

nsafepass_SOURCES = \
src/common.h \
src/nsafepass.c

dist_doc_DATA = README.md

# Dummy test suite
check_PROGRAMS = nsafepass.test

nsafepass_test_SOURCES = $(nsafepass_SOURCES)
nsafepass_test_CPPFLAGS = -DMAIN_TEST

TESTS = $(check_PROGRAMS)

# Enable the most paranoid gcc warnings
AM_CFLAGS = -Wall -Wextra -Wpedantic -Wc++-compat \
 -Wshadow -Wcast-align -Wcast-qual -Wwrite-strings \
 -Wlogical-op -Wconversion -Wstrict-prototypes -Wmissing-prototypes \
 -Wformat=2 -Wuninitialized -Wstrict-overflow=4 \
 -Wdisabled-optimization
