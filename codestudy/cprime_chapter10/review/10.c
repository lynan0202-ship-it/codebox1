// ------------------------------
// 题干：假设有下面的声明：
//      float rootbeer[10], things[10][5], *pf, value = 2.2;
//      int i = 3;
//      判断以下各项是否有效：
//      a. rootbeer[2] = value; 
//      b. scanf("%f", &rootbeer ); 
//      c. rootbeer = value; 
//      d. printf("%f", rootbeer); 
//      e. things[4][4] = rootbeer[3]; 
//      f. things[5] = rootbeer; 
//      g. pf = value; 
//      h. pf = rootbeer; 
// 知识要点：
//  1. 数组元素赋值：同类型元素间可赋值，要注意数组下标是否合法 
//  2. scanf 函数使用：需传入变量地址，数组名代表首地址，但对于一维数组整体，不能直接这样用 
//  3. 数组名特性：数组名是常量指针，不能被赋值 
//  4. printf 函数格式：输出float数组不能直接用数组名，需遍历元素 
//  5. 指针赋值：指针要赋值同类型地址，不能直接赋值普通变量值 
// 总体逻辑：
//  1. 依次分析每个表达式，根据C语言语法规则判断是否有效
#include <stdio.h>
int main() {
    float rootbeer[10], things[10][5], *pf, value = 2.2;
    int i = 3;

    // 分析各项，这里通过注释说明是否有效及原因，实际代码中无法直接运行这些判断，用输出提示
    printf("a. rootbeer[2] = value; ：有效，同类型元素赋值，下标2在0 - 9范围内\n");
    printf("b. scanf(\"%f\", &rootbeer ); ：无效，rootbeer是数组名，代表首地址，&rootbeer是整个数组的地址，scanf %f 期望float变量地址，不匹配\n");
    printf("c. rootbeer = value; ：无效，rootbeer是常量指针，不能被赋值\n");
    printf("d. printf(\"%f\", rootbeer); ：无效，printf %f 用于输出float变量，rootbeer是数组名，需遍历元素输出\n");
    printf("e. things[4][4] = rootbeer[3]; ：有效，同类型元素赋值，下标4在0 - 9（行）和0 - 4（列）范围内\n");
    printf("f. things[5] = rootbeer; ：无效，things[5]是一维数组（内含5个float元素），rootbeer是一维数组（内含10个float元素），类型不匹配\n");
    printf("g. pf = value; ：无效，pf是float指针，value是float变量，不能直接把变量值赋给指针，应取地址（&value）\n");
    printf("h. pf = rootbeer; ：有效，rootbeer是数组名，代表首元素地址，pf是float指针，类型匹配\n");

    return 0;
}
// 测试验证方案：
//  1. 怎么运行：编译并运行代码，查看输出的判断结果
//  2. 预期结果：输出各项是否有效的判断及原因
//  3. 检查点：核对每个判断是否符合C语言语法规则
// 易错点提醒：
//  1. 容易混淆数组名和指针的赋值规则，比如认为rootbeer可以被赋值
//  2. 忘记scanf、printf函数对参数类型的要求，导致判断错误
// 拓展思考：
//  1. 对于d项，怎么修改代码可以正确输出rootbeer数组元素？（用循环遍历输出）
//  2. 对于g项，怎么修改可以让赋值有效？（pf = &value; ）
// 对比说明：
//  - 数组名作为常量指针有特殊的赋值规则，和普通指针、变量赋值不同。指针赋值要注意类型匹配，函数参数要注意类型对应，这些规则保证代码的正确性和可读性 