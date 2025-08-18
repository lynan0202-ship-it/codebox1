#include <stdio.h>

int main(void)
{
    // 第二次优化：区分合法输入（y/n）与非法输入
    int guess = 1;
    char response;  // 存储用户输入的响应字符
    printf("----- 第二次优化（区分合法/非法输入） -----\n");
    printf("Pick an integer from 1 to 100. I will try to guess it.\n");
    printf("Respond with a y if my guess is right and with an n if it is wrong.\n");
    printf("Uh...is your number %d?\n", guess);

    while ((response = getchar()) != 'y') 
    {
        // 跳过当前输入行剩余的所有字符（直到遇到换行符）
        while (getchar() != '\n') 
            continue;

        // 区分合法输入（n）和非法输入（其他字符）
        if (response == 'n') 
        {
            printf("Well, then, is it %d?\n", ++guess);
        } 
        else 
        {
            printf("Sorry, I understand only y or n.\n");
        }
    }

    printf("I knew I could do it!\n\n");
    return 0;
}
/*
----- 第二次优化（区分合法/非法输入） -----
Pick an integer from 1 to 100. I will try to guess it.
Respond with a y if my guess is right and with an n if it is wrong.
Uh...is your number 1?
s
Sorry, I understand only y or n.
d
Sorry, I understand only y or n.
n
Well, then, is it 2?
y
I knew I could do it!
*/