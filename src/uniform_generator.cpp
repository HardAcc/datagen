//-----------------------------------------------------------------------------
// File          : uniform_generator.cpp
// Author        : Wei Song  <wsong83@gmail.com>
// Created       : 13.09.2015
// Last modified : 13.09.2015
//-----------------------------------------------------------------------------
// Description :
// Generate random data comply with uniform distribution
//-----------------------------------------------------------------------------
// Copyright (c) 2015 by Wei Song
// License: BSD
//          See LICENSE for more details.
//------------------------------------------------------------------------------
// Modification history :
// 13.09.2015 : created
//-----------------------------------------------------------------------------

#include "random_generator.h"
#include <boost/random/uniform_int_distribution.hpp>
#include <cassert>

/** Generate a sequence of uniform distributed numbers
  * width:    The width of the number produced (default = 64).
  * min:      The minimal value to be generated.
  * max:      The maximal value to be generated.
  * <return>  One random number at a time.
  */
uint64_t random_uint_uniform(uint32_t width, uint64_t min, uint64_t max) {
  uint64_t m_min = 0, m_max = UINT64_MAX;
  
  // check arguments
  assert(width <= 64);
  if(width == 64) {
    assert(max >= min);
    m_min = min;
    m_max = max;
  } else {
    m_min = min < (1 << width) ? min : (1 << width) - 1;
    m_max = max < (1 << width) ? max : (1 << width) - 1;
    assert(m_max >= m_min);
  }

  // get the random distribution
  boost::random::uniform_int_distribution<uint64_t> ranGen(m_min, m_max);
  return ranGen(gen64);
}
