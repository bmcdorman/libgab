#include <gab/agent_2d.hpp>

using namespace gab;

agent_2d::agent_2d(const class chromosome &c)
  : agent(c)
  , _x(0)
  , _y(0)
{
}

agent_2d::agent_2d(const class chromosome &c, const environment_2d::size_type x, const environment_2d::size_type y)
  : agent(c)
  , _x(x)
  , _y(y)
{
  
}

void agent_2d::x(const environment_2d::size_type x) noexcept
{
  _x = x;
}

void agent_2d::y(const environment_2d::size_type y) noexcept
{
  _y = y;
}

environment_2d::size_type agent_2d::x() const noexcept
{
  return _x;
}

environment_2d::size_type agent_2d::y() const noexcept
{
  return _y;
}

void agent_2d::environment(const environment_2d *const e) noexcept
{
  _environment = e;
}

const environment_2d *agent_2d::environment() const noexcept
{
  return _environment;
}