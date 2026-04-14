#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int M[10][8] = {0}, i, j, i1, j1, lucia=1, cont1=80;
    float porc;

    setlocale (LC_ALL, "portuguese");
    /*Aqui eu coloco para transformar todos os assentos que foram declarados como 0 em 1.*/
    for (i=0; i<10; i++)
    {
        for(j=0; j<8; j++)
        {
            M[i][j] = 1;

        }
    }
    /*Este aqui define os assentos que você quer cancelar, voltando ao seu estado original, que é 0.*/
    do
    {

    for(i=0;i<10;i++)
    {
        for (j=0;j<8;j++)
        {
            printf ("%d  ",M[i][j]);
        }
            printf ("\n");


    }
    /*Obs: este aqui é para calcular a porcentagem de assentos cheios.*/
     do{
                printf("\n\t");
                cont1 --;
                porc = (cont1+1)*1.25;
                printf ("A porcentagem de acentos ocupados é: %f %",porc);
                printf("\n\t");
            }

    while (M[i][j]=!1);


    printf("\n\tDeseja cancelar um assento? \n\t");
    printf("\n\tLinha: ");
    scanf("%d",&i);
    i1=i-1;
    printf("\n\tColuna: ");
    scanf("%d",&j);
    j1 = j-1;
    M[i1][j1]= 0;
    printf("%d",M[i1][j1]);



    system ("cls");


    /*Obs: a variável "lucia" é para realizar o procedimento automaticamente quando você selecionar a linha e a coluna no qual você deseja cancelar.*/

    }
    while(lucia!=0);

    system ("pause");
    return 0;


}
