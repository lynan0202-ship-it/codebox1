#include <stdio.h>
int main(void)
{
    char c1, c2;
    int diff;
    float num;
    // 'S' ASCII 码 83，'O' ASCII 码 79 
    c1 = 'S';  
    c2 = 'O';  
    // 83 - 79 = 4 
    diff = c1 - c2;  
    // diff 是 int 4，赋值给 float num 变为 4.0 
    num = diff;  
    // 输出：S O 83 4 4.00（字符、字符、ASCII 码、差值、浮点数形式 ）
    printf("%c%c%c%d %.2f\n", c1, c2, c2,diff, num);  
    return 0;
}
/*
SOO4 4.00
*/