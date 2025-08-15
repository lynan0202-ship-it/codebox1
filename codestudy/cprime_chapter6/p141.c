/* 
 * 程序名称：scores_inc.c
 * 程序功能：
 *  1. 读取 10 个高尔夫分数并存入数组  
 *  2. 验证输入数据（打印读取的分数）  
 *  3. 计算分数总和、平均分、差点（handicap）  
 *  体现的编程风格（对应教程讲解的“良好编程习惯”）：  
 *  - 用 #define 定义数组大小（SIZE）和标准杆（PAR），方便后续修改  
 *  - 用循环批量处理数组，避免重复写 10 次相同逻辑  
 *  - 拆分多个 for 循环实现“输入、验证、计算”，体现模块化思想  
 */
#include <stdio.h>
  
  // 定义数组大小（存储 10 个分数），如果要改存 20 个，只需修改这里！  
#define SIZE 10  
// 定义“标准杆”（计算差点时用），可根据规则调整  
#define PAR 72  

int main(void)
{
    // index：数组下标，用来遍历数组（从 0 到 SIZE-1）  
    int index;  
    // score：存储 10 个高尔夫分数的数组  
    int score[SIZE];  
    // sum：存储分数总和（用于计算平均分）  
    int sum = 0;  
    // average：存储平均分（需要小数，所以用 float 类型）  
    float average;  

    // 提示用户输入 10 个高尔夫分数  
    printf("Enter 10 golf scores:\n");  

    // 第 1 个 for 循环：读取用户输入的 10 个分数  
    // 逻辑：从下标 0 到 SIZE-1，逐个读取数据存入数组  
    for (index = 0; index < SIZE; index++)  
    {
        // &score[index]：把输入的值存入数组的对应下标位置  
        scanf("%d", &score[index]);  
    }

    // 打印提示，告诉用户接下来会输出“已读取的分数”（验证用）  
    printf("The scores read in are as follows:\n");  

    // 第 2 个 for 循环：验证输入（把数组里的数据打印出来，确认是否正确读取）  
    for (index = 0; index < SIZE; index++)  
    {
        // 逐个打印数组元素，检查输入是否正确  
        printf("%5d", score[index]);  
    }
    // 打印换行，让输出更整洁  
    printf("\n");  

    // 第 3 个 for 循环：计算分数总和  
    for (index = 0; index < SIZE; index++)  
    {
        // 把每个分数累加到 sum 里  
        sum += score[index];  
    }

    // 计算平均分：sum 是 int 类型，转成 float 做除法，避免整数除法丢失小数  
    average = (float)sum / SIZE;  

    // 输出总分、平均分（保留 2 位小数）  
    printf("Sum of scores = %d, average = %.2f\n", sum, average);  
    // 计算并输出差点：平均分 - 标准杆（PAR），保留 0 位小数  
    printf("That's a handicap of %.0f.\n", average - PAR);  

    return 0;
}

/*
Enter 10 golf scores:
99
67
66
34 
34
87
67
5
65
56
The scores read in are as follows:
   99   67   66   34   34   87   67    5   65   56
Sum of scores = 580, average = 58.00
That's a handicap of -14.
*/
