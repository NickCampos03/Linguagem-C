#include <stdio.h>
#include <stdlib.h>

int main()
{
 double a, b, c, media;
 int cont;
 scanf("%lf%lf%lf", &a, &b, &c);
 media= (a+b+c)/3;
 cont=0;
 if(a>media)
 {
     cont=cont+1;
 }
 if (b>media)
 {
     cont=cont+1;
 }
 if (c>media)
 {
     cont=cont+1;
 }
 printf("%d\n", cont);
    return 0;
}
