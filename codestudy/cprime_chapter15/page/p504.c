
/*
 * 代码名称：位操作之整数末尾指定位翻转
 * 知识要点总结：
 *   1. 按位异或（`^`）：用于翻转二进制位（1变0，0变1）。
 *   2. 掩码（`mask`）构造：通过循环、按位或（`|`）、左移（`<<`），生成“末尾N位为1，其余为0”的掩码。
 *   3. 整数转二进制字符串：利用右移（`>>`）和掩码`01`逐位提取二进制位，转换为字符存储。
 *   4. 二进制字符串格式化：按“4位一组”打印，提升可读性。
 * 总体逻辑说明：
 *   程序分四部分：
 *   1. `itobs`：将整数转为二进制字符串，通过右移+掩码`01`提取每一位并转成字符。
 *   2. `show_bstr`：按4位一组打印二进制字符串，让结果更易读。
 *   3. `invert_end`：构造“末尾`bits`位为1”的掩码，用异或翻转整数末尾`bits`位。
 *   4. `main`：读取整数，先显示原始二进制，再翻转末尾4位并显示，直到输入非数字终止。
 */

#include <stdio.h>
#include <limits.h>  // 获取CHAR_BIT（char的位数，通常为8）

char *itobs(int n, char *ps);       // 整数转二进制字符串
void show_bstr(const char *str);    // 格式化显示二进制字符串
int invert_end(int num, int bits);  // 翻转整数末尾bits位

int main(void)
{
    char bin_str[CHAR_BIT * sizeof(int) + 1];  // 存二进制字符串（+1给'\0'）
    int number;

    puts("Enter integers and see them in binary.");
    puts("Non-numeric input terminates program.");

    while (scanf("%d", &number) == 1)  // 成功读入整数时循环
    {
        itobs(number, bin_str);        // 转二进制字符串
        printf("%d is\n", number);
        show_bstr(bin_str);            // 显示原始二进制
        putchar('\n');

        number = invert_end(number, 4); // 翻转末尾4位
        printf("Inverting the last 4 bits gives\n");
        itobs(number, bin_str);
        show_bstr(bin_str);            // 显示翻转后二进制
        putchar('\n');
        putchar('\n');
    }

    puts("Bye!");
    return 0;
}

char *itobs(int n, char *ps)
{
    const static int size = CHAR_BIT * sizeof(int); // int的总位数
    int i;

    for (i = size - 1; i >= 0; i--, n >>= 1)
    {
        ps[i] = (01 & n) + '0'; // 用01掩码提取最后一位，转成'0'或'1'
    }
    ps[size] = '\0'; // 字符串结束符
    return ps;
}

void show_bstr(const char *str)
{
    int i = 0;
    while (str[i])  // 遍历到'\0'为止
    {
        putchar(str[i]);
        if (++i % 4 == 0 && str[i]) // 每4位加一个空格（后面还有字符时）
            putchar(' ');
    }
}

int invert_end(int num, int bits)
{
    int mask = 0;
    int bitval = 1; // 从第0位（最右位）开始构造掩码

    while (bits-- > 0)
    {
        mask |= bitval;   // 当前bitval对应的位置1
        bitval <<= 1;     // bitval左移，准备下一位
    }
    return num ^ mask; // 异或翻转mask中为1的位
}


/*
 * 代码测试及验证建议方案：
 * 1. 测试正整数（如7）：
 *    输入`7`，原始二进制应显示`0000 0000 0000 0000 0000 0000 0000 0111`，
 *    翻转后4位应显示`0000 0000 0000 0000 0000 0000 0000 1000`，验证是否一致。
 * 2. 测试较大正整数（如12541）：
 *    输入`12541`，原始二进制应显示`0000 0000 0000 0011 0001 1110 0101`，
 *    翻转后4位应显示`0000 0000 0000 0011 0001 1110 0010`，验证是否一致。
 * 3. 测试负整数（如-1）：
 *    输入`-1`（二进制全1），翻转后4位应显示`1111 1111 1111 1111 1111 1111 1111 0000`，验证是否一致。
 * 4. 测试不同`bits`参数：
 *    修改`invert_end(number, 4)`为`invert_end(number, 2)`，输入`5`（二进制`0000 0000 0000 0000 0000 0000 0000 0101`），
 *    翻转后2位应显示`0000 0000 0000 0000 0000 0000 0000 0110`，验证是否一致。
 * 5. 测试边界值（如0）：
 *    输入`0`，原始二进制显示`0000 0000 0000 0000 0000 0000 0000 0000`，
 *    翻转后4位应显示`0000 0000 0000 0000 0000 0000 0000 1111`，验证是否一致。
 * 6. 测试非数字输入：
 *    输入字母（如`q`），验证程序是否输出`Bye!`并正常终止。
 */
