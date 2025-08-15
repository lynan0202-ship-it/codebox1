#include <stdio.h>   // 提供 printf、getchar 等输入输出函数
#include <ctype.h>   // 提供字符测试、映射函数（isalpha/tolower 等）

int main(void) {
    char ch = 'A';  // 初始化测试字符，可按需修改（如 '5'、' '、'\n' 等）
    
    // --------------------- 1. 字符测试函数演示 --------------------- 
    // isalpha：判断是否为字母（A-Z/a-z）
    printf("1. isalpha('%c')：%s\n", ch, isalpha(ch) ? "是字母" : "不是字母");
    
    // isdigit：判断是否为数字（0-9）
    ch = '5';  // 修改字符为数字
    printf("2. isdigit('%c')：%s\n", ch, isdigit(ch) ? "是数字" : "不是数字");
    
    // isspace：判断是否为空白字符（空格、换行、制表符等）
    ch = ' ';  // 修改字符为空格
    printf("3. isspace('%c')：%s\n", ch, isspace(ch) ? "是空白字符" : "不是空白字符");
    
    // ispunct：判断是否为标点符号（非字母、数字、空白的可打印字符）
    ch = '!';  // 修改字符为标点
    printf("4. ispunct('%c')：%s\n", ch, ispunct(ch) ? "是标点符号" : "不是标点符号");
    
    // --------------------- 2. 字符映射函数演示 --------------------- 
    ch = 'Z';  // 初始化大写字母，测试 tolower
    // tolower：大写字母转小写，非大写则返回原字符
    char lowerCh = tolower(ch);
    printf("5. tolower('%c') 结果：'%c'（ASCII 码：%d）\n", ch, lowerCh, lowerCh);
    
    ch = 'a';  // 初始化小写字母，测试 toupper
    // toupper：小写字母转大写，非小写则返回原字符
    char upperCh = toupper(ch);
    printf("6. toupper('%c') 结果：'%c'（ASCII 码：%d）\n", ch, upperCh, upperCh);
    
    // --------------------- 3. 综合场景：遍历输入字符并判断 --------------------- 
    printf("\n请输入任意字符（按回车结束）：\n");
    while ((ch = getchar()) != '\n') {  // 循环读取输入，直到遇到换行
        printf("字符：'%c' -> ", ch);
        
        if (isalpha(ch)) {  // 字母判断
            printf("是字母，小写形式：'%c'，大写形式：'%c'\n", 
                   tolower(ch), toupper(ch));
        } else if (isdigit(ch)) {  // 数字判断
            printf("是数字\n");
        } else if (isspace(ch)) {  // 空白字符判断（如空格、换行）
            printf("是空白字符\n");
        } else if (ispunct(ch)) {  // 标点判断
            printf("是标点符号\n");
        } else {
            printf("是其他字符\n");
        }
    }

    return 0;
}

/*
1. isalpha('A')：是字母
2. isdigit('5')：是数字
3. isspace(' ')：是空白字符
4. ispunct('!')：是标点符号
5. tolower('Z') 结果：'z'（ASCII 码：122）
6. toupper('a') 结果：'A'（ASCII 码：65）

请输入任意字符（按回车结束）：
4
字符：'4' -> 是数字
*/