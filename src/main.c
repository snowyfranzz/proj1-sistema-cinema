# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

# define FILEIRAS 10
# define ASSENTOS 8
# define METADELIN FILEIRAS / 2
# define METADECOL ASSENTOS / 2

/*
Guia de refatoração caso os caractéres corrompam denovo:

INVÁLIDO
Próxima Sessão
Disponíveis
máximo
Não
Inválido
Sugestões
lógica
Disponível
número
Não foi possível

*/

void LimpaBuffer() {
    int c;
    while(c = getchar() != '\n' && c != EOF);
}

int main() {
    int cinema[FILEIRAS][ASSENTOS] = {0}, matrizTemp[FILEIRAS][ASSENTOS] = {0}, fileiraTemp, assentoTemp, i, j, k, jk, grupo;
    int incomodo, incomodoFileiras, menosIncomodo, minEsquerdo = 0, fil = 0, recomendEsquerdo[2], recomendDireito[2], recomendFil[2];

    int input, desligado, cancelado = 0, ingressosEscolhidos, cancelaMeia = 0, cancelaInteira = 0, cancelaTotal = 0, ingressosTemp = 0;

    int criticaS = 0, criticaN = 0;

    int ingressos[2] = {0,0}, nIngMeia, nIngInteira, dividir;
    float valorMedia = 9.5, valorInteira = 19.0;

    int assentosDisponiveis = (FILEIRAS * ASSENTOS), assentosOcupados, somaAssentos = 0;

    int somaFileira, somaFileiraComp, somaMaisVazia, somaMaisCheia;

    setlocale(LC_ALL, "Portuguese");

    if (FILEIRAS < 10 || FILEIRAS > 31 || ASSENTOS < 1 || ASSENTOS > 31) {
        printf("\n\nNUMERO DE FILEIRAS OU ASSENTOS INVÁLIDO\n\n");
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
        if (cancelado != 1) {
            assentosDisponiveis -= ingressos[0];
        }
        input = 0, desligado = 0, cancelado = 0, nIngMeia = 0, nIngInteira = 0, ingressos[0] = 0, ingressos[1] = 0, fileiraTemp = 0, assentoTemp = 0, dividir = 2, ingressosEscolhidos = 0;

        // PRIMEIRA TELA
        do {

            assentosOcupados = (FILEIRAS * ASSENTOS) - assentosDisponiveis;

            system("cls");
            ingressos[0] = nIngInteira + nIngMeia;
            printf("+------------------------------------------------------------------------------+\n");
            printf("|                          Bem vindo! | Cinemas CineC                          |\n");
            printf("+------------------------------------------------------------------------------+\n");
            printf("|                        Percentual de Ocupação: %5.1f%%                        |\n", ((float)assentosOcupados/(FILEIRAS * ASSENTOS))*100);
            printf("|                        Assentos Ocupados:      %3i                           |\n", assentosOcupados);
            printf("|                        Assentos Disponíveis:   %3i                           |\n", assentosDisponiveis);
            printf("+------------------------------------------------------------+-----------------+\n");
            printf("|                         Ingressos:                         |    Carrinho:    |\n");
            printf("|============================================================|=================|\n");
            printf("|                                                            |%2ix..Inteira     |\n", nIngInteira);
            printf("|       Inteira...............................R$ %05.2f       |%2ix..Meia-Entrada|\n",valorInteira, nIngMeia);
            printf("|                                                            |                 |\n");
            printf("|       Meia Entrada..........................R$ %5.2f       |Total:           |\n",valorMedia);
            printf("|                                                            |- %02i Ingressos   |\n", ingressos[0]);
            printf("|                                                            |- R$%6.2f       |\n", (nIngInteira*valorInteira + nIngMeia*valorMedia));
            printf("|*  O cliente pode comprar no máximo %2d ingressos de uma vez.|                 |\n", ASSENTOS * 2);
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
                    if(ingressos[0] < ASSENTOS * 2){
                        if(input == 2) {
                            nIngInteira++;
                        } else {
                            nIngMeia++;
                        }
                    } else {
                        system("cls");
                        printf("Você pode comprar somente %2d ingressos de uma vez!\n",ASSENTOS * 2);
                        system("pause");
                    }
                    break;

                case 4:
                    if(ingressos[0] > 0){
                        if (ingressos[0] > 1) {
                            system("cls");
                            printf("Deseja dividir os ingressantes? (1. Sim | 2. Não) > ");
                            scanf("%d",&dividir);
                            LimpaBuffer();
                        }
                    } else {
                        system("cls");
                        printf("Insira pelo menos 1 ingresso no seu carrinho para continuar!\n");
                        input = 0;
                        system("pause");
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
            recomendEsquerdo[0] = 0;
            recomendEsquerdo[1] = 0;
            recomendDireito[0] = 0;
            recomendDireito[1] = 0;

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
                            if (FILEIRAS % 2 == 0) {
                                incomodoFileiras += (METADELIN - (i + 1));
                            } else {
                                incomodoFileiras += (METADELIN - i);
                            }
                        } else {
                            incomodoFileiras += (i - METADELIN);
                        }

                    for (j = 0; j < ASSENTOS; j++) {

                        incomodo = 0;

                        for (k = 0; k < ingressos[grupo]; k++) {

                            jk = j + k;

                            if (cinema[i][jk] == 1 || jk >= ASSENTOS || (grupo > 0 && i + 1 == recomendFil[0] && jk + 1 >= recomendEsquerdo[0] && jk + 1 <= recomendDireito[0])) {
                                incomodo = 999;
                                break;
                            }

                            incomodo += incomodoFileiras;

                            if (jk < METADECOL) {


                                if (ASSENTOS % 2 == 0) {
                                    incomodo += (METADECOL - (jk + 1));
                                } else {
                                    incomodo += (METADECOL - jk);
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

                recomendEsquerdo[grupo] = minEsquerdo;
                recomendDireito[grupo] = minEsquerdo + (ingressos[grupo] - 1);
                recomendFil[grupo] = fil;
            }
            ingressos[0] += ingressos[1];
            ingressos[1] = 0;

            // Mais vazia e mais cheia

            somaMaisVazia = ASSENTOS, somaMaisCheia = 0;

            for(i = 0; i < FILEIRAS; i++){
                somaFileira = 0;
                for(j = 0; j < ASSENTOS; j++){
                    somaFileira += cinema[i][j];
                }

                if(somaFileira > somaMaisCheia){
                    somaMaisCheia = somaFileira;
                } else {
                    if(somaFileira < somaMaisVazia){
                        somaMaisVazia = somaFileira;
                    }
                }
            }




            do {
                criticaN = 0;
                system("cls");
                printf("+--------------------------------------------------------------");
                for (i = 0; i < ASSENTOS; i++) {
                    printf("--");
                }
                printf("+\n");

                printf("|                  ");
                for (i = 0; i < METADECOL; i++) {
                    printf("  ");
                }
                printf("Bem vindo! | Cinemas CineC");
                for (i = 0; i < (METADECOL + ASSENTOS % 2); i++) {
                    printf("  ");
                }
                printf("                  |\n");

                printf("+--------------------------------------------------------------");
                for (i = 0; i < ASSENTOS; i++) {
                    printf("--");
                }
                printf("+\n");

                printf("|");
                for (i = 0; i < METADECOL; i++) {
                    printf("  ");
                }
                printf(" Cinema: ");
                for (i = 0; i < (METADECOL + ASSENTOS % 2); i++) {
                    printf("  ");
                }
                printf("|        Informações:       |       Sugestões:       |\n");

                printf("|=========");
                for (i = 0; i < ASSENTOS; i++) {
                    printf("==");
                }
                printf("|===========================|========================|\n");

                printf("|    ");
                for (i = 0; i < ASSENTOS; i++) {
                    printf("%2d", i + 1);
                }
                printf("     | 0:  Assento Disponível    |                        |\n");

                printf("|");
                for (i = 0; i < ASSENTOS; i++) {
                    printf("  ");
                }
                printf("         | 1:  Assento Ocupado       |     %2d Ingresso(s)     |\n", ingressos[0]);

                for (i = 0; i < FILEIRAS; i++) {

                    criticaS = 0;
                    somaFileiraComp = 0;
                    printf("| %02d  ", i + 1);

                    for (j = 0; j < ASSENTOS; j++) {
                        somaFileiraComp += cinema[i][j];
                        if (cinema[i][j] == 1) {
                            criticaS++;
                        }

                        printf("%d ", cinema[i][j]);
                        if (j + 1 == ASSENTOS) {

                            if (somaFileiraComp == somaMaisVazia) {
                                printf("*");
                            } else {
                                if (somaFileiraComp == somaMaisCheia) {
                                    printf("!");
                                } else {
                                    printf(" ");
                                }
                            }

                            if ((float) criticaS / ASSENTOS >= 0.75) {
                                criticaN++;
                                printf("#%d", ASSENTOS - criticaS);
                            } else {
                                printf("  ");
                            }
                        }
                    }

                somaFileiraComp = 0;

                    switch(i) {
                        case 0:
                            printf(" | !:  Fileira Mais Cheia    |                        |\n");
                            break;
                        case 1:
                            printf(" | *:  Fileira Mais Vazia    |------------------------|\n", nIngMeia, nIngMeia*valorMedia);
                            break;
                        case 2:
                            printf(" | #x: Fileira Crítica       |  Fileira  |  Assentos  |\n");
                            break;
                        case 3:
                            printf(" |===========================|-----------+------------|\n");
                            break;
                        case 4:
                            printf(" | Ocupação:           %5.1f%%|           |            |\n", (float)assentosOcupados/(FILEIRAS * ASSENTOS) * 100);
                            break;
                        case 5:
                            if (recomendEsquerdo[0] != 0 && menosIncomodo < 999) {
                                if (recomendEsquerdo[0] != recomendDireito[0]) {
                                    printf(" | Fileiras Críticas:     %2d | * %02d      | * %02d ao %02d |\n", criticaN, recomendFil[0], recomendEsquerdo[0], recomendDireito[0]);
                                } else {
                                    printf(" | Fileiras Críticas:     %2d | * %02d      | * %02d       |\n", criticaN, recomendFil[0], recomendEsquerdo[0]);
                                }
                            } else {
                                printf(" | Fileiras Críticas:     %2d | * Nada    | * Nada     |\n", criticaN);
                            }
                            break;
                        case 6:
                            printf(" | Assentos Ocupados:    %3d |           |            |\n", assentosOcupados);
                            break;
                        case 7:
                            if (dividir == 1 && menosIncomodo < 999) {
                                if (recomendEsquerdo[1] != recomendDireito[1]) {
                                    printf(" | Assentos Disponíveis: %3d | * %02d      | * %02d ao %02d |\n", assentosDisponiveis, recomendFil[1], recomendEsquerdo[1], recomendDireito[1]);
                                } else {
                                    printf(" | Assentos Disponíveis: %3d | * %02d      | * %02d       |\n", assentosDisponiveis, recomendFil[1], recomendEsquerdo[1]);
                                }
                            } else {
                                printf(" | Assentos Disponíveis: %3d |           |            |\n", assentosDisponiveis);
                            }
                            break;
                        case 8:
                            printf(" | Ingressos Disponíveis: %2d |           |            |\n", ingressos[0] - ingressosEscolhidos);
                            break;
                        case 9:
                            printf(" |                           |           |            |\n");
                            break;
                        default:
                            printf(" |                           |           |            |\n");
                            break;
                    }

                }

                printf("+---------");
                for (i = 0; i < ASSENTOS; i++) {
                    printf("--");
                }
                printf("+---------------------------+------------------------+\n");

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

                printf("|                    ");
                for (i = 0; i < METADECOL; i++) {
                    printf("  ");
                }
                printf("1. Escolher assentos.          ");
                for (i = 0; i < (METADECOL + ASSENTOS % 2); i++) {
                    printf("  ");
                }
                printf("           |\n");

                printf("|                    ");
                for (i = 0; i < METADECOL; i++) {
                    printf("  ");
                }
                printf("2. Cancelar ingressos.         ");
                for (i = 0; i < (METADECOL + ASSENTOS % 2); i++) {
                    printf("  ");
                }
                printf("           |\n");

                printf("|                    ");
                for (i = 0; i < METADECOL; i++) {
                    printf("  ");
                }
                printf("3. Cancelar Compra. ");
                for (i = 0; i < (METADECOL + ASSENTOS % 2); i++) {
                    printf("  ");
                }
                printf("                      |\n");

                printf("+");
                for (i = 0; i < ASSENTOS; i++) {
                    printf("--");
                }
                printf("--------------------------------------------------------------+\n> ");

                scanf("%d", &input);
                LimpaBuffer();

                switch(input){
                    case 1:
                        if (ingressosEscolhidos != ingressos[0]) {
                            printf("Insira a fileira do assento (Ingresso #%d) > ", ingressosEscolhidos + 1);
                            if (!scanf("%d", &fileiraTemp)) {
                                fileiraTemp = 0;
                            }
                            LimpaBuffer();
                            fileiraTemp--;
                            printf("Insira o número do assento (Ingresso #%d) > ", ingressosEscolhidos + 1);
                            if (!scanf("%d", &assentoTemp)) {
                                assentoTemp = 0;
                            }
                            LimpaBuffer();
                            assentoTemp--;
                            if(cinema[fileiraTemp][assentoTemp] == 0 && matrizTemp[fileiraTemp][assentoTemp] == 0 && fileiraTemp >= 0 && fileiraTemp < FILEIRAS && assentoTemp >= 0 && assentoTemp < ASSENTOS){
                                matrizTemp[fileiraTemp][assentoTemp] = 1;
                                ingressosEscolhidos++;
                            } else {
                                printf("Não foi possível selecionar esse assento!\n");
                                i--;
                            }
                            system("pause");
                        } else {
                            ingressosEscolhidos++;
                        }

                        break;

                    case 2:

                        do{
                            if(ingressosEscolhidos == 0){
                                system("cls");
                                printf("Escolha pelo menos um assento antes de prosseguir!\n");
                                system("pause");
                            } else {

                                system("cls");
                                printf("\nQuantos assentos você deseja cancelar? (Assentos disponíveis: %d)\n\n> ", ingressosEscolhidos);
                                scanf("%d", &cancelaTotal);
                                LimpaBuffer();

                                if(cancelaTotal > ingressosEscolhidos || cancelaTotal <= 0){
                                    system("cls");
                                    printf("Número inválido! Você pode cancelar até %d assentos.\n", ingressosEscolhidos);
                                    system("pause");
                                } else {

                                    system("cls");
                                    printf("Assentos disponíveis para cancelar: \n\n");
                                    for(i = 0; i < FILEIRAS; i++){
                                        for(j = 0; j < ASSENTOS; j++){
                                            if(matrizTemp[i][j] == 1){
                                                printf("Fileira: %d, Assento: %d\n", i + 1, j + 1);
                                            }
                                        }
                                    }
                                    printf("\n\n");

                                    for(i = 0; i < cancelaTotal; i++){
                                        printf("%d / %d\n\n", i + 1, cancelaTotal);
                                        printf("\tInsira a fileira do assento que deseja cancelar: ");
                                        if (!scanf("%d", &fileiraTemp)) {
                                            fileiraTemp = 0;
                                        }
                                        LimpaBuffer();
                                        fileiraTemp--;

                                        printf("\tInsira o número do assento que deseja cancelar: ");
                                        if (!scanf("%d", &assentoTemp)) {
                                            assentoTemp = 0;
                                        }
                                        LimpaBuffer();
                                        assentoTemp--;

                                        if(cinema[fileiraTemp][assentoTemp] == 0 && matrizTemp[fileiraTemp][assentoTemp] == 1 && fileiraTemp >= 0 && fileiraTemp < FILEIRAS && assentoTemp >= 0 && assentoTemp < ASSENTOS){
                                            matrizTemp[fileiraTemp][assentoTemp] = 0;
                                            ingressosEscolhidos--;
                                        } else {
                                            printf("Não foi possível cancelar esse assento!\n");
                                            i--;
                                        }
                                        printf("\n");
                                    }

                                }

                            }
                        } while(input != 1 && input != 2 && cancelado != 0);
                        input = 3;
                        break;

                    case 3:
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


                    default:
                        system("cls");
                        printf("Comando Inválido!\n");
                        system("pause");

                        break;
                }
            }while ((input != 4 && ingressosEscolhidos != ingressos[0] + 1) && cancelado != 1);

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

            if (cancelado != 1) {
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

            for(i = 0; i<FILEIRAS; i++){
                for(j = 0; j<ASSENTOS; j++){
                    if (cancelado != 1) {
                        cinema[i][j] += matrizTemp[i][j];
                    }
                    matrizTemp[i][j] = 0;
                }
            }

        }

    } while(desligado != 1);

    return 0;
}
