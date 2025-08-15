#include <stdio.h>
// 一年秒数 
#define SECONDS_PER_YEAR 3.156e7 
int main() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Your age in seconds: %e\n", age * SECONDS_PER_YEAR);
    return 0;
}