
// ------------------------------
// 题干：编写一个函数，提示用户输入日、月和年。月份可以是月份号、月份名或月份名缩写。然后该程序应返回一年中到用户指定日子（包括这一天）的总天数。
// 知识要点：
//  1. 字符串比较函数 `strcmp` 的使用（判断月份名/缩写是否匹配）
//  2. 闰年的判断逻辑（能被4整除但不能被100整除，或能被400整除）
//  3. 多分支结构（处理月份号、全名、缩写三种输入形式）
//  4. 数组的使用（存储月份全名、缩写、每月天数）
//  5. 函数的定义与调用（拆分功能为多个辅助函数，如判断闰年、获取月份天数等）
// 总体逻辑：
//  1. 定义 `isLeapYear` 函数判断闰年，`getMonthDays` 函数根据月份和是否闰年来获取天数，`findMonthNum` 函数根据输入的月份形式找月份号。
//  2. 主函数中提示用户输入日、月（支持号/名/缩写）、年。
//  3. 调用 `findMonthNum` 得到月份号，再验证日期合法性（月份范围、天数是否符合该月）。
//  4. 计算总天数：累加指定月份之前所有月份的天数，再加上指定的日数。
//  5. 输出总天数或错误提示（如日期不合法）。
#include <stdio.h>
#include <string.h>  // 用于 strcmp 函数

// 判断是否为闰年：能被4整除但不能被100整除，或能被400整除返回1，否则返回0
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

// 根据月份号和是否闰年，返回该月的天数
int getMonthDays(int month, int isLeap) {
    // 每月天数（非闰年，二月28天）
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeap) {  // 二月且是闰年，返回29天
        return 29;
    }
    return days[month - 1];  // 月份号从1开始，数组索引从0开始，所以减1
}

// 根据输入的月份形式（号/名/缩写），返回月份号（1-12），若无效返回0
int findMonthNum(char monthInput[]) {
    // 存储12个月的全名和缩写
    char fullNames[12][10] = {"January", "February", "March", "April", "May", "June",
                             "July", "August", "September", "October", "November", "December"};
    char abbrNames[12][5] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int i;

    // 先尝试按月份号解析（如果输入是数字字符串）
    int monthNum = 0;
    sscanf(monthInput, "%d", &monthNum);  // 尝试把输入转成数字
    if (monthNum >= 1 && monthNum <= 12) {
        return monthNum;
    }

    // 再尝试按全名匹配
    for (i = 0; i < 12; i++) {
        if (strcmp(monthInput, fullNames[i]) == 0) {
            return i + 1;  // 数组索引i对应月份号i+1（如i=0是1月）
        }
    }

    // 最后尝试按缩写匹配
    for (i = 0; i < 12; i++) {
        if (strcmp(monthInput, abbrNames[i]) == 0) {
            return i + 1;
        }
    }

    return 0;  // 输入无效，返回0
}

// 计算从年初到指定日期的总天数
int calculateTotalDays(int day, char monthInput[], int year) {
    int month = findMonthNum(monthInput);  // 获取月份号
    int isLeap = isLeapYear(year);         // 判断是否为闰年

    // 验证月份和日期是否合法
    if (month == 0) {
        printf("月份输入无效！\n");
        return -1;  // 表示错误
    }
    int maxDay = getMonthDays(month, isLeap);
    if (day < 1 || day > maxDay) {
        printf("日期%d在%d月不合法（该月最多%d天）！\n", day, month, maxDay);
        return -1;
    }

    int totalDays = 0;
    // 累加前面所有月份的天数
    for (int m = 1; m < month; m++) {
        totalDays += getMonthDays(m, isLeap);
    }
    // 加上当月的天数
    totalDays += day;

    return totalDays;
}

int main() {
    int day, year;
    char monthInput[20];  // 存储输入的月份（名/缩写/号）

    printf("请输入日：");
    scanf("%d", &day);
    printf("请输入月（可以是月份号、全名或缩写，例如 3、March、Mar）：");
    scanf("%s", monthInput);
    printf("请输入年：");
    scanf("%d", &year);

    int result = calculateTotalDays(day, monthInput, year);
    if (result != -1) {
        printf("从年初到%d年%s%d日的总天数是：%d\n", year, monthInput, day, result);
    }

    return 0;
}

// 测试验证方案：
//  1. 怎么运行：使用C语言编译器（如GCC）编译代码（命令示例：`gcc 文件名.c -o test`），然后运行可执行文件（如`./test`）。
//  2. 预期结果：
//     - 输入：日=1，月=January，年=2023 → 输出“从年初到2023年January1日的总天数是：1”。
//     - 输入：日=28，月=2，年=2024（闰年）→ 输出“从年初到2024年228日的总天数是：59”（1月31 + 2月28 = 59）。
//     - 输入：日=29，月=Feb，年=2024 → 输出“从年初到2024年Feb29日的总天数是：60”（闰年二月29天，31+29=60）。
//     - 输入：日=31，月=4，年=2025 → 输出“日期31在4月不合法（该月最多30天）！”。
//     - 输入：月=Invalid → 输出“月份输入无效！”。
//  3. 检查点：重点验证不同月份形式（号、全名、缩写）是否正确识别，闰年二月天数是否正确，日期合法性判断是否准确，总天数累加是否正确。
// 易错点提醒：
//  1. 忘记包含 `<string.h>` 导致 `strcmp` 无法使用（编译报错）。
//  2. 月份号解析时，`sscanf` 处理非数字输入可能导致 `monthNum` 为0，需注意后续判断。
//  3. 闰年判断逻辑写错（比如漏了能被400整除的情况）。
//  4. 月份号和数组索引对应错误（比如把i=0当成1月，返回时要i+1）。
// 拓展思考：
//  1. 如何支持更灵活的输入格式？比如月份名大小写不敏感（可以先把输入和存储的月份名转成同一大小写再比较）。
//  2. 如果要计算任意两个日期之间的天数（跨年份），该如何扩展代码？
//  3. 如何优化 `findMonthNum` 函数，减少多次循环？（比如把全名和缩写存在同一个结构数组里，一次循环遍历）。
// 对比说明：
//  这里的函数参数传递，如 `isLeapYear(year)` 是**值传递**（把year的值拷贝给函数参数）；而 `findMonthNum(monthInput)` 中，`monthInput` 是字符数组，传递的是**数组首地址**（属于地址传递，函数内可以通过地址访问原数组内容）。值传递时函数内修改参数不影响外部变量，地址传递时函数内可以修改数组内容（这里只是比较，没修改）。