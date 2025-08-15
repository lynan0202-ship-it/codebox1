#include <stdio.h>

int main() {
    int max_spaces = 5; // 最多的空格数
    
    for (int i = 1; i <= 5; i++) { 
        // 打印前置空格：最多5个 - 该行$的个数(i)
        for (int j = 0; j < max_spaces - i; j++) {
            printf(" ");
        }
        
        // 打印$符号，每行打印i个
        for (int k = 0; k < i; k++) {
            printf("$");
        }
        
        // 换行
        printf("\n"); 
    }
    return 0;
}
/*
    $
   $$
  $$$
 $$$$
$$$$$
*/