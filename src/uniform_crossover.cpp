/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#include <gab/uniform_crossover.hpp>
#include <assert.h>

using namespace gab;

chromosome uniform_crossover::operator()(const chromosome &lhs, const chromosome &rhs)
{
  assert(lhs.size() == rhs.size());
  
  chromosome ret(lhs.size());
  
  for(chromosome::container_type::size_type i = 0; i < ret.size(); ++i) {
    // FIXME: Why 10? Should we expose this value?
    const double v = std::generate_canonical<double, 10>(_rng);
    if(v >= 0.5) ret[i] = lhs[i];
    else ret[i] = rhs[i];
  }
  
  return ret;
}