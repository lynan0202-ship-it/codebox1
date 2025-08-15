#include <stdio.h>

int main(void) {
    char first[20], last[20];

    // 提示用户输入名和姓
    printf("请输入你的名：");
    scanf("%s", first);
    printf("请输入你的姓：");
    scanf("%s", last);

    // 按“名.姓”格式输出
    printf("%s.%s\n", first, last);

    return 0;
}
/*
请输入你的名：NIANIAN
请输入你的姓：LIU
NIANIAN.LIU
*/