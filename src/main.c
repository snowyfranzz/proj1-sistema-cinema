# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

# define FILEIRAS 10
# define ASSENTOS 8
# define METADELIN FILEIRAS / 2
# define METADECOL ASSENTOS / 2

void LimpaBuffer() {
    int c;
    while(c = getchar() != '\n' && c != EOF);
}

int main() {
    int cinema[FILEIRAS][ASSENTOS] = {0}, fileiraTemp, assentoTemp, i, j, k, jk;
    int incomodo, incomodoFileiras, menosIncomodo, minEsquerdo = 0, fil = 0, recomendEsquerdo[2], recomendDireito[2], truefil;

    int input, desligado, cancelado;

    int ingressos[2] = {0,0}, nIngMeia, nIngInteira, dividir = 2, grupo;
    float valorMedia = 9.5, valorInteira = 19.0;

    int assentosDisponiveis = (FILEIRAS * ASSENTOS), somaAssentos = 0;
    setlocale(LC_ALL, "Portuguese");

    if (FILEIRAS < 10) {
        printf("\n\nNUMERO DE FILEIRAS INV�LIDO\n\n");
        return 1;
    }

    for(i = 0; i<FILEIRAS; i++){
        somaAssentos = 0;
        for(j = 0; j < ASSENTOS; j++){
            somaAssentos += cinema[i][j];
        }
        assentosDisponiveis -= somaAssentos;
    }

    do {
        input = 0, desligado = 0, cancelado = 0, nIngMeia = 0, nIngInteira = 0, ingressos[0] = 0, ingressos[1] = 0, fileiraTemp = 0, assentoTemp = 0;
        assentosDisponiveis -= ingressos[0];

        // PRIMEIRA TELA
        do {
            system("cls");
            ingressos[0] = nIngInteira + nIngMeia;
            printf("+------------------------------------------------------------------------------+\n");
            printf("|                            Bem vindo! | Cinemas CineC                        |\n");
            printf("+------------------------------------------------------------------------------+\n");
            printf("|                            Próxima Sessão: Em 1h                             |\n");
            printf("|                                 Filme: Avatar                                |\n");
            printf("|                           Assentos Dispon�veis: %3i                          |\n", assentosDisponiveis);
            printf("+------------------------------------------------------------+-----------------+\n");
            printf("|                         Ingressos:                         |    Carrinho:    |\n");
            printf("|============================================================|=================|\n");
            printf("|                                                            |%2ix..Inteira     |\n", nIngInteira);
            printf("|       Inteira...............................R$ %05.2f       |%2ix..Meia-Entrada|\n",valorInteira, nIngMeia);
            printf("|                                                            |                 |\n");
            printf("|       Meia Entrada..........................R$ %5.2f       |Total:           |\n",valorMedia);
            printf("|                                                            |- %02i Ingressos   |\n", ingressos[0]);
            printf("|                                                            |- R$%6.2f       |\n", (nIngInteira*valorInteira + nIngMeia*valorMedia));
            printf("|*  O cliente pode comprar no m�ximo 16 ingressos de uma vez.|                 |\n");
            printf("|                                                            |                 |\n");
            printf("+------------------------------------------------------------+-----------------+\n");
            printf("|          Para continuar com sua compra, utilize os comandos abaixo!          |\n");
            printf("|==============================================================================|\n");
            printf("|                1. Sair do programa (Desligar)                                |\n");
            printf("|                2. Adicionar um Ingresso (Inteira) ao carrinho.               |\n");
            printf("|                3. Adicionar um ingresso (Meia) ao carrinho.                  |\n");
            printf("|                4. Prosseguir para a escolha de assento.                      |\n");
            printf("+------------------------------------------------------------------------------+\n> ");

            scanf("%d", &input);
            LimpaBuffer();

            switch(input){
                case 1:
                    desligado = 1;
                    system("cls");
                    break;

                case 2:
                case 3:
                    if(ingressos[0] < 16){
                        if(input == 2) {
                            nIngInteira++;
                        } else {
                            nIngMeia++;
                        }
                    } else {
                        system("cls");
                        printf("Você pode comprar somente 16 ingressos de uma vez!\n");
                        system("pause");
                    }
                    break;

                case 4:
                    if (ingressos[0] > 1) {
                        system("cls");
                        printf("Deseja dividir os ingressantes? (1. Sim | 2. N�o) > ");
                        scanf("%d",&dividir);
                        LimpaBuffer();
                    }
                    break;

                default:
                    system("cls");
                    printf("Comando Inválido!\n");
                    system("pause");
            }
        } while(input != 4 && desligado != 1);

        // SEGUNDA TELA
        if (desligado != 1) {

            if (dividir == 1) {
                ingressos[1] = ingressos[0] % 2;
                ingressos[0] /= 2;
                ingressos[1] += ingressos[0];
            }

            for (grupo = 0; grupo < 2; grupo++) {

                if (ingressos[grupo] == 0) {
                    break;
                }

                menosIncomodo = 999;

                for (i = 0; i < FILEIRAS; i++) {

                        incomodoFileiras = 0;

                        if (i < METADELIN) {
                            incomodoFileiras += (METADELIN - i);

                            if (FILEIRAS % 2 != 0) {
                                incomodoFileiras++;
                            }
                        } else {
                            incomodoFileiras += (i - METADELIN);
                        }

                    for (j = 0; j < ASSENTOS; j++) {

                        incomodo = 0;

                        for (k = 0; k < ingressos[grupo]; k++) {

                            jk = j + k;

                            if (cinema[i][jk] == 1 || jk >= ASSENTOS || (i + 1 == truefil && jk + 1 >= recomendEsquerdo[grupo] && jk + 1 <= recomendDireito[grupo])) {
                                incomodo = 999;
                                break;
                            }

                            incomodo += incomodoFileiras;

                            if (jk < METADECOL) {

                                incomodo += (METADECOL - jk);

                                if (ASSENTOS % 2 != 0) {
                                    incomodo++;
                                }

                            } else {
                                incomodo += (jk - METADECOL);
                            }

                            if (i + 1 < FILEIRAS && cinema[i + 1][jk] == 1) {
                                incomodo++;
                            }
                            if (i - 1 >= 0 && cinema[i - 1][jk] == 1) {
                                incomodo++;
                            }
                            if (k + 1 == ingressos[grupo] && jk + 1 < ASSENTOS && cinema[i][jk + 1] == 1) {
                                incomodo += 2;
                            }
                            if (k == 0 && jk - 1 >= 0 && cinema[i][jk - 1] == 1) {
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
                    recomendEsquerdo[grupo] = minEsquerdo;
                    recomendDireito[grupo] = minEsquerdo + (ingressos[grupo] - 1);
                    truefil = fil;

                    printf("Fileira: %d\n", fil);
                    if (ingressos[0] == 1) {
                        printf("Assento: %d\n", recomendEsquerdo[grupo]);
                    } else {
                        printf("Assentos: %d ao %d\n", recomendEsquerdo[grupo], recomendDireito[grupo]);
                    }
                } else {
                    printf("N�o existem recomenda��es\n\n");
                }
            }
            ingressos[0] += ingressos[1];
            ingressos[1] = 0;

            do {
                system("cls");
                printf("+--------------------------------------------------------------");
                for (i = 0; i < ASSENTOS; i++) {
                    printf("--");
                }
                printf("+\n");

                printf("|                    ");
                for (i = 0; i < METADECOL; i++) {
                    printf("  ");
                }
                printf("Bem vindo! | Cinemas CineC");
                for (i = 0; i < (METADECOL + ASSENTOS % 2); i++) {
                    printf("  ");
                }
                printf("                |\n");

                printf("+--------------------------------------------------------------");
                for (i = 0; i < ASSENTOS; i++) {
                    printf("--");
                }
                printf("+\n");

                printf("|");
                for (i = 0; i < METADECOL; i++) {
                    printf("  ");
                }
                printf("Cinema:");
                for (i = 0; i < (METADECOL + ASSENTOS % 2); i++) {
                    printf("  ");
                }
                printf("|      Sugest�es:     |       Resumo da Compra:        |\n");

                printf("|=======");
                for (i = 0; i < ASSENTOS; i++) {
                    printf("==");
                }
                printf("|=====================|================================|\n");

                printf("|    ");
                for (i = 0; i < ASSENTOS; i++) {
                    printf("%2d", i + 1);
                }
                printf("   |    %2d Ingressos     |                                |\n", ingressos[0]);

                printf("|");
                for (i = 0; i < ASSENTOS; i++) {
                    printf("  ");
                }
                printf("       |---------------------|%2ix Ingresso (Inteira).R$%6.2f |\n", nIngInteira, (float)nIngInteira*valorInteira);

                for (i = 0; i < FILEIRAS; i++) {

                    printf("| %02d  ", i + 1);

                    for (j = 0; j < ASSENTOS; j++) {

                        printf("%d ", cinema[i][j]);
                        if (j + 1 == ASSENTOS) {

                            //Substituir pela l�gica de fileira cheia/ocupada
                            if (i == 3) {
                                printf("*");
                            } else {
                                if (i == 7) {
                                    printf("!");
                                } else {
                                    printf(" ");
                                }
                            }
                        }
                    }
                    switch(i) {
                        case 0:
                            printf(" |  Fileira  Assentos  |                                |\n");
                            break;
                        case 1:
                            printf(" |---------------------|%2ix Ingresso (Meia)....R$%6.2f |\n", nIngMeia, nIngMeia*valorMedia);
                            break;
                        case 2:
                            printf(" | * 05      * 4 ao 5  |                                |\n");
                            break;
                        case 3:
                            printf(" | * 05      * 6 ao 7  |================================|\n");
                            break;
                        case 4:
                            printf(" |                     |                                |\n");
                            break;
                        case 5:
                            printf(" +---------------------+ Total:................R$%6.2f |\n", (nIngInteira*valorInteira + nIngMeia*valorMedia));
                            break;
                        case 6:
                            printf(" |0: Assento Dispon�vel|                                |\n");
                            break;
                        case 7:
                            printf(" |1: Assento Ocupado   |                                |\n");
                            break;
                        case 8:
                            printf(" |!: Fileira Mais Cheia|                                |\n");
                            break;
                        case 9:
                            printf(" |*: Fileira Mais Vazia|                                |\n");
                            break;
                        default:
                            printf(" |                     |                                |\n");
                            break;
                    }

                }

                printf("+-------");
                for (i = 0; i < ASSENTOS; i++) {
                    printf("--");
                }
                printf("+---------------------+--------------------------------+\n");

                printf("|    ");
                for (i = 0; i < METADECOL; i++) {
                    printf("  ");
                }
                printf("Para escolher seu assento, utilize os comandos abaixo!");
                for (i = 0; i < (METADECOL + ASSENTOS % 2); i++) {
                    printf("  ");
                }
                printf("    |\n");

                printf("|");
                for (i = 0; i < ASSENTOS; i++) {
                    printf("==");
                }
                printf("==============================================================|\n");

                printf("|                                                              ");
                for (i = 0; i < ASSENTOS; i++) {
                    printf("  ");
                }
                printf("|\n");

                printf("|           ");
                for (i = 0; i < METADECOL; i++) {
                    printf("  ");
                }
                printf("1. Cancelar Compra.          ");
                for (i = 0; i < (METADECOL + ASSENTOS % 2); i++) {
                    printf("  ");
                }
                printf("                      |\n");

                printf("|           ");
                for (i = 0; i < METADECOL; i++) {
                    printf("  ");
                }
                printf("2. Prosseguir para a escolha do assento.");
                for (i = 0; i < (METADECOL + ASSENTOS % 2); i++) {
                    printf("  ");
                }
                printf("           |\n");

                printf("|");
                for (i = 0; i < ASSENTOS; i++) {
                    printf("  ");
                }
                printf("                                                              |\n");

                printf("+");
                for (i = 0; i < ASSENTOS; i++) {
                    printf("--");
                }
                printf("--------------------------------------------------------------+\n> ");

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
                            system("cls");
                        }
                        break;

                    case 2:
                        for(i = 0; i < ingressos[0]; i++){

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
                        break;

                    default:
                        system("cls");
                        printf("Comando Inválido!\n");
                        system("pause");

                        break;
                }
            } while (input != 2 && cancelado != 1);

            if(cancelado != 1){
                do{
                    system("cls");
                    printf("+------------------------------------------------------------------------------+\n");
                    printf("|                            Bem vindo! | Cinemas CineC                        |\n");
                    printf("+------------------------------------------------------------------------------+\n");
                    printf("|                                  Carrinho:                                   |\n");
                    printf("|==============================================================================|\n");
                    printf("|                                                                              |\n");
                    printf("|                                                                              |\n");
                    printf("|               %02ix Ingresso (Inteira)..................R$%06.2f               |\n", nIngInteira, (float)nIngInteira*valorInteira);
                    printf("|                                                                              |\n");
                    printf("|               %02ix Ingresso (Meia).....................R$%06.2f               |\n", nIngMeia, nIngMeia*valorMedia);
                    printf("|                                                                              |\n");
                    printf("|               ================================================               |\n");
                    printf("|                                                                              |\n");
                    printf("|               Total...................................R$%06.2f               |\n", (nIngMeia*valorMedia + nIngInteira*valorInteira));
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
                    printf("+------------------------------------------------------------------------------+\n> ");
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
                } while (input != 2 && cancelado != 1);
            }

            if (cancelado == 0) {
                system("cls");
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
        }

    } while(desligado != 1);

    return 0;
}
