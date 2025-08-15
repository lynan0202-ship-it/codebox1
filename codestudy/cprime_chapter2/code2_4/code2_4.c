//two_fubnc.c -- 一个文件中包含两个函数
#include <stdio.h>
void butler(void);/*ANSI/ISO C函数原形*/

int main()
{
    printf("I will summon the bulter function.\n");
    butler();
    printf("Yes. Bring me some tea and writeable DVDs.\n");
     
    return 0;

}
void butler(void)
{
    printf("You rang, sir?\n");
}
