/* 
 * running.c -- 跑步数据转换程序，核心演示：
 * 教程知识点覆盖：
 *  1. 类型转换（强制转换、隐式转换）：解决“整数/浮点数混用”的需求 
 *  2. 表达式计算：多变量参与的复杂公式（距离、速度、配速计算 ）
 *  3. 变量作用域：全局常量 vs 局部变量 
 *  4. 问题兼容性：强制转换让程序在老旧编译器也能运行（呼应教程里“类型转换稳定性” ）
 */
#include <stdio.h>

// 全局常量（教程里“符号常量”的应用）：用大写命名强调不可修改
// 1分钟的秒数（60秒），用于时间转换 
const int S_PER_M = 60;  
// 1小时的秒数（60*60=3600秒），用于速度计算（英里/小时）
const int S_PER_H = 3600;  
// 1公里的英里数（约0.62137英里），用于距离转换（公里→英里）
const double M_PER_K = 0.62137;  

int main(void)
{
    // 跑过的距离：distk（公里）、distm（英里）
    double distk, distm;  
    // 平均速度（英里/小时）
    double rate;  
    // 跑步用时：min（分钟）、sec（秒）
    int min, sec;  
    // 总用时（秒）：把分钟和秒合并成“秒数”，方便计算
    int time;  
    // 跑1英里的时间（秒）：用于配速计算（时间/距离）
    double mtime;  
    // 配速的分钟数：mmin = 总时间（秒）÷ 每英里秒数 → 取整
    int mmin;  
    // 配速的秒数余数：msec = 总时间（秒）% 每英里秒数 → 剩余秒数
    int msec;  

    // 程序功能说明（教程里“用户交互”的体现）
    printf("This program converts your time for a metric race\n");
    printf("to a time for running a mile and to your average\n");
    printf("speed in miles per hour.\n");
    printf("Please enter, in kilometers, the distance run.\n");
    // %lf 读取double类型：distk 存用户输入的公里数
    scanf("%lf", &distk);  

    printf("Next enter the time in minutes and seconds.\n");
    printf("Begin by entering the minutes.\n");
    // %d 读取int类型：min 存分钟数
    scanf("%d", &min);  
    printf("Now enter the seconds.\n");
    // %d 读取int类型：sec 存秒数
    scanf("%d", &sec);  


    // ------------------ 核心计算1：总用时（秒） ------------------
    // 教程知识点：隐式类型转换（int + int → int）
    // min*S_PER_M 是“分钟→秒”，加上 sec 得到总秒数
    time = S_PER_M * min + sec;  


    // ------------------ 核心计算2：公里转英里（distk → distm） ------------------
    // 教程知识点：浮点型运算 + 隐式类型转换（double * double → double）
    // M_PER_K 是double，distk 是double → 结果distm（英里）是double
    distm = M_PER_K * distk;  


    // ------------------ 核心计算3：平均速度（英里/小时） ------------------
    // 教程知识点：复杂表达式 + 类型转换（时间、距离单位统一）
    // 逻辑：速度 = 总英里数 ÷ 总小时数 
    // 总小时数 = 总秒数（time） ÷ 3600（S_PER_H）
    // 这里用了“隐式类型转换”：time是int，S_PER_H是int → 相除后转double（因为rate是double）
    rate = distm / (time / (double)S_PER_H);  


    // ------------------ 核心计算4：配速（跑1英里的时间 → 分:秒） ------------------
    // 教程知识点：强制类型转换（解决“整数除法丢失精度”问题）
    // 逻辑：跑1英里的时间（秒）= 总时间（秒） ÷ 总英里数 
    // 用 (double)time 强制把int转double → 避免整数除法（否则time/distm会丢小数）
    mtime = (double)time / distm;  

    // 配速的分钟数：总秒数 ÷ 60（S_PER_M）→ 取整（用int截断小数）
    mmin = (int)mtime / S_PER_M;  
    // 配速的秒数余数：总秒数 % 60 → 剩余秒数（用int存）
    msec = (int)mtime % S_PER_M;  


    // ------------------ 结果输出（教程里“格式化输出”的应用） ------------------
    // 输出跑步距离、用时
    printf("You ran %.2f km (%.2f miles) in %d min, %d sec.\n",
           distk, distm, min, sec);
    // 输出配速（跑1英里的时间：分:秒）
    printf("That pace corresponds to running a mile in %d min, %d sec.\n",
           mmin, msec);
    // 输出平均速度（英里/小时，保留2位小数）
    printf("Your average speed was %.2f mph.\n", rate);  


    return 0;
}
/*
This program converts your time for a metric race
to a time for running a mile and to your average
speed in miles per hour.
Please enter, in kilometers, the distance run.
7 
Next enter the time in minutes and seconds.
Begin by entering the minutes.
30
Now enter the seconds.
26
You ran 7.00 km (4.35 miles) in 30 min, 26 sec.
That pace corresponds to running a mile in 6 min, 59 sec.
Your average speed was 8.58 mph.
*/