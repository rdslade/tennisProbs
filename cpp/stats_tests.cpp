#include "stats.h"
#include "unit_test_framework.h"
#include <iostream>
#include <string>

using namespace std;
TEST(test_factorial){
  ASSERT_TRUE(factorial(0) == 1);
  ASSERT_TRUE(factorial(1) == 1);
  ASSERT_TRUE(factorial(2) == 2);
  ASSERT_TRUE(factorial(3) == 6);
}

TEST(test_nchoosek){
  ASSERT_TRUE(nchoosek(5, 5) == 1);
  ASSERT_TRUE(nchoosek(4, 2) == 6);
  ASSERT_TRUE(nchoosek(3, 1) == 3);
  ASSERT_TRUE(nchoosek(10, 0) == 1);
}

TEST_MAIN()
