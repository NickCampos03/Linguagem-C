#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x, y, cont;
    scanf("%lf%lf", &x, &y);
    cont=0;
    if(x<0||x>432)
    {
        cont=cont+1;
    }
    if(y>468||y<0)
    {
        cont=cont+1;
    }
    if(cont==2||cont==1)
    {
        printf("fora\n");
    }
    else
    {
        printf("dentro\n");
    }

    return 0;
}
