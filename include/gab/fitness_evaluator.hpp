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
  template<typename T, typename S>
  class fitness_evaluator
  {
  public:
    typedef std::list<T> returns_container_type;
    
    virtual ~fitness_evaluator() noexcept {}
    virtual T operator()(const typename S::agent_type &evaluatee) const = 0;
    virtual returns_container_type apply(const typename S::agents_container_type &evaluatees) const
    {
      returns_container_type ret;
      typename S::agents_container_type::const_iterator it = evaluatees.begin();
      for(; it != evaluatees.end(); ++it) ret.push_back((*this)(*it));
      return ret;
    }
  };
  
  template<typename A>
  struct real_fitness_evaluator : public fitness_evaluator<double, A> {};
}

#endif
