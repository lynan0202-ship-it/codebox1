#include <stdio.h>

int main(void) 

{
    int myage;
    int myday;
    int mybirth_month;
    int now_month;

    mybirth_month=2;
    myage=23;
    now_month=8;
    myday=myage*365+(now_month-mybirth_month)*30;

    printf ("myday is %d",myday);
    return 0;

}