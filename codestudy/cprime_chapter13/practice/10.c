// ------------------------------
// 题干：10. 编写一个程序，以循环方式获得文件名。通过一个循环，提示用户输入一个文件位置。然后该程序打印从该位置开始到下一个换行符之前的内容。用户输入负数或非数字字符可以结束循环。
// 知识要点：
//  1. 用户输入处理（fgets读文件名，scanf读位置，处理输入错误）
//  2. 文件定位（fseek设置读取位置，SEEK_SET模式）
//  3. 循环控制（输入负数/非数字退出，清理输入缓冲区）
// 总体逻辑：
//  1. 循环：
//     a. 读文件名→读位置→检查位置合法性（负数/非数字则退出）
//     b. 打开文件→定位到指定位置→读取到换行/EOF→输出内容
//     c. 关闭文件，清理输入缓冲区（避免残留字符干扰下次输入）
#include <stdio.h>
#include <string.h> // 用于strcspn清理换行符

#define MAX_FILENAME 100 // 文件名最大长度

int main() {
    char filename[MAX_FILENAME];
    int pos;

    while (1) { // 无限循环，直到退出条件
        // 步骤1：读文件名
        printf("请输入文件名（输入q退出）：");
        if (fgets(filename, MAX_FILENAME, stdin) == NULL) break; // EOF退出
        // 清理fgets读取的换行符
        filename[strcspn(filename, "\n")] = '\0';
        if (strcmp(filename, "q") == 0) break; // 输入q退出

        // 步骤2：读位置
        printf("请输入文件位置（负数/非数字结束）：");
        if (scanf("%d", &pos) != 1) { // 非数字输入
            while (getchar() != '\n'); // 清理输入缓冲区
            break;
        }
        if (pos < 0) break; // 负数退出

        // 步骤3：打开文件
        FILE *fp = fopen(filename, "r");
        if (fp == NULL) {
            perror(filename); // 打印打开错误
            while (getchar() != '\n'); // 清理缓冲区
            continue;
        }

        // 步骤4：定位到指定位置
        if (fseek(fp, pos, SEEK_SET) != 0) {
            printf("定位失败！位置%d可能超出文件范围。\n", pos);
            fclose(fp);
            while (getchar() != '\n');
            continue;
        }

        // 步骤5：读取到换行/EOF并输出
        printf("位置%d开始的内容：\n", pos);
        int ch;
        while ((ch = fgetc(fp)) != EOF && ch != '\n') {
            putchar(ch); // 逐字符输出
        }
        putchar('\n'); // 换行分隔结果

        // 步骤6：关闭文件+清理缓冲区
        fclose(fp);
        while (getchar() != '\n');
    }

    return 0;
}

// 测试验证方案：
//  1. 准备测试文件test.txt：
//     0123456789\nabcdefghij\n!@#$%^&*()
//  2. 运行测试：
//     - 输入文件名test.txt，位置5→输出"56789"（第一行第5-9字符）
//     - 输入位置15→输出"bcdefghij"（第二行第1-9字符，假设第一行占11字节：10字符+换行）
//     - 输入-1或abc→退出循环
//  3. 检查点：
//     - 定位是否准确（可用ftell验证，如fseek后ftell(fp)应等于pos）
//     - 输入错误时是否正确退出，缓冲区是否清理干净
// 易错点提醒：
//  1. 忘记清理输入缓冲区（如scanf后残留的换行符，导致下次fgets读空行）
//  2. fseek失败未处理（如位置超过文件大小，仍尝试读取）
//  3. 文件名包含换行符（fgets未清理，导致打开错误文件名）
// 拓展思考：
//  1. 如何支持“从文件末尾倒数”？可添加选项（如输入负数表示从末尾开始，fseek(fp, pos, SEEK_END)）
//  2. 大文件定位效率？fseek是直接跳转，效率不受文件大小影响（基于文件系统实现）
// ------------------------------