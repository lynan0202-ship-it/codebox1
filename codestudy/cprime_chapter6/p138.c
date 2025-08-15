#include<stdio.h>
#define ROWS 7
#define CHARS 11

int main (void)
{
    int rows ;
    char ch;
    for (rows=0,ch='a';rows< ROWS ; rows++)
    {
        for (ch='a'; ch<='a'+ CHARS ; ch++)
        {
            printf("%c",ch);
        }
        printf("\n");
    }
    return 0;

}
/*
abcdefghijkl
abcdefghijkl
abcdefghijkl
abcdefghijkl
abcdefghijkl
abcdefghijkl
abcdefghijkl
*/