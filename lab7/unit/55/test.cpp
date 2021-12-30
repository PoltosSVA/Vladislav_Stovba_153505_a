#include "pch.h"

TEST(Case1, Task5) {
    const char* rom[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
    int arabik[] = { 1,   4,    5,   9,    10,  40,  50,   90,  100, 400,  500, 900,  1000 };

    int i = 25;
  EXPECT_TRUE(arab2roman(i,rom,arabik),"XXV");
}
TEST(Case2, Task5) {
    const char* rom[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
    int arabik[] = { 1,   4,    5,   9,    10,  40,  50,   90,  100, 400,  500, 900,  1000 };

    int i = 4327;
    EXPECT_TRUE(arab2roman(i, rom, arabik), "MMMMCCCXXVII");
}
TEST(Case3, Task5) {
    const char* rom[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
    int arabik[] = { 1,   4,    5,   9,    10,  40,  50,   90,  100, 400,  500, 900,  1000 };

    int i = 1;
    EXPECT_TRUE(arab2roman(i, rom, arabik), "I");
}