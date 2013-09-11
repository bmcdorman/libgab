#ifndef _GAB_AGENT_RUNNER_HPP_
#define _GAB_AGENT_RUNNER_HPP_

#include "agent.hpp"
#include <memory>

namespace gab
{
  class agent_runner
  {
  public:
    virtual ~agent_runner();
    virtual bool operator()(const std::shared_ptr<agent> &a) = 0;
  };
}

#endif
