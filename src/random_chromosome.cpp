/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#include <gab/random_chromosome.hpp>

using namespace gab;

random_chromosome::random_chromosome(const chromosome::container_type::size_type size)
  : _size(size)
{
}

chromosome random_chromosome::operator()(double min, double max)
{
  chromosome ret(_size);
  std::uniform_int_distribution<int> dist(min * 1000, max * 1000);
  for(chromosome::container_type::size_type i = 0; i < ret.size(); ++i) ret[i] = dist(_rng) / 1000.0;
  
  return ret;
}