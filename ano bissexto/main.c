#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ano, a, b, c;
    scanf("%d", &ano);
    a=ano%4;
    b=ano%100;
    c=ano%400;
    if(a==0&&b!=0||c==0)
    {
        printf("BISSEXTO\n");
    }
    else
    {
        printf("NAOBISSEXTO\n");
    }
    return 0;
}
