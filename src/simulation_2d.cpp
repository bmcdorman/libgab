/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#include <gab/simulation_2d.hpp>
#include <gab/agent_2d.hpp>

using namespace gab;

simulation_2d::simulation_2d(const environment_2d &environment)
  : _environment(environment)
{
}

simulation_2d::simulation_2d(const environment_2d::size_type width, const environment_2d::size_type height)
  : _environment(width, height)
{
}

void simulation_2d::add_agent(const std::shared_ptr<agent> &a)
{
  simulation::add_agent(a);
  dynamic_cast<agent_2d *>(a.get())->environment(&_environment);
}

bool simulation_2d::remove_agent(const std::shared_ptr<agent> &a)
{
  dynamic_cast<agent_2d *>(a.get())->environment(0);
  return simulation::remove_agent(a);
}

environment_2d &simulation_2d::environment() noexcept
{
  return _environment;
}

const environment_2d &simulation_2d::environment() const noexcept
{
  return _environment;
}

void simulation_2d::environment(const environment_2d &e) noexcept
{
  _environment = e;
}