/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_MUTATION_HPP_
#define _GAB_MUTATION_HPP_

#include "chromosome.hpp"

namespace gab
{
  class mutation
  {
  public:
    virtual chromosome operator()(const chromosome &operand) = 0;
  };
}

#endif
