
// ------------------------------
// 题干：9. 编写一个函数，把字符串中的内容用其反序字符串代替。在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。  
// 知识要点：  
//  1. 字符串反转逻辑：双指针法（首尾交换，向中间靠拢）  
//  2. 指针操作：遍历字符串找末尾、移动指针交换字符  
//  3. 输入处理：清理 `fgets` 读取的换行符，避免影响结果  
// 总体逻辑：  
//  1. 反转函数：  
//     - 处理空字符串/空指针，直接返回；  
//     - 定位字符串首尾指针；  
//     - 循环交换首尾字符，直到指针相遇。  
//  2. 主函数：  
//     - 循环读取用户输入（空字符串退出）；  
//     - 调用反转函数，输出结果。  

#include <stdio.h>

// 反转字符串内容（直接修改原字符串）
void reverse_string(char *str) {
    if (str == NULL || *str == '\0') { // 空指针或空字符串，无需处理
        return;
    }

    char *start = str; // 头指针，指向字符串开头
    char *end = str;   // 尾指针，先找末尾

    // 步骤1：定位尾指针到最后一个有效字符（跳过'\0'）
    while (*end != '\0') {
        end++;
    }
    end--; // 现在 end 指向最后一个字符（如 "hello" 的 'o'）

    // 步骤2：双指针交换，直到头指针超过尾指针
    while (start < end) {
        // 交换 start 和 end 指向的字符
        char temp = *start;
        *start = *end;
        *end = temp;

        start++; // 头指针后移
        end--;   // 尾指针前移
    }
}

int main(void) {
    char input_str[100]; // 存储用户输入的字符串

    printf("=== 字符串反转测试 ===\n");
    printf("输入空行（直接回车）可退出程序。\n\n");

    while (1) {
        // 读取一行输入（最多99字符，留1位给'\0'）
        printf("请输入字符串：");
        if (fgets(input_str, 100, stdin) == NULL) {
            break; // 遇到 EOF（如 Ctrl+D/Ctrl+Z），退出循环
        }

        // 清理换行符（fgets 会把换行符也读入，需要替换为 '\0'）
        char *newline = input_str;
        while (*newline != '\n' && *newline != '\0') {
            newline++;
        }
        *newline = '\0';

        if (input_str[0] == '\0') { // 空字符串，退出循环
            break;
        }

        // 调用反转函数，修改原字符串
        reverse_string(input_str);

        // 输出结果
        printf("反转后的字符串：%s\n\n", input_str);
    }

    return 0;
}


// ------------------------------
// 测试验证方案：  
//  1. 怎么运行：  
//     • 编译：`gcc 9.c -o 9`  
//     • 执行：`./9`（Windows 下为 `9.exe`），输入测试用例：  
//       - 案例1：输入 `hello` → 预期输出 `olleh`；  
//       - 案例2：输入 `12345` → 预期输出 `54321`；  
//       - 案例3：输入 `a` → 预期输出 `a`（单个字符无变化）；  
//       - 案例4：输入空行（直接回车）→ 程序退出。  
//  2. 预期结果：  
//     输入字符串被正确反转，空输入触发退出。  
//  3. 检查点：  
//     • 换行符是否被清理（如输入 `abc\n` 应处理为 `abc` 再反转）；  
//     • 空字符串/单个字符是否正常处理；  
//     • 指针交换逻辑是否正确（首尾字符是否真的交换）。  


// ------------------------------
// 易错点提醒：  
//  1. **忘记清理换行符**：`fgets` 会读取换行符，若不处理，反转后字符串会包含 `\n`，导致输出换行异常。  
//  2. **空指针/空字符串未判断**：若传入 `NULL` 或空字符串，`reverse_string` 直接返回，避免崩溃。  
//  3. **指针交换逻辑错误**：交换时需用临时变量 `temp`，否则会覆盖数据（如直接 `*start = *end; *end = *start;` 会导致两个位置都变成 `*end` 的值）。  


// ------------------------------
// 拓展思考：  
//  1. **处理常量字符串**：  
//     若输入是 `const char *`（如 `"hello"`），无法直接修改，可先复制到数组再反转：  
//     ```c
//     const char *src = "hello";
//     char buf[100];
//     strcpy(buf, src);
//     reverse_string(buf); // 反转 buf
//     ```  
//  2. **支持 Unicode 字符串**：  
//     对于多字节字符（如中文），需用 `wchar_t` 和宽字符函数（如 `wcslen`、`fwprintf`），反转时按“字符”而非“字节”处理。  
//  3. **递归实现反转**：  
//     递归交换首尾字符，缩小问题规模：  
//     ```c
//     void reverse_recursive(char *start, char *end) {
//         if (start >= end) return;
//         char temp = *start;
//         *start = *end;
//         *end = temp;
//         reverse_recursive(start+1, end-1);
//     }
//     // 调用：reverse_recursive(str, str + strlen(str) - 1);
//     ```  
