/*
代码名称：book_catalog.c - 图书目录结构体示例程序
知识要点总结：
1. 结构体（struct）定义：组合字符数组、浮点数，构建自定义数据类型
2. 成员访问：通过 `.` 操作符访问结构体变量的成员（如 library.title）
3. 输入处理：自定义 s_gets 函数解决 fgets 残留换行符问题，含缓冲区清理逻辑
4. 格式化IO：printf 多格式输出，scanf 处理数值输入（注意取地址）

总体逻辑说明：
① 定义 struct book 模板，包含书名、作者、价格三个成员 
② 主函数声明该类型变量 library，用于存储单本图书数据 
③ 分三步输入：书名（s_gets处理换行）→ 作者（同）→ 价格（scanf） 
④ 多格式输出验证数据，演示结构体成员的访问方式 
⑤ s_gets 内部：fgets读取→替换换行符→清理残留字符，保障输入连续性
*/

#include <stdio.h>
#include <string.h>  // 提供 strchr 函数

#define MAXTITLE 40  // 书名最大长度（含'\0'，实际可输入39字符）
#define MAXAUTH  30  // 作者名最大长度（含'\0'，实际可输入29字符）

// 定义图书结构体：组合不同类型数据
struct book {
    char title[MAXTITLE];  // 书名（字符数组存储字符串）
    char author[MAXAUTH];  // 作者名（字符数组）
    float value;           // 价格（浮点数）
};

// 自定义输入函数：处理fgets的换行符问题
char *s_gets(char *str, int n) {
    char *ret_val;  // 存储fgets返回值，判断是否读取成功
    char *find;     // 查找换行符的指针

    ret_val = fgets(str, n, stdin);  // 读取一行，最多n-1字符（留'\0'）
    if (ret_val) {  // 读取成功时处理
        find = strchr(str, '\n');  // 找换行符位置
        if (find) {
            *find = '\0';  // 替换换行符为字符串结束符
        } else {
            // 未找到换行符，清理缓冲区剩余字符
            while (getchar() != '\n') continue;
        }
    }
    return ret_val;  // 返回读取结果（或NULL）
}

int main(void) {
    struct book library;  // 声明book类型变量，存储一本图书信息

    // 输入书名：调用s_gets，自动处理换行符
    printf("Please enter the book title.\n");
    s_gets(library.title, MAXTITLE);  // .操作符访问成员

    // 输入作者：同理，处理换行
    printf("Now enter the author.\n");
    s_gets(library.author, MAXAUTH);

    // 输入价格：scanf需要取地址（因为要修改value的值）
    printf("Now enter the value.\n");
    scanf("%f", &library.value);  // &取结构体成员的地址

    // 输出验证：多格式演示
    printf("\n=== Book Info ===\n");
    printf("Title:  %s\n", library.title);   // 直接输出字符串
    printf("Author: %s\n", library.author);  // 输出作者名
    printf("Price:  $%.2f\n", library.value); // 价格保留两位小数

    // 复合格式输出
    printf("\nCombined: %s by %s costs $%.2f\n", 
           library.title, 
           library.author, 
           library.value);

    printf("Done.\n");
    return 0;
}

/*
代码测试及验证建议方案：
1. 正常流程测试：
   - 输入：书名"Python Basics"、作者"John Doe"、价格49.99 → 检查输出是否完整匹配
   - 观察价格的小数位：输入39 → 输出是否为39.00？（%.2f会自动补零）

2. 边界测试：
   - 书名输入40个字符（如"a"×39）→ 检查是否截断为39字符+'\0'，后续作者输入是否正常
   - 作者名输入超长（如"a"×30）→ 验证截断和缓冲区清理效果

3. 换行符测试：
   - 书名输入后直接按回车（空字符串）→ 检查是否能接收空值，作者输入是否正常
   - 对比：若直接用fgets(library.title, MAXTITLE, stdin) → 输出会包含换行符（如书名后有换行，导致格式混乱）

4. 易错点验证：
   - 故意在价格处输入字母（如"abc"）→ 观察程序行为（本示例未处理输入错误，实际需添加错误处理）
   - 测试s_gets的返回值：若输入EOF（Ctrl+Z/Ctrl+D），检查程序是否正常退出

5. 扩展验证：
   - 修改结构体成员值：library.value = 99.99; 再输出，看是否生效
   - 尝试用指针访问成员：struct book *p = &library; printf("%s", p->title); 验证->的用法
*/