#include "pch.h"

TEST(Case1, Task6) {
  EXPECT_EQ(rec(5), 120);
  
}
TEST(Case2, Task6) {
	EXPECT_EQ(rec(1), 1);

}
TEST(Case3, Task6) {
	EXPECT_EQ(rec(0), 1);

}
TEST(Case4, Task6) {
	EXPECT_EQ(rec(-5), 0);

}