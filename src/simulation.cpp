/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#include <gab/simulation.hpp>

using namespace gab;

void simulation::add_agent(const agent &a)
{
  _agents.push_back(a);
}

bool simulation::remove_agent(const agent &a)
{
  bool status = false;
  simulation::agents_container_type::iterator it = _agents.begin();
  for(; it != _agents.end(); ++it) {
    const agent &b = *it;
    if(a == b) {
      it = _agents.erase(it);
      status = true;
    }
  }
  return status;
}

void simulation::clear_agents()
{
  _agents.clear();
}

simulation::agents_container_type &simulation::agents() noexcept
{
  return _agents;
}

const simulation::agents_container_type &simulation::agents() const noexcept
{
  return _agents;
}