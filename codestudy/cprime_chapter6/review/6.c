

#include <stdio.h>
int main(void)
{
    for (int i = 0; i < 5; i++) { // 控制行数
        for (int j = 0; j < 8; j++) { // 控制每行的字符数
            printf("$");
        }
        printf("\n"); // 每行结束后换行
    }
    return 0;
}
/*
$$$$$$$$
$$$$$$$$
$$$$$$$$
$$$$$$$$
$$$$$$$$
*/