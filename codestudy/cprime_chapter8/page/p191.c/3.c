/*


### 四、【代码示例 3：把程序输出写入文件（模拟输出重定向）】  
**功能**：让程序输出（比如一段文本、计算结果）写入到文件里（替代屏幕输出）。  

```c
*/
/* 
 * 代码功能：
 * 1. 让用户输入文件名，尝试打开文件（写模式）
 * 2. 往文件里写一段内容（比如固定文本 + 用户输入拼接）
 * 
 * 知识点覆盖：文件写操作（fopen "w" 模式）、fprintf/fputc 写内容
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];  // 存用户输入的文件名  
    FILE *fp;            // 文件指针  
    char userText[50];   // 存用户想写入的内容  

    // 1. 获取文件名  
    printf("请输入要写入的文件名（比如 output.txt）：");  
    scanf("%s", filename);  

    // 2. 打开文件："w" 是“写模式”，文件存在会清空旧内容；不存在则创建  
    fp = fopen(filename, "w");  
    if (fp == NULL) {  
        printf("无法打开文件 %s 进行写入，请检查权限或路径！\n", filename);  
        exit(1);  
    }  

    // 3. 让用户输入一段内容  
    // 注意：前面用了 scanf 读文件名，缓冲区可能有残留换行，这里用 getchar 吃掉换行  
    getchar();  
    printf("请输入你想写入文件的内容（简单一行）：");  
    // fgets 会读一行（包括换行符），这里用它避免 scanf 不处理空格的问题  
    fgets(userText, 50, stdin);  

    // 4. 往文件里写内容（两种方式演示）  
    // 4.1 用 fprintf 格式化写入（类似 printf，但输出到文件）  
    fprintf(fp, "=== 自动添加的标题 ===\n");  
    // 4.2 用 fputs 直接写用户输入（也可用 fputc 逐字符写，看需求）  
    fputs(userText, fp);  

    // 5. 关闭文件（必须关！否则内容可能没真正写入磁盘）  
    fclose(fp);  

    printf("内容已成功写入文件 %s ！可以去查看文件验证～\n", filename);  

    return 0;  
}  
/*
```  

**代码注释细节**：  
- `fopen(filename, "w")`：  
  - `"w"` 模式：文件存在 → 清空原有内容；文件不存在 → 创建新文件。  
  - 如果要“追加内容”而不是覆盖，用 `"a"` 模式。  
- `fgets(userText, 50, stdin)`：  
  - 从键盘读一行内容，最多存 `49` 个字符（留 1 个给 `\0` 做字符串结束标志），解决 `scanf` 不识别空格、换行的问题。  
- `fprintf` vs `fputs`：  
  - `fprintf` 支持格式化（像 `printf` 那样带 `%d` `%s` 拼接内容）。  
  - `fputs` 直接写字符串，简单场景更方便。  


---
*/