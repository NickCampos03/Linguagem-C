#include <stdio.h>
#include <stdlib.h>

int main()
{
  double a, b, c, d, e, f;
    scanf("%lf%lf%lf", &a, &b, &c);
    d=a+b;
    e=b+c;
    f=a+c;
    if(d<c||e<a||f<b)
    {
        printf("Nao eh triangulo\n");
    }
    else
    {
        if(a==b&&a==c&&b==c)
        {
            printf("Equilatero\n");
        }
        else
        {
            if(a==b||b==c||a==c)
            {
                printf("Isosceles\n");
            }
            else
            {
                printf("Escaleno\n");
            }
        }
    }
    return 0;
}
