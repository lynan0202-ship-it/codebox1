#include <stdio.h>

int main() {
    for (int i = 1; i <= 5; i++) { 
        for (int k = 0; k < 5-i; k++)
            printf(" "); // 每次循环打印一个空格
        
        for (int j = 0; j < i; j++) 
            printf("$");
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

/*
     $
     $    $
     $    $   $
     $    $   $  $
     $    $   $  $ $
*/
/*
    $
   $$
  $$$
 $$$$
$$$$$
*/