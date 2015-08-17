/*  This file is part of nsafepass
    Copyright 2015 Sergey Kvachonok

    nsafepass is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version. */

#include <stdio.h>
#include <config.h>

#ifdef MAIN_TEST
static int run_test(void);
#endif

int main(void)
{
#ifdef MAIN_TEST
	return run_test();
#endif

	puts("This is " PACKAGE_STRING);

	return 0;
}

#ifdef MAIN_TEST

static int run_test(void)
{
	puts("This is a " PACKAGE_STRING " test");

	return 0;
}

#endif
