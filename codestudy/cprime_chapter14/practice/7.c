// ------------------------------
// 题干：修改程序，从文件中读取每条记录并显示出来，允许用户删除记录或修改记录的内容。如果删除记录，把空出来的空间留给下一个要读入的记录。要修改现有的文件内容，必须用“r+b”模式，而不是“a+b”模式。而且，必须更加注意定位文件指针，防止新加入的记录覆盖现有记录。最简单的方法是改动储存在内存中的所有数据，然后再把最后的信息写入文件。跟踪的一个方法是在 book 结构中添加一个成员表示是否该被删除。
// 知识要点：
//  1. 文件操作（“r+b”“w+b”模式打开文件、`fread`/`fwrite` 读写、`fseek` 定位）
//  2. 结构体的定义与使用（包含标记删除的成员）
//  3. 数组与循环（存储记录、遍历显示）
//  4. 用户交互（菜单、输入选择）
// 总体逻辑：
//  1. 定义包含“是否删除”标记的图书结构体，以“r+b”模式打开数据文件
//  2. 读取文件中所有记录到结构体数组，统计实际记录数量
//  3. 显示所有记录（区分已删除/未删除），提供“删除/修改/保存退出”的操作菜单
//  4. 根据用户选择，修改内存中记录的“删除标记”或内容
//  5. 以“w+b”模式重新打开文件，将内存中未被删除的记录写回文件
//  6. 关闭文件，完成操作
#include <stdio.h>
#include <string.h>

// 定义图书结构体，包含书名、作者、价格，以及“是否删除”的标记
typedef struct {
    char title[50];   // 书名
    char author[50];  // 作者
    float price;      // 价格
    int is_deleted;   // 是否删除：0=未删除，1=已删除
} Book;

int main() {
    // 以“r+b”模式打开二进制文件（可读可写，保留原有内容）
    FILE *file = fopen("books.dat", "r+b");
    if (file == NULL) {
        printf("无法打开文件！\n");
        return 1; // 文件打开失败，结束程序
    }

    Book books[100];   // 用数组存储最多100条图书记录
    int record_count = 0; // 记录实际读取的记录数量

    // 循环从文件读取每条记录到数组，直到读取失败（返回值不为1）
    while (fread(&books[record_count], sizeof(Book), 1, file) == 1) {
        record_count++;
    }

    int choice, index; // choice：用户操作选择；index：记录序号
    do {
        // 显示所有图书记录（区分已删除和未删除）
        printf("\n=== 图书记录列表 ===\n");
        printf("序号\t书名\t\t作者\t\t价格\t状态\n");
        for (int i = 0; i < record_count; i++) {
            if (books[i].is_deleted == 0) {
                printf("%d\t%s\t\t%s\t\t%.2f\t未删除\n", 
                       i, books[i].title, books[i].author, books[i].price);
            } else {
                printf("%d\t%s\t\t%s\t\t%.2f\t已删除\n", 
                       i, books[i].title, books[i].author, books[i].price);
            }
        }

        // 显示操作菜单
        printf("\n=== 操作菜单 ===\n");
        printf("1. 删除记录\n");
        printf("2. 修改记录\n");
        printf("3. 保存并退出\n");
        printf("请输入选择（1-3）：");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // 删除记录：标记对应记录为“已删除”
                printf("请输入要删除的记录序号：");
                scanf("%d", &index);
                if (index >= 0 && index < record_count) { // 检查序号是否在有效范围内
                    books[index].is_deleted = 1;
                    printf("记录已标记为删除！\n");
                } else {
                    printf("序号无效！\n");
                }
                break;
            case 2: // 修改记录：更新对应记录的内容，并确保标记为“未删除”
                printf("请输入要修改的记录序号：");
                scanf("%d", &index);
                if (index >= 0 && index < record_count) {
                    printf("输入新书名：");
                    scanf("%s", books[index].title);
                    printf("输入新作者：");
                    scanf("%s", books[index].author);
                    printf("输入新价格：");
                    scanf("%f", &books[index].price);
                    books[index].is_deleted = 0; // 修改后标记为“未删除”
                    printf("记录已修改！\n");
                } else {
                    printf("序号无效！\n");
                }
                break;
            case 3: // 保存并退出：后续将内存中未删除的记录写回文件
                printf("正在保存记录...\n");
                break;
            default:
                printf("选择无效，请重新输入！\n");
        }
    } while (choice != 3); // 选择3时退出循环

    // 关闭原文件，以“w+b”模式重新打开（会清空原有内容，准备写入新数据）
    fclose(file);
    file = fopen("books.dat", "w+b");
    if (file == NULL) {
        printf("重新打开文件失败！\n");
        return 1;
    }

    // 遍历数组，将未被删除的记录写回文件
    for (int i = 0; i < record_count; i++) {
        if (books[i].is_deleted == 0) { // 只写入“未删除”的记录
            fwrite(&books[i], sizeof(Book), 1, file);
        }
    }

    // 关闭文件，完成保存
    fclose(file);
    printf("记录已保存，程序退出。\n");

    return 0;
}

// 测试验证方案：
//  1. 怎么运行：①先创建测试文件 `books.dat`（可通过简单代码写入几条记录，或用二进制工具生成）；②用 GCC 编译代码（`gcc program.c -o program`）；③运行可执行文件（`./program`）。
//  2. 预期结果：程序显示图书列表，选择“1”可标记记录为“已删除”，选择“2”可修改记录内容，选择“3”保存未删除的记录并退出；再次运行程序，能看到修改/删除后的结果。
//  3. 检查点：删除操作后，记录“状态”显示为“已删除”；修改操作后，书名、作者、价格与输入一致；保存后重新打开程序，已删除的记录不会以“未删除”状态显示。
// 易错点提醒：
//  1. 文件打开模式错误（如用“r”“w”代替“r+b”“w+b”），导致无法正确读写二进制数据。
//  2. `fread`/`fwrite` 的参数错误（如结构体大小写错、元素个数传错），导致数据读写错位。
//  3. 用户输入的记录序号超出数组范围，未做有效性检查，导致数组越界。
//  4. 修改记录后忘记将 `is_deleted` 设为 0，导致修改后的记录仍显示为“已删除”。
// 拓展思考：
//  1. 若记录数量超过数组大小（100条），如何处理？可使用动态内存分配（如 `malloc`）来动态扩展存储。
//  2. 如何添加“新增记录”的功能？在写回文件时，若数组有剩余空间，可让用户输入新记录并加入数组，再写入文件。
//  3. 如何实现“按书名查询记录”？可添加查找函数，遍历数组匹配书名并返回结果。
//  4. “r+b”和“w+b”模式有何区别？`r+b` 是打开**已有**文件（可读可写，指针在文件开头）；`w+b` 是创建**新文件**（若文件已存在则截断，可读可写，指针在开头）。因此修改文件时，先“r+b”读、再“w+b”写，能确保最终文件是修改后的数据。