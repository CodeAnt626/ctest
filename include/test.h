/*************************************************************************
	> File Name: test.h
	> Author: luowen
	> Mail: PohZero_Luo@163.com
	> Created Time: Thu 24 Dec 2020 03:34:52 PM CST
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

#define COLOR(a, b) "\033[0" #b "m" a "\033[0m"
#define COLOR_HL(a, b) "\033[0;1;" #b "m" a "\033[0m"

#define RED(a) COLOR(a, 31)
#define GREEN(a) COLOR(a, 32)
#define YELLOW(a) COLOR(a, 33)
#define BLUE(a) COLOR(a, 34)
#define PURPLE(a) COLOR(a, 35)

#define RED_HL(a) COLOR_HL(a, 31)
#define GREEN_HL(a) COLOR_HL(a, 32)
#define YELLOW_HL(a) COLOR_HL(a, 33)
#define BLUE_HL(a) COLOR_HL(a, 34)
#define PURPLE_HL(a) COLOR_HL(a, 35)

#define TEST(a, b) \
void a##_##b(); \
__attribute__((constructor)) \
void add##_##a##_##b() { \
    add_function(a##_##b, #a "." #b); \
} \
void a##_##b()

#define TYPE(a) _Generic((a), \
    int : "%d", \
    double : "%lf", \
    float : "%f", \
    long long : "%lld", \
    const char * : "%s", \
    char * : "%s" \
)

#define P(a, color) { \
    char frm[1000]; \
    sprintf(frm, color("%s"), TYPE(a)); \
    printf(frm, a); \
}

#define EXPECT(a, b, comp) { \
    __typeof(a) _a = (a); \
    __typeof(b) _b = (b); \
    ++test_info.total; \
    if (_a comp _b) ++test_info.success; \
    else { \
        printf("\n\t"); \
        printf(YELLOW_HL("%s:%d: failure\n"), __FILE__, __LINE__); \
        printf(YELLOW_HL("\t\texpect : " #a" "#comp" "#b "\n\t\t")); \
        printf(YELLOW_HL("actual : ")); \
        P(_a, YELLOW_HL); \
        printf(YELLOW_HL(" vs ")); \
        P(_b, YELLOW_HL); \
        printf("\n\n"); \
    } \
    printf("%s", _a comp _b ? GREEN("[-----------]") : RED("[     X     ]")); \
    printf(" %s %s %s\t%s\n", #a, #comp, #b, _a comp _b ? GREEN("TRUE") : RED("FALSE"));\
}

#define EXPECT_EQ(a, b) EXPECT(a, b, ==)
#define EXPECT_NE(a, b) EXPECT(a, b, !=)
#define EXPECT_LT(a, b) EXPECT(a, b, <)
#define EXPECT_LE(a, b) EXPECT(a, b, <=)
#define EXPECT_GT(a, b) EXPECT(a, b, >)
#define EXPECT_GE(a, b) EXPECT(a, b, >=)

// TEST展开函数的函数指针类型
typedef void (*TestFuncT)();

// 记录TEST展开函数的信息
typedef struct Function {
    TestFuncT func;     // 函数指针
    const char *str;    // 函数名
} Function;

struct FunctionInfo {
    int total, success;
};

extern struct FunctionInfo test_info;
void add_function(TestFuncT, const char *);
int RUN_ALL_TESTS();

#endif
