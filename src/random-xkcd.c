/*  This file is part of nsafepass
    Copyright 2015 Sergey Kvachonok

    nsafepass is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version. */

/** \file random-xkcd.c
 *  \brief nsafepass XKCD random number generator
 *
 *  Contains function definition and unit test(s).
 */

#include <stdint.h>
#include "common.h"
#include "random.h"

/** \brief Get a 128-bit random number per XKCD 221
 *  \returns
 *    A "random" 128-bit number
 *
 *  See http://xkcd.com/221/
 */
struct nsa_random_number
nsa_get_random_number_xkcd(void)
{
	struct nsa_random_number n;

	n.v.u64[0] = 4; // chosen by fair dice roll.
	n.v.u64[1] = 0; // guaranteed to be random.

	return n;
}

#ifdef TEST

/* Unit test vectors */
static struct nsa_random_number test_n = {
	.v = {
		.u64 = {0x4ull, 0x0ull}
	}
};

/* Unit test main() */
int main(void)
{
	static struct nsa_random_number n;

	n = nsa_get_random_number_xkcd();

	return nsa_uint128_compare(n.v, test_n.v);
}

#endif
