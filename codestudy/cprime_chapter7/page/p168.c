#include <stdio.h>

// 每罐油漆可刷面积（平方英尺）
#define COVERAGE 350  

int main(void)
{
    // 待刷面积（平方英尺）
    int sq_feet;  
    // 所需油漆罐数
    int cans;     

    // 提示用户输入待刷面积
    printf("Enter number of square feet to be painted:\n");
    // 循环读取输入，直到用户输入非数字（如 q 退出）
    while (scanf("%d", &sq_feet) == 1) {  

        // --------------------- 条件运算符基础用法（核心语法） --------------------- 
        // 语法：expression1 ? expression2 : expression3
        // 含义：如果 expression1 为真（非0），结果为 expression2；否则为 expression3
        // 这里：sq_feet / COVERAGE → 整数除法（截断小数）
        cans = sq_feet / COVERAGE;  
        // 条件：sq_feet % COVERAGE == 0？（是否能被 COVERAGE 整除）
        //       → 能整除 → +0；不能整除 → +1（补全剩余面积所需的1罐）
        cans += (sq_feet % COVERAGE == 0) ? 0 : 1;  


        // --------------------- 条件运算符与 if-else 对比（教程知识点） --------------------- 
        // 等价 if-else 写法：
        // if (sq_feet % COVERAGE == 0)
        //     cans += 0;
        // else
        //     cans += 1;
        // 条件运算符更简洁，适合简单分支场景


        // --------------------- 条件运算符嵌套（扩展用法） --------------------- 
        // 示例：判断 cans 是否为1，决定输出 "can" 或 "cans"
        // 语法：多层嵌套时，按从左到右的优先级解析
        // 这里：(cans == 1) ? "can" : "cans"
        printf("You need %d %s of paint.\n", 
               cans, 
               (cans == 1) ? "can" : "cans");  


        // --------------------- 条件运算符的运算对象（支持字符串） --------------------- 
        // 教程知识点：条件运算符的 expression2 和 expression3 可以是字符串
        // 注意：C语言中字符串是 const char* 类型，这里直接使用字面量


        // 提示继续输入或退出
        printf("Enter next value (q to quit):\n");
    }

    printf("Bye.\n");
    return 0;
}
/*
Enter number of square feet to be painted:
354
You need 2 cans of paint.
Enter next value (q to quit):
1
You need 1 can of paint.
Enter next value (q to quit):
2
You need 1 can of paint.
Enter next value (q to quit):
q
Bye.
*/