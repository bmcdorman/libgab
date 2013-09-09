/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_CROSSOVER_HPP_
#define _GAB_CROSSOVER_HPP_

#include "chromosome.hpp"

namespace gab
{
  class crossover
  {
  public:
    virtual chromosome operator()(const chromosome &lhs, const chromosome &rhs) = 0;
  };
}

#endif
