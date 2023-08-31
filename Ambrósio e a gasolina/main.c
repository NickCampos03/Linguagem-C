#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d, r, l, p, g, valor, falta, autonomia, resto, qtd_litros, n_nec;
    scanf("%d%d%d%d%d", &d, &r, &l, &p, &g);
    autonomia=l*10;
    falta=d-autonomia;
    n_nec=(d/autonomia)-1;
    qtd_litros=falta/10;
    valor=qtd_litros*g;
    resto=r-valor;
    if(n_nec>p)
    {
        printf("Nao pode viajar.\n");
    }
    else
    {
        if(resto>=0)
        {
            printf("Pode viajar.\n");
            printf("R$: %d\n", resto);
        }
        else
        {
            printf("Nao pode viajar.\n");
        }
    }

    return 0;
}
