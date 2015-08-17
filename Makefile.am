bin_PROGRAMS = nsafepass

# Specify C99 for all sources
AM_CFLAGS = -std=c99

nsafepass_SOURCES = \
src/common.h \
src/encrypt.h \
src/nsafepass.c \
src/encrypt-xor.c

dist_doc_DATA = README.md

check_PROGRAMS = nsafepass.test encrypt-xor.test
TESTS = $(check_PROGRAMS)

nsafepass_test_SOURCES = $(nsafepass_SOURCES)
nsafepass_test_CPPFLAGS = -DMAIN_TEST

encrypt_xor_test_SOURCES = src/encrypt-xor.c
encrypt_xor_test_CPPFLAGS = -DTEST

# Enable the most paranoid gcc warnings
AM_CFLAGS += -Wall -Wextra -Wpedantic -Wc++-compat \
 -Wshadow -Wcast-align -Wcast-qual -Wwrite-strings \
 -Wlogical-op -Wconversion -Wstrict-prototypes -Wmissing-prototypes \
 -Wformat=2 -Wuninitialized -Wstrict-overflow=4 \
 -Wdisabled-optimization

# Use Doxygen if available
if HAVE_DOXYGEN

doxygen/doxyfile.stamp:
	cd doxygen ; $(DOXYGEN)
	echo Timestamp > $@

CLEANFILES = doxygen/doxyfile.stamp

all-local: doxygen/doxyfile.stamp

clean-local:
	rm -rf doxygen/html

endif
