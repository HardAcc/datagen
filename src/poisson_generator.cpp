//-----------------------------------------------------------------------------
// File          : poisson_generator.cpp
// Author        : Wei Song  <wsong83@gmail.com>
// Created       : 13.09.2015
// Last modified : 13.09.2015
//-----------------------------------------------------------------------------
// Description :
// Generate random data comply with poisson distribution
//-----------------------------------------------------------------------------
// Copyright (c) 2015 by Wei Song
// License: BSD
//          See LICENSE for more details.
//------------------------------------------------------------------------------
// Modification history :
// 13.09.2015 : created
//-----------------------------------------------------------------------------

#include "random_generator.h"
#include <boost/random/poisson_distribution.hpp>
#include <cassert>

/* integers in poisson distribution
 * mean:    The mean of the poisson distribution
 */
uint32_t random_uint_poisson(double mean) {
  assert(mean > 0);

  // get the random distribution
  boost::random::poisson_distribution<uint32_t, double> ranGen(mean);
  return ranGen(gen32);  
}
