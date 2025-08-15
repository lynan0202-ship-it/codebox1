#include <stdio.h>  // 包含标准输入输出库，用于printf等函数

int main() {
    // 定义一个字符数组lets，存储26个大写字母
    // "ABCDEFGHIJKLMNOPQRSTUVWXYZ"是字符串常量，会自动在末尾加'\0'结束符
    // 数组大小27刚好容纳26个字母加1个结束符
    char lets[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    // 外层循环：控制金字塔的行数，共6行（i从0到5）
    // i=0时是第1行，i=5时是第6行
    for (int i = 0; i < 6; i++) { 
        // 内层循环：控制每行打印的字母数量
        // j从0到i，共i+1个字母（第1行1个，第2行2个...第6行6个）
        for (int j = 0; j <= i; j++) { 
            // 打印对应的字母，重点理解这里的下标计算：
            // 'F' - 'A' 的结果是5（因为F是第6个字母，A是第1个，6-1=5）
            // 减去j后，得到从5开始递减的下标：5,4,3,2,1,0...
            // lets[5]是'F'，lets[4]是'E'，lets[3]是'D'，以此类推
            printf("%c", lets['F' - 'A' - j]); 
        }
        // 每行字母打印完后换行，进入下一行
        printf("\n"); 
    }
    return 0;  // 程序正常结束
}
/*
F
FE
FED
FEDC
FEDCB
FEDCBA
*/