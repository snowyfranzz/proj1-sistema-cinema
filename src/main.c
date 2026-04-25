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
    int ingressos[2] = {0,0}, incomodo, incomodoFileiras, menosIncomodo, i, j, k, grupo, minEsquerdo = 0, trueEsquerdo = 0, trueDireito = 0, truefil = 0, fil = 0;
    setlocale(LC_ALL, "portuguese");

    //as pessoas são divididas em dois grupos (ingressos[0] e ingressos[1]) se são mais de 8
    ingressos[0] = 6;
    printf("Ingressos: %d\n\n", ingressos[0]);

    if (ingressos[0] >= 8) {
        ingressos[1] = (ingressos[0] % 2);
        ingressos[0] /= 2;
        ingressos[1] += ingressos[0];
    }

    for (i = 0; i < fileiras; i++) {
        for (j = 0; j < assentos; j++) {
            printf("%d ", teatro[i][j]);
        }
        printf("\n");
    }

    for (grupo = 0; grupo < 2; grupo++) {

        menosIncomodo = 999;

        if (ingressos[grupo] == 0) {
            break;
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

                for (k = 0; k < ingressos[grupo]; k++) {

                    if (teatro[i][j + k] == 1 || j + k >= assentos || (i + 1 == truefil && (j + k) + 1 >= trueEsquerdo && (j + k) + 1 <= trueDireito)) {
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
                    if (k + 1 == ingressos[grupo] && (j + k) + 1 < assentos && teatro[i][(j + k) + 1] == 1) {
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
            trueEsquerdo = minEsquerdo;
            trueDireito = minEsquerdo + (ingressos[grupo] - 1);
            truefil = fil;

            printf("\nGrupo %d\n", grupo + 1);
            printf("Fileira: %d\n", fil);
            printf("Assentos: %d..%d\n", trueEsquerdo, trueDireito);
        } else {
            printf("Não existem recomendações\n\n");
        }
    }

    return 0;
}
