/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_CHROMOSOME_HPP_
#define _GAB_CHROMOSOME_HPP_

#include <vector>

namespace gab
{
  class chromosome
  {
  public:
    typedef double value_type;
    typedef std::vector<value_type> container_type;
    
    chromosome(const container_type::size_type size);
    value_type &operator[](const container_type::size_type i);
    const value_type &operator[](const container_type::size_type i) const;
    const container_type &genes() const noexcept;
    container_type &genes() noexcept;
    typename container_type::size_type size() const noexcept;
    bool valid() const noexcept;
    
    bool operator ==(const chromosome &rhs) const;
    
  private:
    container_type _genes;
  };
}

#endif
