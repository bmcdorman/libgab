#include <gab/chromosome.hpp>

using namespace gab;

chromosome::chromosome(const chromosome::container_type::size_type size)
  : _genes(size)
{
}

chromosome::value_type &chromosome::operator[](const chromosome::container_type::size_type i)
{
  return _genes[i];
}

const chromosome::value_type &chromosome::operator[](const chromosome::container_type::size_type i) const
{
  return _genes[i];
}

const chromosome::container_type &chromosome::genes() const noexcept
{
  return _genes;
}

chromosome::container_type &chromosome::genes() noexcept
{
  return _genes;
}

typename chromosome::container_type::size_type chromosome::size() const noexcept
{
  return _genes.size();
}

bool chromosome::valid() const noexcept
{
  return !_genes.empty();
}

bool chromosome::operator ==(const chromosome &rhs) const
{
  return _genes == rhs._genes;
}