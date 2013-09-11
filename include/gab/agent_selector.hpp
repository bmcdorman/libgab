#ifndef _GAB_AGENT_SELECTOR_HPP_
#define _GAB_AGENT_SELECTOR_HPP_

#include <list>
#include <memory>
#include "agent.hpp"
#include "fitness_evaluator.hpp"

namespace gab
{
  class agent_selector
  {
  public:
    virtual std::list<std::shared_ptr<agent>> operator()(const std::list<std::shared_ptr<agent>> &agents, const fitness_evaluator::returns_container_type &fitnesses) const = 0;
  };
}

#endif
