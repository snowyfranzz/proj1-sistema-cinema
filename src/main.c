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
    int teatro[fileiras][assentos], cont = 1, entropy = 0, metadeLin = fileiras / 2, metadeCol = assentos / 2, i, j;

    setlocale(LC_ALL, "portuguese");

    //cada valor da matriz começa = 0
    for (i = 0; i < fileiras; i++) {
        for (j = 0; j < assentos; j++) {
            teatro[i][j] = 0;
        }
    }

    do {
        //limpa o terminal
        system("cls");

        //imprime matriz
        for (i = 0; i < fileiras; i++) {
            for (j = 0; j < assentos; j++) {
                //colunas
                printf("%02d ", teatro[i][j]);
            }
            //linhas
            printf("\n");
        }

        //pede a localização da linha (de 1 a "fileiras")
        printf("Linha: ");
        scanf("%d", &i);

        //pede a localização da coluna (de 1 a "assentos")
        printf("\nColuna: ");
        scanf("%d", &j);

        //se for uma localização fora da matriz, avisa que é invalido e pede se sair do loop ou não
        if (i < 1 || i > fileiras || j < 1 || j > assentos) {
            printf("\ninvalido\n\n Continuar? (1 ou 0): ");
            scanf("%d", &cont);
        } else {
            //se for localização valida

            //decrementa os valores recebidos (para transformar em coordenadas de matriz em C)
            i--;
            j--;

            //coloca o numero "11" naquela localização
            teatro[i][j] = 11;
        }
    } while (cont != 0); //continue o loop até o usuario mudar cont para 0 (cont armazena se o jogador quer continuar depois de colocar um valor invalido)

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
            if (teatro[i + 1][j] == 11 && i + 1 <= fileiras) {
                entropy++;
            }
            if (teatro[i - 1][j] == 11  && i - 1 >= 0) {
                entropy ++;
            }


            //COLUNAS

            //aumenta quanto mais longe das colunas do meio
            if (j < metadeCol) {
                entropy += (metadeCol - (j + 1));
            } else {
                entropy += (j - metadeCol);
            }

            //aumenta + 2 se estiver do lado de um lugar reservado
            if (teatro[i][j + 1] == 11 && j + 1 <= assentos) {
                entropy += 2;
            }
            if (teatro[i][j - 1] == 11 && j - 1 >= 0) {
                entropy += 2;
            }

            //colocar o valor da entropia (que tão não-recomendado é o lugar) na posição
            if (teatro[i][j] != 11) {
                teatro[i][j] = entropy;
            }
        }
    }

    //imprime mapa de calor
    for (i = 0; i < fileiras; i++) {
        for (j = 0; j < assentos; j++) {
            printf("%02d ", teatro[i][j]);
        }
        printf("\n");
    }


    system("pause");
    return 0;
}
