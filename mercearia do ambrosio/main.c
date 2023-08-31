#include <stdio.h>
#include <stdlib.h>

int main()
{
    int b;
    double a, x, y, z;
    scanf("%lf%d", &a, &b);
    if(a==1)
    {
        a=5.30;
    }
    if(a==2)
    {
        a=6.00;
    }
    if(a==3)
    {
        a=3.20;
    }
    if(a==4)
    {
        a=2.50;
    }
    x=a*b;
        if(x>=40||b>=15)
        {
        y=x-(x*0.15);
        printf("R$ %.2lf\n", y);
    }
    else
    {
        {
        printf("R$ %.2lf\n", x);
        }
    }
    return 0;
}
