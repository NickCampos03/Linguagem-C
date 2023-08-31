#include <stdio.h>
#include <stdlib.h>

int main()
{
    double f, i;
    int cont;
    scanf("%lf%lf", &f, &i);
    cont=0;
    if(f>=150&&i>=12)
    {
        cont=cont+1;
    }


        if(f>=140&&i>=14)
        {
            cont=cont+1;
        }


            if(f>=170||i>=16)
            {
                cont=cont+1;
            }
            printf("%d\n", cont);

    return 0;
}
