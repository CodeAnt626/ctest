/*************************************************************************
	> File Name: main.c
	> Author: luowen
	> Mail: PohZero_Luo@163.com
	> Created Time: Thu 24 Dec 2020 02:54:13 PM CST
 ************************************************************************/
#include <stdio.h>
#include <test.h>

int add(int a, int b) {
    return a + b;
}

double double_add(double a, double b) {
    return a + b;
}

TEST(func, add) {
    EXPECT_EQ(add(1, 2), 3);
    EXPECT_EQ(add(2, 4), 7);
    EXPECT_EQ(add(2, 4), 6);
    EXPECT_GT(add(0, 9), -9);
    EXPECT_GE(add(0, 9), 9);
}

TEST(func, double_add) {
    EXPECT_EQ(double_add(0.5, 2), 2.5);
    EXPECT_EQ(double_add(2.1, 0.9), 3);
    EXPECT_EQ(double_add(3.2, 3.2), 6);
    EXPECT_GT(double_add(0, 3.7), -9);

}

TEST(func, add2) {
    EXPECT_EQ(add(-1, 1), 0);
    EXPECT_EQ(add(3, -2), 1);
    EXPECT_NE(add(2, 3), 4);
    EXPECT_LT(add(-1, -2), 3);
    EXPECT_LE(add(0, 6), 5);
}

TEST(f, uncadd) {
    EXPECT_EQ(add(0, 0), 0);
    EXPECT_EQ(add(12, -12), 0);
}

int main() {
    return RUN_ALL_TESTS();
}
