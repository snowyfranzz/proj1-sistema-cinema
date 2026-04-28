# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

# define FILEIRAS 10
# define ASSENTOS 8

int main() {
    int input;
    int desligado;
    int cancelado;
    int nIngMeia, nIngInteira;
    int fileiraTemp = 0, assentoTemp = 0;
    int totalIngressos = 0;
    int assentosDisponiveis = 80, somaFileira = 0;
    int i, j, teatro[FILEIRAS][ASSENTOS] = {0}; // teatro = {0} garante ja que todos os numeros dentro dela serão 0. isso so serve para o numero 0!!
    setlocale(LC_ALL, "Portuguese");

    for(i = 0; i<FILEIRAS; i++){
        for(j = 0; j < ASSENTOS; j++){
            somaFileira += teatro[i][j];
        }

        assentosDisponiveis -= somaFileira;
        somaFileira = 0;
    }

    do{
        assentosDisponiveis -= totalIngressos;
        desligado = 0, input = 0, cancelado = 0, nIngMeia = 0, nIngInteira = 0, totalIngressos = 0, fileiraTemp = 0, assentoTemp = 0;
        // PRIMEIRA TELA
        do{
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

            switch(input){
                case 1:
                    desligado = 1;
                    system("cls");
                    return 0;
                    break;

                case 2:
                    if(nIngMeia+nIngInteira<10){
                    nIngInteira++;
                    }
                    else{
                        system("cls");
                        printf("Você pode comprar somente 10 ingressos de uma vez!\n");
                        system("pause");
                    }
                    break;

                case 3:
                    if(nIngMeia+nIngInteira<10){
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
                    printf("Isso não é um comando válido!\n");
                    system("pause");
            }
            system("cls");
        } while(input!=4);

        // =============== SEGUNDA TELA =====================

        totalIngressos = nIngInteira + nIngMeia;

        do {
            printf("+------------------------------------------------------------------------------+\n");
            printf("|                            Bem vindo! | Cinemas CineC                        |\n");
            printf("+-----------------------+---------------------+--------------------------------+\n");
            printf("| Assentos Disponíveis: |      Sugestão:      |       Resumo da Compra:        |\n");
            printf("|=======================|=====================|================================|\n");
            printf("|     1 2 3 4 5 6 7 8   |Para 2 ingressos, os |                                |\n");
            printf("|                       |  melhores lugares   |%02ix Ingresso (Inteira).R$%06.2f |\n", nIngInteira, (float)nIngInteira*19);
            printf("| 01  %d %d %d %d %d %d %d %d   | serão os assentos:  |                                |\n", teatro[0][0], teatro[0][1], teatro[0][2], teatro[0][3], teatro[0][4], teatro[0][5], teatro[0][6], teatro[0][7]);
            printf("| 02  %d %d %d %d %d %d %d %d   |* 05-4               |%02ix Ingresso (Meia)....R$%06.2f |\n", teatro[1][0], teatro[1][1], teatro[1][2], teatro[1][3], teatro[1][4], teatro[1][5], teatro[1][6], teatro[1][7], nIngMeia, nIngMeia*9.5);
            printf("| 03  %d %d %d %d %d %d %d %d   |* 05-5               |                                |\n", teatro[2][0], teatro[2][1], teatro[2][2], teatro[2][3], teatro[2][4], teatro[2][5], teatro[2][6], teatro[2][7]);
            printf("| 04  %d %d %d %d %d %d %d %d * |                     |================================|\n", teatro[3][0], teatro[3][1], teatro[3][2], teatro[3][3], teatro[3][4], teatro[3][5], teatro[3][6], teatro[3][7]);
            printf("| 05  %d %d %d %d %d %d %d %d   |                     |                                |\n", teatro[4][0], teatro[4][1], teatro[4][2], teatro[4][3], teatro[4][4], teatro[4][5], teatro[4][6], teatro[4][7]);
            printf("| 06  %d %d %d %d %d %d %d %d   +---------------------+Total:.................R$%06.2f |\n", teatro[5][0], teatro[5][1], teatro[5][2], teatro[5][3], teatro[5][4], teatro[5][5], teatro[5][6], teatro[5][7], (nIngInteira*19 + nIngMeia*9.5));
            printf("| 07  %d %d %d %d %d %d %d %d   |0: Assento Disponível|                                |\n", teatro[6][0], teatro[6][1], teatro[6][2], teatro[6][3], teatro[6][4], teatro[6][5], teatro[6][6], teatro[6][7]);
            printf("| 08  %d %d %d %d %d %d %d %d ! |1: Assento Ocupado   |                                |\n", teatro[7][0], teatro[7][1], teatro[7][2], teatro[7][3], teatro[7][4], teatro[7][5], teatro[7][6], teatro[7][7]);
            printf("| 09  %d %d %d %d %d %d %d %d   |!: Fileira Mais Cheia|                                |\n", teatro[8][0], teatro[8][1], teatro[8][2], teatro[8][3], teatro[8][4], teatro[8][5], teatro[8][6], teatro[8][7]);
            printf("| 10  %d %d %d %d %d %d %d %d   |*: Fileira Mais Vazia|                                |\n", teatro[9][0], teatro[9][1], teatro[9][2], teatro[9][3], teatro[9][4], teatro[9][5], teatro[9][6], teatro[9][7]);
            printf("+-----------------------+---------------------+--------------------------------+\n");
            printf("|            Para escolher seu assento, utilize os comandos abaixo!            |\n");
            printf("|==============================================================================|\n");
            printf("|                                                                              |\n");
            printf("|                   1. Cancelar Compra.                                        |\n");
            printf("|                   2. Prosseguir para a escolha do assento.                   |\n");
            printf("|                                                                              |\n");
            printf("+------------------------------------------------------------------------------+\n");
            scanf("%d", &input);

            switch(input){
                case 1:
                    system("cls");
                    printf("Tem certeza que quer cancelar sua compra? (1. Sim | 2. Não) > ");
                    scanf("%d", &input);
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
                        scanf("%d", &fileiraTemp);
                        fileiraTemp--;

                        printf("Insira o número do assento (Ingresso #%i) > ", i + 1);
                        scanf("%d", &assentoTemp);
                        assentoTemp--;

                        if(teatro[fileiraTemp][assentoTemp] == 0 && fileiraTemp <= 10 && assentoTemp <= 8){
                            teatro[fileiraTemp][assentoTemp] = 1;
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
                    printf("Isso não é um comando válido!\n");
                    system("pause");

                    break;
            }
        } while (input != 2 || cancelado == 1);

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

                switch(input){
                    case 1:
                        system("cls");
                        printf("Tem certeza que quer cancelar sua compra? (1. Sim | 2. Não) > ");
                        scanf("%d", &input);
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
                        printf("Isso não é um comando válido!\n");
                        system("pause");
                }
            }while (input != 2 || cancelado == 1);
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

    }while(desligado != 1);

    return 0;
}
