// ------------------------------  
// 题干：假设文件的开始处有如下声明：  
// static int plink;  
// int find(const int arr[], int value, int n);  
// a. 以上声明表明了程序员的什么意图？  
// b. 用const int value和const int n替换参数，是否加强主调程序保护？  
// 知识要点：  
//  1. static全局变量：内部链接，**仅限本文件访问**（隐藏变量）  
//  2. const修饰指针参数（const int arr[]）：保护**数组内容**（因arr是指针传递，传地址）  
//  3. 值传递（value、n）：形参是实参的拷贝，函数内修改不影响实参；const修饰是**语义保护**（防止函数内误改）  
//  4. 数组退化为指针：`int arr[]`等价于`int *arr`，是**指针传递**（传地址）  
// 总体逻辑：  
//  1. 解释static plink的意图（本文件私有）  
//  2. 解释const arr[]的意图（保护数组内容）  
//  3. 分析value和n的const修饰效果（语义约束，不改变值传递本质）  
#include <stdio.h>  

static int plink; // a：static让plink仅本文件可见（内部链接）  

// find函数：  
// - const int arr[] → 等价于`const int *arr`，指针传递，函数内不能改数组内容  
// - int value → 值传递，形参是实参的拷贝  
// - int n → 值传递，形参是实参的拷贝  
int find(const int arr[], int value, int n) {  
    // 以下操作的合法性：  
    // arr[0] = 10; // 编译报错！const保护数组内容不能改  
    // value = 20;  // 允许（修改形参，不影响实参）  
    // n = 100;     // 允许（同理）  

    for (int i=0; i<n; i++) {  
        if (arr[i] == value) return i;  
    }  
    return -1;  
}  

int main(void) {  
    // a部分解释：  
    printf("a. static int plink：程序员想让plink仅限当前文件访问，避免跨文件命名冲突。\n");  

    // b部分分析：  
    int arr[] = {1,2,3,4};  
    int val = 3, len = 4;  
    printf("b. 原参数value/n是int：\n");  
    printf("   - 它们是值传递，函数内修改value/n不会影响主调的val/len（因为是拷贝）。\n");  
    printf("   - 加const修饰：不是“加强主调保护”（本来就保护），而是告诉编译器“函数内不会改这两个形参”，让代码更健壮。\n");  

    // 调用find，测试const效果  
    int index = find(arr, val, len);  
    printf("数组中找到val=%d的索引：%d\n", val, index);  

    return 0;  
}  

// 测试验证方案：  
//  1. 怎么运行：gcc编译后运行（如 `gcc 9.c -o 9 && ./9`）  
//  2. 预期结果：  
//     - 输出对static和const的解释  
//     - 找到val=3的索引2  
//  3. 检查点：  
//     - 理解static隐藏变量、const保护数组内容、值传递的const语义  
// 易错点提醒：  
//  1. 混淆“数组参数”和“值传递”：`int arr[]`是**指针传递**（传地址），不是值传递！  
//  2. 认为const修饰值传递参数能改变保护效果（实际只是语义约束）  
// 拓展思考：  
//  1. 如果plink去掉static，其他文件能extern引用并修改吗？→ 能，所以static用来隐藏。  
//  2. `const int *arr`和`int *const arr`有何区别？→ 前者保护**内容**，后者保护**指针本身**（不能改指向）。  
// 对比说明：  
//  static全局 vs 普通全局：  
//  - 普通全局：外部链接，跨文件可见（extern可引用/修改）  
//  - static全局：内部链接，仅限本文件可见（更安全，避免冲突）  
//  const修饰指针传递（arr） vs 值传递（value、n）：  
//  - arr（指针传递）：const保护**数组内容**不被改（如arr[0]）。  
//  - value、n（值传递）：const保护**形参本身**不被改（语义约束，防止函数内误写）。  
//  值传递的本质：  
//  - 无论是否const，形参修改都不影响实参；const只是让编译器帮忙检查，避免写错。  