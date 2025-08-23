/*
代码名称：manybook.c（图书目录管理程序）
知识要点总结：
1. 结构数组：用 `struct book` 定义图书结构，通过 `struct book library[MAXBKS]` 创建结构数组存储多本书信息
2. 自定义输入：编写 `s_gets` 处理 `fgets` 换行符问题，避免缓冲区残留影响后续输入
3. 结构体操作：通过 `.` 访问结构数组成员（如 `library[count].title`）
4. 流程控制：循环接收用户输入，判断终止条件（空行/数量上限），最后遍历输出
5. 缓冲区处理：用 `getchar()` 清理 `scanf` 残留的换行符

代码总体逻辑说明：
① 定义图书结构和常量 → ② 主函数初始化结构数组和计数器 → ③ 循环接收书名（空行终止）、作者、价格 → ④ 清理输入缓冲区 → ⑤ 遍历输出已存图书信息 → ⑥ 自定义 `s_gets` 处理字符串输入（替换换行符/清理多余字符）
*/

#include <stdio.h>
#include <string.h>

// 自定义函数声明：安全读取字符串（处理换行符）
char * s_gets(char * st, int n);

#define MAXTITLE 40  // 书名最大长度
#define MAXAUTL  40  // 作者名最大长度
#define MAXBKS  100  // 最大图书数量

// 定义图书结构体：包含标题、作者、价格
struct book {
    char title[MAXTITLE];
    char author[MAXAUTL];
    float value;
};

int main(void) {
    struct book library[MAXBKS];  // 结构数组：存储多本图书
    int count = 0;                // 已输入图书数量
    int index;                    // 遍历数组用的索引

    // 提示输入规则：空行（开头按回车）终止输入
    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");

    // 循环条件：① 未达最大数量 ② 书名非空（s_gets返回有效 & title首字符非空）
    while (count < MAXBKS && 
           s_gets(library[count].title, MAXTITLE) != NULL && 
           library[count].title[0] != '\0') 
    {
        // 步骤1：输入作者
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);

        // 步骤2：输入价格（注意：scanf不会读取换行符，后续需清理）
        printf("Now enter the value.\n");
        scanf("%f", &library[count].value);

        // 清理缓冲区残留的换行符（否则会影响下一次s_gets读取）
        while (getchar() != '\n') 
            continue;

        // 若还能输入，提示继续（避免最后一次循环多余提示）
        if (count < MAXBKS - 1) 
            printf("Enter the next title.\n");
        
        count++;  // 计数加1
    }

    // 输出结果：区分有书/没书的情况
    if (count > 0) {
        printf("\nHere is the list of your books:\n");
        for (index = 0; index < count; index++) {
            // 格式化输出：书名 + 作者 + 价格（保留2位小数）
            printf("%s by %s: $%.2f\n", 
                   library[index].title, 
                   library[index].author, 
                   library[index].value);
        }
    } else {
        printf("No books? Too bad.\n");
    }

    return 0;
}

/* 
自定义函数：安全读取字符串（解决fgets的两个问题）
① 若输入含换行符，替换为'\0'（避免字符串带换行）
② 若输入超长（没换行符），清理缓冲区剩余字符（避免影响后续输入）
*/
char * s_gets(char * st, int n) {
    char * ret_val;  // 存储fgets返回值（判断是否读取成功）
    char * find;     // 查找换行符的指针

    // 用fgets读取：最多读n-1个字符（留1位存'\0'），从标准输入读
    ret_val = fgets(st, n, stdin);
    if (ret_val != NULL) {  // 读取成功才处理
        // 查找换行符位置
        find = strchr(st, '\n');
        if (find != NULL) {  // 找到换行符 → 替换为字符串结束符
            *find = '\0';
        } else {
            // 没找到换行符（输入超长）→ 清理缓冲区剩余字符
            while (getchar() != '\n') 
                continue;
        }
    }
    return ret_val;  // 返回读取结果（NULL表示读取失败）
}

/*
代码测试及验证建议方案：
1. 正常流程测试：
   - 输入3本图书，包含长标题（接近40字符）、空作者、小数价格，检查输出格式是否正确。
   - 示例输入：
     My Life as a Buggie↵
     Mack Zacks↵
     12.95↵
     Thought and Unthought Rethought↵
     Kindra Schlameyer↵
     43.50↵
     （空行终止）
   - 检查输出是否按 "书名 by 作者: $XX.XX" 显示。

2. 边界测试：
   - 输入100本图书（达MAXBKS），检查是否能正常存储和输出，无崩溃。
   - 输入空行（直接回车），验证是否终止输入，且之前内容正常输出。
   - 输入标题刚好40字符（如39个字母+1个空格），检查s_gets是否正确处理（无换行符残留）。

3. 错误测试：
   - 价格输入非数字（如abc），观察程序行为（本程序未处理，会导致价格为0，可借此理解scanf的错误处理）。
   - 故意在价格后输入多个换行符，检查下一次书名输入是否正常（验证缓冲区清理是否有效）。

4. 编译器兼容测试（针对Borland C）：
   - 若用Borland C/C++编译报错"floating point format not linked"，添加：
     #include <math.h>
     double dummy = sin(0.0); 
   - 重新编译，检查错误是否消失。

5. 对比测试：
   - 注释掉`while (getchar() != '\n')`，观察输入作者时是否被之前的换行符干扰（理解缓冲区残留的影响）。
*/