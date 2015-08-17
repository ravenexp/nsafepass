/*  This file is part of nsafepass
    Copyright 2015 Sergey Kvachonok

    nsafepass is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version. */

/** \file encrypt-xor.c
 *  \brief nsafepass XOR encryption primitive
 *
 *  Contains function definition and unit test(s).
 */

#include <stdint.h>
#include "common.h"
#include "encrypt.h"

/** \brief Encrypt with XOR
 *  \param p
 *    Plaintext block to encrypt
 *  \param k
 *    Encryption key
 *  \returns
 *    Encrypted ciphertext block
 *
 *  Encrypts as C = P ^ K
 *  AKA 'I have nothing to hide'
 */
struct nsa_ciphertext_block
nsa_encrypt_xor(struct nsa_plaintext_block p, struct nsa_key_block k)
{
	struct nsa_ciphertext_block c;

	c.v = nsa_uint128_xor(p.v, k.v);

	return c;
}

#ifdef TEST

/* Unit test vectors */
static struct nsa_key_block test_k = {
	.v = {
		.u64 = {0xeff2ea104989b1faull, 0x061ca7fc4c2a8455ull}
	}
};

static struct nsa_plaintext_block test_p = {
	.v = {
		.u64 = {0x436c889e738d4385ull, 0x6a6c2d4da7d5eca9ull}
	}
};

static struct nsa_ciphertext_block test_c = {
	.v = {
		.u64 = {0xac9e628e3a04f27full, 0x6c708ab1ebff68fcull}
	}
};

/* Unit test main() */
int main(void)
{
	static struct nsa_ciphertext_block c;

	c = nsa_encrypt_xor(test_p, test_k);

	return nsa_uint128_compare(c.v, test_c.v);
}

#endif
