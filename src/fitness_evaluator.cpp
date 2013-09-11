#include <gab/fitness_evaluator.hpp>

using namespace gab;

fitness_evaluator::returns_container_type fitness_evaluator::apply(const std::list<std::shared_ptr<agent>> &evaluatees) const
{
  fitness_evaluator::returns_container_type ret;
  typename std::list<std::shared_ptr<agent>>::const_iterator it = evaluatees.begin();
  for(; it != evaluatees.end(); ++it) ret.push_back((*this)(*it));
  return ret;
}