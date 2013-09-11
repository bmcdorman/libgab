/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_FITNESS_EVALUATOR_HPP_
#define _GAB_FITNESS_EVALUATOR_HPP_

#include <list>
#include "agent.hpp"

namespace gab
{
  class fitness_evaluator
  {
  public:
    typedef double return_type;
    typedef std::list<return_type> returns_container_type;
    
    virtual ~fitness_evaluator() noexcept {}
    virtual return_type operator()(const std::shared_ptr<agent> &evaluatee) const = 0;
    virtual returns_container_type apply(const std::list<std::shared_ptr<agent>> &evaluatees) const;
  };
}

#endif
