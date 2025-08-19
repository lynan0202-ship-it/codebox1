/* 
代码名称：test_fit.c（教材程序清单11.17，演示strlen与字符串截断）
知识要点总结：
1. strlen函数：计算字符串有效长度（不含末尾'\0'），需包含<string.h>
2. 字符串截断：通过修改指定位置为'\0'实现，直接操作原字符串（参数为char*，非const）
3. 字符串常量串联：相邻双引号字符串会被编译器自动拼接（如"a""b" → "ab"）
4. 指针偏移特性：mesg + 39 指向数组第39个元素，即使前面被截断，后续字符仍驻留内存
5. puts行为：遇到'\0'停止输出，但不会清除内存中后续字符

代码总体逻辑：
1. 定义fit函数：
   - 第一步：用strlen判断字符串长度是否超过size
   - 第二步：若超过，将string[size]设为'\0'（截断字符串）
2. main函数流程：
   - 初始化mesg为拼接后的长字符串（利用字符串串联特性）
   - 输出原始字符串 → 调用fit截断 → 输出截断后字符串（到新'\0'为止）
   - 输出提示信息 → 通过mesg+39访问截断点后的字符，演示内存中剩余数据的存在

*/

#include <stdio.h>
#include <string.h>  // 必须包含，否则strlen未定义

// 函数声明：修改字符串内容，故参数为char*（允许修改），size是无符号整数（长度不能为负）
void fit(char *string, unsigned int size);

int main(void)
{
    // 字符串串联：两个相邻的字符串字面量会被编译器合并成一个
    char mesg[] = "Things should be as simple as possible,"
                  " but not simpler.";  // 实际存储为连续的字符数组
    
    puts(mesg);  // 输出完整字符串（包含拼接后的内容）
    
    // 截断操作：保留前38个有效字符（索引0~37），第38位设为'\0'
    fit(mesg, 38);  
    puts(mesg);     // 输出到新'\0'为止，后续字符仍在内存但不显示
    
    puts("Let's look at some more of the string.");
    // mesg+39：指向数组第39个元素的地址（跳过前39个字符）
    // 即使前面被截断，后面的字符还在内存中，puts会从该位置输出到原字符串的'\0'
    puts(mesg + 39);
    
    return 0;
}

// fit函数：截断字符串的实现
void fit(char *string, unsigned int size)
{
    // strlen(string)：计算当前字符串长度（直到第一个'\0'，不含'\0'）
    if (strlen(string) > size) {
        string[size] = '\0';  // 在size位置插入结束符，后续字符仍在内存但不再被视为字符串的一部分
    }
}

/* 
测试及验证建议方案：
1. 基础功能验证：
   - 运行程序，检查输出是否与教材一致：
     - 原始行："Things should be as simple as possible, but not simpler."
     - 截断后："Things should be as simple as possible"（逗号被截断）
     - mesg+39输出：" but not simpler."（验证后续字符存在）

2. 边界条件测试：
   - 测试size=0：fit(mesg, 0) → mesg[0]='\0'，puts(mesg)输出空行
   - 测试size等于字符串长度：fit(mesg, strlen(mesg)) → 无操作，输出完整字符串
   - 测试size超过字符串长度：fit(mesg, 100) → 无操作，输出完整字符串

3. 内存观察测试：
   - 在fit调用后，添加循环打印前50个字符：
     for (int i = 0; i < 50; i++) {
         putchar(mesg[i]);
     }
     putchar('\n');
     观察'\0'的位置（第38位）和后续字符是否存在

4. 字符串串联验证：
   - 修改mesg初始化：char mesg[] = "Hello" " World"; → 输出"Hello World"，验证串联
   - 故意插入空格：char mesg[] = "Hello" "  " "World"; → 输出"Hello  World"，验证空格保留

5. 易错点排查：
   - 传入const字符串：const char *s = "test"; fit(s, 2); → 编译报错（尝试修改只读内存），理解const的保护作用
   - size设为负数：fit(mesg, -1); → 因unsigned特性，-1变成很大的数（如4294967295），可能导致数组越界，体会无符号类型的风险
   - 忘记包含<string.h>：编译提示"strlen未定义"，理解头文件的必要性

6. 扩展理解测试：
   - 手动实现strlen：写一个my_strlen函数，用指针遍历统计长度，对比库函数结果
   - 测试动态数组：char mesg[100] = "long string..."; 验证截断后数组剩余空间的内容
   - 对比printf输出：printf("%s\n", mesg + 39); 与puts效果一致，验证输出函数特性
*/