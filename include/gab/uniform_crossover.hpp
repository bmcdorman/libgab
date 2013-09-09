/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_UNIFORM_CROSSOVER_HPP_
#define _GAB_UNIFORM_CROSSOVER_HPP_

#include <random>
#include "crossover.hpp"

namespace gab
{
  class uniform_crossover : public crossover
  {
  public:
    virtual chromosome operator()(const chromosome &lhs, const chromosome &rhs);
    
  private:
    std::random_device _rng;
  };
}

#endif
