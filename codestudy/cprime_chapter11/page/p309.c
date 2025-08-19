
/* 
代码名称：SelectionSortStringPointers（选择排序实现字符串指针排序）
知识要点总结：
1. 选择排序算法：通过两层循环，外层确定当前位置，内层寻找剩余元素中字典序最小的字符串，交换指针位置 
2. 字符串指针数组：排序时仅交换指针（地址），而非字符串内容，效率远高于交换字符串本身 
3. strcmp函数：比较两个字符串的字典序，返回值规则： 
   - 若str1 < str2 → 返回负数；相等→0；str1 > str2→正数 
4. 输入处理技巧：s_gets函数处理fgets的换行符，及超长输入的缓冲区清理，保证字符串格式正确 
总体逻辑说明：
1. 输入阶段： 
   - 用s_gets读取用户输入，存入input二维数组（每行最多80字符） 
   - 同时让ptstr指针数组的元素指向input每行的首地址 
   - 当输入空行（首字符为'\0'）或达最大行数（LIM=20）时，终止输入 
2. 排序阶段： 
   - stsort函数采用选择排序： 
     - 外层循环（top）：依次处理第0到第num-2个位置（最后一个位置会自动有序） 
     - 内层循环（seek）：从top+1开始，找到剩余元素中字典序最小的字符串 
     - 交换指针：仅交换strings[top]和strings[seek]的地址，不改动原字符串内容 
3. 输出阶段：遍历排序后的ptstr数组，通过指针打印对应的字符串内容 
*/

#include <stdio.h>
#include <string.h>

#define SIZE 81   // 每个字符串最大长度（含'\0'，实际存储80字符）
#define LIM 20    // 最多读取20行字符串
#define HALT ""   // 空行作为输入终止标记

// 函数声明
void stsort(char *strings[], int num);  // 字符串指针数组排序函数
char *s_gets(char *st, int n);          // 安全读取字符串函数（处理换行和超长）

int main(void) {
    char input[LIM][SIZE];  // 存储实际输入的字符串（二维数组）
    char *ptstr[LIM];       // 指针数组：每个元素指向input中某行的首地址
    int ct = 0;             // 记录已输入的行数

    printf("请输入最多 %d 行字符串，按空行结束输入：\n", LIM);
    
    // 输入循环：
    // 1. 未达最大行数（ct < LIM）
    // 2. s_gets读取成功（非NULL，即未到文件末尾）
    // 3. 输入行非空（首字符不是'\0'）
    while (ct < LIM && s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0') {
        ptstr[ct] = input[ct];  // 让指针指向当前输入行的首地址
        ct++;
    }

    if (ct > 0) {  // 若有有效输入，才进行排序
        stsort(ptstr, ct);  // 对指针数组进行排序（排序的是指针，不是字符串本身！）
        
        printf("\n排序后的结果：\n");
        for (int k = 0; k < ct; k++) {
            puts(ptstr[k]);  // 通过指针打印对应的字符串
        }
    } else {
        printf("未输入有效内容，程序结束。\n");
    }

    return 0;
}

/* 
函数：stsort 
功能：对字符串指针数组进行**升序排序**（字典序），采用选择排序算法 
核心逻辑：
1. 外层循环（top）：控制当前要排序的位置，从第0个到第num-2个（最后一个位置会自动有序） 
2. 内层循环（seek）：从top+1开始，找到剩余元素中**字典序最小**的字符串 
3. 交换指针：若当前top位置的字符串比seek位置的大，则交换两者的指针（仅交换地址，效率极高） 
易错点对比： 
   - 若直接交换字符串内容（用strcpy），代码更复杂且效率低（需拷贝大量字符） 
   - 此处仅交换指针，原字符串在input中的位置不变，只是指针指向变化 
*/
void stsort(char *strings[], int num) {
    char *temp;  // 临时指针，用于交换地址
    int top, seek;

    // 外层循环：处理第top个位置（从0到num-2）
    for (top = 0; top < num - 1; top++) {  
        // 内层循环：从top+1开始，找剩余元素中字典序最小的
        for (seek = top + 1; seek < num; seek++) {  
            // strcmp规则：
            // strings[top] > strings[seek] → 返回正数 → 需要交换
            if (strcmp(strings[top], strings[seek]) > 0) {  
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
        }
    }
}

/* 
函数：s_gets 
功能：安全读取一行输入，解决两个问题： 
1. 处理fgets读取的换行符（将'\n'替换为'\0'，规范字符串格式） 
2. 处理超长输入（若输入超过n-1字符，清理输入缓冲区剩余字符，避免影响后续输入） 
*/
char *s_gets(char *st, int n) {
    char *ret_val = fgets(st, n, stdin);  // 读取一行，最多n-1字符，留'\0'
    if (ret_val != NULL) {  // 若读取成功（非EOF）
        int i = 0;
        // 寻找换行符或字符串结束符
        while (st[i] != '\n' && st[i] != '\0') {
            i++;
        }
        if (st[i] == '\n') {  // 找到换行符：替换为'\0'
            st[i] = '\0';
        } else {  // 未找到换行符（输入超长）：清理缓冲区
            while (getchar() != '\n') {  // 持续读取，直到读完换行符
                continue;
            }
        }
    }
    return ret_val;
}

/* 
代码测试及验证建议方案：
1. 基础功能测试： 
   - 输入3行："Banana"、"Apple"、"Cherry"，检查输出是否为Apple、Banana、Cherry（升序） 
   - 输入含空格的字符串："Hello World"、"Hi"，观察排序结果（逐字符比较，"Hello World" < "Hi"，因第1个字符'e' < 'i'） 

2. 边界情况测试： 
   - 输入恰好20行（LIM=20），检查是否全部读取并排序 
   - 输入空行（直接回车），验证是否终止输入 
   - 输入81个字符的超长字符串，检查s_gets是否截断并清理缓冲区，后续输入是否正常 

3. 特殊场景测试： 
   - 输入重复字符串（如"Test"×5），观察排序后顺序是否不变（选择排序此处稳定，相等时不交换） 
   - 输入大小写混合字符串（"apple"、"Apple"），验证strcmp大小写敏感（"Apple" < "apple"，因'A' ASCII 65 < 'a' 97） 

4. 调试观察： 
   - 在stsort中添加printf("%p %p\n", strings[top], strings[seek]); ，观察指针交换前后的地址变化 
   - 打印input和ptstr的地址，对比排序前后ptstr的指向，理解“排序指针而非字符串”的高效性 

5. 对比实验： 
   - 修改stsort为交换字符串内容（用strcpy(strings[top], strings[seek])），对比代码复杂度和运行效率 
   - 将stsort的strcmp判断改为<0，测试降序排序效果（如"Cherry"、"Banana"、"Apple" → 升序变降序） 
*/