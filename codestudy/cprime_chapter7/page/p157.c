// 程序功能：根据用电量(kwh)分段计算电费，演示 if - else 分支结构、#define 宏定义的用法
// 教程知识点覆盖：
// 1. #define 符号常量（费率、分界点、基础费用）的作用 
// 2. if - else 分支逻辑（含嵌套写法等价性）
// 3. else 与 if 的匹配规则（就近匹配原则）
// 4. 分段计费的实际场景应用

#include <stdio.h>

// --------------- 1. #define 宏定义（对应教程“用符号常量管理费率/分界点”）--------------- 
// 首次 360kwh 的费率
#define RATE1 0.13230    
// 接着 108kwh（360~468kwh）的费率
#define RATE2 0.15040    
// 接着 252kwh（468~720kwh）的费率
#define RATE3 0.30025    
// 超过 720kwh 部分的费率
#define RATE4 0.34025    
// 第1个分界点（360kwh）
#define BREAK1 360.0     
// 第2个分界点（360+108=468kwh）
#define BREAK2 468.0     
// 第3个分界点（468+252=720kwh）
#define BREAK3 720.0     

// --------------- 2. 基础费用计算（用宏提前算好“分段总费用”，简化主逻辑）--------------- 
// 360kwh 以内的总费用：360 * RATE1
#define BASE1 (RATE1 * BREAK1)  
// 360~468kwh 的总费用：BASE1 + 108*RATE2
#define BASE2 (BASE1 + (RATE2 * (BREAK2 - BREAK1)))  
// 468~720kwh 的总费用：BASE2 + 252*RATE3
#define BASE3 (BASE2 + (RATE3 * (BREAK3 - BREAK2)))  


int main(void)
{
    // 存储用户用电量（单位：kwh）
    double kwh;        
    // 存储计算后的电费
    double bill;       

    // 提示用户输入用电量
    printf("Please enter the kwh used.\n");  
    // %lf 对应 double 类型，读取用户输入的用电量
    scanf("%lf", &kwh);                      

    // --------------- 3. if - else 分支结构（教程核心：分段逻辑 + 嵌套等价性）--------------- 
    // 场景1：用电量 <= 360kwh，直接按 RATE1 计算
    if (kwh <= BREAK1)                      
        // 电费 = 用电量 * 费率1
        bill = RATE1 * kwh;                  
    // 场景2：用电量 > 360kwh 时进入 else，继续判断
    else if (kwh <= BREAK2) {               
        // 注释：对应教程“else 里嵌套 if - else”的等价写法
        // 电费 = 360kwh 基础费用 + 超出部分(360~468) * 费率2
        bill = BASE1 + (RATE2 * (kwh - BREAK1));  
    }
    // 场景3：用电量 > 468kwh 时进入 else，继续判断
    else if (kwh <= BREAK3) {               
        // 电费 = 468kwh 基础费用 + 超出部分(468~720) * 费率3
        bill = BASE2 + (RATE3 * (kwh - BREAK2));  
    }
    // 场景4：用电量 > 720kwh 时进入 else
    else {                                  
        // 电费 = 720kwh 基础费用 + 超出部分(>720) * 费率4
        bill = BASE3 + (RATE4 * (kwh - BREAK3));  
    }

    // 输出结果：用电量（保留1位小数）、电费（保留2位小数）
    printf("The charge for %.1f kwh is $%.2f.\n", kwh, bill);  

    return 0;
}


// --------------- 4. 教程知识点补充（代码外逻辑，用注释说明）--------------- 
/* 
 * 1. #define 作用：
 *    - 用符号常量替代魔法数，修改费率/分界点时只需改宏定义，无需改主逻辑
 *    - 编译器预处理阶段会直接替换宏（如 BASE1 替换为 (0.13230 * 360.0) ）
 * 
 * 2. if - else 嵌套与 else if 等价性：
 *    教程提到“else if 是 if - else 嵌套的简写”，以下是等价写法验证：
 *    // 原 else if 逻辑的嵌套形式（可替换主逻辑测试）
 *    else {
 *        if (kwh <= BREAK2) {
 *            bill = BASE1 + (RATE2 * (kwh - BREAK1));
 *        } else if (kwh <= BREAK3) {
 *            bill = BASE2 + (RATE3 * (kwh - BREAK2));
 *        } else {
 *            bill = BASE3 + (RATE4 * (kwh - BREAK3));
 *        }
 *    }
 *    两种写法功能完全一致，else if 更简洁直观。
 * 
 * 3. else 与 if 的匹配规则：
 *    编译器遵循“就近匹配”原则，else 会匹配离它最近的、未被匹配的 if。
 *    若要强制改变匹配关系，需用 {} 明确代码块（如教程提到“花括号可以清晰分组”）。
 * 
 * 4. 扩展性：
 *    若要新增“夏季超 720kwh 加 10% 费用”，可在最后 else 里扩展：
 *    bill = BASE3 + (RATE4 * (kwh - BREAK3)) * 1.1; 
 */