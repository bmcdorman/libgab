#include <gab/thread_pool.hpp>
#include <iostream>
#include <random>
#include <unistd.h>

using namespace gab;

class test
{
public:
  test() {}
  test(const test &test) {}
  void operator()(unsigned i)
  {
    // std::this_thread::sleep_for(std::chrono::milliseconds(10));
    mutex.lock();
    std::cout << "test" << std::endl;
    value += i;
    mutex.unlock();
  }
  
  unsigned value = 0;
  
private:
  std::mutex mutex;
};

int main(int argc, char *argv[]) 
{
  thread_pool<test, unsigned> workers;
  for(int j = 0; j < 1; ++j) {
    for(unsigned i = 0; i < 100; ++i) workers.admit(i);
  }
  while(workers.idle()) std::this_thread::yield();
  while(!workers.idle()) std::this_thread::yield();
  std::cout << "Functor: " << workers.functor().value << std::endl;
  
  return 0;
}