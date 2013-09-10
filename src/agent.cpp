/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#include <gab/agent.hpp>

using namespace gab;

agent::agent(const class chromosome &c) noexcept
  : _chromosome(c)
{
}

const class chromosome &agent::chromosome() const noexcept
{
  return _chromosome;
}

bool agent::operator ==(const agent &rhs) const
{
  return _chromosome == rhs._chromosome;
}