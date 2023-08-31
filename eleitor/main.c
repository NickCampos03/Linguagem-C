#include <stdio.h>
#include <stdlib.h>

int main()
{
    int idade;
    scanf("%d", &idade);
    if(idade<16)
    {
        printf("nao eleitor");
    }
    else
    {
        if(16<=idade&&idade<18||idade>65)
        {
            printf("eleitor facultativo");
        }
        else
        {
            if (idade>=18&&idade<=65)
            {
                printf("eleitor obrigatorio");
            }
        }
    }
    return 0;
}
