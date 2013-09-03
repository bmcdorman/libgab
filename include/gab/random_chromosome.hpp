#ifndef _GAB_RANDOM_CHROMOSOME_HPP_
#define _GAB_RANDOM_CHROMOSOME_HPP_

#include <random>

namespace gab
{
  template<typename C>
  class random_chromosome
  {
  public:
    virtual C operator()()
    {
      typename C::container_type::size_type size = C::size * sizeof(typename C::value_type);
      
      
      C ret;
      unsigned char *const data = reinterpret_cast<unsigned char *>(ret.container().data());
      for(typename C::size_type i = 0; i < C::size; ++i) data[i] = _rng() % 255;
      
      return ret;
    }
    
  private:
    std::random_device _rng;
  };
}

#endif
