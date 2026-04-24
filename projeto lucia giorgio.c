#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define fileiras 10
#define assentos 8

int main() {
    int M[fileiras][assentos] = {0}, i, j, lucia = 1, cont;
    float porc;

    setlocale (LC_ALL, "portuguese");

    for (i = 0; i < fileiras; i++) {
        for(j = 0; j < assentos; j++) {
            M[i][j] = 1;
        }
    }

    do {

        cont = 0;

        for(i = 0; i < fileiras; i++) {
            for (j = 0; j < assentos; j++) {
                printf ("%d  ",M[i][j]);
                if (M[i][j] == 1) {
                    cont++;
                }
            }
                printf ("\n");
        }

        porc = (float) cont / (fileiras * assentos) * 100.0;
        printf ("\nA porcentagem de acentos ocupados é: %.2f %%\n", porc);

        printf("\nLinha: ");
        if (!scanf("%d",&i)) {
            i = 0;
        }

        printf("\nColuna: ");
        if (!scanf("%d",&j)) {
            j = 0;
        }

        if (i > 0 && i <= fileiras && j > 0 && j <= assentos) {
            i--;
            j--;
            M[i][j]= 0;
        } else {
            system ("cls");
            printf("Inválido\n\nContinuar?: ");
            scanf("%d", &lucia);
        }

        system ("cls");

    } while (lucia != 0);
    return 0;
}
