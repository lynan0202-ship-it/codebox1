// ------------------------------
// 题干：14. 数字图像，尤其是从宇宙飞船发回的数字图像，可能包含一些失真。为编程练习12添加消除失真的函数。该函数把每个值与它上下左右相邻的值作比较，如果该值与共周围相邻值的差都大于1，则用所有相邻值的平均值（四舍五入为整数）代替该值。注意，与边界上的点相邻的点少于4个，所以做特殊处理。
// 知识要点：
//  1. 二维数组的邻居判断（上下左右，处理边界情况）
//  2. 平均值计算与四舍五入（总和除以数量，处理小数）
//  3. 基于原始数据的修改（需临时数组保存原始值）
// 总体逻辑：
//  1. 同题目12，读取数据到int数组data。
//  2. 复制data到临时数组temp，用于判断（避免修改后影响后续判断）。
//  3. 遍历每个像素(i,j)：
//     a. 收集上下左右四个方向的有效邻居（判断坐标是否越界）。
//     b. 若邻居数量为0，跳过（实际不会出现）。
//     c. 检查当前值temp[i][j]与所有邻居的差的绝对值是否都>1。
//     d. 若是，计算邻居的平均值（四舍五入），更新data[i][j]。
//  4. 转换为字符数组，输出（同题目12）。

#include <stdio.h>

// 辅助函数：计算四舍五入的平均值（sum:总和，count:数量）
int round_average(int sum, int count) {
    // 公式：(sum + count/2) / count 实现四舍五入
    return (sum + count / 2) / count;
}

int main() {
    const char *input_file = "data.txt";
    const char *output_file = "output_denoise.txt";
    int data[20][30] = {0};
    char symbols[] = " .:~*=+###";  // 字符映射表
    
    // 步骤1：读取输入数据
    FILE *fp_in = fopen(input_file, "r");
    if (fp_in == NULL) {
        printf("无法打开输入文件 %s\n", input_file);
        return 1;
    }
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 30; j++) {
            fscanf(fp_in, "%d", &data[i][j]);
        }
    }
    fclose(fp_in);
    
    // 步骤2：复制原始数据到临时数组（避免修改影响判断）
    int temp[20][30];
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 30; j++) {
            temp[i][j] = data[i][j];
        }
    }
    
    // 步骤3：遍历每个点，检测并修复失真
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 30; j++) {
            int neighbors[4];  // 存储上下左右邻居的值
            int count = 0;     // 有效邻居数量
            
            // 收集上邻居（i-1 >= 0）
            if (i - 1 >= 0) neighbors[count++] = temp[i-1][j];
            // 收集下邻居（i+1 < 20）
            if (i + 1 < 20) neighbors[count++] = temp[i+1][j];
            // 收集左邻居（j-1 >= 0）
            if (j - 1 >= 0) neighbors[count++] = temp[i][j-1];
            // 收集右邻居（j+1 < 30）
            if (j + 1 < 30) neighbors[count++] = temp[i][j+1];
            
            // 无邻居时跳过（理论上不会发生）
            if (count == 0) continue;
            
            // 检查当前值与所有邻居的差是否都>1
            int current = temp[i][j];
            int all_diff_gt1 = 1;  // 假设都满足
            for (int k = 0; k < count; k++) {
                int diff = current - neighbors[k];
                if (diff < 0) diff = -diff;  // 取绝对值
                if (diff <= 1) {
                    all_diff_gt1 = 0;
                    break;
                }
            }
            
            // 若满足条件，计算平均值并更新data
            if (all_diff_gt1) {
                int sum = 0;
                for (int k = 0; k < count; k++) sum += neighbors[k];
                int avg = round_average(sum, count);
                data[i][j] = avg;
            }
        }
    }
    
    // 步骤4：转换为字符数组（同题目12）
    char chars[20][31] = {0};
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 30; j++) {
            chars[i][j] = symbols[data[i][j]];
        }
        chars[i][30] = '\0';
    }
    
    // 步骤5：输出到屏幕和文件
    FILE *fp_out = fopen(output_file, "w");
    if (fp_out == NULL) {
        printf("无法打开输出文件 %s\n", output_file);
        return 1;
    }
    for (int i = 0; i < 20; i++) {
        printf("%s\n", chars[i]);
        fprintf(fp_out, "%s\n", chars[i]);
    }
    fclose(fp_out);
    
    return 0;
}

// 测试验证方案：
//  1. 怎么运行：
//     - 构造测试用例：比如某点(i=10,j=15)周围是5，自身是8（差3>1），应被替换为5。
//     - 编译：gcc 14.c -o 14 ；运行生成output_denoise.txt。
//  2. 预期结果：
//     - 失真点被替换为邻居平均值（四舍五入后），符号变化符合映射规则（如8→# 变为5→=）。
//  3. 检查点：
//     - 手动验证测试用例的替换结果，边界点（如左上角）的邻居判断是否正确。
// 易错点提醒：
//  1. 忘记复制临时数组：直接修改data会导致后续判断用修改后的值，必须用temp保存原始值。
//  2. 邻居判断错误：如i-1 >=0 写成i-1 >0，漏掉上邻居。
//  3. 四舍五入错误：round_average函数中公式是否正确（如sum=7, count=2 → (7+1)/2=4，正确）。
// 拓展思考：
//  1. 若邻居数量为0（如1×1图像），如何处理？本题无需考虑，但可添加保护逻辑。
//  2. 能否支持8邻域（含对角线）？修改邻居判断逻辑，增加四个对角线方向。
//  3. 对比值传递与指针：round_average用值传递，函数内修改不影响外部，此处逻辑正确。