/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#include <gab/simulation.hpp>

using namespace gab;

simulation::simulation()
  : _generation(0)
{
}

void simulation::add_agent(const std::shared_ptr<agent> &a)
{
  _agents.push_back(a);
}

bool simulation::remove_agent(const std::shared_ptr<agent> &a)
{
  bool status = false;
  simulation::agents_container_type::iterator it = _agents.begin();
  for(; it != _agents.end(); ++it) {
    const std::shared_ptr<agent> &b = *it;
    if(a == b) {
      it = _agents.erase(it);
      status = true;
    }
  }
  return status;
}

void simulation::clear_agents()
{
  _agents.clear();
}

simulation::agents_container_type &simulation::agents() noexcept
{
  return _agents;
}

const simulation::agents_container_type &simulation::agents() const noexcept
{
  return _agents;
}

void simulation::agent_runner(const std::shared_ptr<class agent_runner> &a) noexcept
{
  _agent_runner = a;
}

const std::shared_ptr<class agent_runner> &simulation::agent_runner() const noexcept
{
  return _agent_runner;
}

void simulation::fitness_evaluator(const std::shared_ptr<class fitness_evaluator> &f) noexcept
{
  _fitness_evaluator = f;
}

const std::shared_ptr<class fitness_evaluator> &simulation::fitness_evaluator() const noexcept
{
  return _fitness_evaluator;
}

void simulation::agent_selector(const std::shared_ptr<class agent_selector> &a) noexcept
{
  _agent_selector = a;
}

const std::shared_ptr<class agent_selector> &simulation::agent_selector() const noexcept
{
  return _agent_selector;
}

fitness_evaluator::return_type simulation::average_fitness() const
{
  gab::fitness_evaluator::returns_container_type fits = _fitness_evaluator->apply(_agents);
  gab::fitness_evaluator::returns_container_type::const_iterator it = fits.begin();
  
  gab::fitness_evaluator::return_type ret = 0.0;
  for(; it != fits.end(); ++it) ret += *it;
  return ret / fits.size();
}

std::size_t simulation::generation() const
{
  return _generation;
}

void simulation::next_generation()
{
  fitness_evaluator::returns_container_type rets = _fitness_evaluator->apply(_agents);
  _agents = (*_agent_selector)(_agents, rets);
  ++_generation;
}
