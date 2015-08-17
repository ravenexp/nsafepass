/*  This file is part of nsafepass
    Copyright 2015 Sergey Kvachonok

    nsafepass is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version. */

/** \file common.h
 *  \brief nsafepass private common header
 *
 *  Contains common constant, data type and function declarations.
 */


/* Data type declaration section */


/** \brief nsafepass 128-bit integer data type
 *
 *  Used for representing cipher keys, plaintext and ciphertext blocks, etc.
 */
union nsa_uint128_t
{
	uint8_t u8[16];
	uint16_t u16[8];
	uint32_t u32[4];
	uint64_t u64[2];
};

/** \brief nsafepass cipher key data type
 *
 *  Cipher keys have their own disjoint data type to prevent accidental misuse.
 */
struct nsa_key_block
{
	/** 128-bit value */
	union nsa_uint128_t v;
};

/** \brief nsafepass plaintext block data type
 *
 *  Plaintext blocks have their own disjoint data type.
 */
struct nsa_plaintext_block
{
	/** 128-bit value */
	union nsa_uint128_t v;
};

/** \brief nsafepass ciphertext block data type
 *
 *  Ciphertext blocks have their own disjoint data type.
 */
struct nsa_ciphertext_block
{
	/** 128-bit value */
	union nsa_uint128_t v;
};

/** \brief nsafepass random number data type
 *
 *  Random numbers have their own disjoint data type.
 */
struct nsa_random_number
{
	/** 128-bit value */
	union nsa_uint128_t v;
};


/* Function declaration section */


/** \brief Compare 128-bit numbers
 *  \param a
 *    Comparison argument 1
 *  \param b
 *    Comparison argument 2
 *  \returns
 *    0 if the arguments are equal and 1 otherwise
 */
static inline int
nsa_uint128_compare(union nsa_uint128_t a, union nsa_uint128_t b)
{
	return (a.u64[0] != b.u64[0]) || (a.u64[1] != b.u64[1]);
}

/** \brief XOR 128-bit numbers
 *  \param a
 *    XOR argument 1
 *  \param b
 *    XOR argument 2
 *  \returns
 *    a XOR b
 */
static inline union nsa_uint128_t
nsa_uint128_xor(union nsa_uint128_t a, union nsa_uint128_t b)
{
	union nsa_uint128_t r;

	r.u64[0] = a.u64[0] ^ b.u64[0];
	r.u64[1] = a.u64[1] ^ b.u64[1];

	return r;
}
