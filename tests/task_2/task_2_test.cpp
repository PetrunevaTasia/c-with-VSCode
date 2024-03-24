#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../tasks/task_2/task_2.hpp"
#include <optional>

using namespace std;
using namespace Framework;

TEST(FirstTest, TestName) {
	optional<Point> p = find_intersection(Line(5, 4), Line(3, 6));
	ASSERT_EQ(1, p->x);
	ASSERT_EQ(9, p->y);
}
TEST(SecondTest, TestName) {
	optional<Point> p = find_intersection(Line(6, 9), Line(2, 1));
	ASSERT_EQ(-2, p->x);
	ASSERT_EQ(-3, p->y);
}
TEST(ThirdTest, TestName) {
	optional<Line> line = find_perpendicular(Line(5, 1), Point(3, 1));
	ASSERT_EQ(-0.2, line->p.first);
	ASSERT_EQ(1.6, line->p.second);
}
TEST(FourthTest, TestName) {
	optional<Line> line = find_perpendicular(Line(12, 89), Point(-2, 6));
	ASSERT_DOUBLE_EQ(-1. / 12, line->p.first);
	ASSERT_DOUBLE_EQ(35. / 6, line->p.second);
}
TEST(FifthTest, TestName) {
	optional<Point> p = find_intersection(Line(-8, 13), Line(9, 54));
	ASSERT_DOUBLE_EQ(-41. / 17, p->x);
	ASSERT_DOUBLE_EQ(549. / 17, p->y);
}
TEST(SixthTest, TestName) {
	optional<Point>p = find_intersection(Line(12, 16), Line(12, 20));
	ASSERT_TRUE(p == nullopt);
}
TEST(SevenTest, TestName) {
	optional<Line> line = find_perpendicular(Line(0, 16), Point(12, 20));
	ASSERT_TRUE(line == nullopt);
}
int main(int argc, char **argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}