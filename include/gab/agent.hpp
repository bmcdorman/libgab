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
    agent(const class chromosome &c) noexcept;
    
    const class chromosome &chromosome() const noexcept;
    
    virtual bool operator ==(const agent &rhs) const;
  private:
    class chromosome _chromosome;
  };
}

#endif
