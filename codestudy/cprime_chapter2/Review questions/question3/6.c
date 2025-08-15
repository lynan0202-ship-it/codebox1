#include <stdio.h>
int main(void)
{
    int x, y;
    x = 10;
    y = 5;      /* 第 7 行 */
    y = x + y;  /* 第 8 行 */
    printf("%d %d\n", x, y);
    x = x * y;  /* 第 9 行 */
    printf("%d %d\n", x, y);
    return 0;
}