/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_CHROMOSOME_HPP_
#define _GAB_CHROMOSOME_HPP_

#include <array>
#include <cstddef>
#include <typeinfo>

#include "serial_node.hpp"

namespace gab
{
  template<typename T, std::size_t N>
  class chromosome
  {
  public:
    typedef T value_type;
    typedef std::size_t size_type;
    typedef std::array<T, N> container_type;
    
    static constexpr size_type size = N;
    
    T &operator[](const typename std::array<T, N>::size_type i)
    {
      return _array[i];
    }
    
    const T &operator[](const typename std::array<T, N>::size_type i) const
    {
      return _array[i];
    }
    
    const container_type &container() const noexcept
    {
      return _array;
    }
    
    container_type &container() noexcept
    {
      return _array;
    }
    
    serial_node::ptr_type serialize() const
    {
      serial_node::ptr_type ret(new serial_node);
      ret->set_attribute("name", "chromosome");
      for(size_type i = 0; i < size; ++i) {
      }
      return ret;
    }
    
  private:
    serial_node::ptr_type serialize_array() const
    {
      serial_node::ptr_type ret(new serial_node);
      ret->set_attribute("name", "array");
      ret->set_attribute("size", size);
      for(size_type i = 0; i < size; ++i) {
        ret->add_child(serialize_array_element());
      }
      return ret;
    }
    
    serial_node::ptr_type serialize_array_element(const size_type i) const
    {
      serial_node::ptr_type ret(new serial_node);
      return ret;
    }
    
    container_type _array;
  };
  
  template<std::size_t N>
  struct real_chromosome : public chromosome<double, N> {};
  
  template<std::size_t N>
  struct byte_chromosome : public chromosome<unsigned char, N> {};
}

#endif
