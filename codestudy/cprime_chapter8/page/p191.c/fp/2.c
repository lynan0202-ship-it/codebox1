#include <stdlib.h>  // 包含 exit 函数*/

#include <stdio.h>   // 包含文件操作函数
int main() {
    FILE *fp;  // 定义文件指针
    
    // 打开文件：参数1是文件名，参数2是打开模式
    // "r" 表示只读模式（读取已存在的文件）
    fp = fopen("test.txt", "r");
    
    // 关键：检查文件是否打开成功
    if (fp == NULL) {
        printf("文件打开失败！可能原因：文件不存在或权限不足。\n");
        exit(1);  // 打开失败则退出程序
    }
    
    // 后续操作...
    // 接上面的代码（文件已成功打开）
    printf("文件内容：\n");
    int ch;  // 用 int 类型接收，因为 fgetc 返回 EOF 时是负数

    // 循环读取，直到文件末尾（EOF 表示文件结束）
    while ((ch = fgetc(fp)) != EOF) {
    putchar(ch);  // 把读到的字符打印到屏幕
    }
    return 0;
}