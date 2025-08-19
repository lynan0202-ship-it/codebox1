
/*
知识要点总结：
1. 数组基础：
   - 存储相同类型数据，元素顺序存储，下标从 0 开始
   - 传统数组用常量表达式指定大小（C99 支持变长数组用变量指定）
   - 数组名是首元素地址，与指针等价（ar[i] 等价于 *(ar+i) ）
2. 数组与函数：
   - 不能直接传递整个数组，需传地址（数组名或指针）
   - 用 const 修饰形参防止数组被修改
   - 处理多维数组时，需指定除第一维外的维度（或用变长数组语法）
3. 指针运算：
   - 指针加减整数，步长是元素大小（如 double* 指针 +1 跳过 8 字节）
   - 数组表示法和指针表示法可互换（函数形参是指针也能用数组语法）
4. 关键概念：
   - 变长数组（VLA）：C99 特性，大小运行时确定，创建后不可变
   - 复合字面量：匿名数组，临时传递参数时用（需注意作用域）

代码总体逻辑说明：
1. 定义 4 个函数演示数组处理：
   - print_array：打印一维数组（用数组语法）
   - sum_array：计算一维数组总和（用指针语法）
   - print_2d_array：打印二维数组（传统语法）
   - sum_2d_vla：计算二维数组总和（变长数组语法）
2. 主函数中：
   - 用传统数组、变长数组、复合字面量创建测试数据
   - 调用上述函数，验证数组与指针的关系、函数传参、多维数组处理
   - 对比数组表示法和指针表示法的等价性
   - 演示复合字面量临时传参的用法
*/

#include <stdio.h>

// 打印一维数组（数组表示法，形参是指针但用数组语法）
void print_array(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        // arr[i] 等价于 *(arr+i)
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 计算一维数组总和（指针表示法，形参是指针）
int sum_array(const int *arr, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        // 指针语法：*(arr+i)
        total += *(arr + i);
    }
    return total;
}

// 打印二维数组（传统语法，指定第二维大小）
void print_2d_array(const int arr[][4], int rows) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < 4; c++) {
            // 数组名 + 下标访问
            printf("%d ", arr[r][c]);
        }
        printf("\n");
    }
}

// 计算二维数组总和（变长数组语法，运行时指定维度）
int sum_2d_vla(int rows, int cols, const int arr[rows][cols]) {
    int total = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            // 指针语法访问二维数组：*(*(arr+r)+c)
            total += *(*(arr + r) + c);
        }
    }
    return total;
}

int main(void) {
    // 1. 一维数组测试
    // 传统数组（常量大小）
    int arr1[5] = {1, 2, 3, 4, 5};
    // 变长数组（变量大小）
    int size = 5;
    int arr2[size];
    for (int i = 0; i < size; i++) {
        arr2[i] = i * 2; // 0, 2, 4, 6, 8
    }

    printf("一维数组 arr1：");
    print_array(arr1, 5);
    printf("arr1 总和：%d\n", sum_array(arr1, 5));

    printf("一维数组 arr2（变长数组）：");
    print_array(arr2, size);
    printf("arr2 总和：%d\n", sum_array(arr2, size));

    // 2. 二维数组测试（传统语法）
    int arr_2d[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    printf("\n二维数组 arr_2d（传统语法）：\n");
    print_2d_array(arr_2d, 3);
    printf("arr_2d 总和（传统语法）：%d\n", sum_2d_vla(3, 4, arr_2d));

    // 3. 变长数组（VLA）测试
    int rows = 2, cols = 3;
    // 运行时创建变长数组
    int vla_arr[rows][cols];
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            vla_arr[r][c] = (r + 1) * (c + 1); // 1,2,3; 2,4,6
        }
    }
    printf("\n二维变长数组 vla_arr（%dx%d）：\n", rows, cols);
    // 用变长数组语法调用函数
    printf("vla_arr 总和（VLA 语法）：%d\n", sum_2d_vla(rows, cols, vla_arr));

    // 4. 复合字面量测试（临时传参）
    printf("\n复合字面量测试：\n");
    // 直接传递复合字面量给函数
    int total = sum_array((int[]){10, 20, 30}, 3);
    printf("复合字面量总和：%d\n", total);

    // 5. 指针与数组等价性演示
    int test_arr[4] = {100, 200, 300, 400};
    int *p = test_arr; // p 是首元素地址
    printf("\n指针与数组等价性：\n");
    printf("test_arr[0] = %d, *(test_arr+0) = %d\n", test_arr[0], *(test_arr + 0));
    printf("p[1] = %d, *(p+1) = %d\n", p[1], *(p + 1));

    return 0;
}

/*
测试及验证建议方案：
1. 基础功能验证：
   - 运行代码，检查数组打印、求和结果是否正确
   - 修改数组元素值（如 arr1[2] = 99 ），验证函数是否正确处理
2. 编译器特性测试：
   - 用 C89 标准编译（gcc -std=c89），观察变长数组（VLA）相关报错
   - 用 C99 标准编译（gcc -std=c99），验证 VLA、复合字面量是否支持
3. 边界情况测试：
   - 传递空数组（size=0），检查函数是否崩溃（需处理边界）
   - 传递极大数组（如 size=1000000 ），观察内存使用和性能
4. 指针等价性测试：
   - 在 print_array 中用指针语法替换数组语法（*(arr+i) ），验证输出是否一致
   - 修改指针 p 的地址（如 p += 2 ），观察数组访问结果
5. 多维数组测试：
   - 改变二维数组的行数/列数，验证 sum_2d_vla 函数是否正确
   - 用复合字面量创建二维数组传递给 sum_2d_vla（如 (int[2][3]){{1,2,3},{4,5,6}} ）
6. 作用域测试：
   - 在复合字面量所在块外访问其地址（如保存指针后离开块），观察是否失效
   - 用动态分配内存（malloc）创建数组，对比复合字面量的作用域


### 关键教学点强化说明  
- **数组与指针等价性**：通过 `test_arr` 和指针 `p` 的打印，让初学者直观看到 `arr[i]` 和 `*(arr+i)` 的等价性  
- **变长数组（VLA）**：特意用变量 `rows/cols` 创建数组，对比传统数组的常量维度，强化“运行时确定大小”的特性  
- **复合字面量**：演示直接传递匿名数组给函数，说明“临时传参无需先定义变量”的优势，同时注释提醒作用域风险  
- **多维数组处理**：对比传统语法（指定列数 `4` ）和 VLA 语法（传递 `rows/cols` ），解释“第二维必须指定”的原因  

通过运行代码并按测试建议验证，可深度理解数组与指针的核心关系、函数传参规则、C99 特性（VLA、复合字面量）
的用法，解决书中“数组和指针”章节的关键知识点。
*/