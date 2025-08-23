/*
代码名称：complit.c
知识要点总结：
1. 复合字面量（C99特性）：  
   - 语法：`(struct 类型) { 成员初始化 }`，创建**匿名临时结构体**  
   - 可直接赋值给同类型变量，或作为函数参数传递（值/地址）  
2. 结构操作：  
   - 复合字面量的成员初始化规则与结构体变量一致（按顺序赋值，支持部分成员省略）  
3. 函数传参：  
   - 传**复合字面量的值**：函数接收结构体副本，原临时结构不影响  
   - 传**复合字面量的地址**：临时结构的地址仅在**调用期间有效**（避免长期保存指针）  
4. const 修饰：保护指针参数指向的数据，防止函数内意外修改  

代码总体逻辑说明：  
1. **书籍示例**：  
   - 定义 `struct book` 存储书名、作者、价格  
   - 根据用户输入的测试分数，用**复合字面量**创建临时书结构，赋值给 `readfirst`  
   - 输出 `readfirst` 的内容，演示复合字面量的赋值用法  
2. **矩形面积扩展示例**：  
   - 定义 `struct rect` 存储长和宽  
   - 实现两个函数：  
     - `rect_area`：接收**结构体值**（复合字面量直接传值）  
     - `rect_area_p`：接收**结构体指针**（复合字面量传地址，配合 `&`）  
   - 调用函数时，用复合字面量作为参数，验证面积计算逻辑  


以下是完整代码（包含教材示例+扩展演示）：
*/

#include <stdio.h>

// ========== 书籍结构定义（教材示例） ==========
#define MAXTITLE 41  // 书名最大长度
#define MAXAUTL  31  // 作者名最大长度
struct book {
    char title[MAXTITLE]; // 书名
    char author[MAXAUTL]; // 作者
    float value;          // 价格
};

// ========== 矩形结构定义（扩展演示） ==========
struct rect {
    double x; // 长
    double y; // 宽
};

// ========== 函数声明（扩展演示） ==========
double rect_area(struct rect);          // 接收结构体**值**
double rect_area_p(const struct rect *); // 接收结构体**指针**（const 保护）

int main(void)
{
    // ---------- 1. 书籍示例：根据分数选择书籍 ----------
    struct book readfirst; // 存储最终选中的书
    int score;             // 测试分数

    printf("Enter test score: ");
    scanf("%d", &score);

    if (score >= 84) {
        // 复合字面量语法：(struct book) + 初始化列表
        readfirst = (struct book){
            "Crime and Punishment",  // title 成员
            "Fyodor Dostoevsky",     // author 成员
            11.25                    // value 成员
        };
    } else {
        readfirst = (struct book){
            "Mr. Bouncy's Nice Hat", // title 成员
            "Fred Winsome",          // author 成员
            5.99                     // value 成员
        };
    }

    // 输出书籍信息
    printf("\nYour assigned reading:\n");
    printf("%s by %s: $%.2f\n", 
           readfirst.title,   // 访问结构体成员
           readfirst.author, 
           readfirst.value);


    // ---------- 2. 扩展演示：复合字面量作为函数参数 ----------
    // 2.1 传**复合字面量的值**给函数（结构体整体拷贝）
    double area_val = rect_area(
        (struct rect){10.5, 20.0}  // 临时创建 rect 结构，直接传值
    );
    printf("\nArea (passed by value): %.2f\n", area_val);

    // 2.2 传**复合字面量的地址**给函数（& + 复合字面量）
    double area_ptr = rect_area_p(
        &(struct rect){10.5, 20.0}  // 临时创建 rect 结构，传地址
    );
    printf("Area (passed by pointer): %.2f\n", area_ptr);


    return 0;
}


// ========== 函数定义（扩展演示） ==========
/* 
rect_area：接收结构体**值**  
- 函数内操作的是结构体副本，不影响外部临时结构  
*/
double rect_area(struct rect r) {
    return r.x * r.y; // 通过 `.` 访问成员（变量形式）
}

/* 
rect_area_p：接收结构体**指针**（const 修饰，保证只读）  
- 函数内通过 `->` 访问成员（指针形式）  
- const 防止修改传入的临时结构数据  
*/
double rect_area_p(const struct rect *rp) {
    return rp->x * rp->y; // 通过 `->` 访问指针指向的成员
}


/*
代码测试及验证建议方案：
1. 书籍示例验证：  
   - 输入 `85`，检查输出是否为《Crime and Punishment》及对应作者、价格  
   - 输入 `83`，检查输出是否为《Mr. Bouncy's Nice Hat》及对应信息  

2. 矩形面积验证：  
   - 手动计算 `10.5×20.0=210.0`，检查两个函数输出是否均为 `210.00`  
   - 修改复合字面量参数（如 `{5.0, 6.0}`），验证计算结果是否为 `30.00`  

3. 编译器兼容性：  
   - 使用 `gcc` 编译时，需添加 `-std=c99` 选项（如 `gcc -std=c99 complit.c -o complit`）  
   - 若编译器不支持C99，复合字面量语法会报错，需升级编译器或调整编译选项  

4. 易错点测试：  
   - 尝试保存复合字面量的地址到全局指针（如 `struct rect *p = &(struct rect){1,2};`），后续访问 `p->x`（会触发未定义行为，因为临时结构已销毁）  
   - 移除 `rect_area_p` 的 `const` 修饰，尝试修改 `rp->x`，观察编译器是否允许（验证 const 的保护作用）  

5. 传参对比观察：  
   - 对比 `rect_area`（传值）和 `rect_area_p`（传指针）的调用方式，体会 **值拷贝** vs **地址传递** 的差异  
   - 在 `rect_area` 内修改 `r.x`，观察外部复合字面量是否受影响（预期：不影响，因为是副本）  
*/