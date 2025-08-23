/*
代码名称：names3.c
知识要点总结：
1. 结构体指针成员：用 char* 代替字符数组，灵活分配字符串内存
2. 动态内存管理：
   - malloc(size)：按需求分配内存（size 需包含字符串结束符 '\0'）
   - free(ptr)：释放动态分配的内存，避免泄漏
3. 字符串操作：
   - strcpy(dest, src)：将字符串内容拷贝到新内存（区别于指针赋值！）
   - strlen(str)：计算字符串有效长度（不含 '\0'）
4. 输入安全：s_gets 处理 fgets 残留换行符，避免缓冲区溢出
5. 内存生命周期：动态分配的内存需手动释放，通过 cleanup 函数统一管理

代码总体逻辑说明：
1. 主流程（main）：
   - 定义结构体变量 person（含两个 char* 指针，初始为随机值）
   - getinfo：为 fname/lname 动态分配内存，读取用户输入并拷贝到新内存
   - makeinfo：计算 fname + lname 的总长度，存入 letters
   - showinfo：输出名字和总长度（只读访问，用 const 保护）
   - cleanup：释放 fname/lname 指向的动态内存，避免泄漏
2. 核心细节：
   - getinfo 中用临时数组 temp 暂存输入，再为指针分配精确内存（strlen(temp)+1）
   - 必须用 strcpy 拷贝内容（而非指针赋值），否则指针会指向栈上的临时数组（函数结束后失效）
   - cleanup 需在程序结束前调用，确保动态内存及时释放
*/

#include <stdio.h>
#include <string.h>   // 提供 strcpy、strlen
#include <stdlib.h>   // 提供 malloc、free

#define SLEN 81       // 临时数组长度（足够存用户输入）

// 定义结构体：用指针存储字符串（动态分配）
struct namect {
    char *fname;      // 指向动态分配的名字内存
    char *lname;      // 指向动态分配的姓氏内存
    int letters;      // 名字+姓氏的总字母数（不含 '\0'）
};

// 函数声明
void getinfo(struct namect *pat);     // 分配内存 + 读取输入
void makeinfo(struct namect *pat);    // 计算名字总长度
void showinfo(const struct namect *pat); // 输出信息（const 保证只读）
void cleanup(struct namect *pat);     // 释放动态内存
char *s_gets(char *st, int n);        // 安全输入函数（处理换行符）

int main(void)
{
    struct namect person;  // 定义结构体变量，初始时 fname/lname 是野指针！

    getinfo(&person);      // 1. 分配内存 + 读入名字（必须先调用，否则野指针危险）
    makeinfo(&person);     // 2. 计算总长度
    showinfo(&person);     // 3. 输出结果
    cleanup(&person);      // 4. 释放内存（关键！否则程序结束后内存泄漏）

    return 0;
}

/* 
getinfo 函数逻辑：
1. 用栈上的临时数组 temp 暂存用户输入（避免直接操作野指针）
2. 为 fname 分配内存：大小是 strlen(temp)+1（+1 存 '\0'）
3. 用 strcpy 将 temp 内容拷贝到新内存（而非直接赋值指针！）
4. lname 重复上述步骤
*/
void getinfo(struct namect *pat)
{
    char temp[SLEN];       // 临时数组，存在栈上，函数结束后销毁

    // 读取名字
    printf("Please enter your first name.\n");
    s_gets(temp, SLEN);    // 安全读取，处理换行符
    // 分配内存：长度是 temp 的有效长度 + 1（存 '\0'）
    pat->fname = (char *)malloc(strlen(temp) + 1);
    // 拷贝内容（必须用 strcpy，不能直接 pat->fname = temp！）
    strcpy(pat->fname, temp);

    // 读取姓氏（重复上述流程）
    printf("Please enter your last name.\n");
    s_gets(temp, SLEN);
    pat->lname = (char *)malloc(strlen(temp) + 1);
    strcpy(pat->lname, temp);
}

// makeinfo：计算名字 + 姓氏的总长度（strlen 不含 '\0'）
void makeinfo(struct namect *pat)
{
    pat->letters = strlen(pat->fname) + strlen(pat->lname);
}

// showinfo：只读输出，用 const 保证不会修改结构体内容
void showinfo(const struct namect *pat)
{
    printf("%s %s, your name contains %d letters.\n", 
           pat->fname,   // 访问动态分配的名字
           pat->lname,   // 访问动态分配的姓氏
           pat->letters  // 总长度
    );
}

/* 
cleanup 函数：释放动态分配的内存
注意：
1. 必须确认指针非 NULL（本示例中 getinfo 一定分配了内存，故省略检查）
2. 释放顺序不影响，但必须和 malloc 一一对应
*/
void cleanup(struct namect *pat)
{
    free(pat->fname);  // 释放名字的动态内存
    free(pat->lname);  // 释放姓氏的动态内存
}

// s_gets：和之前示例一致，处理 fgets 的换行符和超长输入
char *s_gets(char *st, int n)
{
    char *ret_val = fgets(st, n, stdin);  // 读取一行，最多存 n-1 个字符
    if (ret_val != NULL) {                // 读取成功时处理
        char *find = strchr(st, '\n');    // 查找换行符
        if (find != NULL) {               // 找到换行符
            *find = '\0';                 // 替换为结束符，去除换行
        } else {                          // 未找到换行符（输入超长）
            while (getchar() != '\n') {   // 清空输入缓冲区剩余字符
                continue;
            }
        }
    }
    return ret_val;  // 返回 fgets 的结果（可能为 NULL，如 EOF）
}

/*
代码测试及验证建议方案：
1. 基础功能测试：
   - 输入短名字（如 "Joe"）和长名字（如 "Pasolomeonasandro"），检查输出长度是否正确（3+16=19？需实际计算）
   - 观察 cleanup 前后的内存变化（可通过调试工具或 valgrind 检测）

2. 内存泄漏检测：
   - 方法1：使用 valgrind 运行程序：valgrind --leak-check=full ./names3
   - 预期：无 "definitely lost" 报错（cleanup 正常工作）
   - 测试：注释掉 cleanup 调用，重新运行，观察泄漏报告

3. 易错点验证：
   - 故意修改 getinfo 为 `pat->fname = temp;`（直接赋值指针），运行后观察 showinfo 输出（会出现乱码，因为 temp 已销毁）
   - 测试 malloc 失败场景（可手动让 malloc 返回 NULL，观察程序行为，实际需添加错误处理）

4. 边界输入测试：
   - 输入空字符串（直接回车），检查程序是否正常（malloc(1) 分配内存存 '\0'，长度计算为 0+0=0）
   - 输入超长字符串（80 个字符），检查 s_gets 是否正确截断，且 malloc 分配 81 字节（80+1）

5. 对比实验：
   - 和 names1.c（字符数组版）对比内存占用：用 sizeof(struct namect) 查看，指针版更小（仅存两个地址），但需动态分配
   - 体会 "指针赋值" vs "内容拷贝" 的区别：修改 getinfo 中的 strcpy 为指针赋值，观察错误
*/