
/* 
问题5题干：EOF是什么？

知识要点：
1. EOF宏定义：在stdio.h中定义为-1
2. 作用：标记文件结束（End-Of-File）
3. 应用场景：作为getchar()、scanf()等函数的返回值

总体逻辑：
通过代码演示EOF的检测和值的验证

代码功能：
1. 读取字符并检测EOF
2. 输出EOF的实际值（验证为-1）
*/

#include <stdio.h>

int main() {
    int ch;
    
    printf("Enter characters (press Ctrl+D/Ctrl+Z to end):\n");
    
    // 持续读取字符，直到遇到EOF
    while ((ch = getchar()) != EOF) {
        printf("Character: %c (ASCII: %d)\n", ch, ch);
    }
    
    // 输出EOF的实际值
    printf("EOF detected! EOF value is: %d\n", EOF);

    return 0;
}

/* 
测试验证方案：
1. 正常输入测试：
   - 输入abc，观察输出字符的ASCII值（如a=97, b=98, c=99）

2. EOF触发测试：
   - 按Ctrl+D（Linux/Mac）或Ctrl+Z（Windows）
   - 观察输出EOF value is: -1（验证定义）

3. 跨平台验证：
   - 在不同操作系统测试EOF触发方式，确认程序行为一致
*/