/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_UNARY_MUTATION_HPP_
#define _GAB_UNARY_MUTATION_HPP_

#include "chromosome.hpp"

namespace gab
{
  template<typename C>
  class mutation
  {
  public:
    virtual C operator()(const C &operand) = 0;
  };
}

#endif
