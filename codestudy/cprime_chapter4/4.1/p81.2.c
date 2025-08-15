#include <stdio.h>

int main(void) {
    // ========== 原有场景变量 ==========
    // 场景 1/2/3 基础测试数据
    int val1_1 = 12, val2_1 = 234, val3_1 = 1222;
    int val1_2 = 4, val2_2 = 5, val3_2 = 23;
    int val1_3 = 22334, val2_3 = 2322, val3_3 = 10001;
    double distance = 10.22;


    // ========== 场景 1：默认无固定宽度（原逻辑） ==========
    printf("----- 场景 1：不指定固定字段宽度 -----\n");
    printf("%d %d %d\n", val1_1, val2_1, val3_1);
    printf("%d %d %d\n", val1_2, val2_2, val3_2);
    printf("%d %d %d\n", val1_3, val2_3, val3_3);
    printf("\n");


    // ========== 场景 2：固定 9 字符宽度对齐（原逻辑） ==========
    printf("----- 场景 2：指定固定字段宽度（9 个字符） -----\n");
    printf("%9d %9d %9d\n", val1_1, val2_1, val3_1);
    printf("%9d %9d %9d\n", val1_2, val2_2, val3_2);
    printf("%9d %9d %9d\n", val1_3, val2_3, val3_3);
    printf("\n");


    // ========== 场景 3 扩展：溢出 10 位 + 空白分隔（新增逻辑） ==========
    // 新增溢出测试变量（加 _ext 后缀避免重复）
    int val1_ext = 123456789;  // 11 位，溢出 9 字符宽度
    int val2_ext = 2322, val3_ext = 10001; 

    printf("----- 场景 3 扩展：溢出字段宽度演示（变量名加 _ext 区分） -----\n");
    // 带空白分隔：即使溢出也不会紧连
    printf("%9d  %9d  %9d\n", val1_ext, val2_ext, val3_ext);
    // 无空白分隔：溢出后数字直接拼接，演示混淆风险
    printf("%9d%9d%9d\n", val1_ext, val2_ext, val3_ext);
    printf("\n");


    // ========== 场景 4：文字嵌入数字（原逻辑） ==========
    printf("----- 场景 4：文字中嵌入数字（适配宽度） -----\n");
    printf("Count Beppo ran %.2f miles in 3 hours.\n", distance);
    printf("Count Beppo ran %10.2f miles in 3 hours.\n", distance);


    return 0;
}
/*
----- 场景 1：不指定固定字段宽度 -----
12 234 1222
4 5 23
22334 2322 10001

----- 场景 2：指定固定字段宽度（9 个字符） -----
       12       234      1222
        4         5        23
    22334      2322     10001

----- 场景 3 扩展：溢出字段宽度演示（变量名加 _ext 区分） -----
-539222987       2322      10001
-539222987     2322    10001

----- 场景 4：文字中嵌入数字（适配宽度） -----
Count Beppo ran 10.22 miles in 3 hours.
Count Beppo ran      10.22 miles in 3 hours.
*/

/*
----- 场景 1：不指定固定字段宽度 -----
12 234 1222
4 5 23
22334 2322 10001

----- 场景 2：指定固定字段宽度（9 个字符） -----
       12       234      1222
        4         5        23
    22334      2322     10001

----- 场景 3 扩展：溢出字段宽度演示（变量名加 _ext 区分） -----
-539222987       2322      10001
-539222987     2322    10001

----- 场景 4：文字中嵌入数字（适配宽度） -----
Count Beppo ran 10.22 miles in 3 hours.
Count Beppo ran      10.22 miles in 3 hours.
*/