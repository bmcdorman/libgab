/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#include <gab/random_chromosome.hpp>

using namespace gab;

chromosome random_chromosome::operator()(const chromosome::container_type::size_type size)
{
  typename chromosome::container_type::size_type bsize = size * sizeof(chromosome::value_type);
  
  chromosome ret(size);
  unsigned char *const data = reinterpret_cast<unsigned char *>(ret.genes().data());
  for(chromosome::container_type::size_type i = 0; i < bsize; ++i) data[i] = _rng() % 255;
  
  return ret;
}