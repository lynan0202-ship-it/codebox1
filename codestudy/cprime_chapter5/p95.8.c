//八、其他常用运算符（7 个 ，如 sizeof、逗号等 ）

#include <stdio.h>
// 自定义结构体演示 sizeof 
struct Student {
    int id; 
    char name[20]; 
};

int main() 
{
    int arr[5] = {1,2,3,4,5}; 
    struct Student stu = {1, "Tom"}; 

    // 1. 长度运算符 sizeof 
    // 功能：计算变量、类型所占字节数 
    printf("int 类型占 %zu 字节\n", sizeof(int)); // 通常 4 
    printf("arr 数组占 %zu 字节\n", sizeof(arr)); // 5*4=20 
    printf("结构体 Student 占 %zu 字节\n", sizeof(stu)); // 4 + 20 = 24（不同环境可能有内存对齐差异 ）

    // 2. 逗号运算符 , 
    // 功能：按顺序执行多个表达式，结果取最后一个表达式的值 
    int x = 1, y = 2; 
    int res_comma = (x++, y++, x + y); 
    printf("逗号运算结果：%d\n", res_comma); // x=2，y=3 → 5 

    // 3. 下标运算符 [] 
    // 功能：数组访问，arr[0] 等价于 *(arr + 0) 
    printf("数组 arr 第 3 个元素（下标 2）：%d\n", arr[2]); // 3 

    // 4. 成员访问运算符 . 和 ->（简单演示 ）
    // . 用于直接访问结构体成员 
    printf("结构体 stu 的 id：%d\n", stu.id); // 1 

    // 如果是指针访问结构体成员，用 -> 
    struct Student *p_stu = &stu; 
    printf("通过指针访问 stu 的 name：%s\n", p_stu->name); // Tom 

    // 5. 强制类型转换运算符 (type) 
    // 功能：把一个类型的值转成另一个类型（注意可能丢失精度 ）
    float f = 3.14; 
    int f_to_int = (int)f; 
    printf("float 转 int：%d\n", f_to_int); // 3（

}