#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char name[50];
    char temp[52];  // 为双引号和空字符留出空间

    printf("请输入你的名字：");
    scanf("%s", name);

    // a. 带双引号输出
    printf("\"%s\"\n", name);

    // b. 宽度20、右对齐（带双引号）
    sprintf(temp, "\"%s\"", name);
    printf("%20s\n", temp);

    // c. 宽度20、左对齐（带双引号）
    printf("%-20s\n", temp);

    // d. 宽度20、首字母大写
    if (name[0] >= 'a' && name[0] <= 'z') {
        name[0] = name[0] - 'a' + 'A';
    }
    printf("%20s\n", name);

    return 0;
}
/*

请输入你的名字：liunianian
"liunianian"
        "liunianian"
"liunianian"        
          Liunianian

*/