//-----------------------------------------------------------------------------
// File          : random_generator.h
// Author        : Wei Song  <wsong83@gmail.com>
// Created       : 13.09.2015
// Last modified : 13.09.2015
//-----------------------------------------------------------------------------
// Description :
// Define the interfaces used in testing the Parallel Merging Sorters
//-----------------------------------------------------------------------------
// Copyright (c) 2015 by Wei Song
// License: BSD
//          See LICENSE for more details.
//------------------------------------------------------------------------------
// Modification history :
// 13.09.2015 : created
//-----------------------------------------------------------------------------

#ifndef DG_RANDOM_GENERATOR_H
#define DG_RANDOM_GENERATOR_H

#include <stdint.h>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/lagged_fibonacci.hpp>
#include <boost/random/ranlux.hpp>

//------------------------------------------------------------------------------
// Various generators used for different randomizers

// generator for 64-bit integer
// length: 2^19937
// storage:  312*sizeof(uint32_t)
extern boost::random::mt19937_64 gen64;

// set seed for gen64
void set_seed_gen64(uint64_t);

// generator for 32-bit integer
// length: 2^19937
// storage:  625*sizeof(uint32_t)
extern boost::random::mt19937 gen32;

// set seed for gen32
void set_seed_gen32(uint32_t);

// generator for double
// length: ~2^2300000
// storage:  44497*sizeof(double)
extern boost::random::lagged_fibonacci44497 genDouble;

// set seed for genDouble
void set_seed_gen_double(double);

// generator for float
// length: ~10^171
// storage: 24*sizeof(float)
extern boost::random::ranlux3_01 genFloat;

// set seed for genDouble
void set_seed_gen_float(float);

/* integers in uniform distribution in [min, max]
 * width:    The width of the number produced (default = 64).
 * min:      The minimal value to be generated.
 * max:      The maximal value to be generated.
 */
uint64_t random_uint_uniform(uint32_t width = 64, uint64_t min = 0, uint64_t max = UINT64_MAX);

/* double in uniform distribution in [0, 1)
 */
double random_double_uniform_01();

/* integers in poisson distribution
 * mean:    The mean of the poisson distribution
 */
uint32_t random_uint_poisson(double mean = 1);

#endif

// emacs local variable

// Local Variables:
// mode: C++
// End:
