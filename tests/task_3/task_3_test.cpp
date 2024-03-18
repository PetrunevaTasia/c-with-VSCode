#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../tasks/task_3/task_3.h"

int arr[] = { 5, 24, 42, 13, 99, 2, 17 };
TEST(FirstTest, FirstName) {
	Treap t = Treap();
	int summ = start(t, arr, 7, 1, 7);
	Treap t2 = t;
	t2.insert_pos(4, 89);
	ASSERT_FALSE(summ == t2.sum(1, 7));
}
TEST(SecondTest, SecondName) {
	Treap t = Treap();
	int summ = start(t, arr, 7, 1, 7);
	Treap t2 = t;
	ASSERT_TRUE(summ == t2.sum(1, 7));
}
TEST(ThirdTest, ThirdName) {
	Treap t = Treap();
	int summ = start(t, arr, 7, 1, 6);
	Treap t2 = t;
	t2.insert_pos(7, 89);
	ASSERT_TRUE(summ == t2.sum(1, 6));
}
int main(int argc, char **argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}