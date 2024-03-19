#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../tasks/task_1/task_1.h"

int arr[] = { 5, 24, 42, 13, 99, 2, 17 };
TEST(FirstTest, FirstName) {
	int a = 5 + 24 + 42 + 13 + 99 + 2 + 17;
	ASSERT_EQ(a, start(arr, 7, 1, 7));
}
TEST(SecontTest, FirstName) {
	int a = 5 + 24 + 42 + 13 + 99 + 2;
	ASSERT_EQ(a, start(arr, 7, 1, 6));
}
TEST(ThirdTest, FirstName) {
	int a = 42 + 13;
	ASSERT_EQ(a, start(arr, 7, 3, 4));
}
TEST(FourthTest, FirstName) {
	int a = 13 + 99 + 2;
	ASSERT_EQ(a, start(arr, 7, 4, 6));
}
TEST(FifthTest, FirstName) {
	int a = 99 + 2 + 17;
	ASSERT_EQ(a, start(arr, 7, 5, 7));
}

int main(int argc, char **argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}