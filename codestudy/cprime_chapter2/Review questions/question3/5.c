#include <stdio.h>
int main(void)
{
    int a, b;
    a = 5;  /* 第 7 行 */
    b = 2;  /* 第 8 行 */
    a = b;  /* 第 9 行 */
    printf("%d %d\n", b, a);
    return 0;
}