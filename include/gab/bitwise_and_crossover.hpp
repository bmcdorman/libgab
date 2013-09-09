/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_BITWISE_AND_CROSSOVER_HPP_
#define _GAB_BITWISE_AND_CROSSOVER_HPP_

#include "crossover.hpp"

namespace gab
{
  class bitwise_and_crossover : public crossover
  {
  public:
    virtual chromosome operator()(const chromosome &lhs, const chromosome &rhs);
  };
}

#endif
