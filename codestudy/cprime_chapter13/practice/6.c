// ------------------------------
// 题干：6. 重写程序清单13.2中的程序（假设是存储客户信息），不使用命令行参数，而是提示用户输入所需信息。
// 知识要点：
//  1. 结构体定义与使用
//  2. 标准输入（scanf读取用户数据）
//  3. 二进制文件写入（fwrite）
// 总体逻辑：
//  1. 定义客户结构体 → 2. 提示输入信息 → 3. 打开文件写入 → 4. 关闭文件
#include <stdio.h>

// 客户结构体
typedef struct {
    char name[50]; // 姓名（无空格）
    int account;   // 账户ID
    float balance; // 余额
} Client;

int main() {
    Client c; // 定义客户变量
    
    printf("请输入客户姓名：");
    scanf("%s", c.name); // 姓名不含空格，如需空格用fgets
    printf("请输入账户ID：");
    scanf("%d", &c.account);
    printf("请输入账户余额：");
    scanf("%f", &c.balance);
    
    FILE *fp = fopen("clients.dat", "ab"); // 二进制追加模式
    if (fp == NULL) {
        printf("无法打开文件 clients.dat\n");
        return 1;
    }
    
    fwrite(&c, sizeof(Client), 1, fp); // 写入1个结构体
    fclose(fp);
    
    printf("客户信息已保存！\n");
    return 0;
}

// 测试验证方案：
//  1. 运行：输入姓名ZhangSan、账户1001、余额5000.5
//  2. 预期：生成clients.dat文件，可通过二进制工具（如hexdump）查看内容
//  3. 检查：结构体大小是否正确，数据是否匹配输入
// 易错点提醒：
//  1. scanf读字符串时，name是数组，无需加&（写&c.name会报错）
//  2. 文件打开模式错误（用"w"会清空文件，应选"ab"追加）
//  3. fwrite参数顺序错误（sizeof(Client)是元素大小，1是数量）
// 拓展思考：
//  1. 如何支持姓名含空格？（改用fgets(c.name, 50, stdin)并处理换行）
//  2. 如何读取文件中的客户信息？（编写读取程序，用fread逐个读结构体）
// 对比说明：
//  命令行参数是"传值式"调用，本方案是"运行时输入"，前者适合自动化，后者适合手动录入。