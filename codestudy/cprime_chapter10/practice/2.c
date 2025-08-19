// ------------------------------
// 题干：编写一个程序，初始化一个 double 类型的数组，然后把该数组的内容拷贝至 3 个其他数组中。使用带数组表示法的函数进行第 1 份拷贝。使用带指针表示法和指针递增的函数进行第 2 份拷贝。第 3 个函数以目标数组名、源数组名和指向源数组最后一个元素后面的元素的指针调用。
// 知识要点：
//  1. 数组与指针的等价性：数组下标访问（`arr[i]`）和指针解引用（`*(arr+i)`）效果相同。
//  2. 指针递增：指针`++`会按元素类型大小移动（如`double*`每次移动8字节）。
//  3. 尾指针用法：通过`末尾指针 - 首指针`计算元素个数（`n = end - start`）。
//  4. 函数参数传递：数组作为参数时退化为指针，需显式传元素个数或尾指针。
// 总体逻辑：
//  1. 初始化源数组`source`和三个目标数组`target1~3`。
//  2. 调用三个拷贝函数：
//     - `copy_arr`：用数组下标法拷贝（`target[i] = source[i]`）。
//     - `copy_ptr`：用指针递增法拷贝（`*target_ptr++ = *source_ptr++`）。
//     - `copy_ptrs`：用尾指针法，先算元素个数（`end - source`），再拷贝。
//  3. 打印四个数组，验证拷贝结果是否一致。
#include <stdio.h>

// 函数1：数组表示法拷贝（下标访问）
void copy_arr(double target[], const double source[], int n) {
    for (int i = 0; i < n; i++) {
        target[i] = source[i]; // 用数组下标，把source的第i个元素赋给target的第i个元素
    }
}

// 函数2：指针表示法 + 指针递增拷贝
void copy_ptr(double target[], const double source[], int n) {
    const double *src_ptr = source; // 指向source第一个元素的指针
    double *tar_ptr = target;       // 指向target第一个元素的指针
    for (int i = 0; i < n; i++) {
        *tar_ptr = *src_ptr; // 解引用指针，把source的值赋给target
        tar_ptr++;           // 指针后移，指向下一个元素
        src_ptr++;
    }
}

// 函数3：尾指针法拷贝（通过末尾指针算元素个数）
void copy_ptrs(double target[], const double source[], const double *end) {
    int n = end - source; // 末尾指针 - 首指针 = 元素个数（如source+5 - source = 5）
    const double *src_ptr = source;
    double *tar_ptr = target;
    for (int i = 0; i < n; i++) {
        *tar_ptr = *src_ptr; // 拷贝值
        tar_ptr++;           // 指针后移
        src_ptr++;
    }
}

int main() {
    // 初始化源数组
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    // 声明三个目标数组（未初始化，值随机，拷贝后会被覆盖）
    double target1[5];
    double target2[5];
    double target3[5];

    // 调用三个拷贝函数
    copy_arr(target1, source, 5);          // 数组下标法
    copy_ptr(target2, source, 5);          // 指针递增法
    copy_ptrs(target3, source, source + 5); // 尾指针法（source+5是最后一个元素的下一个位置）

    // 打印所有数组，验证结果
    printf("源数组 source：");
    for (int i = 0; i < 5; i++) {
        printf("%.1f ", source[i]); // 输出浮点数，保留1位小数
    }
    printf("\n");

    printf("目标数组 target1（copy_arr）：");
    for (int i = 0; i < 5; i++) {
        printf("%.1f ", target1[i]);
    }
    printf("\n");

    printf("目标数组 target2（copy_ptr）：");
    for (int i = 0; i < 5; i++) {
        printf("%.1f ", target2[i]);
    }
    printf("\n");

    printf("目标数组 target3（copy_ptrs）：");
    for (int i = 0; i < 5; i++) {
        printf("%.1f ", target3[i]);
    }
    printf("\n");

    return 0;
}

// 测试验证方案：
//  1. 怎么运行：
//     - 保存为`copy_array.c`，用`gcc copy_array.c -o copy_array`编译，运行`./copy_array`。
//  2. 预期结果：
//     - 四个数组输出完全一致：`1.1 2.2 3.3 4.4 5.5`。
//  3. 检查点：
//     - 观察`target1~3`的输出是否和`source`相同。

// 易错点提醒：
//  1. 指针递增时，容易忽略指针类型（如`double*`移动8字节，不是1字节）。
//  2. `copy_ptrs`中如果`end`不是合法尾指针（如`source+6`），会导致计算错误。
//  3. 忘记给源数组加`const`，可能不小心修改源数据。

// 拓展思考：
//  1. 如果源数组是动态分配的（`double *source = malloc(5*sizeof(double))`），怎么改？
//     → 分配后赋值，用法不变，但要记得`free(source)`。
//  2. 如何简化`copy_ptr`的代码？
//     → 合并赋值和递增：`*tar_ptr++ = *src_ptr++;`。
//  3. 如果数组类型改为`int`，要改哪些地方？
//     → 把`double`换成`int`，`printf`用`%d`。

// 对比说明：
//  - 数组下标 vs 指针递增：
//    → 下标法直观，指针法更灵活（比如反向遍历`ptr--`）。
//    → 本质都是访问内存地址，编译后指令几乎一样。
//  - 显式传个数 vs 尾指针：
//    → 尾指针无需传`n`，但要保证`end`合法；显式传`n`更直接，但容易传错值。