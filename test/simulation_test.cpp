#include <gab/simulation.hpp>
#include <gtest/gtest.h>

using namespace gab;

TEST(constructed, defaults)
{
  simulation s;
  EXPECT_EQ(s.agents().empty(), true);
}