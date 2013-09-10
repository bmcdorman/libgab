#ifndef _GAB_ENVIRONMENT_2D_HPP_
#define _GAB_ENVIRONMENT_2D_HPP_

#include <cstddef>
#include <map>
#include <string>

namespace gab
{
  class environment_2d
  {
  public:
    typedef std::size_t size_type;
    typedef std::size_t handle_type;
    typedef std::size_t hash_type;
    typedef std::string name_type;
    typedef std::map<handle_type, name_type> type_map_type;
    
    environment_2d(const size_type width, const size_type height);
    environment_2d(const environment_2d &rhs);
    ~environment_2d();
    
    size_type width() const;
    size_type height() const;
    size_type size() const;
    
    handle_type add_type(const name_type &name);
    bool remove_type(const handle_type type);
    const type_map_type &types() const;
    hash_type types_hash() const;
    
    const handle_type *operator[](const size_type x) const;
    
  private:
    size_type _width;
    size_type _height;
    handle_type _next;
    type_map_type _types;
    handle_type **_environment;
  };
}

#endif
