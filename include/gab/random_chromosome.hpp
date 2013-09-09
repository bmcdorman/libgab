#ifndef _GAB_RANDOM_CHROMOSOME_HPP_
#define _GAB_RANDOM_CHROMOSOME_HPP_

#include <random>
#include "chromosome.hpp"

namespace gab
{
  class random_chromosome
  {
  public:
    virtual chromosome operator()(const chromosome::container_type::size_type size);
    
  private:
    std::random_device _rng;
  };
}

#endif
