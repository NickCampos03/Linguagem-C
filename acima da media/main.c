#include <stdio.h>
#include <stdlib.h>

int main()
{
    double nota1, nota2, nota3, x;
    scanf("%lf%lf%lf", &nota1, &nota2, &nota3);
    x=(nota1+nota2+nota3)/3;
    if (nota1>x&&nota2>x&&nota3>x)
    {
        printf("3/n");
    }
    else
    {
        if (nota1>x&&nota2>x)
        {
            printf("2\n");
        }
        else
        {
            if (nota1>x&&nota3>x)
            {
                printf("2\n");
            }
            else
            {
                if (nota2>x&&nota3>x)
                {
                    printf("2\n");
                }
                else
                {
                    if(nota1>x||nota2>x||nota3>x)
                    {
                        printf("1\n");
                    }
                }
            }
        }
    }

    return 0;
}
