#include "pch.h"

TEST(Case1, task1) {
	std::string mas = "28989";
	EXPECT_TRUE(lens(mas), 5);
}
TEST(Case2, task1) {
	std::string mas = "..........";
	EXPECT_TRUE(lens(mas), 10);
}
TEST(Case3, task1) {
	std::string mas = "++-lpm";
	EXPECT_TRUE(lens(mas), 6);
}
TEST(Case4, task1) {
	std::string mas = "wwwwww";
	EXPECT_TRUE(lens(mas), 6);
}