#include <stdio.h>

int main() {
    // 定义数组存储 8 个整数
    int arr[8];  

    printf("请输入 8 个整数：\n");
    for (int i = 0; i < 8; i++) {
        // 读入 8 个整数
        scanf("%d", &arr[i]);  
    }

    printf("倒序结果：\n");
    // 倒序遍历数组（从最后一个元素开始 ）
    for (int i = 7; i >= 0; i--) {  
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
/*
请输入 8 个整数：
10 2 4 6 3 6 6 5 4 3 
倒序结果：
5 6 6 3 6 4 2 10 
*/