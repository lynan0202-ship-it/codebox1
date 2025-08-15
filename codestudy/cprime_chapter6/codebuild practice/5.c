#include <stdio.h>

int main() {
    char inputChar;
    printf("请输入一个大写字母: ");
    // 输入大写字母（如 'E'）
    scanf(" %c", &inputChar);  

    // 计算输入字母与 'A' 的偏移，确定总行数（如 'E' - 'A' = 4，共 5 行 ）
    int maxRow = inputChar - 'A' + 1;  

    // 外层循环控制行数
    for (int row = 1; row <= maxRow; row++) {  
        // 1. 打印前导空格：让金字塔居中
        for (int space = 1; space <= maxRow - row; space++) {  
            printf(" ");
        }

        // 2. 升序打印字母（如 A→B→C... ）
        for (int asc = 'A'; asc < 'A' + row; asc++) {  
            printf("%c", asc);
        }

        // 3. 降序打印字母（如 C→B→A，注意从 row-2 开始 ）
        for (int desc = 'A' + row - 2; desc >= 'A'; desc--) {  
            printf("%c", desc);
        }

        // 换行，准备下一行
        printf("\n");  
    }

    return 0;
}

/*
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA
*/

/*
输入字母决定金字塔高度（如 E 对应 5 行 ）。
每行分三部分：前导空格（居中）、升序字母、降序字母。
降序部分从 row-2 开始，避免重复打印中间字母（如第 3 行 ABCBA，升序到 C，降序从 B 开始 ）。
*/