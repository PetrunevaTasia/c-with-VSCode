#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../tasks/task_4/task_4.hpp"

int arr[] = { 5, 24, 42, 13, 99, 2, 17 };
TEST(FirstTest, move_constructor) {
	Treap t = Treap();
	int summ = start(t, arr, 7, 1, 7);
	Treap t2 = Treap(std::move(t));
	ASSERT_TRUE(summ == t2.sum(1, 7));
    ASSERT_TRUE(t.get_root() == nullptr);
}
TEST(SecondTest, move_assignment_operator) {
	Treap t = Treap();
	int summ = start(t, arr, 7, 1, 7);
	Treap t2 = Treap();
    t2 = std::move(t);
	ASSERT_TRUE(summ == t2.sum(1, 7));
    ASSERT_TRUE(t.get_root() == nullptr);
}

int main(int argc, char **argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}