# include <stdio.h>
# include <locale.h>

# define fileiras 10
# define assentos 8
# define metadeLin fileiras / 2
# define metadeCol assentos / 2

int main() {
    int teatro[fileiras][assentos] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };
    int incomodo, incomodoFileiras, menosIncomodo = 999, i, j, k, ingressos, minEsquerdo = 0, fil = 0;
    setlocale(LC_ALL, "portuguese");

    ingressos = 4;
    printf("Ingressos: %d\n\n", ingressos);

    for (i = 0; i < fileiras; i++) {
        for (j = 0; j < assentos; j++) {
            printf("%2d ", teatro[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < fileiras; i++) {
            incomodoFileiras = 0;

            if (i < metadeLin) {
                incomodoFileiras += (metadeLin - (i + 1));
            } else {
                incomodoFileiras += (i - metadeLin);
            }

        for (j = 0; j < assentos; j++) {
            incomodo = 0;

            for (k = 0; k < ingressos; k++) {
                if (teatro[i][j + k] == 1 || j + k >= assentos) {
                    incomodo = 999;
                    break;
                }

                incomodo += incomodoFileiras;

                if (j + k < metadeCol) {
                    incomodo += (metadeCol - ((j + k) + 1));
                } else {
                    incomodo += ((j + k) - metadeCol);
                }

                if (i + 1 < fileiras && teatro[i + 1][j + k] == 1) {
                    incomodo++;
                }
                if (i - 1 >= 0 && teatro[i - 1][j + k] == 1) {
                    incomodo++;
                }
                if (k + 1 == ingressos && (j + k) + 1 < assentos && teatro[i][(j + k) + 1] == 1) {
                    incomodo += 2;
                }
                if (k == 0 && (j + k) - 1 >= 0 && teatro[i][(j + k) - 1] == 1) {
                    incomodo += 2;
                }
            }

            if (incomodo < menosIncomodo) {
                menosIncomodo = incomodo;
                fil = i + 1;
                minEsquerdo = j + 1;
            }
        }
    }

    if (menosIncomodo < 999) {
        printf("\nFileira: %d\n", fil);
        printf("Assentos: %d..%d\n", minEsquerdo, minEsquerdo + (ingressos - 1));
    } else {
        printf("\nNão existem recomendações\n");
    }

    return 0;
}
