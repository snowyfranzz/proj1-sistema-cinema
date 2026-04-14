# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

# define fileiras 10
# define assentos 8
# define metadeLin fileiras / 2
# define metadeCol assentos / 2

int main() {
    int teatro[fileiras][assentos] = {0}, cont = 1, entropy = 0, minEnt = 999, i, j, k, N, c;
    setlocale(LC_ALL, "portuguese");

    do {
        system("cls");

        for (i = 0; i < fileiras; i++) {
            for (j = 0; j < assentos; j++) {
                printf("%2d ", teatro[i][j]);
            }
            printf("\n");
        }

        printf("\nLinha: ");
        if (scanf("%d", &i) == 0) {
            i = 0;
        }
        while((c = getchar()) != '\n' && c != EOF);

        printf("\nColuna: ");
        if (scanf("%d", &j) == 0) {
            j = 0;
        }
        while((c = getchar()) != '\n' && c != EOF);

        if (i > 0 && i <= fileiras && j > 0 && j <= assentos) {
            i--;
            j--;
            teatro[i][j] = 11;
        } else {
            system("cls");
            printf("\nINVÁLIDO\n\nContinuar? (1 ou 0): ");
            scanf("%d", &cont);
            while((c = getchar()) != '\n' && c != EOF);
        }
    } while (cont != 0);

    do {
        system("cls");
        printf("\nNumero de pessoas: ");
        if (scanf("%d", &N) == 0) {
            N = 0;
        }
        while((c = getchar()) != '\n' && c != EOF);
    } while (!N);

    system("cls");

    for (i = 0; i < fileiras; i++) {
        for (j = 0; j < assentos; j++) {

            if (teatro[i][j] == 11) {
                continue;
            }

            entropy = 0;

            if (i < metadeLin) {
                entropy += (metadeLin - (i + 1));
            } else {
                entropy += (i - metadeLin);
            }
            if (i + 1 < fileiras) {
                if (teatro[i + 1][j] == 11) {
                    entropy++;
                }
            }
            if (i - 1 >= 0) {
                if (teatro[i - 1][j] == 11) {
                    entropy ++;
                }
            }

            if (j < metadeCol) {
                entropy += (metadeCol - (j + 1));
            } else {
                entropy += (j - metadeCol);
            }
            if (j + 1 < assentos) {
                if (teatro[i][j + 1] == 11) {
                    entropy += 2;
                }
            }
            if (j - 1 >= 0) {
                if (teatro[i][j - 1] == 11) {
                    entropy += 2;
                }
            }

            teatro[i][j] = entropy;
        }
    }

    for (i = 0; i < fileiras; i++) {
        for (j = 0; j < assentos; j++) {

            entropy = 0;

            for (k = 0; k < N; k++) {
                if (j + k < assentos && teatro[i][j + k] != 11) {
                    entropy += teatro[i][j + k];
                } else {
                    entropy = 999;
                    break;
                }
            }

            if (entropy < minEnt) {
                minEnt = entropy;
            }
        }
    }

    for (i = 0; i < fileiras; i++) {
        for (j = 0; j < assentos; j++) {
            printf("%2d ", teatro[i][j]);
        }
        printf("\n");
    }

    printf("menorsoma: %d\n", minEnt);
    printf("\n");

    system("pause");
    return 0;
}
