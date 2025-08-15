#include <stdio.h>
#define BOOK "War and Peace"

int main(void) {
    float cost = 12.99;
    float percent = 80.0;

    // 按要求输出：
    // This copy of "War and Peace" sells for $12.99.
    // That is 80% of list.
    printf("This copy of \"%s\" sells for $%.2f.\n", BOOK, cost);
    printf("That is %.1f%% of list.\n", percent);
    //  A%.0f%% gai  B%.1f%% 
    return 0;
}
/*
A
This copy of "War and Peace" sells for $12.99.
That is 80% of list.
B
This copy of "War and Peace" sells for $12.99.
That is 80.0% of list.
*/