// 1. Escreva uma programa que lê (pelo terminal) dois números inteiros (a e b) e informa:
// a. Adição
// b. Subtração (a menos b)

#include <stdio.h>

int main(){
    int n1;
    int n2;


    printf("Digite um numero: \n");
    scanf("%d", &n1);
    printf("Digite outro numero\n");
    scanf("%d", &n2);

    printf("%d + %d = %d \n", n1, n2 , (n1 + n2));
    printf("%d - %d = %d", n1, n2, (n1 - n2));

    return 0;
}