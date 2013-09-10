/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#include <gab/one_point_crossover.hpp>
#include <assert.h>

using namespace gab;

chromosome one_point_crossover::operator()(const chromosome &lhs, const chromosome &rhs)
{
  assert(lhs.size() == rhs.size());
  
  std::uniform_int_distribution<chromosome::container_type::size_type> dist(0, lhs.size());
  
  const typename std::uniform_int_distribution<chromosome::container_type::size_type>::result_type a = dist(_rng);
  
  chromosome ret(lhs.size());
  for(chromosome::container_type::size_type i = 0; i < a; ++i) ret[i] = lhs[i];
  for(chromosome::container_type::size_type i = a; i < ret.size(); ++i) ret[i] = rhs[i];
  
  return ret;
}