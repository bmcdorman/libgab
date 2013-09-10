/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#include <gab/bitwise_and_crossover.hpp>
#include <assert.h>

using namespace gab;

chromosome bitwise_and_crossover::operator()(const chromosome &lhs, const chromosome &rhs)
{
  assert(lhs.size() == rhs.size());
  
  typename chromosome::container_type::size_type size = lhs.size() * sizeof(typename chromosome::value_type);
  
  chromosome ret(lhs.size());
  
  unsigned char *const ret_data = reinterpret_cast<unsigned char *>(ret.genes().data());
  const unsigned char *const lhs_data = reinterpret_cast<const unsigned char *>(lhs.genes().data());
  const unsigned char *const rhs_data = reinterpret_cast<const unsigned char *>(rhs.genes().data());
  
  for(typename chromosome::container_type::size_type i = 0; i < size; ++i) {
    ret_data[i] = lhs_data[i] & rhs_data[i];
  }
  
  return ret;
}