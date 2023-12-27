// 12. Escreva um programa que lê um caractere e informa:
// a. Se é letra e, neste caso, também informa se é vogal ou consoante;
// b. Se é número;
// c. Se é símbolo (ASCII 33 ao 126, exceto números e símbolos).

#include <stdio.h>

int main() {
    char caractere;

    printf("Digite um caractere: ");
    scanf("%c", &caractere);

    if ((caractere >= 'a' && caractere <= 'z') || (caractere >= 'A' && caractere <= 'Z')) {
        printf("O caractere é uma letra.\n");

        if (caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u' ||
            caractere == 'A' || caractere == 'E' || caractere == 'I' || caractere == 'O' || caractere == 'U') {
            printf("É uma vogal.\n");
        } else {
            printf("É uma consoante.\n");
        }
    } else if (caractere >= '0' && caractere <= '9') {
        printf("O caractere é um número.\n");
    } else if ((caractere >= 33 && caractere <= 47) || (caractere >= 58 && caractere <= 126)) {
        printf("O caractere é um símbolo.\n");
    } else {
        printf("O caractere não se encaixa em nenhuma categoria conhecida.\n");
    }

    return 0;
}
