/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_EVALUATION_POOL_HPP_
#define _GAB_EVALUATION_POOL_HPP_

#include <thread>

namespace gab
{
  template<typename E>
  class evaluation_pool
  {
  public:
    evaluation_pool(const simulation::agents_containter_type &agents)
    {
      unsigned threads = std::thread::hardware_concurrency();
      typedef simulation::agents_container_type::size_type size = agents.size();
      threads = std::min(threads, size);
      
      
      
      std::size_t agents_per_thread = agents.size() / threads;
      
      
      for(unsigned i = 0; i < threads; ++i) {
        
      }
      _pool.emplace();
    }
    
  private:
    void run(const simulation::agents_container_type &&agents)
    {
      
    }
    
    std::list<std::thread> _evaluators;
  };
}

#endif
