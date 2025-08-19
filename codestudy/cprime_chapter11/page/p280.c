// ------------------------------
// 知识要点总结：
//  1. 两种字符串数组形式：  
//     - 指针数组（`const char *mytalents[]`）：每个元素是**指针**，指向**静态区的字符串字面量**，内存效率高（只存地址）。  
//     - 二维字符数组（`char yourtalents[LIM][SLEN]`）：每个元素是**固定长度的字符数组**，存储字符串的**拷贝**，内存占用大（按最长字符串分配空间）。  
//  2. `sizeof` 计算：  
//     - 指针数组：`sizeof(mytalents)` = 元素个数 × 指针大小（如 5×8=40，64位系统）。  
//     - 二维数组：`sizeof(yourtalents)` = 行数 × 每行长度（如 5×40=200）。  
//  3. 可修改性：  
//     - 指针数组指向的字符串字面量**不可修改**（否则程序崩溃）；  
//     - 二维数组的元素是拷贝，**可以修改**（如 `yourtalents[0][0] = 'W'` 合法）。  
// 总体逻辑说明：  
//  1. 定义两种字符串数组，分别存储“才能”列表：  
//     - `mytalents` 是指针数组，指向静态区的字符串；  
//     - `yourtalents` 是二维字符数组，存储字符串的拷贝。  
//  2. 打印表头，通过循环逐行对比输出两个数组的内容。  
//  3. 打印 `sizeof` 的结果，验证两者的内存占用差异。  

#include <stdio.h>
#define SLEN 40  // 二维字符数组的每行长度（最长字符串的长度+1）
#define LIM 5    // 字符串的个数

int main(void) {
    // 【指针数组】每个元素是指针，指向静态区的字符串字面量
    const char *mytalents[LIM] = {
        "Adding numbers swiftly",
        "Multiplying accurately", "Stashing data",
        "Following instructions to the letter",
        "Understanding the C language"
    };

    // 【二维字符数组】每个元素是长度为 SLEN 的字符数组，存储字符串的拷贝
    char yourtalents[LIM][SLEN] = {
        "Walking in a straight line",
        "Sleeping", "Watching television",
        "Mailing letters", "Reading email"
    };

    puts("Let's compare talents.");  // 输出标题

    // 打印表头，设置格式：左列占36字符，右列占25字符
    printf("%-36s %-25s\n", "My Talents", "Your Talents");

    // 循环遍历每个字符串，对比输出
    for (int i = 0; i < LIM; i++) {
        printf("%-36s %-25s\n", mytalents[i], yourtalents[i]);
    }

    // 打印 sizeof 的结果，对比内存占用
    printf("\nsizeof mytalents: %zd, sizeof yourtalents: %zd\n",
           sizeof(mytalents), sizeof(yourtalents));

    return 0;
}

// ------------------------------
// 测试验证建议方案：
//  1. 编译运行：  
//     - 保存为 `arrchar.c`，执行命令 `gcc arrchar.c -o arrchar && ./arrchar`（Linux/Mac），或在编译器中直接运行（Windows）。  
//  2. 预期结果：  
//     - 输出5行对比，左列是 `mytalents` 的内容，右列是 `yourtalents` 的内容，格式对齐；  
//     - `sizeof` 输出：`mytalents` 为 40（5个指针，每个8字节），`yourtalents` 为 200（5行×40列）。  
//  3. 检查点：  
//     - 观察字符串输出是否对齐（`%-36s` 和 `%-25s` 确保左对齐，宽度固定）；  
//     - 核对 `sizeof` 的值是否符合计算（如64位系统，指针占8字节，5×8=40；5×40=200）。  

// ------------------------------
// 易错点提醒：  
//  1. 指针数组的 `sizeof` 误解：  
//     - 新手易以为 `sizeof(mytalents)` 是字符串总长度，实际是**指针的总大小**（和字符串内容长度无关）。  
//  2. 修改指针数组的字符串：  
//     - 尝试 `mytalents[0][0] = 'A';` 会崩溃（因为指向的是静态区的只读字符串）。  
//  3. 二维数组的空间浪费：  
//     - `yourtalents` 中短字符串（如 "Sleeping" 长度7）会占用40字节，剩余空间被 '\0' 填充，内存利用率低。  

// ------------------------------
// 拓展思考：  
//  1. 验证可修改性：  
//     → 修改 `yourtalents[1][0] = 'Z';`，再次输出，观察 "Sleeping" 变为 "Zleeping"（合法，因为是拷贝）。  
//  2. 动态分配指针数组：  
//     → 用 `const char **mytalents = malloc(LIM * sizeof(char *));`，手动赋值指针，体验动态内存管理。  
//  3. 对比内存布局：  
//     → 打印 `&mytalents[0]` 和 `&yourtalents[0]` 的地址，观察指针数组（存地址）和二维数组（存字符）的内存差异。  