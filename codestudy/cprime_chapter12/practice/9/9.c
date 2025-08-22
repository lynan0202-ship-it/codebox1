// ------------------------------  
// 题干：动态创建字符串数组，存储用户输入的单词，最终打印  
// 知识要点：  
//  1. 指针的指针（char**）：存储多个字符串的指针  
//  2. 动态内存嵌套分配（先分配指针数组，再分配每个字符串）  
//  3. 字符串处理（scanf读单词，strcpy复制，sizeof计算长度）  
// 总体逻辑：  
//  1. 询问单词数量n，分配n个char*的空间（char** words）  
//  2. 循环n次：读单词→分配该单词长度+1的空间→复制单词→存入words  
//  3. 打印所有单词→释放每个字符串→释放指针数组  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h> // 包含strcpy、strlen  

int main(void) {  
    int n;  
    printf("How many words do you wish to enter? ");  
    scanf("%d", &n);  

    // 分配：n个char*的空间（指针数组，每个元素指向一个字符串）  
    char **words = (char **)malloc(n * sizeof(char *));  
    if (words == NULL) {  
        printf("Memory allocation failed!\n");  
        exit(1);  
    }  

    // 逐个读取单词，动态分配空间并存储  
    for (int i = 0; i < n; i++) {  
        char temp[100]; // 临时存储输入的单词（假设单词长度<100）  
        printf("Enter word #%d: ", i + 1);  
        scanf("%s", temp); // 读入临时数组  

        // 分配：单词长度+1（存'\0'）  
        words[i] = (char *)malloc(strlen(temp) + 1);  
        if (words[i] == NULL) {  
            printf("Memory allocation failed for word %d!\n", i + 1);  
            exit(1);  
        }  
        strcpy(words[i], temp); // 复制临时数组内容到动态空间  
    }  

    // 打印所有单词  
    printf("Here are your words:\n");  
    for (int i = 0; i < n; i++) {  
        printf("%s\n", words[i]);  
    }  

    // 释放内存：先释放每个字符串，再释放指针数组  
    for (int i = 0; i < n; i++) {  
        free(words[i]);  
    }  
    free(words);  

    return 0;  
}  

// 测试验证方案：  
//  1. 怎么运行：编译后运行（如 `gcc 9.c -o 9 && ./9`），输入示例：  
//     → 输入 `5` → 依次输入 `I` `enjoyed` `doing` `this` `exercise`  
//  2. 预期结果：  
//     - 输出5行，每行一个单词，与输入一致  
//     - 内存正常释放（无泄漏，可通过valgrind检查）  
//  3. 检查点：  
//     - 指针数组是否正确分配？（words不为NULL）  
//     - 每个字符串是否独立分配？（修改temp不影响words里的内容）  
//     - 释放是否完整？（先释放每个字符串，再释放指针数组）  
// 易错点提醒：  
//  1. 指针数组分配错误：`char **words = malloc(n * sizeof(char));`（应为sizeof(char*)，否则空间不足）  
//  2. 忘记释放每个字符串：只free(words)，导致每个字符串的内存泄漏  
//  3. 临时数组溢出：输入单词超过temp的长度（如100），导致缓冲区溢出  
// 拓展思考：  
//  1. 如何处理输入单词长度不确定的情况？（动态读取，如用fgets+strchr处理换行）  
//  2. 若要支持重复单词去重，如何修改？（遍历数组，对比字符串，释放重复的）  
// 对比说明：  
//  指针的指针（char**） vs 二维数组（char words[][100]）：  
//  - 二维数组：每行长度固定，浪费空间，大小编译时确定  
//  - 指针的指针：每行长度动态分配，更节省空间，大小运行时确定  
//  内存分配顺序：  
//  - 先分配指针数组（存n个char*），再分配每个字符串（存具体内容）  
//  - 释放顺序相反：先释放每个字符串，再释放指针数组（避免悬垂指针）  