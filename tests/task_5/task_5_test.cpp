#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../tasks/task_5/task_5.hpp"

TEST(FirstTest, deep_copying) {
    Point* p = new Point(5, 4);
    ScopedPointer s1 = ScopedPointer(p);
    ScopedPointer s2 = ScopedPointer(s1);
    Point result = s2.get();
    ASSERT_TRUE(result.x == 5);
    ASSERT_TRUE(result.y == 4);
}
TEST(SecondTest, transferring_an_ownership) {
    // Point* p = new Point(5, 4);
    // ScopedPointer<Point> s1 = ScopedPointer<Point>(p);
    // ScopedPointer<Point> s2 = ScopedPointer<Point>(std::move(s1));
    // Point result = s2.get();
    // ASSERT_TRUE(result.x == 5);
    // ASSERT_TRUE(result.y == 4);
}

int main(int argc, char **argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}