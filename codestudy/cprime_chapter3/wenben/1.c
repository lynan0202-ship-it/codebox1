/*platform.c--your weight in platform*/
#include<stdio.h>
int main (void)
{   
    float weight;
    float value;

    printf("Are you worth youir weight in platinum?\n");
    printf("Let's check it out,\n");
    printf("Please enter your weight in pounds:");

/*获取用户输入          */  
    scanf ("%f", &weight);
/*假设白金的价格是每盎司1700美元       */
/*14.59833用于把英镑常衡盎司1转换为金衡盎司*/
    value =1700.0*weight*14.5833;

    printf("Your weight in platinum is worth $%.2f.\n",value);
    printf("You are easily worth that! If platinumn prices drop,\n");
    printf("eat more to maintain your value.\n");
}