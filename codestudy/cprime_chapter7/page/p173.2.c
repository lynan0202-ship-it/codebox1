#include <stdio.h>
#include <ctype.h>

int main(void) {
    char ch;
    printf("请输入一个字符：");
    ch = getchar();

    // 判断是否为字母
    if (isalpha(ch)) {
        printf("是字母(ch=%d)\n",ch);
        // 判断是否为小写字母
        if (islower(ch)) {
            printf("是小写字母。\n");
        } else {
            printf("不是小写字母(ch=%d)。\n",ch);
        }
    } else {
        printf("不是字母。\n");
    }
    return 0;
}
/*
请输入一个字符：a
是字母(ch=97)
是小写字母。
*/
/*
请输入一个字符：1
不是字母。
*/