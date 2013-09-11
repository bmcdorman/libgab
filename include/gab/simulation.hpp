/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_SIMULATION_HPP_
#define _GAB_SIMULATION_HPP_

#include <list>
#include <memory>
#include "agent.hpp"
#include "agent_runner.hpp"
#include "fitness_evaluator.hpp"
#include "agent_selector.hpp"

namespace gab
{
  class simulation
  {
  public:
    typedef std::list<std::shared_ptr<agent>> agents_container_type;

    simulation();

    virtual void add_agent(const std::shared_ptr<agent> &a);
    virtual bool remove_agent(const std::shared_ptr<agent> &a);
    virtual void clear_agents();
    agents_container_type &agents() noexcept;
    const agents_container_type &agents() const noexcept;
    
    void agent_runner(const std::shared_ptr<class agent_runner> &a) noexcept;
    const std::shared_ptr<class agent_runner> &agent_runner() const noexcept;
    
    void fitness_evaluator(const std::shared_ptr<class gab::fitness_evaluator> &f) noexcept;
    const std::shared_ptr<class gab::fitness_evaluator> &fitness_evaluator() const noexcept;
    
    void agent_selector(const std::shared_ptr<class agent_selector> &a) noexcept;
    const std::shared_ptr<class agent_selector> &agent_selector() const noexcept;
    
    gab::fitness_evaluator::return_type average_fitness() const;
    
    std::size_t generation() const;
    void next_generation();
    
  private:
    std::size_t _generation;
    agents_container_type _agents;
    std::shared_ptr<class agent_runner> _agent_runner;
    std::shared_ptr<class fitness_evaluator> _fitness_evaluator;
    std::shared_ptr<class agent_selector> _agent_selector;
  };
}

#endif
