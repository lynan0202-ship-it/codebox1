#include <stdio.h>
// 需包含 string.h 才能使用 strlen
#include <string.h>  

int main() {
    char word[100];
    printf("请输入一个单词: ");
    // 输入单词
    scanf("%s", word);  

    // strlen 获取单词长度（不含结束符 '\0' ）
    int len = strlen(word);  

    printf("倒序结果: ");
    // 从最后一个字符开始遍历
    for (int i = len - 1; i >= 0; i--) {  
        printf("%c", word[i]);
    }
    printf("\n");

    return 0;
}

/*
请输入一个单词: PRACTICE
倒序结果: ECITCARP
*/