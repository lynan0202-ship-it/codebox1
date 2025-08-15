#include <stdio.h>
int main(void)
{
    int k;
    for (k = 1, printf("%d: Hi!\n", k);    printf("k = %d\n", k), k*k < 26;    k += 2, printf("Now k is %d\n", k))
        printf("k is %d in the loop\n", k);
    return 0;
}

/*
这段 C 语言代码中的for循环展示了 C 语言中for循环的几个重要特征，尤其是关于循环控制部分的灵活性：
for循环的核心特征
三部分结构的灵活性
for循环的标准结构是：for(初始化; 条件判断; 迭代更新)，但 C 语言允许这三部分中使用逗号表达式（,）执行多个语句：
初始化部分：k = 1, printf("%d: Hi!\n", k)
先将k赋值为 1，再执行打印语句
条件判断部分：printf("k = %d\n", k), k*k < 26
先执行打印，再通过k*k < 26判断是否继续循环（逗号表达式的值为最后一个表达式的值）
迭代更新部分：k += 2, printf("Now k is %d\n", k)
先将k增加 2，再执行打印语句
执行顺序严格固定
初始化部分：仅在循环开始时执行一次
条件判断部分：每次循环前执行，若为真则进入循环体
循环体执行后，执行迭代更新部分，然后再次回到条件判断，直到条件为假
循环体可以是单条语句
此处循环体是printf("k is %d in the loop\n", k)，因只有一条语句，所以省略了{}
为什么for循环中会有打印语句？



C 语言允许for循环的三个控制部分中放入任意合法表达式（包括函数调用），printf()本质是一个函数，因此可以出现在这些位置。
这段代码的打印语句执行顺序如下（实际运行结果）：



*/
/*
1: Hi!
k = 1
k is 1 in the loop
Now k is 3
k = 3
k is 3 in the loop
Now k is 5
k = 5
k is 5 in the loop
Now k is 7
k = 7
*/