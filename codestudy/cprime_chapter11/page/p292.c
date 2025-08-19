/* 
代码名称：put_put.c（教材程序清单11.16，含put1、put2及测试逻辑）
知识要点总结：
1. 字符串遍历：通过指针++遍历，利用 '\0' 自动终止循环（while(*string) 等价于 while(*string!='\0')）
2. 自定义输出函数：基于putchar实现，替代库函数puts，灵活控制格式
3. const修饰：参数用const char*，保证函数内不修改输入字符串，增强安全性
4. 函数返回值：put2返回打印的字符数（不含换行），演示“先执行函数，再用返回值”的嵌套逻辑
5. 代码复用：put1是基础输出，put2在其基础上扩展统计功能

代码总体逻辑：
1. 定义put1：逐字符输出字符串（无自动换行），通过指针遍历直到遇到'\0'
2. 定义put2：调用put1的逻辑（逐字符输出），同时统计字符数，最后手动换行，返回统计值
3. main函数测试：
   - 用put1分两次输出长句（模拟多行拼接）
   - 用printf嵌套调用put2，先输出句子，再输出其统计的字符数，验证执行顺序（put2先执行，再处理printf）
*/

#include <stdio.h>

// 函数声明：提前告诉编译器函数存在（定义在main之后，必须声明）
void put1(const char *string);  
int put2(const char *string);  

int main(void)
{
    // 测试put1：分两次输出，模拟拼接长句（put1不自动换行，所以手动加\n控制格式）
    put1("If I'd as much money");     // 输出：If I'd as much money（不换行）
    put1(" as I could spend,\n");     // 输出： as I could spend,（换行，因为字符串里有\n）
    
    // 测试put2的嵌套调用：
    // 1. 先执行put2("I never would cry old chairs to mend.") → 输出该句子并换行
    // 2. put2返回字符数，传给printf的%d → 输出统计结果
    printf("I count %d characters.\n",  
           put2("I never would cry old chairs to mend."));
    
    return 0;
}

/* 
put1函数：逐字符输出字符串，**不自动换行**（对比puts的自动换行）
参数：const char *string → 只读指针，防止函数内修改字符串内容
实现：
- 循环条件：*string → 当字符不是'\0'时继续（'\0'的ASCII值是0，条件为假时退出）
- 每次操作：putchar(*string++) → 先输出当前字符，再将指针移动到下一个字符
*/
void put1(const char *string)
{
    while (*string) {  // 等价于 while(*string != '\0')
        putchar(*string++);  // 先解引用输出，再移动指针（指针自增是地址+1，不是字符值+1）
    }
}

/* 
put2函数：在put1基础上，**统计输出的字符数**，并在最后**手动换行**
返回值：int → 输出的字符总数（不含最后的换行符）
实现：
1. 初始化count=0，统计字符数
2. 调用put1的逻辑逐字符输出，同时count++
3. 输出换行符（putchar('\n')），但不统计到count里
4. 返回count
*/
int put2(const char *string)
{
    int count = 0;
    while (*string) {
        putchar(*string++);
        count++;  // 每输出一个字符，计数+1
    }
    putchar('\n');  // 手动添加换行，模仿puts的换行效果，但单独控制
    return count;   // 返回实际输出的字符数（不含换行）
}


/* 
测试及验证建议方案：
1. 基础功能测试：
   - 测试put1：输入"Hello"，预期输出"Hello"（不换行）；接着输出put1(" World")，预期行内拼接为"Hello World"
   - 测试put2：输入"Hi"，预期输出"Hi\n"，返回值2；输入空字符串（""），预期输出换行，返回0

2. 嵌套调用验证：
   - 观察main中printf的输出顺序：put2先输出句子，再输出"I count ..."，验证“函数先执行，返回值后使用”的逻辑
   - 修改put2的返回值为count+1，看统计数是否变化，验证计数逻辑

3. 边界情况测试：
   - 传入超长字符串（如1000个字符），看是否正常遍历（利用'\0'自动终止，无需传长度，体现字符串的优势）
   - 传入NULL指针（危险！实际测试需谨慎，理解const不防NULL，调用时需保证string有效）

4. 对比库函数：
   - 用puts替换put1/put2，观察输出差异（puts自动换行，put1不换行；put2统计字符数，puts不能）
   - 测试put2("a\n")，看输出是否包含换行，统计数是否为2（'a'和'\n'？不，原字符串是"a\n"，遍历到'\n'时会输出，count+1，然后put2再手动加\n？哦，这里有坑！→ 发现教材中put2的逻辑：如果输入字符串本身有'\n'，put2会输出该'\n'，然后再加一个'\n'，导致两行空行。测试此情况，理解字符串内容对输出的影响。

5. 指针行为观察：
   - 在put1中添加printf("Current char: %c\n", *string); 观察指针移动过程（注意：会破坏输出格式，测试后删除）
   - 测试put1的参数为字符数组（如char str[]="Test"; put1(str);）和字符串字面量（put1("Test");），验证两者等价（因为数组名和字符串字面量都会退化为指针）

易错点提醒：
- while(*string++) 会先判断*string，再移动指针 → 即使字符串为空（首字符是'\0'），也会执行一次判断（但不会进入循环）
- const char* 是“指向const字符的指针”，可以传入非const的字符串（如char[]），但函数内不能修改内容
- put2统计的字符数不含**自己添加的换行符**，只统计输入字符串中的字符（包括其中的'\n'，如果有的话）
- 字符串字面量存在只读区，传入put1/put2是安全的（因为函数不修改内容）
*/