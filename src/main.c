# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

# define fileiras 10
# define assentos 8

int main() {
    int i, j, teatro[fileiras][assentos];

    setlocale(LC_ALL, "portuguese");

    //coloca cada valor como 0
    for (i = 0; i < fileiras; i++) {
        for (j = 0; j < assentos; j++) {
            teatro[i][j] = 0;
        }
    }

    //imprime matriz
    for (i = 0; i < fileiras; i++) {
            printf("\n");
        for (j = 0; j < assentos; j++) {
            printf("%d ", teatro[i][j]);
        }
    }

    //imprime numero de linhas/colunas
    printf("\n\nfileiras: %d assentos: %d\n\n", fileiras, assentos);

    system("pause");
    return 0;
}
