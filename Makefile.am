bin_PROGRAMS = nsafepass

nsafepass_SOURCES = src/nsafepass.c

dist_doc_DATA = README.md

# Dummy test suite
check_PROGRAMS = nsafepass.test

nsafepass_test_SOURCES = $(nsafepass_SOURCES)
nsafepass_test_CPPFLAGS = -DTEST

TESTS = $(check_PROGRAMS)
