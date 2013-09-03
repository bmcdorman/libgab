/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#ifndef _GAB_SERIAL_NODE_HPP_
#define _GAB_SERIAL_NODE_HPP_

#include <cstddef>
#include <list>
#include <memory>
#include <sstream>
#include <map>

namespace gab
{
  class serial_node
  {
  public:
    typedef std::string key_type;
    typedef std::string value_type;
  private:
    typedef std::map<key_type, value_type> attribute_container_type;
  public:
    typedef std::shared_ptr<serial_node> ptr_type;
    typedef std::list<ptr_type> child_container_type;
    typedef std::size_t size_type;
    
    void set_attribute(const key_type &key, const value_type &value);
    template<typename T>
    void set_attribute(const key_type &key, const T &value)
    {
      std::ostringstream o;
      o << value;
      set_attribute(key, o.str());
    }
    
    template<typename T>
    T get_attribute(const key_type &key, const T &def = T()) const
    {
      const attribute_container_type::const_iterator it = _attributes.find(key);
      if(it == _attributes.end()) return def;
      std::istringstream i(it->second);
      T ret;
      i >> ret;
      return ret;
    }
    
    bool remove_attribute(const key_type &key);
    void clear_attributes();
    
    void add_child(const serial_node::ptr_type &child);
    bool remove_child(const serial_node::ptr_type &child);
    void clear_children();
    child_container_type::iterator children_begin();
    child_container_type::iterator children_end();
    size_type num_children() const;
    
  private:
    child_container_type _children;
    attribute_container_type _attributes;
  };
}

#endif
