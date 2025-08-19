/* 
代码名称：scan_str.c（教材程序清单11.11实现）
知识要点总结：
1. scanf("%s") 特性：以空白字符（空格/换行/制表符）作为字符串结束标志，读取“单词”而非整行
2. 字段宽度用法：%5s 表示最多读取5个字符（剩余位置存'\0'），可防止缓冲区溢出
3. 返回值规则：返回成功读取的项数（如两个%s都读成功则返回2），读到文件尾返回EOF
4. 与gets/fgets的区别：scanf按空白分割，后两者按换行分割；scanf需手动设字段宽度防溢出
5. 数组大小要求：必须比字段宽度大1（预留'\0'的位置，如%5s需至少6字节空间）

代码总体逻辑：
1. 定义两个字符数组：name1[11]（适配%5s，存5字符+'\0'）、name2[11]（适配%10s，存10字符+'\0'）
2. 提示用户输入两个名字
3. 调用 scanf("%5s %10s", ...)：
   - 对name1：最多读5个字符，遇到空白停止
   - 对name2：最多读10个字符，从name1读取结束的位置继续读
4. 输出scanf返回的项数，以及两个数组存储的内容（展示字段宽度的截断效果）
*/

#include <stdio.h>

int main(void)
{
    // name1数组大小11：%5s最多存5个有效字符 + 1个'\0'（实际用了6字节，剩余5字节空闲，不影响）
    // name2数组大小11：%10s最多存10个有效字符 + 1个'\0'
    char name1[11], name2[11];  
    int count;  // 记录scanf成功读取的项数

    printf("Please enter 2 names.\n");
    // 格式说明：
    // %5s → 从输入读最多5个字符到name1（遇到空白就停，即使没到5个）
    // %10s → 从name1读取结束的位置继续读，最多10个字符到name2
    count = scanf("%5s %10s", name1, name2);  

    // 输出结果：
    // count为2时，两个名字都成功读取；若输入不足2项，count会小于2，name2可能是未初始化的垃圾值
    printf("I read the %d names %s and %s.\n", count, name1, name2);

    return 0;
}

/* 
代码测试及验证建议方案：
1. 正常截断测试（教材示例1）：
   输入：Jesse Jukes（Jesse是5字符，Jukes是5字符）
   预期：count=2，输出"I read the 2 names Jesse and Jukes."

2. 超长名称截断测试（教材示例2）：
   输入：Liza Applebotham（Applebotham共12字符，%10s取前10个→Applebotth）
   预期：count=2，输出"I read the 2 names Liza and Applebotth."

3. 跨字段连续读取测试（教材示例3）：
   输入：Portensia Callowit（Portensia是9字符，%5s取前5个→Porte；剩余"nsia"被%10s读取）
   预期：count=2，输出"I read the 2 names Porte and nsia."

4. 输入不足测试（验证返回值）：
   输入：OnlyOne（只输入1个单词）
   预期：count=1，name2内容为随机值（未初始化），观察输出变化

5. 溢出风险对比测试（突出字段宽度的意义）：
   ① 将格式改为"%s %s"，数组仍用11字节
   ② 输入超长字符串（如"VeryVeryLongName1 VeryVeryLongName2"，超过10字符）
   ③ 观察程序行为（可能崩溃或输出异常，对比带字段宽度的安全情况）

6. 空白字符测试（验证scanf的分割规则）：
   输入："  Alex   Bob  "（前后有空格，中间多个空格）
   预期：name1=Alex（跳过前导空格，读5字符内的单词），name2=Bob（跳过中间空格）

易错点提醒：
- 数组大小必须≥字段宽度+1！例如%10s需要至少11字节，否则'\0'会覆盖其他内存
- scanf不会清理输入流中剩余的字符！如果输入超长，多余字符会留在缓冲区，影响后续输入
- 若输入项数不足，未读取的数组内容是随机值（如测试4中的name2），需额外判断返回值处理
*/