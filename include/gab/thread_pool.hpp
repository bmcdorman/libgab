/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_THREAD_POOL_HPP_
#define _GAB_THREAD_POOL_HPP_

#include <thread>
#include <list>
#include <iostream>

namespace gab
{
  template<typename F, typename T>
  class thread_pool
  {
  private:
    typedef std::list<std::thread> threads_container_type;
    
  public:
    thread_pool(const unsigned num_threads, const F &functor = F())
      : _functor(functor)
    {
      for(unsigned i = 0; i < num_threads; ++i) {
        _threads.push_back(std::thread(&thread_pool::worker, this));
      }
    }
    
    thread_pool(const F &functor = F())
      : thread_pool(std::thread::hardware_concurrency(), functor)
    {
    }
    
    void admit(const T &t)
    {
      {
        std::lock_guard<std::mutex> lock(_mutex);
        _work.push_back(t);
      }
      _empty = false;
      _work_cond.notify_one();
    }
    
    bool idle() const
    {
      std::lock_guard<std::mutex> lock(_mutex);
      return _work.empty();
    }
    
    void wait()
    {
      std::lock_guard<std::mutex> lock(_mutex);
      std::mutex mut;
      std::unique_lock<std::mutex> lk(mut);
      _cond.wait(lk);
    }
    
    const F &functor() const
    {
      return _functor;
    }
    
    ~thread_pool() {
      _quit = true;
      threads_container_type::iterator it = _threads.begin();
      for(; it != _threads.end(); ++it) {
        std::thread &thread = *it;
        thread.join();
      }
    }
    
  private:
    void worker()
    {
      T w;
      for(;;) {
        {
          std::unique_lock<std::mutex> lock(_mutex);
          while(!_quit && _work.empty()) {
            _work_cond.wait(lock);
          }
          if(_quit) break;
          w = std::move(_work.front());
          _work.pop_front();
        }
        
        try {
          _functor(w);
        } catch(...) {
          // An exception shouldn't kill the worker thread
        }
      }
    }
    
    threads_container_type _threads;
    std::list<T> _work;
    mutable std::mutex _mutex;
    bool _quit = false;
    bool _empty = true;
    std::condition_variable _work_cond;
    std::condition_variable _cond;
    F _functor;
  };
}

#endif
