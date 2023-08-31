#include <stdio.h>
#include <stdlib.h>

int main()
{
    double ph;
    scanf("%lf", &ph);
    if (ph>7&&ph<=14)
    {
        printf("Basica\n");
    }
    else
    {
        if(ph>=0&&ph<7)
        {
            printf("Acida\n");
        }
        else
        {
            printf("neutra");
        }
    }
    return 0;
}
