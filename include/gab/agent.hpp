/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_AGENT_HPP_
#define _GAB_AGENT_HPP_

#include "chromosome.hpp"

namespace gab
{
  template<typename C>
  class agent
  {
  public:
    typedef C chromosome_type;
    
    agent(const C &chromosome) noexcept
      : _chromosome(chromosome)
    {
    }
    
    const C &chromosome() const noexcept
    {
      return _chromosome;
    }
  private:
    C _chromosome;
  };
}

#endif
