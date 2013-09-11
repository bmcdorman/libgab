#include <gab/simulation_2d.hpp>
#include <gtest/gtest.h>

using namespace gab;

TEST(size, retention_1)
{
  const static simulation_2d::size_type width = 125;
  const static simulation_2d::size_type height = 51;
  simulation_2d s(width, height);
  EXPECT_EQ(s.environment().width(), width);
  EXPECT_EQ(s.environment().height(), height);
}


TEST(size, retention_2)
{
  const static simulation_2d::size_type width = 13;
  const static simulation_2d::size_type height = 53;
  environment_2d test(width, height);
  simulation_2d s(test);
  EXPECT_EQ(s.environment(), test);
}
