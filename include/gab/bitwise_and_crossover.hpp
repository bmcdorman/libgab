/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_BITWISE_AND_CROSSOVER_HPP_
#define _GAB_BITWISE_AND_CROSSOVER_HPP_

#include "crossover.hpp"

namespace gab
{
  template<typename C>
  class bitwise_and_crossover : public crossover<C>
  {
  public:
    virtual C operator()(const C &lhs, const C &rhs)
    {
      typename C::container_type::size_type size = C::size * sizeof(typename C::value_type);
      
      C ret;
      
      unsigned char *const ret_data = reinterpret_cast<unsigned char *>(ret.container().data());
      const unsigned char *const lhs_data = reinterpret_cast<const unsigned char *>(lhs.container().data());
      const unsigned char *const rhs_data = reinterpret_cast<const unsigned char *>(rhs.container().data());
      
      for(typename C::container_type::size_type i = 0; i < size; ++i) {
        ret_data[i] = lhs_data[i] & rhs_data[i];
      }
      
      return ret;
    }
  };
}

#endif
