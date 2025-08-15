#include<stdio.h>
int main (void)
{
int value = 36;
while (value > 0) {
    printf("%3d", value);
    value /= 2;
}
return 0 ;
}
/*
 36 18  9  4  2  1
*/