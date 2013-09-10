/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_SIMULATION_2D_HPP_
#define _GAB_SIMULATION_2D_HPP_

#include "simulation.hpp"
#include "environment_2d.hpp"

namespace gab
{
  class simulation_2d : public simulation
  {
  public:
    simulation_2d(const environment_2d &environment);
    simulation_2d(const environment_2d::size_type width, const environment_2d::size_type height);
    
    const environment_2d &environment() const noexcept;
    environment_2d &environment() noexcept;
    
  private:
    environment_2d _environment;
  };
}

#endif
