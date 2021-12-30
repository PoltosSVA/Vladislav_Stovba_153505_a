#include "pch.h"

TEST(Case1, Task7) {

	std::string mas("argentinamanitnegra");
  EXPECT_EQ(palin(mas), true);
 
}
TEST(Case2, Task7) {

	std::string mas("aboba");
	EXPECT_EQ(palin(mas), true);

}
TEST(Case3, Task7) {

	std::string mas("asdfghj");
	EXPECT_EQ(palin(mas), false);

}
TEST(Case4, Task7) {

	std::string mas("exe");
	EXPECT_EQ(palin(mas), true);
	
}
TEST(Case5, Task7) {

	std::string mas("exe");
	
	EXPECT_EQ(prov(mas), false);
}
TEST(Case6, Task7) {

	std::string mas("aaa");

	EXPECT_EQ(prov(mas),true);
}