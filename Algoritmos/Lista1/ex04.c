// 4. Escreva um programa que lê dois números inteiros (a e b) e informa:
// a. Resto (utilizado o operador %)
// b. Resto (sem utilizar o operador %)
// i. Dica: Faça a divisão “no papel” e observe quais outras operações podem ser
// utilizadas para obter o resto

#include <stdio.h>


int main(){

    int n1, n2;

    printf("Digite um numero: \n");
    scanf("%d", &n1);
    printf("Digite outro numero\n");
    scanf("%d", &n2);

    int resto = n1 % n2;
    printf("Resto utilizando o operador = %d \n", resto);

    int x = n1 / n2;
    int y = n1 - (x*n2);
    printf("Resto nao utilizando o operador = %d \n",y);



    return 0;
}