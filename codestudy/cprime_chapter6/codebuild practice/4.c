#include <stdio.h>

int main() {
    // 记录每行起始字母的偏移，控制 A、B、D、G 等起始位置
    int startOffset = 0;  

    // 外层循环控制行数（共 6 行）
    for (int row = 1; row <= 6; row++) {  
        // 内层循环打印当前行的字母
        for (int col = 0; col < row; col++) {  
            // 'A' + startOffset + col：逐个取字母
            printf("%c", 'A' + startOffset + col);  
        }
        // 更新下一行起始字母的偏移，每行偏移量递增（1, 2, 3...）
        startOffset += row;  
        // 换行，准备打印下一行
        printf("\n");  
    }

    return 0;
}
/*
A
BC
DEF
GHIJ
KLMNO
PQRSTU
*/

/*
注释说明：
startOffset 控制每行第一个字母的位置（A → B → D → G...）。
外层循环 row 决定行数，内层循环 col 打印当前行的字母。
每行结束后，startOffset 累加当前行数，实现字母 “跳跃”（如第 1 行后 startOffset=1，第 2 行后 startOffset=3 等 ）。
*/