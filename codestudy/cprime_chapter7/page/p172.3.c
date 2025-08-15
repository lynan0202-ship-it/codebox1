/*
3. break 与 switch 的关联（教材 7.7 节知识点预埋）
*/
#include <stdio.h>

int main(void)
{
    char ch;
    printf("Enter a letter (q to quit): ");

    // 读取字符，直到输入 'q'
    while ((ch = getchar()) != 'q') {  
        // 处理换行符（避免残留输入影响）
        if (ch == '\n') continue;       

        // --------------------- switch 中 break 的作用（教材 7.7 节核心） --------------------- 
        switch (ch) {                   
            case 'a':
            case 'A':
                printf("Animal: Ant\n");
                // break：跳出 switch 分支，避免“贯穿到下一个 case”
                break;                   
            case 'b':
            case 'B':
                printf("Animal: Bear\n");
                break;
            default:
                printf("Unknown letter\n");
                // default 分支可省略 break（已到分支末尾）
        }

        // 提示用户继续输入
        printf("\nEnter next letter (q to quit): ");  
        // 清理输入缓冲区剩余字符（避免影响下次读取）
        while (getchar() != '\n') continue;  
    }

    printf("Quit program.\n");
    return 0;
}
/*
注释与知识点对应：
switch 中 break 的必要性：case 'A': ... break; → 没有 break，程序会 “贯穿” 执行后续 case（如 case 'A' 执行后，会继续执行 case 'B'），break 确保 “匹配一个 case 后跳出 switch”，覆盖教材 “switch 依赖 break 实现分支隔离” 的知识点。
与循环的结合：while ((ch = getchar()) != 'q') → switch 用于多分支判断，break 同时作用于 switch 分支和外层循环（输入 q 时，while 条件不满足自然退出）。
总结：注释串联教材核心知识点
基础用法：break 跳出当前所在循环 /switch，简化 “异常退出” 逻辑。
嵌套循环：仅影响当前层级循环，需多层 break 跳出外层循环。
与 switch 协同：break 是 switch 实现 “分支独立” 的关键，避免分支贯穿。
代码覆盖教材 break 基础用法、嵌套循环控制、switch 关联逻辑 等全部知识点，注释逐行对应教材描述，便于理解 break 在流程控制中的核心作用。
*/