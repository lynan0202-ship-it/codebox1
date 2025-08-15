/*
width.c -- 字段宽度
*/

#include <stdio.h>
#define PAGES 959

int main(void)
{
    // 无宽度指定：直接输出整数和星号，无填充
    printf("%d*\n", PAGES);  // 输出：959*
    
    // 宽度为2，但实际数值959占3位：自动扩展宽度，不截断数值
    printf("*%2d*\n", PAGES); // 输出：*959*
    
    // 宽度为10：右对齐，左边用空格填充至总宽度10
    printf("*%10d*\n", PAGES); // 输出：*       959*
    
    // 负号表示左对齐：宽度为10，右边用空格填充至总宽度10
    printf(" *%-10d*\n", PAGES); // 输出： *959       *
    
    return 0;
}
/*
print out:

959*
*959*
*       959*
 *959       *

*/