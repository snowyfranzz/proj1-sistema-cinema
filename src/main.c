# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

# define fileiras 10
# define assentos 8

//protótipo do algoritmo que pode determinar quais lugares são mais recomendados que outros
//se chama "mapa de calor" porque achei similar a esses mapas. Em vez de usar cores, uso um contador

//uso:

    //o primeiro bloco é responsável por te deixar colocar lugares que já estão reservados.
    //Para que esses lugares sejam fáceis de achar, eles serão marcados com o valor "11"

    //após isso, a variável de "entropy" é utilizada como contador
    //cada condição (distância do meio/pessoas) aumenta o contador por uma quantidade
        //+1 por cada linha e coluna mais longe do meio
        //+1 se estiver em frente ou de traz de uma pessoa
        //+2 se estiver do lado de uma pessoa
    //o valor da entropia depois é guardado no lugar da matriz para mostrar o mapa de calor resultante

int main() {
    int teatro[fileiras][assentos] = {0}, cont = 1, entropy = 0, minEnt = 999, metadeLin = fileiras / 2, metadeCol = assentos / 2, i, j, k, N, teste;

    setlocale(LC_ALL, "portuguese");

    do {
        //limpa o terminal
        system("cls");

        //imprime matriz
        for (i = 0; i < fileiras; i++) {
            for (j = 0; j < assentos; j++) {
                printf("%2d ", teatro[i][j]);
            }
            printf("\n");
        }

        //pede a localização da linha (de 1 a "fileiras")
        printf("\nLinha: ");
        teste = scanf("%d", &i);
        while(getchar() != '\n');
        if (!teste) {
            i = 0;
        }

        //pede a localização da coluna (de 1 a "assentos")
        printf("\nColuna: ");
        teste = scanf("%d", &j);
        while(getchar() != '\n');
        if (!teste) {
            j = 0;
        }


        //se for uma localização fora da matriz, avisa que é invalido e pede se sair do loop ou não
        if (i > 0 && i <= fileiras && j > 0 && j <= assentos) {
            //se for localização valida

            //decrementa os valores recebidos (para transformar em coordenadas de matriz em C)
            i--;
            j--;

            //coloca o numero "11" naquela localização
            teatro[i][j] = 11;
        } else {
            system("cls");
            printf("\nINVÁLIDO\n\nContinuar? (1 ou 0): ");
            scanf("%d", &cont);
            while(getchar() != '\n');
        }
    } while (cont != 0); //continue o loop até o usuario mudar cont para 0 (cont armazena se o jogador quer continuar depois de colocar um valor invalido)

    do {
        system("cls");
        printf("\nNumero de pessoas: ");
        teste = scanf("%d", &N);
        while(getchar() != '\n');
    } while (!teste);

    //limpa a tela de novo
    system("cls");

    //algoritmo - mapa de calor
    for (i = 0; i < fileiras; i++) {
        for (j = 0; j < assentos; j++) {

            entropy = 0;

            //LINHAS

            //aumenta quanto mais longe das linhas do meio
            if (i < metadeLin) {
                entropy += (metadeLin - (i + 1));
            } else {
                entropy += (i - metadeLin);
            }
            //aumenta se estiver perto de um lugar reservado
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


            //COLUNAS

            //aumenta quanto mais longe das colunas do meio
            if (j < metadeCol) {
                entropy += (metadeCol - (j + 1));
            } else {
                entropy += (j - metadeCol);
            }

            //aumenta + 2 se estiver do lado de um lugar reservado
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

            //colocar o valor da entropia (que tão não-recomendado é o lugar) na posição
            if (teatro[i][j] != 11) {
                teatro[i][j] = entropy;
            }
        }
    }


    for (i = 0; i < fileiras; i++) {
        for (j = 0; j < assentos; j++) {

            entropy = 0;
            for (k = 0; k < N; k++) {
                if (teatro[i][j + k] == 11) {
                    entropy = 999;
                    break;
                }

                if (j + k < assentos) {
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

    //imprime mapa de calor
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
