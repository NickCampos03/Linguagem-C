#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    if(a>b&&b>c||b>a&&a>c)
    {
        printf("Terceiro produto\n");
    }
    if(a>c&&c>b||c>a&&a>b)
    {
        printf("Segundo produto\n");
    }
    if(b>c&&c>a||c>b&&b>a)
    {
        printf("Primeiro produto\n");
    }
    return 0;
}
