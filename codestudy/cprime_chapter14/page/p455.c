/*
代码名称：names1.c
知识要点总结：
1. 结构体定义与成员访问：通过 struct 定义复合结构，用 -> 访问指针指向结构体的成员
2. 函数传参：通过结构体指针实现双向数据传递，const 修饰指针保证只读访问
3. 输入处理：自定义 s_gets 函数解决 fgets 残留换行符问题，结合 strchr 处理输入边界
4. 字符串操作：strlen 计算长度、strchr 查找字符，体现 C 标准库的使用
5.  const 修饰：showinfo 用 const 确保函数不修改结构体内容，增强代码健壮性

代码总体逻辑说明：
1. 主流程：main 中定义结构体变量 person，依次调用三个函数：
   - getinfo：接收用户输入的名和姓（通过指针修改结构体）
   - makeinfo：计算名和姓的总长度（通过指针修改结构体）
   - showinfo：输出结果（通过 const 指针只读访问）
2. 辅助函数：s_gets 封装 fgets，处理换行符和超长输入，避免缓冲区污染
*/

#include <stdio.h>
#include <string.h>  // 提供 strlen、strchr 函数支持

#define NLEN 30      // 定义名字最大长度（含结束符）

// 定义结构体：存储名、姓、总字母数
struct namect {     
    char fname[NLEN];// 名（字符数组）
    char lname[NLEN];// 姓（字符数组）
    int letters;     // 名+姓的总字母数
};

// 函数声明（便于编译器提前识别）
void getinfo(struct namect *);        // 获取用户输入
void makeinfo(struct namect *);       // 计算名字长度
void showinfo(const struct namect *); // 输出信息（const 保证只读）
char * s_gets(char * st, int n);      // 安全输入函数

int main(void)
{
    struct namect person;  // 定义结构体变量
    getinfo(&person);      // 传递地址，让函数修改 person
    makeinfo(&person);     // 传递地址，计算长度
    showinfo(&person);     // 传递地址，只读输出
    return 0;
}

// getinfo：通过指针接收结构体地址，获取用户输入
void getinfo(struct namect * pat)
{
    printf("Please enter your first name.\n");
    s_gets(pat->fname, NLEN); // 给 fname 成员赋值（pat->fname 等价于 (*pat).fname）
    
    printf("Please enter your last name.\n");
    s_gets(pat->lname, NLEN); // 给 lname 成员赋值
}

// makeinfo：计算名和姓的总字母数（strlen 不包含结束符）
void makeinfo(struct namect * pat)
{
    // 累加两个字符串的长度，存入 letters 成员
    pat->letters = strlen(pat->fname) + strlen(pat->lname);
}

// showinfo：用 const 修饰指针，确保函数内不会修改结构体内容
void showinfo(const struct namect * pat)
{
    printf("%s %s, your name contains %d letters.\n", 
           pat->fname,   // 访问名
           pat->lname,   // 访问姓
           pat->letters  // 访问总长度
    );
}

// s_gets：解决 fgets 残留换行符问题，返回值同 fgets（方便判断输入是否有效）
char * s_gets(char * st, int n)
{
    char * ret_val = fgets(st, n, stdin); // 读取一行，最多存 n-1 个字符
    if (ret_val != NULL) {                // 读取成功时处理
        char * find = strchr(st, '\n');   // 查找换行符位置
        if (find != NULL) {               // 找到换行符
            *find = '\0';                 // 替换为结束符，去掉换行
        } else {                          // 没找到换行符（输入超长）
            while (getchar() != '\n') {   // 清空输入缓冲区剩余字符
                continue;
            }
        }
    }
    return ret_val; // 返回 fgets 的结果（可能为 NULL，比如EOF）
}

/*
代码测试及验证建议方案：
1. 正常流程测试：
   - 输入短名字（如 "Ada" "Lovelace"），检查输出长度是否 3+8=11
   - 输入超长名字（如 29 个字符的名），检查是否截断，且后续输入正常

2. 边界情况测试：
   - 输入空字符串（直接回车），观察程序是否能处理空名字
   - 测试 const 约束：尝试在 showinfo 里写 pat->letters=0，看编译器是否报错

3. 输入污染测试：
   - 故意输入带换行符的内容（如 "Alice\nBob"），检查 s_gets 是否正确处理
   - 输入超过 NLEN-1 的字符（如 30 个字符），检查缓冲区是否被清空

4. 知识点验证：
   - 对比 "pat->fname" 和 "(*pat).fname" 的写法，理解 -> 的语法糖作用
   - 注释掉 const 修饰，观察函数内修改结构体是否被允许，体会 const 的保护作用
*/