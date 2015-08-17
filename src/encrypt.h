/*  This file is part of nsafepass
    Copyright 2015 Sergey Kvachonok

    nsafepass is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version. */

/** \file encrypt.h
 *  \brief nsafepass encryption primitives header
 *
 *  Contains interface and function declarations.
 */


/* Data type declaration section */


/** \brief Common block cipher algorithm interface
 *  \param p
 *    Plaintext block to encrypt
 *  \param k
 *    Encryption key
 *  \returns
 *    Encrypted ciphertext block
 *
 *  The interface implicitly assumes that the cipher block size and
 *  the cipher key size are equal.
 */
typedef struct nsa_ciphertext_block
(*nsa_encrypt_t)(struct nsa_plaintext_block p, struct nsa_key_block k);


/* Function declaration section */


/** \brief Encrypt with XOR
 *  \param p
 *    Plaintext block to encrypt
 *  \param k
 *    Encryption key
 *  \returns
 *    Encrypted ciphertext block
 *
 *  Encrypts as C = P ^ K AKA 'I have nothing to hide'
 */
struct nsa_ciphertext_block
nsa_encrypt_xor(struct nsa_plaintext_block p, struct nsa_key_block k);
