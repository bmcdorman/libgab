/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_TWO_POINT_CROSSOVER_HPP_
#define _GAB_TWO_POINT_CROSSOVER_HPP_

#include <random>
#include "crossover.hpp"

namespace gab
{
  template<typename C>
  class two_point_crossover : public crossover<C>
  {
  public:
    virtual C operator()(const C &lhs, const C &rhs)
    {
      std::uniform_int_distribution<typename C::size_type> dist(0, C::size);
      
      typename std::uniform_int_distribution<typename C::size_type>::result_type a = dist(_rng);
      typename std::uniform_int_distribution<typename C::size_type>::result_type b = dist(_rng);
      if(a > b) std::swap(a, b);
      
      C ret;
      for(std::size_t i = 0; i < a; ++i) ret[i] = lhs[i];
      for(std::size_t i = a; i < b; ++i) ret[i] = rhs[i];
      for(std::size_t i = b; i < C::size; ++i) ret[i] = lhs[i];
      
      return ret;
    }
    
  private:
    std::random_device _rng;
  };
}

#endif
