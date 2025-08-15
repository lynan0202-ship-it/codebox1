#define MESS "COMPUTER BYTES DOG"
#include <stdio.h>
int main(void) {
    int n = 0;
    while (n < 5) {
        printf("%s\n", MESS);
        n++;
        printf("That's all.\n");
    }
    return 0;

}
/*
COMPUTER BYTES DOG0
That's all.
COMPUTER BYTES DOG1
That's all.
COMPUTER BYTES DOG2
That's all.
COMPUTER BYTES DOG3
That's all.
COMPUTER BYTES DOG4
That's all.
*/