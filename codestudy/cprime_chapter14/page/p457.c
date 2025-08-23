/*
代码名称：names2.c
知识要点总结：
1. 结构体传值传递：函数参数直接使用结构体类型，调用时传递结构体副本（数据拷贝）
2. 结构体返回值：函数可直接返回整个结构体，实现数据回传
3. 对比指针版差异：
   - 指针版操作同一块内存，传值版每次传递/返回都产生数据拷贝（适合小结构体场景）
   - 传值时函数内修改的是副本，需通过返回值同步结果到主调函数
4. 输入处理复用：s_gets 函数保持与指针版一致，解决 fgets 换行符残留问题
5. 函数职责明确：通过"数据流动"方式（返回值→赋值→传递）完成功能，而非指针的"内存操作"

代码总体逻辑说明：
1. 主流程（main函数）：
   - 调用 getinfo() 获取用户输入的结构体（函数内部创建临时结构体，返回时拷贝数据）
   - 将返回的结构体赋值给 person
   - 调用 makeinfo(person) ：传递 person 的副本，计算名字总长度后返回新结构体，再赋值给 person
   - 调用 showinfo(person) ：传递 person 的副本，输出最终结果
2. 函数细节：
   - getinfo：内部创建局部结构体 temp，通过 s_gets 录入数据，以值传递方式返回整个结构体
   - makeinfo：接收结构体副本 info，计算名字总长度后，以值传递方式返回修改后的结构体
   - showinfo：接收结构体副本 info，仅用于输出（修改副本不影响原数据）
   - s_gets：通用输入处理函数，兼容指针版的输入逻辑
*/

#include <stdio.h>
#include <string.h>  // 提供strlen、strchr函数支持

#define NLEN 30      // 定义名字最大长度（包含字符串结束符）

// 定义结构体：存储名、姓、名字总字母数
struct namect {     
    char fname[NLEN]; // 名（字符数组）
    char lname[NLEN]; // 姓（字符数组）
    int letters;      // 名和姓的总字母数
};

// 函数声明
struct namect getinfo(void);          // 获取用户输入，返回结构体
struct namect makeinfo(struct namect info); // 计算名字长度，返回修改后的结构体
void showinfo(struct namect info);    // 输出结构体内容
char *s_gets(char *st, int n);        // 安全输入函数（处理换行符）

int main(void)
{
    struct namect person;  // 定义结构体变量，存储最终数据
    
    // 1. 获取用户输入：getinfo返回新结构体，赋值给person
    person = getinfo();
    
    // 2. 计算名字长度：传递person副本，返回修改后的结构体，重新赋值给person
    person = makeinfo(person);
    
    // 3. 输出结果：传递person副本，输出信息（不影响原数据）
    showinfo(person);
    
    return 0;
}

// getinfo：创建局部结构体，录入数据后返回（值传递）
struct namect getinfo(void)
{
    struct namect temp;  // 局部结构体，函数结束时会拷贝数据返回
    
    printf("Please enter your first name.\n");
    s_gets(temp.fname, NLEN);  // 直接访问结构体成员（. 运算符，因为temp是变量）
    
    printf("Please enter your last name.\n");
    s_gets(temp.lname, NLEN);
    
    return temp;  // 返回整个结构体（发生数据拷贝，temp的内容复制到调用处）
}

// makeinfo：接收结构体副本，计算长度后返回（值传递）
struct namect makeinfo(struct namect info)
{
    // 计算名和姓的总长度（strlen不包含字符串结束符）
    info.letters = strlen(info.fname) + strlen(info.lname);
    return info;  // 返回修改后的副本，调用处用该副本覆盖原数据
}

// showinfo：接收结构体副本，只读输出（修改副本不影响原数据）
void showinfo(struct namect info)
{
    printf("%s %s, your name contains %d letters.\n", 
           info.fname,   // 访问副本的成员
           info.lname,   // 访问副本的成员
           info.letters  // 访问副本的成员
    );
}

// s_gets：处理fgets的换行符和超长输入问题（与指针版完全一致）
char *s_gets(char *st, int n)
{
    char *ret_val = fgets(st, n, stdin);  // 读取一行，最多存储n-1个字符
    if (ret_val != NULL) {                // 读取成功时处理
        char *find = strchr(st, '\n');    // 查找换行符位置
        if (find != NULL) {               // 找到换行符
            *find = '\0';                 // 替换为字符串结束符，去除换行
        } else {                          // 未找到换行符（输入超长）
            while (getchar() != '\n') {   // 清空输入缓冲区剩余字符
                continue;
            }
        }
    }
    return ret_val;  // 返回fgets的结果（可能为NULL，如遇到EOF）
}

/*
代码测试及验证建议方案：
1. 传值特性验证：
   - 在makeinfo函数内添加 info.fname[0] = 'Z'; ，观察输出是否改变原person的fname（预期：不改变，因为修改的是副本）
   - 对比names1.c（指针版），修改指针指向的成员会影响原数据，体会传值与传指针的本质区别

2. 返回值验证：
   - 打印getinfo中temp的地址（printf("%p\n", &temp);）和main中person的地址（printf("%p\n", &person);），验证是否为不同地址（拷贝特性）
   - 测试链式调用：person = makeinfo(getinfo()); ，检查是否能正常运行（语法支持，因getinfo返回结构体可直接传参）

3. 性能对比（可选）：
   - 定义更大的结构体（如添加多个长字符数组），对比names1.c（指针版）和本版的运行时间，感知拷贝开销

4. 输入边界测试：
   - 输入超长名字（如30个字符），检查s_gets是否正确截断并清空缓冲区
   - 输入空行（直接回车），观察程序对空名字的处理逻辑

5. 易错点验证：
   - 尝试返回局部结构体的指针（如return &temp;），观察编译器警告（局部变量地址无效，值传递返回才安全）
   - 对比函数参数写法：struct namect info（传值） vs struct namect *info（传指针），明确语法差异
*/