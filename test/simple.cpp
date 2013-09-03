#include <gab/agent.hpp>
#include <gab/chromosome.hpp>
#include <gab/bitwise_and_crossover.hpp>
#include <gab/bitwise_not_mutation.hpp>
#include <gab/two_point_crossover.hpp>
#include <gab/one_point_crossover.hpp>
#include <gab/uniform_crossover.hpp>
#include <gab/random_chromosome.hpp>
#include <gab/fitness_evaluator.hpp>
#include <gab/thread_pool.hpp>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace gab;

class my_chromosome : public byte_chromosome<3>
{
public:
  value_type &x()
  {
    return (*this)[0];
  }
  
  const value_type &x() const
  {
    return (*this)[0];
  }
  
  value_type &y()
  {
    return (*this)[1];
  }
  
  const value_type &y() const
  {
    return (*this)[1];
  }
  
  value_type &z()
  {
    return (*this)[2];
  }
  
  const value_type &z() const
  {
    return (*this)[2];
  }
};

template<typename S>
class my_fitness_evaluator : public real_fitness_evaluator<S>
{
public:
  virtual double operator()(const typename S::agent_type &evaluatee) const
  {
    double dist = 0;
    typename S::agent_type::chromosome_type c = evaluatee.chromosome();
    for(std::size_t i = 0; i < S::agent_type::chromosome_type::size; ++i) {
      dist += c[i] * c[i];
    }
    return sqrt(dist);
  }
};

int main(int argc, char *argv[])
{
  typedef agent<my_chromosome> my_agent;
  typedef simulation<my_agent> my_simulation;
  typedef random_chromosome<my_chromosome> my_random_chromosome;
  typedef my_fitness_evaluator<my_simulation> my_simulation_fitness_evaluator;
  
  my_simulation s;
  
  // Add some random agents to simulation
  my_random_chromosome gen;
  for(std::size_t i = 0; i < 1000; ++i) {
    s.add_agent(gen());
  }
  
  my_simulation_fitness_evaluator eval;
  typename my_simulation_fitness_evaluator::returns_container_type rets = eval.apply(s.agents());
  typename my_simulation_fitness_evaluator::returns_container_type::const_iterator it = rets.begin();
  for(; it != rets.end(); ++it) {
    std::cout << "agent fitness: " << *it << std::endl;
  }
  
  return 0;
}