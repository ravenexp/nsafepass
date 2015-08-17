/*  This file is part of nsafepass
    Copyright 2015 Sergey Kvachonok

    nsafepass is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version. */

/** \file random.h
 *  \brief nsafepass random number generator functions
 *
 *  Contains interface and function declarations.
 */


/* Data type declaration section */


/** \brief Common random number generator algorithm interface
 *  \returns
 *    A random 128-bit number
 *
 *  This function returns a random number it acquires from the OS.
 */
typedef struct nsa_random_number
(*nsa_get_random_number_t)(void);


/* Function declaration section */


/** \brief Get a 128-bit random number per XKCD 221
 *  \returns
 *    A "random" 128-bit number
 *
 *  See http://xkcd.com/221/
 */
struct nsa_random_number
nsa_get_random_number_xkcd(void);
