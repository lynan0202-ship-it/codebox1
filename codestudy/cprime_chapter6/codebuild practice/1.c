#include <stdio.h>

int main() {
    // 用 ASCII 码初始化数组，'a' 到 'z' 依次存储
    char letters[26];
    for (int i = 0; i < 26; i++) {
        letters[i] = 'a' + i;
    }

    // 打印数组内容
    for (int i = 0; i < 26; i++) {
        printf("%c ", letters[i]);
    }
    printf("\n");

    return 0;
}