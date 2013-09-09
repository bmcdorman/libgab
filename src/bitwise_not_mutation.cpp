#include <gab/bitwise_not_mutation.hpp>

using namespace gab;

chromosome bitwise_not_mutation::operator()(const chromosome &operand)
{
  chromosome::container_type::size_type bsize = operand.size() * sizeof(chromosome::value_type);
  
  chromosome ret(operand.size());
  unsigned char *const ret_data = reinterpret_cast<unsigned char *>(ret.genes().data());
  const unsigned char *const orig_data = reinterpret_cast<const unsigned char *>(operand.genes().data());
  
  for(chromosome::container_type::size_type i = 0; i < bsize; ++i) {
    ret_data[i] = ~orig_data[i];
  }
  
  return ret;
}