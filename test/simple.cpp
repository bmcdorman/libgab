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

class my_chromosome : public chromosome
{
public:
  my_chromosome()
    : chromosome(3)
  {}
  
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

class my_fitness_evaluator : public fitness_evaluator
{
public:
  virtual fitness_evaluator::return_type operator()(const agent &evaluatee) const
  {
    fitness_evaluator::return_type dist = 0;
    const chromosome &c = evaluatee.chromosome();
    for(std::size_t i = 0; i < c.size(); ++i) {
      dist += c[i] * c[i];
    }
    return sqrt(dist);
  }
};

int main(int argc, char *argv[])
{
  simulation s;
  
  // Add some random agents to simulation
  random_chromosome gen;
  my_chromosome template_;
  for(std::size_t i = 0; i < 1000; ++i) {
    s.add_agent(gen(template_.size()));
  }
  
  my_fitness_evaluator eval;
  typename my_fitness_evaluator::returns_container_type rets = eval.apply(s.agents());
  typename my_fitness_evaluator::returns_container_type::const_iterator it = rets.begin();
  for(; it != rets.end(); ++it) {
    std::cout << "agent fitness: " << *it << std::endl;
  }
  
  return 0;
}