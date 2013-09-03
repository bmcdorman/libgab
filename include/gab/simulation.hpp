/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_SIMULATION_HPP_
#define _GAB_SIMULATION_HPP_

#include <list>

namespace gab
{
  template<typename A>
  class simulation
  {
  public:
    typedef A agent_type;
    typedef std::list<agent_type> agents_container_type;

    void add_agent(const agent_type &agent)
    {
      _agents.push_back(agent);
    }
    
    bool remove_agent(const agent_type &agent)
    {
      bool status = false;
      typename agents_container_type::iterator it = _agents.begin();
      for(; it != _agents.end(); ++it) {
        if(*it == agent) {
          it = _agents.erase(it);
          status = true;
        }
      }
      return status;
    }
    
    void clear_agents()
    {
      _agents.clear();
    }

    agents_container_type &agents() noexcept
    {
      return _agents;
    }
    
    const agents_container_type &agents() const noexcept
    {
      return _agents;
    }
    
  private:
    agents_container_type _agents;
  };
}

#endif
