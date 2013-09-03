/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_BITWISE_NOT_MUTATION_HPP_
#define _GAB_BITWISE_NOT_MUTATION_HPP_

#include "mutation.hpp"

namespace gab
{
  template<typename C>
  class bitwise_not_mutation : public mutation<C>
  {
  public:
    virtual C operator()(const C &operand)
    {
      typename C::container_type::size_type size = C::size * sizeof(typename C::value_type);
      
      C ret;
      unsigned char *const ret_data = reinterpret_cast<unsigned char *>(ret.container().data());
      const unsigned char *const orig_data = reinterpret_cast<const unsigned char *>(operand.container().data());
      
      for(typename C::container_type::size_type i = 0; i < size; ++i) {
        ret_data[i] = ~orig_data[i];
      }
      
      return ret;
    }
  };
}

#endif
