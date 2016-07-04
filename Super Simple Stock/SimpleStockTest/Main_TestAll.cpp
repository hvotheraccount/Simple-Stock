//main class for running all google tests
#include <gtest\gtest.h>

int main(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}