# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

# define fileiras 10
# define assentos 8
# define metadeLin fileiras / 2
# define metadeCol assentos / 2

int main() {
    int teatro[fileiras][assentos] = {0}, cont = 1, entropy, entropyLin, minEnt = 999, i, j, k, ingressos, c, minEsquerdo = 0, fil = 0;
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
        if (scanf("%d", &ingressos) == 0) {
            ingressos = 0;
        }
        while((c = getchar()) != '\n' && c != EOF);
    } while (!ingressos);

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
            printf("%2d ", teatro[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < fileiras; i++) {
            entropyLin = 0;

            if (i < metadeLin) {
                entropyLin += (metadeLin - (i + 1));
            } else {
                entropyLin += (i - metadeLin);
            }

        for (j = 0; j < assentos; j++) {
            entropy = 0;

            for (k = 0; k < ingressos; k++) {
                if (teatro[i][j + k] == 11 || j + k >= assentos) {
                    entropy = 999;
                    break;
                }

                entropy += entropyLin;

                if (i + 1 < fileiras && teatro[i + 1][j + k] == 11) {
                    entropy++;
                }
                if (i - 1 >= 0 && teatro[i - 1][j + k] == 11) {
                    entropy++;
                }

                if (j + k < metadeCol) {
                    entropy += (metadeCol - ((j + k) + 1));
                } else {
                    entropy += ((j + k) - metadeCol);
                }
                if (k + 1 == ingressos && (j + k) + 1 < assentos && teatro[i][(j + k) + 1] == 11) {
                    entropy += 2;
                }
                if (k == 0 && (j + k) - 1 >= 0 && teatro[i][(j + k) - 1] == 11) {
                    entropy += 2;
                }
            }

            if (entropy < minEnt) {
                minEnt = entropy;
                minEsquerdo = j + 1;
                fil = i + 1;
            }
        }
    }

    if (minEnt < 999) {
        printf("\nmenorsoma: %d\n\n", minEnt);
        printf("Fileira: %d\n\n", fil);
        printf("Assentos: %d..%d\n\n", minEsquerdo, minEsquerdo + (ingressos - 1));
    } else {
        printf("\nNão existem recomendações\n\n");
    }

    system("pause");
    return 0;
}
