#include <stdio.h>
int main(void)          /*一个简单的c程序*/

{
    int num;            /*定义一个名为num的变量*/
    num =1;             /*为num赋值*/

    {
        printf("I am a simple ");/*使用printf函数*/
        printf("computer.\n");
        printf("\tMy favorite number is %d because it is first .\n",num);
    }   
    return 0;
}