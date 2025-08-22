
// ------------------------------  
// 题干：下面的变量对哪些函数可见？程序是否有误？  
// /* 文件1 */  
// int daisy;  
// int main(void) { int lily; ... }  
// int petal() { extern int daisy, lily; ... }  
// /* 文件2 */  
// extern int daisy; static int lily; int rose;  
// int stem() { int rose; ... } void root() { ... }  
// 知识要点：  
//  1. 全局/局部/静态全局变量的作用域 + 链接属性  
//  2. extern的用法（只能引用**全局变量**，不能引用局部变量）  
// 总体逻辑：  
//  1. 分析每个变量的可见范围  
//  2. 找出核心错误：`petal()`中`extern int lily`非法（lily是main的局部变量）  

// ------ 文件1：file1.c ------  
int daisy; // 全局变量（外部链接，跨文件可见）  

int main(void) {  
    int lily; // 局部变量，仅main可见  
    return 0;  
}  

int petal() {  
    extern int daisy; // 合法（引用文件1的全局daisy）  
    extern int lily;  // 非法！lily是main的局部变量，作用域不在petal，extern无法引用  
    // 编译报错：未定义标识符lily  
    return 0;  
}  

// ------ 文件2：file2.c ------  
extern int daisy;    // 合法（引用文件1的全局daisy）  
static int lily;     // 静态全局（内部链接，仅file2可见）  
int rose;            // 全局变量（外部链接，跨文件可见）  

int stem() {  
    int rose; // 局部变量，屏蔽全局rose，仅stem可见  
    return 0;  
}  

void root() {  
    // 可见：daisy（extern引用）、lily（file2的静态全局）、rose（全局，未被屏蔽时）  
    return;  
}  

// 测试验证方案（编译看报错）：  
//  1. 怎么运行：编译两个文件（如 `gcc file1.c file2.c -o 7`）  
//  2. 预期结果：编译报错（提示`petal()`中`lily`未定义）  
//  3. 检查点：  
//     - 错误点：`extern`不能引用**局部变量**（lily是main的局部变量）  
//     - 可见性总结：  
//       → daisy：main、petal、file2的stem/root可见（file2用extern声明后）  
//       → lily（main局部）：仅main可见，petal的extern声明非法  
//       → lily（file2静态全局）：仅file2的stem/root可见  
//       → rose（全局）：file2的root可见，stem中被局部rose屏蔽  
// 易错点提醒：  
//  1. 混淆“局部变量”和“全局变量”的extern用法（extern只能引全局）  
//  2. 静态全局（file2的lily）和局部变量（stem的rose）的**屏蔽效应**  
// 拓展思考：  
//  1. 如果file2的lily想被file1访问，怎么改？→ 去掉`static`（改为普通全局）  
// 对比说明：  
//  局部变量 vs 全局变量的extern：  
//  - 局部变量：作用域仅限函数/块，extern无法引用  
//  - 全局变量：extern可跨文件引用（普通全局），或仅限
//本文件（静态全局）  
