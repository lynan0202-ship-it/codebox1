/* 
知识要点与总体逻辑说明：
1. 核心场景：实现一个简单猜数字游戏，程序猜数字，用户通过输入'y'(正确)、'n'(错误)反馈
2. 涉及问题与解决：
   - 原始问题：用户输入含换行符、多字符（如输入"no"）时，程序误判（把换行符、多余字符当有效输入）
   - 第一次优化：用嵌套 while 循环处理多余输入（吃掉换行符、多余字符），避免程序逻辑混乱
   - 第二次优化：增加输入校验，区分合法输入（'y'/'n'）和非法输入，让程序更健壮
3. 关键技术：
   - 字符输入函数 getchar() 的使用与特性（处理缓冲输入、换行符残留问题）
   - while 循环控制流（处理输入、跳过无效内容）
   - if-else 分支处理多条件判断（区分合法/非法输入）
4. 代码逻辑：
   程序先尝试猜测数字，根据用户输入 'y'/'n' 调整猜测逻辑，逐步优化输入处理，让交互更友好 
*/

#include <stdio.h>

int main(void)
{
    /*
    // 1. 原始版本（教材程序清单 8.4）：存在输入处理问题
    // 问题：用户输入含换行符、多字符时，程序会误读，导致逻辑异常
    // 示例逻辑：程序从1开始猜，用户输入'y'表示猜对，'n'表示猜错
    {
        int guess = 1;
        printf("----- 原始版本（未优化输入） -----\n");
        printf("Pick an integer from 1 to 100. I will try to guess it.\n");
        printf("Respond with a y if my guess is right and with an n if it is wrong.\n");
        printf("Uh...is your number %d?\n", guess);
        // 问题点：getchar() 会读取用户输入的换行符，导致循环异常
        // 比如用户输入'n'后按回车，getchar() 会先读'n'，后续还会读'\n'
    /*
        while (getchar() != 'y') 
        {
            printf("Well, then, is it %d?\n", ++guess);
        }
        printf("I knew I could do it!\n\n");
    }


    // 2. 第一次优化：处理换行符和多余输入（吃掉换行符、多字符内容）
    // 优化点：用嵌套 while 循环，跳过输入行剩余内容（包括换行符、多字符）
    // 解决问题：用户输入"no"等多字符时，程序不会误判多个输入
    {
        int guess = 1;
        printf("----- 第一次优化（处理换行符/多字符输入） -----\n");
        printf("Pick an integer from 1 to 100. I will try to guess it.\n");
        printf("Respond with a y if my guess is right and with an n if it is wrong.\n");
        printf("Uh...is your number %d?\n", guess);
        
        // 外层循环：判断用户核心反馈（是否猜对）
        while (getchar() != 'y') 
        {
            // 内层循环：跳过当前输入行剩余的所有字符（直到遇到换行符）
            // 作用：处理像"no"这类多字符输入，避免程序误读后续字符
            while (getchar() != '\n') 
                continue;  // 跳过本行剩余内容，直到换行符
            
            printf("Well, then, is it %d?\n", ++guess);
        }
        printf("I knew I could do it!\n\n");
    }
    */

    // 3. 第二次优化：区分合法输入（y/n）与非法输入
    // 优化点：增加字符变量存储响应，用 if-else 处理非法输入（非'y'/'n'的情况）
    // 解决问题：用户输入其他字符（如'f'）时，程序给出提示，而非直接当'n'处理
    
     int guess = 1;
        char response;  // 存储用户输入的响应字符
        printf("----- 第二次优化（区分合法/非法输入） -----\n");
        printf("Pick an integer from 1 to 100. I will try to guess it.\n");
        printf("Respond with a y if my guess is right and with an n if it is wrong.\n");
        printf("Uh...is your number %d?\n", guess);
        
        // 外层循环：获取用户响应，判断是否为'y'（猜对）
        // 同时把输入的字符存入 response，方便后续校验
        while ((response = getchar()) != 'y') 
        {
            // 跳过当前输入行剩余的所有字符（直到遇到换行符）
            // 作用：清理输入缓冲区，避免残留字符影响后续输入
            while (getchar() != '\n') 
                continue;
            
            // 区分合法输入（n）和非法输入（其他字符）
            if (response == 'n') 
            {
                // 合法输入'n'：继续猜下一个数字
                printf("Well, then, is it %d?\n", ++guess);
            } 
            else 
            {
                // 非法输入：提示用户只能输入'y'或'n'
                printf("Sorry, I understand only y or n.\n");
            }
        }

        printf("I knew I could do it!\n\n");
    

    return 0;
}

/* 
代码执行与验证建议：
1. 原始版本测试：
   - 输入'n'后按回车，观察程序是否连续打印两次猜测（因为读了'n'和'\n'）
   - 输入"no"，看程序是否误判为两次输入，导致猜测逻辑异常
2. 第一次优化测试：
   - 输入"no"后按回车，程序应只响应一次，跳过多余字符
   - 输入'n' + 回车，程序正常处理，不重复响应
3. 第二次优化测试：
   - 输入'f'（非法字符），程序应提示"Sorry, I understand only y or n."
   - 输入"no way"，程序应正确识别'n'为合法输入，跳过剩余字符

通过对比三个版本的运行效果，能清晰理解：
- 缓冲输入（getchar()）的特性（换行符会残留、多字符输入需清理）
- 如何用循环/分支优化输入处理，让程序交互更健壮、友好 
*/

/*
### 代码与教材知识点对应说明
1. **原始版本**：对应教材“程序清单 8.4”，演示 **缓冲输入的问题**（换行符残留、多字符输入误读）。  
2. **第一次优化**：对应教材“用 while 循环丢弃输入行剩余内容”，解决 **换行符、多字符干扰问题**，让程序能正确区分单次输入。  
3. **第二次优化**：对应教材“用 if 语句筛选响应”，增加 **非法输入校验**，让程序能识别并提示用户正确输入格式。  

通过注释和分阶段演示，能帮你清晰梳理“输入处理问题→优化思路→代码实现”的完整逻辑，匹配教材从基础到优化的教学节奏。
*/