/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_FITNESS_EVALUATOR_HPP_
#define _GAB_FITNESS_EVALUATOR_HPP_

#include "simulation.hpp"
#include <list>

namespace gab
{
  class fitness_evaluator
  {
  public:
    typedef double return_type;
    typedef std::list<return_type> returns_container_type;
    
    virtual ~fitness_evaluator() noexcept {}
    virtual return_type operator()(const agent &evaluatee) const = 0;
    virtual returns_container_type apply(const std::list<agent> &evaluatees) const
    {
      returns_container_type ret;
      typename std::list<agent>::const_iterator it = evaluatees.begin();
      for(; it != evaluatees.end(); ++it) ret.push_back((*this)(*it));
      return ret;
    }
  };
}

#endif
