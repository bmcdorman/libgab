/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_AGENT_HPP_
#define _GAB_AGENT_HPP_

#include "chromosome.hpp"

namespace gab
{
  class agent
  {
  public:
    agent(const chromosome &c) noexcept;
    
    const chromosome &chromosome() const noexcept;
    
    bool operator ==(const agent &rhs) const;
  private:
    class chromosome _chromosome;
  };
}

#endif
