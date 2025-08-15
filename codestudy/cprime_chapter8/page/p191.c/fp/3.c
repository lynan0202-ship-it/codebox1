/*
### 五、完整示例代码（带详细注释）  
 * 功能：用文件指针实现文件读写
 * 步骤：打开文件 → 写入内容 → 重新打开读取 → 关闭文件
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;  // 文件指针
    char text[] = "Hello, 文件指针！";  // 要写入的内容

    // 第一步：以写模式打开文件（创建或清空文件）
    fp = fopen("demo.txt", "w");
    if (fp == NULL) {
        printf("创建文件失败！\n");
        exit(1);
    }

    // 第二步：往文件中写入内容
    fprintf(fp, "%s", text);  // 用 fprintf 写字符串
    printf("已写入内容：%s\n", text);
    fclose(fp);  // 写完先关闭
    fp = NULL;

    // 第三步：以读模式打开文件，验证写入结果
    fp = fopen("demo.txt", "r");
    if (fp == NULL) {
        printf("读取文件失败！\n");
        exit(1);
    }

    // 第四步：读取文件内容并打印
    printf("读取到的内容：");
    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    printf("\n");

    // 第五步：关闭文件
    fclose(fp);
    fp = NULL;
    printf("操作完成！\n");

    return 0;
}
/*
```  


### 六、学习建议  
1. **亲手调试**：运行上面的代码，修改文件名或内容，观察结果变化。  
2. **故意犯错**：比如不写 `fclose`、用错误的打开模式，看看程序会出现什么问题。  
3. **逐步扩展**：尝试用 `fgets` 读一行、`fputs` 写一行，熟悉更多文件操作函数。  

文件指针是 C 语言文件操作的核心，掌握它后，就能轻松实现读取配置文件、保存程序数据等功能啦！
*/
/*
已写入内容：Hello, 文件指针！
读取到的内容：Hello, 文件指针！
操作完成！
*/