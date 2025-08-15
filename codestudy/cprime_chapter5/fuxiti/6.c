#include <stdio.h>
#define S_CONV 60
int main(void)
{
    int sec, min, left;
    printf("This program converts seconds to minutes and ");
    printf("seconds.\n");
    printf("Enter the number of seconds.\n");
    printf("Enter 0 to end the program.\n");
    while (1) { 
        printf("Enter seconds: ");
        // 错误：sec 未初始化，若用户输入非整数，scanf 失败后 sec 是随机值，可能让 (sec > 0) 误判
        scanf("%d", &sec); 
        if (sec == 0) {
            break; 
        }
        min = sec / S_CONV;
        left = sec % S_CONV;
        printf("%d sec is %d min, %d sec.\n", sec, min, left);
        printf("Next input?\n");
    }
    printf("Bye!\n");
    return 0;
}