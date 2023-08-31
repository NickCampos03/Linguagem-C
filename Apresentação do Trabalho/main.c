#include <stdio.h>
#include <stdlib.h>

int main()
{
int a, b, c, d, e, cont;
scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
cont=0;
if(a==1||b==1)
{
    cont=cont+1;
}
if(c==1&&d==1)
{
    cont=cont+1;
}
if(e==1)
{
    cont=cont+1;
}
if(cont==3)
{
    printf("AVALIADO\n");
}
else
{
    if(cont<=2&&cont>=0)
    {
        printf("0\n");
    }
}   return 0;
}
