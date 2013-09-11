#ifndef _GAB_AGENT_2D_HPP_
#define _GAB_AGENT_2D_HPP_

#include "agent.hpp"
#include "environment_2d.hpp"

namespace gab
{
  class agent_2d : public agent
  {
  public:
    agent_2d(const class chromosome &c);
    agent_2d(const class chromosome &c, const environment_2d::size_type x, const environment_2d::size_type y);
    
    void x(const environment_2d::size_type x) noexcept;
    void y(const environment_2d::size_type y) noexcept;
    
    environment_2d::size_type x() const noexcept;
    environment_2d::size_type y() const noexcept;
    
    void environment(const environment_2d *const e) noexcept;
    const environment_2d *environment() const noexcept;
    
  private:
    environment_2d::size_type _x;
    environment_2d::size_type _y;
    const environment_2d *_environment;
  };
}

#endif
