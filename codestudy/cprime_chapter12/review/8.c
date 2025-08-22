// ------------------------------  
// 题干：下面程序会打印什么？  
// #include <stdio.h>  
// char color = 'B'; void first(void); void second(void);  
// int main(void) { extern char color; ... first(); ... second(); ... }  
// void first(void) { char color; color='R'; ... }  
// void second(void) { color='G'; ... }  
// 知识要点：  
//  1. 全局变量 vs 局部变量的**屏蔽效应**  
//  2. extern的作用（引用全局变量，可省略但语义明确）  
//  3. 变量的**存储期**（全局变量全程存在）  
// 总体逻辑：  
//  1. 全局color初始为'B'  
//  2. main用extern引用全局color → 打印'B'  
//  3. first定义局部color → 屏蔽全局，修改局部为'R' → 打印'R'  
//  4. second未定义局部color → 修改**全局color**为'G' → 打印'G'  
//  5. main再次打印全局color → 输出'G'  
#include <stdio.h>  

char color = 'B'; // 全局变量，全程存在，初始'B'  
void first(void);  
void second(void);  

int main(void) {  
    extern char color; // 引用全局color（可省略，语义强调）  
    printf("color in main() is %c\n", color); // 输出：B  

    first(); // 调用first，内部有局部color  
    printf("color in main() is %c\n", color); // 全局color未变 → B  

    second(); // 调用second，修改全局color  
    printf("color in main() is %c\n", color); // 全局color已改 → G  

    return 0;  
}  

void first(void) {  
    char color; // 定义局部color，**屏蔽全局color**  
    color = 'R'; // 修改局部color，不影响全局  
    printf("color in first() is %c\n", color); // 输出：R  
}  

void second(void) {  
    // 未定义局部color → 操作**全局color**  
    color = 'G'; // 修改全局color为'G'  
    printf("color in second() is %c\n", color); // 输出：G  
}  

// 测试验证方案：  
//  1. 怎么运行：gcc编译后运行（如 `gcc 8.c -o 8 && ./8`）  
//  2. 预期输出：  
//     color in main() is B  
//     color in first() is R  
//     color in main() is B  
//     color in second() is G  
//     color in main() is G  
//  3. 检查点：  
//     - first的局部color是否屏蔽全局？（是，输出R）  
//     - second是否修改全局color？（是，main第三次输出G）  
// 易错点提醒：  
//  1. 误以为first里的color是全局变量（实际是局部，屏蔽全局）  
//  2. 忽略second未定义局部color，直接修改全局  
// 拓展思考：  
//  1. 如果second也定义局部color（`char color='Y';`），全局color会变吗？→ 不会，修改的是局部  
// 对比说明：  
//  局部变量的屏蔽 vs 全局变量的修改：  
//  - 局部变量：定义后屏蔽全局，修改仅影响自身  
//  - 全局变量：未定义局部时，修改会影响整个程序  
//  extern的意义：  
//  - 本文件中可省略，但跨文件时必须用extern引用全局变量