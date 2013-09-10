/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#include <gab/serial_node.hpp>

using namespace gab;

void serial_node::set_attribute(const key_type &key, const value_type &value)
{
  _attributes[key] = value;
}

bool serial_node::remove_attribute(const key_type &key)
{
  serial_node::attribute_container_type::iterator it = _attributes.find(key);
  if(it == _attributes.end()) return false;
  _attributes.erase(it);
  return true;
}

void serial_node::clear_attributes()
{
  _attributes.clear();
}

void serial_node::add_child(const serial_node::ptr_type &child)
{
  _children.push_back(child);
}

bool serial_node::remove_child(const serial_node::ptr_type &child)
{
  bool state = false;
  serial_node::child_container_type::iterator it = _children.begin();
  for(; it != _children.end(); ++it) {
    if(*it == child) {
      it = _children.erase(it);
      state = true;
    }
  }
  return state;
}

void serial_node::clear_children()
{
  _children.clear();
}

serial_node::child_container_type::iterator serial_node::children_begin()
{
  return _children.begin();
}

serial_node::child_container_type::iterator serial_node::children_end()
{
  return _children.end();
}

serial_node::size_type serial_node::num_children() const
{
  return _children.size();
}