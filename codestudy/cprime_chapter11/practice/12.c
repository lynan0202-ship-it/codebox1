// ------------------------------
// 题干：编写一个程序，读入10个字符串或者读到EOF时停止。该程序为用户提供一个有5个选项的菜单：打印源字符串列表、以ASCII中的顺序打印字符串、按长度递增顺序打印字符串、按字符串中第1个单词的长度打印字符串、退出。菜单可以循环显示，除非用户选择退出选项。当然，该程序要能真正完成菜单中各选项的功能。
// 知识要点：
//  1. 二维数组存储字符串：用 `char original[MAX_STRINGS][MAX_LEN]` 保存输入的字符串，固定长度方便处理。
//  2. qsort 库函数使用：通过自定义比较函数，实现不同规则的排序（ASCII序、长度序、单词长度序）。
//  3. 菜单循环控制：用 `do-while` 循环实现菜单重复显示，`switch-case` 处理不同选项。
//  4. 字符串处理：`fgets` 读整行输入，`strchr` 处理换行符；`isspace` 判断空白符，提取第一个单词。
//  5. 指针数组应用：排序时用指针数组 `temp` 指向原字符串，避免修改原始输入顺序。
// 总体逻辑：
//  1. 读入阶段：循环用 `fgets` 读入最多10行字符串，处理换行符，记录实际读入数量 `n`。
//  2. 菜单阶段：
//     - 显示5个选项，用 `scanf` 读取用户选择，清理输入缓冲区避免干扰。
//     - 根据选项调用对应功能：  
//       - 选项1：直接遍历原数组，打印输入顺序的字符串。  
//       - 选项2~4：先将原数组的指针复制到 `temp`，再用 `qsort` 配合不同比较函数排序，最后打印排序结果。  
//       - 选项5：退出循环。  
//  3. 辅助函数：实现比较函数（ASCII序、长度、首单词长度）和首单词长度计算函数。

#include <stdio.h>
#include <string.h>   // 提供 strcmp、strchr 等函数
#include <ctype.h>    // 提供 isspace 函数
#include <stdlib.h>   // 提供 qsort 函数

#define MAX_STRINGS 10  // 最多读10个字符串
#define MAX_LEN    100  // 每个字符串最大长度

// 函数声明（提前告诉编译器函数存在）
void printOriginal(const char original[][MAX_LEN], int n);
void printAsciiSort(const char original[][MAX_LEN], int n);
void printLengthSort(const char original[][MAX_LEN], int n);
void printFirstWordSort(const char original[][MAX_LEN], int n);
int  getFirstWordLen(const char *s);


int main() {
    char original[MAX_STRINGS][MAX_LEN] = {0};  // 存储输入的字符串，初始化为全0
    int n = 0;  // 实际读入的字符串数量
    int choice = 0;  // 菜单选项

    // ---------- 1. 读入字符串 ----------
    printf("请输入字符串（最多10个，按 Ctrl+D 结束输入）：\n");
    while (n < MAX_STRINGS) {  // 没读够10个，且没到文件末尾
        // fgets 读一行，存入 original[n]，最多读 MAX_LEN-1 个字符（留位置存 '\0'）
        if (fgets(original[n], MAX_LEN, stdin) == NULL) {
            break;  // 读到 EOF，结束读入
        }
        // 处理换行符：把末尾的 '\n' 换成 '\0'，否则字符串会包含换行
        char *newline = strchr(original[n], '\n');
        if (newline != NULL) {
            *newline = '\0';
        }
        n++;  // 计数+1
    }

    // ---------- 2. 菜单循环 ----------
    do {
        // 显示菜单
        printf("\n========== 菜单 ==========\n");
        printf("1. 打印原字符串列表\n");
        printf("2. 按 ASCII 顺序打印（字典序）\n");
        printf("3. 按字符串长度递增打印\n");
        printf("4. 按第1个单词的长度打印\n");
        printf("5. 退出程序\n");
        printf("请输入选项（1-5）：");
        
        // 读用户选择，并用 getchar 清理换行符（否则下次读入会出错）
        scanf("%d", &choice);
        while (getchar() != '\n');  // 吃掉输入缓冲区里的换行符

        // 根据选项执行功能
        switch (choice) {
            case 1:
                printOriginal(original, n);
                break;
            case 2:
                printAsciiSort(original, n);
                break;
            case 3:
                printLengthSort(original, n);
                break;
            case 4:
                printFirstWordSort(original, n);
                break;
            case 5:
                printf("程序已退出～\n");
                break;
            default:
                printf("输入无效！请重新选择（1-5）\n");
        }
    } while (choice != 5);  // 选5才退出

    return 0;
}


// ---------- 功能函数实现 ----------

// 打印原始顺序的字符串
void printOriginal(const char original[][MAX_LEN], int n) {
    printf("\n=== 原字符串列表 ===\n");
    for (int i = 0; i < n; i++) {
        printf("第 %d 个：%s\n", i+1, original[i]);
    }
}

// 按 ASCII 顺序（字典序）排序并打印
void printAsciiSort(const char original[][MAX_LEN], int n) {
    // 用指针数组 temp 指向 original 的每一行，排序时不修改原数组
    char *temp[MAX_STRINGS];
    for (int i = 0; i < n; i++) {
        temp[i] = original[i];  // 存指针，而非复制字符串
    }

    // qsort 参数：数组名、元素个数、每个元素大小、比较函数
    // 比较函数直接用 strcmp（注意类型转换，因为 qsort 要求 void* 入参）
    qsort(temp, n, sizeof(char*), (int (*)(const void*, const void*))strcmp);

    // 打印排序结果
    printf("\n=== 按 ASCII 顺序排序 ===\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", temp[i]);
    }
}

// 按字符串长度递增排序并打印
void printLengthSort(const char original[][MAX_LEN], int n) {
    char *temp[MAX_STRINGS];
    for (int i = 0; i < n; i++) {
        temp[i] = original[i];
    }

    // 自定义比较函数：比较两个字符串的长度
    qsort(temp, n, sizeof(char*), cmpByLength);

    printf("\n=== 按长度递增排序 ===\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", temp[i]);
    }
}

// 比较字符串长度的函数（供 qsort 使用）
int cmpByLength(const void *a, const void *b) {
    // a 和 b 是指针数组里的元素（即 char* 类型的指针），所以先转成 char** 再解引用
    char *strA = *(char**)a;
    char *strB = *(char**)b;
    int lenA = strlen(strA);
    int lenB = strlen(strB);
    return lenA - lenB;  // 升序：短的在前，长的在后
}

// 按第一个单词的长度排序并打印
void printFirstWordSort(const char original[][MAX_LEN], int n) {
    char *temp[MAX_STRINGS];
    for (int i = 0; i < n; i++) {
        temp[i] = original[i];
    }

    // 自定义比较函数：比较第一个单词的长度
    qsort(temp, n, sizeof(char*), cmpByFirstWordLen);

    printf("\n=== 按第1个单词长度排序 ===\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", temp[i]);
    }
}

// 计算字符串中第一个单词的长度（从开头到第一个空白符）
int getFirstWordLen(const char *s) {
    int len = 0;
    while (*s != '\0' && !isspace(*s)) {  // 不是结束符，也不是空白符（空格、制表符等）
        len++;
        s++;
    }
    return len;
}

// 比较第一个单词长度的函数（供 qsort 使用）
int cmpByFirstWordLen(const void *a, const void *b) {
    char *strA = *(char**)a;
    char *strB = *(char**)b;
    int lenA = getFirstWordLen(strA);
    int lenB = getFirstWordLen(strB);
    return lenA - lenB;  // 升序：单词短的在前
}


// ------------------------------
// 测试验证方案：
//  1. 怎么运行：  
//     - 编译：`gcc 11.c -o 11`（需确保编译器支持标准库），然后运行 `./11`。  
//     - 输入示例（手动输入3行，再按 Ctrl+D 结束）：  
//       hello world  
//       apple  
//       banana pie  
//  2. 预期结果：  
//     - 选项1：按输入顺序打印3行：`hello world`、`apple`、`banana pie`。  
//     - 选项2（ASCII序）：按字典序，`apple`（a开头）→ `banana pie`（b开头）→ `hello world`（h开头）。  
//     - 选项3（长度序）：`apple`（5字符）→ `banana pie`（10字符）→ `hello world`（11字符）。  
//     - 选项4（首单词长度）：`apple`（5）和 `hello`（5）长度相同，所以 `apple`、`hello world`、`banana pie`（banana是6）。  
//  3. 检查点：  
//     - 原列表是否和输入顺序一致。  
//     - 各排序规则是否生效（ASCII看首字符，长度看字符串总长度，首单词看第一个空格前的字符数）。  


// ------------------------------
// 易错点提醒：  
//  1. qsort 比较函数的类型转换：  
//     - 忘记把 `void*` 转成 `char**` 再解引用，会导致编译错误（如 `error: invalid use of void expression`）。  
//  2. 换行符处理：  
//     - 如果没把 `fgets` 读入的 `\n` 换成 `\0`，字符串末尾会有换行，影响显示和比较（比如长度计算会包含换行）。  
//  3. 输入缓冲区残留：  
//     - `scanf` 后如果不清理换行符，下次读入会直接取到换行，导致菜单选项判断错误。  
//  4. 空字符串处理：  
//     - 如果输入空行（只有换行符），会被存为空白字符串，此时首单词长度为0，排序时会排在最前面。  


// ------------------------------
// 拓展思考：  
//  1. 动态扩展存储：  
//     - 不用固定10个字符串，用 `malloc`+`realloc` 动态分配内存，直到读到 EOF，更灵活。  
//  2. 降序排序：  
//     - 修改比较函数的返回值（如 `lenB - lenA`），增加“降序”选项，让排序更灵活。  
//  3. 复杂单词划分：  
//     - 现在只处理空白符，若要支持连字符（如 `hello-world` 算一个单词），可修改 `isspace` 为自定义判断（比如排除 `-`）。  
//  4. 对比排序算法：  
//     - 把 `qsort` 换成自己实现的冒泡排序，理解排序逻辑（虽然效率低，但更直观）。  
//  5. 多条件排序：  
//     - 比如长度相同时按ASCII序排序，可在比较函数里增加次级判断（如长度相等时，调用 `strcmp` 比较）。  


// ------------------------------
// 对比总结（值传递 vs 指针传递）：  
//  - 本题中，`original` 是二维数组，传递给函数时，实际是**指针传递**（数组名退化为指针），函数内修改 `original` 的内容会影响主函数（但本题里排序用了指针数组 `temp`，避免了修改原数组）。  
//  - 如果用**值传递**（比如传单个字符串的拷贝），函数内的修改不会影响主函数。  
//  - 区别核心：指针传递传的是**地址**，函数可直接操作原内存；值传递传的是**拷贝**，函数操作的是副本。  
// （本题中利用指针数组的指针传递特性，实现了“排序临时数组，保留原数组”的效果。）