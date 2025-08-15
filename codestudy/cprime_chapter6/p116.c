/*  summming.c -- 根据用户输入指定输出*/
#include <stdio.h>
int main (void)
{
    long num;           // 用于存储用户输入的整数
    long sum = 0;       // 用于累加所有输入的整数，初始值为0
    int status;         // 用于存储scanf函数的返回值，判断输入是否成功

    // 提示用户输入一个整数用于求和，或输入q退出程序
    printf("Please enter an integer to be summed");
    printf("(q to quit)");
    
    // 尝试读取一个长整数，并将scanf的返回值存入status
    // scanf返回成功读取的数据项数，成功读取一个整数时返回1
    status = scanf("%ld", &num);
    
    // while循环的条件：当status等于1时继续循环
    // 即当成功读取到一个整数时，继续执行循环体内的累加操作
    while (status == 1)
    {
        sum = sum + num;  // 将读取到的整数累加到sum中
        
        // 提示用户输入下一个整数或q退出
        printf("Please enter next integer(q to quit):");
        
        // 再次尝试读取整数，并更新status的值
        status = scanf("%ld", &num);
    }
    
    // 当循环结束时，输出所有输入整数的总和
    printf("Those integers sum to %ld.\n", sum);

    return 0;
}
/*
Please enter an intefar to be summed(q to quit)2
Please enter next integer(q to quit):3
Please enter next integer(q to quit):4
Please enter next integer(q to quit):4
Please enter next integer(q to quit):3
Please enter next integer(q to quit):5
Please enter next integer(q to quit):6
Please enter next integer(q to quit):2
Please enter next integer(q to quit):6
Please enter next integer(q to quit):3
Please enter next integer(q to quit):q
Those integers sum to 38.
*/