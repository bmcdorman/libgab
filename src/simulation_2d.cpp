/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#include <gab/simulation_2d.hpp>

using namespace gab;

simulation_2d::simulation_2d(const environment_2d &environment)
  : _environment(environment)
{
}

simulation_2d::simulation_2d(const environment_2d::size_type width, const environment_2d::size_type height)
  : _environment(width, height)
{
}

const environment_2d &simulation_2d::environment() const noexcept
{
  return _environment;
}

environment_2d &simulation_2d::environment() noexcept
{
  return _environment;
}