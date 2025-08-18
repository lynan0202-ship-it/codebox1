/*
### 三、【代码示例 2：简单用户交互（猜数字简化版）】  
**功能**：模拟基础用户交互流程，让用户输入数字，程序判断大小（可扩展成完整猜数字游戏）。  
*/
/* 
 * 代码功能：
 * 1. 生成一个简单“目标值”（这里直接写死，可扩展成随机数）
 * 2. 让用数字，程序判断输入是否合理、与目标值大小关系
 * 
 * 知识点覆盖：scanf 输入、printf 输出、if 条件判断、流程控制
 */

#include <stdio.h>

int main() {
    // 目标值（可后续用 rand() 改成随机数，这里简化演示）  
    int target = 7;  
    int userInput;   // 存用户输入的数字  

    printf("=== 简单猜数字游戏 ===\n");  
    printf("规则：猜一个 1~10 的整数，看是否接近目标值！\n\n");  

    // 让用户输入，直到输入合法数字  
    printf("请输入你猜的数字（1~10 之间）：");  
    // %d 匹配整数，&userInput 要加 & 取地址，否则 scanf 无法修改变量  
    if (scanf("%d", &userInput) != 1) {  
        printf("错误！请输入合法整数！\n");  
        // 简单处理：输入不对直接退出（实际项目可循环让用户重新输）  
        return 1;  
    }  

    // 判断输入范围  
    if (userInput < 1 || userInput > 10) {  
        printf("你输入的数字 %d 超出范围啦！必须是 1~10 之间的数哦～\n", userInput);  
        return 1;  
    }  

    // 判断与目标值的关系  
    if (userInput == target) {  
        printf("恭喜！猜对啦！目标值就是 %d ！\n", target);  
    } else if (userInput < target) {  
        printf("你猜小啦！目标值比 %d 大～\n", userInput);  
    } else {  
        printf("你猜大啦！目标值比 %d 小～\n", userInput);  
    }  

    return 0;  
}  
/*
```  

**代码注释细节**：  
- `scanf("%d", &userInput)`：  
  - `&userInput` 是“取地址符”，必须加！否则 `scanf` 无法把输入值存到变量里。  
  - 返回值是“成功读取的变量个数”，如果用户输入字母/符号，返回值不是 `1`，可用来判断输入是否合法。  
- `if (userInput < 1 || userInput > 10)`：简单做输入范围校验，避免用户乱输导致逻辑错误。  


---
*/