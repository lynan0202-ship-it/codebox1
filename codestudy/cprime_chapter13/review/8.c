// ------------------------------
// 题干：8. 分析printf、fprintf(stdout)、fprintf(stderr)的区别
// 知识要点：
//  1. 输出流：stdout（标准输出，默认缓冲）、stderr（标准错误，无缓冲）
//  2. 缓冲差异：stdout可能延迟输出，stderr立即输出
//  3. printf是fprintf(stdout, ...)的简写
// 总体逻辑：
//  1. 模拟耗时操作，观察输出时机差异
#include <stdio.h>
#include <unistd.h> // 用于sleep（Linux/Unix环境）

int main() {
    char name[] = "World";
    
    printf("printf输出 ");      // stdout，行缓冲（没换行时可能延迟）
    fprintf(stdout, "fprintf(stdout) "); // 同stdout，缓冲
    fprintf(stderr, "fprintf(stderr) "); // stderr，无缓冲，立即输出
    
    sleep(3); // 暂停3秒，看输出时机
    
    printf("\n"); // 强制stdout换行，刷新缓冲
    return 0;
}

// 测试验证方案：
//  1. 运行：编译后执行，观察输出顺序
//  2. 预期：
//     - 立即看到 "fprintf(stderr) "
//     - 3秒后看到 "printf输出 fprintf(stdout) \n"
//  3. 核心原因：stderr无缓冲，stdout有缓冲
// 易错点提醒：
//  1. 以为三者输出完全同步，忽略缓冲差异
//  2. Windows环境下，<unistd.h>不存在，需替换为：
//     #include <windows.h> 
//     Sleep(3000); // 注意首字母大写
// 拓展思考：
//  1. 如何强制刷新stdout的缓冲？用 fflush(stdout); 
//  2. 为什么错误信息必须用stderr？（确保即使程序崩溃，错误也能输出）
// ------------------------------
