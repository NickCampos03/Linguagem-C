#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dia, mes, ano;
    scanf("%d%d%d", &dia, &mes, &ano);
    if((mes==4||mes==6||mes==9||mes==11)&&dia>=31){
                    printf("Data invalida\n");}
                    else if((mes==1||mes==3||mes==5||mes==7||mes==8||mes==10||mes==12)&&dia>=32){
                             printf("Data invalida\n");}
                        elseif(mes==2&&dia>=29){
                                 printf("Data invalida\n");}
    if(mes==4||mes==6||mes==9||mes==11){
                if(dia>=1&&dia<30){
                        printf("%d.%d.%d\n", dia+1, mes, ano);}
        elseif((mes==4||mes==6||mes==9||mes==11)&&dia==30){
            printf("1.%d.%d\n", mes+1, ano);}}
        if(mes==2){
            if(dia>=1&&dia<=27){
                    printf("%d.%d.%d\n", dia+1, mes, ano);}
                else if(mes==2&&dia==28){
                    printf("1.%d.%d\n", mes+1, ano);}}
        else if(mes==1||mes==3||mes==5||mes==7||mes==8||mes==10){
                if(dia>=1&&dia<31){
                    printf("%d.%d.%d\n", dia+1, mes, ano);}
                else if((mes==1||mes==3||mes==5||mes==7||mes==8||mes==10)&&dia==31){
                   printf("1.%d.%d\n", mes+1, ano);}}
            else if(mes==12){
                    if(dia>=1&&dia<31){
                            printf("%d.%d.%d\n", dia+1, mes, ano);}
                        else if(dia==31&&mes==12){
                                printf("1.1.%d\n", ano+1);}}
    return 0;
}
