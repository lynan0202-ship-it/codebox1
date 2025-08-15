#include <stdio.h>
// 需包含 string.h 才能用 strlen
#include <string.h>  

int main() {
    // 假设每行不超过 255 字符
    char input[256];  

    printf("请输入一行内容：");
    // 注意：scanf 遇到空格会停止，这里用 fgets 读取整行（包含空格 ）
    fgets(input, 256, stdin);  

    // 去掉 fgets 可能读取的换行符（如果存在 ）
    input[strcspn(input, "\n")] = '\0';  

    // 倒序遍历字符数组
    for (int i = strlen(input) - 1; i >= 0; i--) {  
        printf("%c", input[i]);
    }
    printf("\n");

    return 0;
}

