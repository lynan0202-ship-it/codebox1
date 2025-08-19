/* 
代码名称：StringSortByPointer（字符串指针排序示例）
知识要点总结：
1. 指针数组妙用：排序指针而非字符串本身，避免大量字符串拷贝，效率更高 
2. 选择排序算法：通过两层循环找到“最小”字符串，交换指针实现排序 
3. strcmp函数：比较字符串字典序（返回<0/0/>0，区分大小写） 
4. 自定义输入：s_gets处理fgets的换行符，清理输入缓冲区残留字符 
5. 输入控制：空行（首字符为'\0'）或达最大行数时终止输入 
总体逻辑说明：
1. 输入阶段：用s_gets读取每行到input数组，同时让ptstr指针数组指向各字符串首地址 
2. 排序阶段：stsort用选择排序，通过strcmp比较指针指向的字符串，交换指针位置（不改动原字符串） 
3. 输出阶段：遍历ptstr数组，打印排序后指针指向的字符串 
*/

#include <stdio.h>
#include <string.h>
#define SIZE 81      // 每个字符串最大长度（含'\0'，实际存80字符）
#define LIM 20       // 最多读取20行 
#define HALT ""      // 空行作为输入终止标记 

// 函数声明：排序函数 + 安全读字符串函数
void stsort(char *strings[], int num);  
char *s_gets(char *st, int n);          

int main(void) {
    char input[LIM][SIZE];  // 存储实际输入的字符串（每行SIZE字节）
    char *ptstr[LIM];       // 指针数组：每个元素指向input中某行的首地址 
    int ct = 0;             // 记录已输入的行数 
    int k;                  // 输出循环变量 

    printf("Input up to %d lines, and I will sort them.\n", LIM);
    printf("To stop, press the Enter key at a line's start.\n");

    // 读取输入的循环条件：
    // 1. 未达最大行数（ct < LIM） 
    // 2. s_gets读取成功（非EOF） 
    // 3. 输入行非空（首字符不是'\0'） 
    while (ct < LIM && s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0') {
        ptstr[ct] = input[ct];  // 让指针指向当前输入的字符串首地址 
        ct++;
    }

    stsort(ptstr, ct);  // 对指针数组排序（排序的是指针，不是字符串本身！）

    printf("\nHere's the sorted list:\n");
    for (k = 0; k < ct; k++) {
        puts(ptstr[k]);  // 输出指针指向的字符串内容 
    }

    return 0;
}

/* 
 * 函数：stsort 
 * 功能：用选择排序对字符串指针数组升序排序 
 * 核心逻辑：
 * - 外层循环top：确定第top个位置的“最小”字符串 
 * - 内层循环seek：从top+1开始找真正的最小字符串 
 * - 交换指针：仅交换指针地址，不移动字符串内容（效率高） 
 * 对比易错点：如果直接交换字符串内容（用strcpy），代码更复杂且效率低 
 */
void stsort(char *strings[], int num) {
    char *temp;  // 临时指针，用于交换地址 
    int top, seek;

    // 外层循环：处理前num-1个位置（最后一个位置会自动有序）
    for (top = 0; top < num - 1; top++) {  
        // 内层循环：找top之后的最小字符串（字典序）
        for (seek = top + 1; seek < num; seek++) {  
            // strcmp规则：
            // strings[top] > strings[seek] → 返回>0 → 需要交换 
            if (strcmp(strings[top], strings[seek]) > 0) {  
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
        }
    }
}

/* 
 * 函数：s_gets 
 * 功能：安全读取一行，处理换行符和超长输入 
 * 解决的问题：
 * 1. fgets会把换行符'\n'读入，需替换为'\0'规范字符串 
 * 2. 若输入超长（超过n-1字符），清理缓冲区剩余字符，避免影响后续输入 
 */
char *s_gets(char *st, int n) {
    char *ret_val;  // 存储fgets的返回值（成功则为st，失败为NULL）
    int i = 0;

    ret_val = fgets(st, n, stdin);  // 读取一行，最多n-1字符，留'\0' 
    if (ret_val) {  // 若读取成功（非EOF）
        // 寻找换行符或字符串结束符 
        while (st[i] != '\n' && st[i] != '\0') {
            i++;
        }
        if (st[i] == '\n') {  // 找到换行符：替换为'\0' 
            st[i] = '\0';
        } else {  // 没找到换行符（输入超长）：清理缓冲区 
            while (getchar() != '\n') {  // 不断读，直到读完换行符 
                continue;
            }
        }
    }
    return ret_val;
}

/* 
代码测试及验证建议方案：
1. 正常输入测试：
   - 输入5行不同字符串（如Apple、Banana、Cherry、Date、Egg），检查输出是否按字典序排列。 
   - 输入含大小写的字符串（如Apple、apple），观察strcmp的大小写敏感特性（A的ASCII比a小，所以Apple排前面）。 

2. 边界测试：
   - 输入恰好20行（LIM=20），检查是否完整读取和排序。 
   - 输入空行（直接回车），验证是否终止输入。 
   - 输入超长字符串（如81个字符），检查s_gets是否清理缓冲区，后续输入是否正常。 

3. 特殊场景测试：
   - 输入所有行相同的字符串，观察排序后相对顺序是否不变（选择排序在此处是稳定的，因为相等时不交换）。 
   - 输入含空格的字符串（如"Hello World"、"Hi"），检查是否按整个字符串的字典序排序（空格的ASCII比字母小，所以" Hi"会排在"Hello"前面）。 

4. 调试观察：
   - 在stsort中添加printf，打印每次交换后的ptstr数组，观察指针地址变化（仅交换指针，input数组内容不变）。 
   - 打印input和ptstr的地址，对比排序前后ptstr的指向，理解“排序指针而非字符串”的高效性。 

5. 对比实验：
   - 修改stsort为交换字符串内容（用strcpy），对比代码复杂度和运行效率（体会指针排序的优势）。 
   - 替换strcmp为自定义忽略大小写的比较函数，观察排序结果变化（理解strcmp的比较规则）。 
*/