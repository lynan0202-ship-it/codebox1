#include <stdio.h>
int main() {
    int ascii_code;
    printf("Enter an ASCII code value (e.g., 66): ");
    scanf("%d", &ascii_code);
    // %c 按字符格式输出 
    printf("The character is: %c\n", ascii_code); 
    return 0;
}