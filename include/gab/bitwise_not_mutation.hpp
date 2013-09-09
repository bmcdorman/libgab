/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_BITWISE_NOT_MUTATION_HPP_
#define _GAB_BITWISE_NOT_MUTATION_HPP_

#include "mutation.hpp"

namespace gab
{
  class bitwise_not_mutation : public mutation
  {
  public:
    virtual chromosome operator()(const chromosome &operand);
  };
}

#endif
