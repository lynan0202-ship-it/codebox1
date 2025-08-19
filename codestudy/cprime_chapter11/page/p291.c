/* 
代码名称：printf_demo.c（演示printf函数核心特性：格式化、换行控制、多数据输出）
知识要点总结：
1. 字符串输出对比：
   - puts：自动追加换行符，用法简单（puts(str)）
   - printf：需手动加\n（printf("%s\n", str)），但支持更复杂格式
2. 多数据格式化能力：
   - printf可在一个语句中拼接多个字符串、变量（如%s搭配多个参数）
   - 支持不同数据类型（扩展示例：整数、浮点数等，体现“多才多艺”）
3. 效率与灵活性权衡：
   - printf语法更复杂，但功能更强大；puts更简洁但功能单一

代码总体逻辑：
1. 基础对比阶段：
   - 定义字符串str，分别用printf（加\n）和puts输出，观察换行效果
2. 多数据拼接阶段：
   - 定义用户名name和宏MSG，用printf一次性拼接输出多个内容
3. 扩展数据类型阶段（延伸教材，体现格式化能力）：
   - 加入整数age，演示printf同时输出字符串和整数（%s和%d的配合）
   - 展示printf处理不同类型的灵活性，对比puts只能输出字符串的局限
*/

#include <stdio.h>  // 包含printf/puts所需的头文件

#define MSG "Welcome to C world!"  // 定义宏字符串，类似教材示例

int main(void) {
    // 基础字符串测试
    char str[] = "Hello, printf!";  // 定义字符数组，末尾自动加'\0'
    
    // ========== 测试1：printf与puts的换行对比 ==========
    printf("--- 测试1：换行行为对比 ---\n");
    // printf输出：格式串里加\n，才会换行
    printf("%s\n", str);  // 效果：Hello, printf!（换行）
    // puts输出：自动加换行，无需手动写\n
    puts(str);            // 效果：Hello, printf!（换行）
    // 额外对比：printf不加\n的情况
    printf("%s", str);    // 效果：Hello, printf!（不换行，后面内容会接在此行）
    printf("（这里是printf不加\\n的后续内容）\n");  // 验证换行差异
    
    // ========== 测试2：多字符串拼接（教材核心示例） ==========
    char name[] = "Alice";  // 模拟用户名
    printf("\n--- 测试2：多字符串拼接 ---\n");
    // 教材示例：拼接"Well, " + name + ", " + MSG
    printf("Well, %s, %s\n", name, MSG);  // 输出：Well, Alice, Welcome to C world!
    
    // ========== 测试3：扩展：多数据类型格式化（延伸教材，体现“多才多艺”） ==========
    int age = 20;  // 定义整数，演示printf处理不同类型
    printf("--- 测试3：多数据类型格式化（延伸） ---\n");
    // 同时输出字符串、整数、字符串（%s对应字符串，%d对应整数）
    printf("Hi, %s! You are %d years old. %s\n", name, age, MSG);  
    // 输出示例：Hi, Alice! You are 20 years old. Welcome to C world!
    
    return 0;
}

/* 
测试及验证建议方案：
1. 基础换行验证：
   - 运行程序，观察测试1的输出：
     - printf("%s\n", str) 和 puts(str) 都换行，效果一致
     - printf("%s", str) 后接的内容在同一行，验证“printf不自动换行”
   - 修改str内容，重复测试，确保换行逻辑稳定

2. 拼接功能验证：
   - 测试2中，修改name和MSG的内容（如name改为"Bob"，MSG改为"Have fun!"），观察输出是否正确拼接
   - 尝试添加更多%s参数（如再加一个字符串），验证printf可支持多个参数拼接

3. 多类型格式化验证（延伸测试）：
   - 修改age的值（如30），观察%d是否正确替换
   - 加入浮点数（如float score=95.5;），用%f测试：printf("Your score is %f\n", score); 验证格式支持
   - 对比：尝试用puts输出整数（会报错，因为puts只接受字符串地址），体会printf的类型兼容性

4. 易错点排查：
   - 故意写错格式符（如把%s写成%z），观察编译警告/运行错误，理解格式符必须匹配数据类型
   - 忘记给printf加\n，观察输出是否连在一起，强化“printf需手动控制换行”的记忆
   - 对比printf和puts的运行效率（实际差别极小，可通过循环输出10000次，粗略感受时间差异，但初学者可跳过，重点理解功能差异）

5. 教材示例复现：
   - 严格按照教材里的#define和printf示例，删除扩展部分，单独运行，确保和教材描述一致
   - 比如：#define MSG "Test"，char name[]="Tom"，printf("Well, %s, %s\n", name, MSG); 验证输出
*/