#include <stdio.h>
#include <stdlib.h>

int main()
{


{
    double velocidadecarro, velocidadevia;
    scanf("%lf%lf", &velocidadevia, &velocidadecarro);
    if(velocidadecarro<=velocidadevia+(0.2*velocidadevia)&&velocidadecarro>velocidadevia)
        {
            printf("85.13\n");
            printf("4\n");
        }
        else
        {
         if((velocidadecarro>velocidadevia+(0.2*velocidadevia))&&(velocidadecarro<=velocidadevia+(0.5*velocidadevia)))
         {
             printf("127.69\n");
             printf("5\n");
         }
         else
         {
             if(velocidadecarro>velocidadevia+(0.5*velocidadevia))
             {
                 printf("574.62\n");
                 printf("7\n");
             }
             else
             {
                 if(velocidadecarro<=velocidadevia)
                    printf("0.00\n");
                    printf("0\n");
             }
         }
        }
    }
    return 0;
}
