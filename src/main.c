# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

# define fileiras 10
# define assentos 8

int main() {
    setlocale(LC_ALL, "portuguese");

    printf("fileiras: %d assentos: %d\n\n", fileiras, assentos);

    system("pause");
    return 0;
}