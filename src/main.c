# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

# define fileiras 10
# define assentos 8

int main() {
    int teatro[fileiras][assentos], i, j, repeat = 0, total = fileiras * assentos, totalLivres;
    float porcent;

    setlocale(LC_ALL, "portuguese");

    //coloca cada valor como 0
    for (i = 0; i < fileiras; i++) {
        for (j = 0; j < assentos; j++) {
            teatro[i][j] = 0;
        }
    }

    do {
        system("cls");
        //imprime numero de linhas/colunas
        printf("Fileiras: %d | Assentos: %d\n\n", fileiras, assentos);

        totalLivres = 0;

        //calcula os assentos livres
        for (i = 0; i < fileiras; i++) {
            for (j = 0; j < assentos; j++) {
                if (teatro[i][j] == 0) {
                    totalLivres++;
                }
            }
        }

        printf("Livres: %d\nOcupados: %d\n", totalLivres, total - totalLivres);

        porcent = (float) (total - totalLivres)/total * 100;

        printf("Percentual de ocupação: %%%.1f\n\n", porcent);

        //imprime matriz
        for (i = 0; i < fileiras; i++) {
            printf("\n\t%2d  ", i + 1);
            for (j = 0; j < assentos; j++) {
                printf("%d ", teatro[i][j]);
            }
            printf(" %d", i + 1);
        }

        // escolha a fileira
        printf("\n\nEscolha a sua fileira: ");
        scanf("%d", &i);

        if (i < 1 || i > fileiras) {
            break;
        }

        i--;


        //imprime fileira
        printf("\n\t%2d  ", i + 1);
        for (j = 0; j < assentos; j++) {
            printf("%d ", teatro[i][j]);
        }
        printf(" %d", i + 1);

        // escolha a fileira
        printf("\n\nEscolha a sua Cadeira: ");
        scanf("%d", &j);

        if (j < 1 || j > assentos) {
            break;
        }

        j--;

        teatro[i][j] = 1;

        printf("\n Continue? (1 ou 0): ");
        scanf("%d", &repeat);
     } while (repeat == 1);

    system("pause");
    return 0;
}
