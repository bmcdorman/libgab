/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_ONE_POINT_CROSSOVER_HPP_
#define _GAB_ONE_POINT_CROSSOVER_HPP_

#include <random>
#include "crossover.hpp"

namespace gab
{
  template<typename C>
  class one_point_crossover : public crossover<C>
  {
  public:
    virtual C operator()(const C &lhs, const C &rhs)
    {
      std::uniform_int_distribution<typename C::size_type> dist(0, C::size);
      
      const typename std::uniform_int_distribution<typename C::size_type>::result_type a = dist(_rng);
      
      C ret;
      for(std::size_t i = 0; i < a; ++i) ret[i] = lhs[i];
      for(std::size_t i = a; i < C::size; ++i) ret[i] = rhs[i];
      
      return ret;
    }
    
  private:
    std::random_device _rng;
  };
}

#endif
