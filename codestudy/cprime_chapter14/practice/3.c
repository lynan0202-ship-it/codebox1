// ------------------------------
// 题干：修改程序清单14.2中的图书目录程序，使其按照输入图书的顺序输出图书的信息，然后按照标题字母的顺序输出图书的信息，最后按照价格的升序输出图书的信息。
// 知识要点：
//  1. 结构体的定义与使用（存储图书的标题、作者、价格）
//  2. 数组存储多个结构体变量（用数组保存多本图书信息）
//  3. 字符串比较函数 `strcmp`（按标题排序时比较字符串大小）
//  4. 冒泡排序算法的实现（分别按标题和价格对结构体数组排序）
//  5. 函数的封装（把“输出”“排序+输出”的逻辑拆成单独函数）
// 总体逻辑：
//  1. 定义`Book`结构体，包含标题、作者、价格字段。
//  2. 主函数中，先让用户输入图书数量，再循环输入每本图书的标题、作者、价格，按输入顺序存入数组。
//  3. 调用函数，按**输入顺序**输出所有图书信息。
//  4. 调用函数，用冒泡排序按**标题字母顺序**排序图书数组，再输出。
//  5. 调用函数，用冒泡排序按**价格升序**排序图书数组，再输出。
#include <stdio.h>
#include <string.h>  // 包含 strcmp 所需的头文件

// 定义图书结构体，存储单本图书的信息
struct Book {
    char title[50];   // 图书标题，最多存49个字符（留1个给'\0'）
    char author[30];  // 作者姓名，最多存29个字符
    float price;      // 图书价格
};

// 函数：按输入顺序输出图书信息
void printBooksInInputOrder(struct Book books[], int count) {
    printf("\n--- 按输入顺序输出图书 ---\n");
    for (int i = 0; i < count; i++) {
        printf("第 %d 本图书：\n", i + 1);
        printf("  标题：%s\n", books[i].title);
        printf("  作者：%s\n", books[i].author);
        printf("  价格：%.2f 元\n", books[i].price);
    }
}

// 函数：按标题字母顺序排序（冒泡排序），然后输出
void sortAndPrintByTitle(struct Book books[], int count) {
    struct Book temp;  // 临时变量，用于交换图书结构体
    // 冒泡排序：比较标题，按字母升序排列
    for (int i = 0; i < count - 1; i++) {  // 外层循环控制排序轮数
        for (int j = 0; j < count - 1 - i; j++) {  // 内层循环比较相邻元素
            // strcmp返回>0，说明books[j].title比books[j+1].title“大”，需要交换
            if (strcmp(books[j].title, books[j + 1].title) > 0) {
                temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
    // 输出排序后的结果
    printf("\n--- 按标题字母顺序输出图书 ---\n");
    for (int i = 0; i < count; i++) {
        printf("第 %d 本图书：\n", i + 1);
        printf("  标题：%s\n", books[i].title);
        printf("  作者：%s\n", books[i].author);
        printf("  价格：%.2f 元\n", books[i].price);
    }
}

// 函数：按价格升序排序（冒泡排序），然后输出
void sortAndPrintByPrice(struct Book books[], int count) {
    struct Book temp;  // 临时变量，用于交换图书结构体
    // 冒泡排序：比较价格，按升序排列
    for (int i = 0; i < count - 1; i++) {  // 外层循环控制排序轮数
        for (int j = 0; j < count - 1 - i; j++) {  // 内层循环比较相邻元素
            if (books[j].price > books[j + 1].price) {  // 前一个价格比后一个高，交换
                temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
    // 输出排序后的结果
    printf("\n--- 按价格升序输出图书 ---\n");
    for (int i = 0; i < count; i++) {
        printf("第 %d 本图书：\n", i + 1);
        printf("  标题：%s\n", books[i].title);
        printf("  作者：%s\n", books[i].author);
        printf("  价格：%.2f 元\n", books[i].price);
    }
}

int main() {
    int bookCount;
    printf("请输入图书的数量：");
    scanf("%d", &bookCount);
    getchar();  // 吸收输入数字后的换行符，避免影响后续fgets

    // 定义图书数组，存储所有输入的图书
    struct Book books[bookCount];

    // 循环输入每本图书的信息
    for (int i = 0; i < bookCount; i++) {
        printf("\n输入第 %d 本图书的信息：\n", i + 1);
        
        printf("  标题：");
        fgets(books[i].title, 50, stdin);  // 读取标题（支持带空格的字符串）
        // 处理fgets可能读取到的换行符
        int len = strlen(books[i].title);
        if (books[i].title[len - 1] == '\n') {
            books[i].title[len - 1] = '\0';  // 把换行符换成字符串结束符
        }

        printf("  作者：");
        fgets(books[i].author, 30, stdin);  // 读取作者
        len = strlen(books[i].author);
        if (books[i].author[len - 1] == '\n') {
            books[i].author[len - 1] = '\0';
        }

        printf("  价格：");
        scanf("%f", &books[i].price);  // 读取价格
        getchar();  // 吸收输入价格后的换行符
    }

    // 按三种不同顺序输出图书
    printBooksInInputOrder(books, bookCount);
    sortAndPrintByTitle(books, bookCount);
    sortAndPrintByPrice(books, bookCount);

    return 0;
}

// 测试验证方案：
//  1. 怎么运行：用C语言编译器（如GCC）编译代码（例：`gcc 文件名.c -o book_sort`），然后运行可执行文件（例：`./book_sort`）。
//  2. 预期结果：
//     - 输入图书数量（比如3本），再依次输入每本的标题、作者、价格（例如：
//       第1本：标题"Python Basics"，作者"Alice"，价格29.9；
//       第2本：标题"C Primer"，作者"Bob"，价格39.5；
//       第3本：标题"Java Core"，作者"Charlie"，价格45.0）。
//     - 首先输出“按输入顺序”：3本图书顺序与输入一致。
//     - 然后输出“按标题字母顺序”：标题按字典序排列（"C Primer" → "Java Core" → "Python Basics"）。
//     - 最后输出“按价格升序”：价格从低到高（29.9 → 39.5 → 45.0）。
//  3. 检查点：重点看三种输出的顺序是否符合要求，标题排序时字符串比较是否正确，价格排序时数值是否从小到大。
// 易错点提醒：
//  1. 用`scanf`读价格后，忘记用`getchar()`吸收换行符，导致后续`fgets`直接读到换行符，标题/作者输入异常。
//  2. 字符串比较时，误用赋值符号`=`代替`strcmp`函数（比如写成`if (books[j].title = books[j+1].title)`，这是错误的赋值而非比较）。
//  3. 冒泡排序的循环边界写错（比如内层循环写成`j < count - i`，少减1，导致排序不完整）。
//  4. `fgets`读取的字符串包含换行符，忘记用`if`判断并替换为`\0`，导致输出时显示多余空行。
// 拓展思考：
//  1. 如果图书数量很多（比如100本），冒泡排序效率低，如何优化？可以使用标准库的`qsort`函数（需要写比较函数，结合函数指针）。
//  2. 如何支持“按作者姓名排序”？可以仿照`sortAndPrintByTitle`，编写按`author`字段排序的函数（用`strcmp(books[j].author, books[j+1].author)`比较）。
//  3. 若要将图书信息保存到文件，下次运行时从文件读取，该怎么改？可以在主函数中添加文件操作：用`fopen`打开文件，`fwrite`写入图书数组；程序启动时用`fread`读取文件内容到数组。
// 对比说明：
//  传递结构体数组到函数时（如`printBooksInInputOrder(books, bookCount)`），是**地址传递**（数组名`books`本质是首地址）。函数内修改数组里的结构体（如排序时交换元素），主函数中的数组会被直接修改。而如果是传递单个结构体变量（如`struct Book b; func(b);`），默认是**值传递**（拷贝一份给函数，函数内修改不影响外部）。地址传递能直接修改原数据，值传递则不能，这是两者的核心区别。