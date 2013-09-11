#ifndef _GAB_RANDOM_CHROMOSOME_HPP_
#define _GAB_RANDOM_CHROMOSOME_HPP_

#include <random>
#include "chromosome.hpp"

namespace gab
{
  class random_chromosome
  {
  public:
    random_chromosome(const chromosome::container_type::size_type size);
    virtual chromosome operator()(double min, double max);
    
  private:
    const chromosome::container_type::size_type _size;
    std::random_device _rng;
  };
}

#endif
