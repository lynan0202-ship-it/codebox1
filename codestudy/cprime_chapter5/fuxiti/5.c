#include <stdio.h>
#define FORMAT "Hi! %s C is cool!\n"
int main(void)
{
    int num = 10;
    // 1. 先替换 FORMAT 为 "Hi! %s C is cool!\n"，再把 FORMAT 当参数传，即 printf("Hi! %s C is cool!\n", "Hi! %s C is cool!\n");
    printf(FORMAT, FORMAT); 
    // 2. num 自增前是 10，++num 先加 1 再用，输出 11
    printf("%d\n", ++num);  
    // 3. num++ 先用当前值 11，再自增，输出 11（之后 num 变为 12 ）
    printf("%d\n", num++);  
    // 4. num 现在是 12，输出 12
    printf("%d\n", num--);  
    // 5. 输出固定字符串
    printf("%d\n",num);  
    return 0;
}
/*
Hi! Hi! %s C is cool!
 C is cool!
11
11
12
11
*/