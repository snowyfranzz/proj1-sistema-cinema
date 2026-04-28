# include <stdio.h>
# include <locale.h>

# define FILEIRAS 10
# define ASSENTOS 8
# define METADELIN FILEIRAS / 2
# define METADECOL ASSENTOS / 2

int main() {
    int teatro[FILEIRAS][ASSENTOS] = {
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
    int ingressos[2] = {0,0}, incomodo, incomodoFileiras, menosIncomodo, i, j, k, jk, grupo, minEsquerdo = 0, fil = 0, trueEsquerdo, trueDireito, truefil;
    setlocale(LC_ALL, "portuguese");

    ingressos[0] = 16;
    printf("Ingressos: %d\n\n", ingressos[0]);

    if (ingressos[0] >= 8) {
        ingressos[1] = ingressos[0] % 2;
        ingressos[0] /= 2;
        ingressos[1] += ingressos[0];
    }

    for (i = 0; i < FILEIRAS; i++) {
        for (j = 0; j < ASSENTOS; j++) {
            printf("%d ", teatro[i][j]);
        }
        printf("\n");
    }

    for (grupo = 0; grupo < 2; grupo++) {

        if (ingressos[grupo] == 0) {
            break;
        }

        menosIncomodo = 999;

        for (i = 0; i < FILEIRAS; i++) {

                incomodoFileiras = 0;

                if (i < METADELIN) {
                    incomodoFileiras += (METADELIN - (i + 1));
                } else {
                    incomodoFileiras += (i - METADELIN);
                }

            for (j = 0; j < ASSENTOS; j++) {

                incomodo = 0;

                for (k = 0; k < ingressos[grupo]; k++) {

                    jk = j + k;

                    if (teatro[i][jk] == 1 || jk >= ASSENTOS || (i + 1 == truefil && jk + 1 >= trueEsquerdo && jk + 1 <= trueDireito)) {
                        incomodo = 999;
                        break;
                    }

                    incomodo += incomodoFileiras;

                    if (jk < METADECOL) {
                        incomodo += (METADECOL - (jk + 1));
                    } else {
                        incomodo += (jk - METADECOL);
                    }

                    if (i + 1 < FILEIRAS && teatro[i + 1][jk] == 1) {
                        incomodo++;
                    }
                    if (i - 1 >= 0 && teatro[i - 1][jk] == 1) {
                        incomodo++;
                    }
                    if (k + 1 == ingressos[grupo] && jk + 1 < ASSENTOS && teatro[i][jk + 1] == 1) {
                        incomodo += 2;
                    }
                    if (k == 0 && jk - 1 >= 0 && teatro[i][jk - 1] == 1) {
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

        printf("\nGrupo %d\n", grupo + 1);

        if (menosIncomodo < 999) {
            trueEsquerdo = minEsquerdo;
            trueDireito = minEsquerdo + (ingressos[grupo] - 1);
            truefil = fil;

            printf("Fileira: %d\n", fil);
            if (ingressos[0] == 1) {
                printf("Assento: %d\n", trueEsquerdo);
            } else {
                printf("Assentos: %d ao %d\n", trueEsquerdo, trueDireito);
            }
        } else {
            printf("Não existem recomendações\n\n");
        }
    }

    return 0;
}
