# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

# define fileiras 10
# define assentos 8

int main() {
    int teatro[fileiras][assentos], i, j, totalLivres;

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
    } while (i < 1 || i > fileiras);

    i--;

    do {

    system("cls");

    //imprime fileira
    printf("\n\t%2d  ", i + 1);
    for (j = 0; j < assentos; j++) {
        printf("%d ", teatro[i][j]);
    }
    printf(" %d", i + 1);

    // escolha a fileira
        printf("\n\nEscolha a sua Cadeira: ");
        scanf("%d", &j);

    } while (j < 1 || j > assentos);


    j--;

    teatro[i][j] = 1;

    //imprime matriz final
    for (i = 0; i < fileiras; i++) {
        printf("\n\t%2d  ", i + 1);
        for (j = 0; j < assentos; j++) {
            printf("%d ", teatro[i][j]);
        }
        printf(" %d", i + 1);
    }

    for (i = 0; i < fileiras; i++) {
        for (j = 0; j < assentos; j++) {
            if (teatro[i][j] == 0) {
                totalLivres++;
            }
        }
    }

    printf("\n\n");

    printf("Livres: %d\nOcupados: %d\n\n", totalLivres, (fileiras * assentos) - totalLivres);

    system("pause");
    return 0;
}
