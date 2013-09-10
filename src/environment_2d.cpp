/*
 * Copyright (c) 2013, Braden McDorman
 * All Rights Reserved. Distributed under the terms of the MIT License.
 */

#include <gab/environment_2d.hpp>

using namespace gab;

environment_2d::environment_2d(const environment_2d::size_type width, const environment_2d::size_type height)
  : _width(width)
  , _height(height)
  , _next(1)
  , _environment(new environment_2d::handle_type*[_width])
{
  for(environment_2d::size_type x = 0; x < _width; ++x) {
    _environment[x] = new environment_2d::handle_type[_height];
    memset(_environment[x], 0, _height * sizeof(environment_2d::handle_type));
  }
}

environment_2d::environment_2d(const environment_2d &rhs)
  : _width(rhs._width)
  , _height(rhs._height)
  , _next(rhs._next)
  , _types(rhs._types)
  , _environment(new environment_2d::handle_type*[_width])
{
  for(environment_2d::size_type x = 0; x < _width; ++x) {
    _environment[x] = new environment_2d::handle_type[_height];
    memcpy(_environment[x], rhs._environment[x], _height * sizeof(environment_2d::handle_type));
  }
}

environment_2d::~environment_2d()
{
  for(environment_2d::size_type x = 0; x < _width; ++x) delete[] _environment[x];
  delete[] _environment;
}

environment_2d::size_type environment_2d::width() const
{
  return _width;
}

environment_2d::size_type environment_2d::height() const
{
  return _height;
}

environment_2d::size_type environment_2d::size() const
{
  return _width * _height;
}

environment_2d::handle_type environment_2d::add_type(const environment_2d::name_type &name)
{
  _types[_next] = name;
  return _next++;
}

environment_2d::hash_type environment_2d::types_hash() const
{
  // This will in theory correctly identify changes to the type map.
  // 0 is also reserved for users as a "null" value.
  return (_next << 16) | (_types.size() << 0);
}

bool environment_2d::remove_type(const environment_2d::handle_type type)
{
  type_map_type::iterator it = _types.find(type);
  if(it == _types.end()) return false;
  _types.erase(it);
  return true;
}

const environment_2d::type_map_type &environment_2d::types() const
{
  return _types;
}

const environment_2d::handle_type *environment_2d::operator[](const environment_2d::size_type x) const
{
  if(x >= _width) throw std::out_of_range("x >= width");
  return _environment[x];
}