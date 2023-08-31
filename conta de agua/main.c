#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a, valora, valorb, valorc;
   scanf("%d", &a);
   if (a<=10&&a>=0)
   {
       printf("7\n");
   }
      else
       {
       if(a<=30&&a>=11)
       {
        valora=((a-10)*1)+7;
        printf("%d", valora);
       }
        else
        {
            if(a<=100&&a>=31)
            {
                valorb=(((a-30)*2)+7)+20;
                printf("%d", valorb);
            }
            else
            {
                if(a>=101)
                {
                    valorc=((((a-100)*5)+7)+140+20);
                    printf("%d", valorc);
                }
            }
        }
   }
    return 0;
}
