#include <stdio.h>

void br (void);
void rc (void);


int main(void) 
{
    char ch;

    printf("Please enter a character.\n");
    scanf("%c", &ch);  // 添加取地址符&
    printf("The code for %c is %d or %d or %o or 0x%x.\n", 
           ch, (int)ch, (int)ch, (int)ch, (int)ch);  // 补充完整参数并修正格式符

    return 0;
}

void br (void)
{

}


void rc (void)
{
   
}