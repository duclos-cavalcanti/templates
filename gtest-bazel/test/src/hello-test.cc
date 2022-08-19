#include <gtest/gtest.h>

extern "C"
{
#include "hello-lib.h"
#include "hello-other.h"
}

// Simple test case
TEST(HelloTestSuite, HelloTestName_Increment) {
  // This test is named HelloTestName 
  // But belongst the Hello Test

  EXPECT_EQ(2, exampleIncrement(1));

  // EXPECT_EQ(expected, actual) is the same as
  //
  //   EXPECT_TRUE((expected) == (actual))
  //
  // except that it will print both the expected value and the actual
  // value when the assertion fails.  This is very helpful for
  // debugging.  Therefore in this case EXPECT_EQ is preferred.
  //
  // On the other hand, EXPECT_TRUE accepts any Boolean expression,
  // and is thus more general.
}

TEST(HelloTestSuite, HelloTestName_Decrement_PASSED) {
  EXPECT_EQ(1, exampleDecrement(2));
}

TEST(HelloTestSuite, HelloTestName_Decrement_FAILED) {
  EXPECT_EQ(1, exampleDecrement(1));
}
