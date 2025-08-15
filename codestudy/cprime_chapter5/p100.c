// 引入标准输入输出库，让程序能使用 printf 等输入输出函数
#include <stdio.h>  
// 定义常量 MAX，代表初始的矿泉水瓶总数（100 瓶）
#define MAX 15     

int main(void)
{
    // 初始化计数器，初始值比 MAX 多 1，为前缀递减做准备
    int count = MAX + 1;  

    // while 循环：使用前缀递减运算符 --count
    // 每次先将 count 减 1，再判断是否大于 0；当 count 减到 0 时，循环结束
    while (--count > 0) {  
        // 第一行输出：显示当前剩余的矿泉水瓶数（墙上的数量）
        // %d 用于格式化输出整数（count 的值）
        printf("%d bottles of spring water on the wall, ", count);  
        // 第二行输出：呼应第一行，强调总数，语法和第一行一致
        printf("%d bottles of spring water!\n", count);  

        // 第三行输出：模拟“取下一瓶传递”的动作描述
        printf("Take one down and pass it around,\n");  
        // 第四行输出：显示取下一瓶后剩余的数量（count - 1）
        // 这里故意保留“复数问题”（比如 count=1 时会显示 0 bottles ），后续学条件运算符可修复
        printf("%d bottles of spring water!\n\n", count - 1);  
    }

    // 程序正常结束，返回 0 给操作系统
    return 0;  
}
/*

.........
9 bottles of spring water on the wall, 9 bottles of spring water!
Take one down and pass it around,
8 bottles of spring water!

8 bottles of spring water on the wall, 8 bottles of spring water!
Take one down and pass it around,
7 bottles of spring water!

7 bottles of spring water on the wall, 7 bottles of spring water!
Take one down and pass it around,
6 bottles of spring water!

6 bottles of spring water on the wall, 6 bottles of spring water!
Take one down and pass it around,
5 bottles of spring water!

5 bottles of spring water on the wall, 5 bottles of spring water!
Take one down and pass it around,
4 bottles of spring water!

4 bottles of spring water on the wall, 4 bottles of spring water!
Take one down and pass it around,
3 bottles of spring water!

3 bottles of spring water on the wall, 3 bottles of spring water!
Take one down and pass it around,
2 bottles of spring water!

2 bottles of spring water on the wall, 2 bottles of spring water!
Take one down and pass it around,
1 bottles of spring water!

1 bottles of spring water on the wall, 1 bottles of spring water!
Take one down and pass it around,
0 bottles of spring water!

*/