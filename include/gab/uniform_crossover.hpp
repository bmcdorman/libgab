/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_UNIFORM_CROSSOVER_HPP_
#define _GAB_UNIFORM_CROSSOVER_HPP_

#include <random>
#include "crossover.hpp"

namespace gab
{
  template<typename C>
  class uniform_crossover : public crossover<C>
  {
  public:
    virtual C operator()(const C &lhs, const C &rhs)
    {
      C ret;
      
      for(typename C::size_type i = 0; i < C::size; ++i) {
        // FIXME: Why 10? Should we expose this value?
        const double v = std::generate_canonical<double, 10>(_rng);
        if(v >= 0.5) ret[i] = lhs[i];
        else ret[i] = rhs[i];
      }
      
      return ret;
    }
    
  private:
    std::random_device _rng;
  };
}

#endif
