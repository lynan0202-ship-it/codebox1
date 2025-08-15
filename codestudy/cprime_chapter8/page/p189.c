/*echo_eof.c--重复输入，直到文件结尾*/
#include<stdio.h>
int main (void)
{
    int ch;
    while((ch=getchar())!=EOF)/*当输入不是文件结尾时*/
        putchar(ch);          /*输出该字符*/
    return 0;
}
/*
uiwreqiuwgruiqiwq^Z
uiwreqiuwgruiqiwq␦

safageasegafaa^Z
safageasegafaa␦

^X

^Z
PS C:\code\codebox1> 
*/