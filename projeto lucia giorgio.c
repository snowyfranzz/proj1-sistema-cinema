#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define fileiras 10
#define assentos 8

int main() {
    int teatro[fileiras][assentos] = {0}, i, j, continuar = 1, ocupados, c;
    float porc;

    setlocale(LC_ALL, "portuguese");

    for (i = 0; i < fileiras; i++) {
        for(j = 0; j < assentos; j++) {
            teatro[i][j] = 1;
        }
    }

    do {

        ocupados = 0;

        for(i = 0; i < fileiras; i++) {
            for (j = 0; j < assentos; j++) {
                printf ("%d  ",teatro[i][j]);
                if (teatro[i][j] == 1) {
                    ocupados++;
                }
            }
                printf ("\n");
        }

        porc = (float) ocupados / (fileiras * assentos) * 100.0;
        printf ("\nA porcentagem de acentos ocupados é: %.2f %%\n", porc);

        printf("\nLinha: ");
        if (!scanf("%d",&i)) {
            i = 0;
        }
        while(c = getchar() != '\n' && c != EOF);

        printf("\nColuna: ");
        if (!scanf("%d",&j)) {
            j = 0;
        }
        while(c = getchar() != '\n' && c != EOF);

        if (i > 0 && i <= fileiras && j > 0 && j <= assentos) {
            i--;
            j--;
            teatro[i][j]= 0;
        } else {
            system ("cls");
            printf("Inválido\n\nContinuar?: ");
            scanf("%d", &continuar);
            while(c = getchar() != '\n' && c != EOF);
        }

        system ("cls");

    } while(continuar != 0);

    return 0;
}
