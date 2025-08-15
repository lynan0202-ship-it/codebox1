//第二段代码（演示 scanf 跳过输入功能 ）

#include <stdio.h>
int main(void)
{
    // 用于存储最终要获取的整数
    int n;

    // 提示用户输入三个整数
    printf("Please enter three integers:\n");
    // %*d 表示跳过一个整数输入，这里跳过前两个，只把第三个整数存入 n 
    scanf("%*d %*d %d", &n);
    // 输出最终获取到的第三个整数
    printf("The last integer was %d\n", n);

    return 0;
}

/*
Please enter three integers:
2013 2014 2015
The last integer was 2015
*/


/*
重点展示 scanf 里 * 修饰符的 “跳过” 效果：
%*d 会读取一个整数但不存储，所以前两个输入被跳过，仅第三个输入赋值给 n ，契合教程中 “跳过指定输入项，获取特定位置数据” 的用法说明，
比如处理有固定冗余数据的输入场景 。
这两段注释紧扣教程对 printf/scanf 修饰符、动态格式控制的讲解逻辑，
能帮你更清晰理解代码里每个部分对应知识点的实践方式，若对具体语法细节（如 * 修饰符原理）想深挖，可接着拓展分析～
*/