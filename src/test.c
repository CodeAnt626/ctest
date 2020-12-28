#include <test.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

Function func_arr[100];
int func_cnt = 0;           // 记录当前有几个测试用例
struct FunctionInfo test_info; // 记录成功与总次数

void add_function(TestFuncT func, const char *str) {
    func_arr[func_cnt].func = func;
    func_arr[func_cnt].str = strdup(str);
    ++func_cnt;
    return ;
}

int RUN_ALL_TESTS() {
    for (int i = 0; i < func_cnt; ++i) {
        printf(GREEN("[====RUN====]"));
        printf(RED_HL(" %s\n"), func_arr[i].str);
        test_info.total = 0, test_info.success = 0;
        func_arr[i].func();
        double rate = 100.0 * test_info.success / test_info.total;
        printf(PURPLE_HL("[  "));
        if (fabs(rate - 100.0) < 1e-6) {
            printf(BLUE_HL("%6.2lf%%"), rate);
        } else {
            printf(RED_HL("%6.2lf%%"), rate);
        }
        printf(PURPLE_HL("  ]"));
        printf(" total : %d\tsuccess : %d\n", test_info.total, test_info.success);
    }
    return 0;
}
