# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

# define FILEIRAS 10
# define ASSENTOS 8

void LimpaBuffer() {
    int c;
    while(c = getchar() != '\n' && c != EOF);
}

int main() {
    int input, desligado, cancelado;
    int nIngMeia, nIngInteira;
    int fileiraTemp, assentoTemp;
    int totalIngressos = 0;
    int assentosDisponiveis = (FILEIRAS * ASSENTOS), somaAssentos = 0;
    int cinema[FILEIRAS][ASSENTOS] = {0}, i, j; // cinema = {0} garante ja que todos os numeros dentro dela serão 0. isso so serve para o numero 0!!
    setlocale(LC_ALL, "Portuguese");

    for(i = 0; i<FILEIRAS; i++){
        somaAssentos = 0;
        for(j = 0; j < ASSENTOS; j++){
            somaAssentos += cinema[i][j];
        }
        assentosDisponiveis -= somaAssentos;
    }

    do {
        assentosDisponiveis -= totalIngressos;
        input = 0, desligado = 0, cancelado = 0, nIngMeia = 0, nIngInteira = 0, totalIngressos = 0, fileiraTemp = 0, assentoTemp = 0;
        // PRIMEIRA TELA
        do {
            printf("+------------------------------------------------------------------------------+\n");
            printf("|                            Bem vindo! | Cinemas CineC                        |\n");
            printf("+------------------------------------------------------------------------------+\n");
            printf("|                            Próxima Sessão: Em 1h                             |\n");
            printf("|                                 Filme: Avatar                                |\n");
            printf("|                           Assentos Disponíveis: %i                           |\n", assentosDisponiveis);
            printf("+------------------------------------------------------------+-----------------+\n");
            printf("|                         Ingressos:                         |    Carrinho:    |\n");
            printf("|============================================================|=================|\n");
            printf("|                                                            |%02ix..Inteira     |\n", nIngInteira);
            printf("|       Inteira...............................R$ 19,00       |%02ix..Meia-Entrada|\n", nIngMeia);
            printf("|                                                            |                 |\n");
            printf("|       Meia Entrada..........................R$  9,50       |Total:           |\n");
            printf("|                                                            |- %02i Ingressos   |\n", nIngInteira + nIngMeia);
            printf("|                                                            |- R$%06.2f       |\n", (nIngInteira*19 + nIngMeia*9.5));
            printf("|*  O cliente pode comprar no máximo 10 ingressos de uma vez.|                 |\n");
            printf("|                                                            |                 |\n");
            printf("+------------------------------------------------------------+-----------------+\n");
            printf("|          Para continuar com sua compra, utilize os comandos abaixo!          |\n");
            printf("|==============================================================================|\n");
            printf("|                1. Sair do programa (Desligar)                                |\n");
            printf("|                2. Adicionar um Ingresso (Inteira) ao carrinho.               |\n");
            printf("|                3. Adicionar um ingresso (Meia) ao carrinho.                  |\n");
            printf("|                4. Prosseguir para a escolha de assento.                      |\n");
            printf("+------------------------------------------------------------------------------+\n");

            scanf("%d", &input);
            LimpaBuffer();

            switch(input){
                case 1:
                    desligado = 1;
                    system("cls");
                    break;

                case 2:
                    if(nIngMeia + nIngInteira < 16){
                        nIngInteira++;
                    } else {
                        system("cls");
                        printf("Você pode comprar somente 16 ingressos de uma vez!\n");
                        system("pause");
                    }
                    break;

                case 3:
                    if(nIngMeia + nIngInteira < 10){
                        nIngMeia++;
                    }
                    else{
                        system("cls");
                        printf("Você pode comprar somente 10 ingressos de uma vez!\n");
                        system("pause");
                    }
                    break;

                case 4:
                    break;

                default:
                    system("cls");
                    printf("Comando Inválido!\n");
                    system("pause");
            }
            system("cls");
        } while(input != 4 && desligado != 1);

        // SEGUNDA TELA
        if (desligado != 1) {
            totalIngressos = nIngInteira + nIngMeia;

            do {
                printf("+------------------------------------------------------------------------------+\n");
                printf("|                            Bem vindo! | Cinemas CineC                        |\n");
                printf("+-----------------------+---------------------+--------------------------------+\n");
                printf("| Assentos Disponíveis: |      Sugestão:      |       Resumo da Compra:        |\n");
                printf("|=======================|=====================|================================|\n");
                printf("|     1 2 3 4 5 6 7 8   |Para 2 ingressos, os |                                |\n");
                printf("|                       |  melhores lugares   |%02ix Ingresso (Inteira).R$%06.2f |\n", nIngInteira, (float)nIngInteira*19);
                printf("| 01  %d %d %d %d %d %d %d %d   | serão os assentos:  |                                |\n", cinema[0][0], cinema[0][1], cinema[0][2], cinema[0][3], cinema[0][4], cinema[0][5], cinema[0][6], cinema[0][7]);
                printf("| 02  %d %d %d %d %d %d %d %d   |* 05-4               |%02ix Ingresso (Meia)....R$%06.2f |\n", cinema[1][0], cinema[1][1], cinema[1][2], cinema[1][3], cinema[1][4], cinema[1][5], cinema[1][6], cinema[1][7], nIngMeia, nIngMeia*9.5);
                printf("| 03  %d %d %d %d %d %d %d %d   |* 05-5               |                                |\n", cinema[2][0], cinema[2][1], cinema[2][2], cinema[2][3], cinema[2][4], cinema[2][5], cinema[2][6], cinema[2][7]);
                printf("| 04  %d %d %d %d %d %d %d %d * |                     |================================|\n", cinema[3][0], cinema[3][1], cinema[3][2], cinema[3][3], cinema[3][4], cinema[3][5], cinema[3][6], cinema[3][7]);
                printf("| 05  %d %d %d %d %d %d %d %d   |                     |                                |\n", cinema[4][0], cinema[4][1], cinema[4][2], cinema[4][3], cinema[4][4], cinema[4][5], cinema[4][6], cinema[4][7]);
                printf("| 06  %d %d %d %d %d %d %d %d   +---------------------+Total:.................R$%06.2f |\n", cinema[5][0], cinema[5][1], cinema[5][2], cinema[5][3], cinema[5][4], cinema[5][5], cinema[5][6], cinema[5][7], (nIngInteira*19 + nIngMeia*9.5));
                printf("| 07  %d %d %d %d %d %d %d %d   |0: Assento Disponível|                                |\n", cinema[6][0], cinema[6][1], cinema[6][2], cinema[6][3], cinema[6][4], cinema[6][5], cinema[6][6], cinema[6][7]);
                printf("| 08  %d %d %d %d %d %d %d %d ! |1: Assento Ocupado   |                                |\n", cinema[7][0], cinema[7][1], cinema[7][2], cinema[7][3], cinema[7][4], cinema[7][5], cinema[7][6], cinema[7][7]);
                printf("| 09  %d %d %d %d %d %d %d %d   |!: Fileira Mais Cheia|                                |\n", cinema[8][0], cinema[8][1], cinema[8][2], cinema[8][3], cinema[8][4], cinema[8][5], cinema[8][6], cinema[8][7]);
                printf("| 10  %d %d %d %d %d %d %d %d   |*: Fileira Mais Vazia|                                |\n", cinema[9][0], cinema[9][1], cinema[9][2], cinema[9][3], cinema[9][4], cinema[9][5], cinema[9][6], cinema[9][7]);
                printf("+-----------------------+---------------------+--------------------------------+\n");
                printf("|            Para escolher seu assento, utilize os comandos abaixo!            |\n");
                printf("|==============================================================================|\n");
                printf("|                                                                              |\n");
                printf("|                   1. Cancelar Compra.                                        |\n");
                printf("|                   2. Prosseguir para a escolha do assento.                   |\n");
                printf("|                                                                              |\n");
                printf("+------------------------------------------------------------------------------+\n");
                scanf("%d", &input);
                LimpaBuffer();

                switch(input){
                    case 1:
                        system("cls");
                        printf("Tem certeza que quer cancelar sua compra? (1. Sim | 2. Não) > ");

                        scanf("%d", &input);
                        LimpaBuffer();

                        if(input == 2){
                           input = 1;
                            system("cls");
                        } else {
                            cancelado = 1;
                        }
                        break;

                    case 2:
                        for(i = 0; i < totalIngressos; i++){

                            printf("Insira a fileira do assento (Ingresso #%i) > ", i + 1);
                            if (!scanf("%d", &fileiraTemp)) {
                                fileiraTemp = 0;
                            }
                            LimpaBuffer();
                            fileiraTemp--;

                            printf("Insira o número do assento (Ingresso #%i) > ", i + 1);
                            if (!scanf("%d", &assentoTemp)) {
                                assentoTemp = 0;
                            }
                            LimpaBuffer();
                            assentoTemp--;

                            if(cinema[fileiraTemp][assentoTemp] == 0 && fileiraTemp >= 0 && fileiraTemp < FILEIRAS && assentoTemp >= 0 && assentoTemp < ASSENTOS){
                                cinema[fileiraTemp][assentoTemp] = 1;
                            } else {
                                printf("Não foi possível selecionar esse assento!\n");
                                i--;
                                system("pause");
                            }
                        }
                        system("pause");
                        system("cls");
                        break;

                    default:
                        system("cls");
                        printf("Comando Inválido!\n");
                        system("pause");

                        break;
                }
            } while (input != 2 && cancelado == 1);

            if(cancelado != 1){
                do{
                    printf("+------------------------------------------------------------------------------+\n");
                    printf("|                            Bem vindo! | Cinemas CineC                        |\n");
                    printf("+------------------------------------------------------------------------------+\n");
                    printf("|                                  Carrinho:                                   |\n");
                    printf("|==============================================================================|\n");
                    printf("|                                                                              |\n");
                    printf("|                                                                              |\n");
                    printf("|               %02ix Ingresso (Inteira)..................R$%06.2f               |\n", nIngInteira, (float)nIngInteira*19);
                    printf("|                                                                              |\n");
                    printf("|               %02ix Ingresso (Meia).....................R$%06.2f               |\n", nIngMeia, nIngMeia*9.5);
                    printf("|                                                                              |\n");
                    printf("|               ================================================               |\n");
                    printf("|                                                                              |\n");
                    printf("|               Total...................................R$%06.2f               |\n", (nIngMeia*9.5 + nIngInteira*19));
                    printf("|                                                                              |\n");
                    printf("|                                                                              |\n");
                    printf("|                                                                              |\n");
                    printf("+------------------------------------------------------------------------------+\n");
                    printf("|           Para continuar com a compra, utilize os comandos abaixo!           |\n");
                    printf("|==============================================================================|\n");
                    printf("|                                                                              |\n");
                    printf("|                            1. Cancelar Compra.                               |\n");
                    printf("|                            2. Verificar pagamento.                           |\n");
                    printf("|                                                                              |\n");
                    printf("+------------------------------------------------------------------------------+\n");
                    scanf("%d", &input);
                    LimpaBuffer();

                    switch(input){
                        case 1:
                            system("cls");
                            printf("Tem certeza que quer cancelar sua compra? (1. Sim | 2. Não) > ");
                            scanf("%d", &input);
                            LimpaBuffer();
                            if(input == 2){
                                input = 1;
                                system("cls");
                            } else {
                                cancelado = 1;
                            }
                            break;

                        case 2:
                            break;

                        default:
                            system("cls");
                            printf("Comando Inválido!\n");
                            system("pause");
                    }
                } while (input != 2 && cancelado == 1);
            }

            printf("+------------------------------------------------------------------------------+\n");
            printf("|                            Bem vindo! | Cinemas CineC                        |\n");
            printf("+------------------------------------------------------------------------------+\n");
            printf("|                                                                              |\n");
            printf("|                                                                              |\n");
            printf("|                                                                              |\n");
            printf("|                                                                              |\n");
            printf("|                                                                              |\n");
            printf("|                                                                              |\n");
            printf("|                       Compra efetuada com sucesso!                           |\n");
            printf("|                           Obrigado pela compra!                              |\n");
            printf("|                                                                              |\n");
            printf("|                                                                              |\n");
            printf("|                                                                              |\n");
            printf("|                                                                              |\n");
            printf("|                                                                              |\n");
            printf("|                                                                              |\n");
            printf("+------------------------------------------------------------------------------+\n");
            printf("|                                                                              |\n");
            printf("|                                                                              |\n");
            printf("|                   Digite qualquer tecla para contiunuar...                   |\n");
            printf("|                                                                              |\n");
            printf("|                                                                              |\n");
            printf("+------------------------------------------------------------------------------+\n");
            system("pause");
        }

    } while(desligado != 1);

    return 0;
}
