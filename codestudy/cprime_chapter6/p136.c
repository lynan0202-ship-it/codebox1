#include <stdio.h>
int main (void)
{
    const int secret_code = 13;
    int code_entered;

    do
    {
        printf("To enter the triskaidekaphobia therapy club,\n");
        printf("please enter the secret code number :");
        scanf("%d",&code_entered);

    }
    while 
    (
        code_entered!=secret_code
    );
    printf("congratulation! you are cured");

    return 0;

}
/*
To enter the triskaidekaphobia therapy club,
please enter the secret code number :4
To enter the triskaidekaphobia therapy club,
please enter the secret code number :5
To enter the triskaidekaphobia therapy club,
please enter the secret code number :13
congratulation! you are cured
*/