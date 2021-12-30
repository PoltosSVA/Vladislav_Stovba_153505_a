#include "pch.h"

TEST(Case1, task4) {
	std::string wewe = "lern";
  EXPECT_TRUE(lens(wewe),4);
}
TEST(Case2, task4) {
	std::string wewe = "lololololo";
	EXPECT_TRUE(lens(wewe), 10);
}
TEST(Case3, task4) {
	std::string wewe = "a";
	EXPECT_TRUE(lens(wewe), 1);
}
TEST(Case4, task4) {
	std::string wewe = "    ";
	EXPECT_TRUE(lens(wewe), 4);
}