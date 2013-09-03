/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_CROSSOVER_HPP_
#define _GAB_CROSSOVER_HPP_

#include "chromosome.hpp"

namespace gab
{
  template<typename C>
  class crossover
  {
  public:
    virtual C operator()(const C &lhs, const C &rhs) = 0;
  };
}

#endif
