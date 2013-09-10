/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_SIMULATION_HPP_
#define _GAB_SIMULATION_HPP_

#include <list>
#include "agent.hpp"

namespace gab
{
  class simulation
  {
  public:
    typedef std::list<agent> agents_container_type;

    virtual void add_agent(const agent &a);
    virtual bool remove_agent(const agent &a);
    virtual void clear_agents();
    agents_container_type &agents() noexcept;
    const agents_container_type &agents() const noexcept;
    
  private:
    agents_container_type _agents;
  };
}

#endif
