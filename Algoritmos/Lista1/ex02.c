// 2. Escreva um programa que lê dois números inteiros (a e b) e informa:
// a. Multiplicação
// b. Divisão inteira (a dividido por b)
// c. Divisão float (a dividido por b)

#include <stdio.h>

int main(){

    int n1;
    int n2;

    printf("Digite um numero: \n");
    scanf("%d", &n1);
    printf("Digite outro numero\n");
    scanf("%d", &n2);

    printf("%d x %d = %d \n", n1, n2, (n1*n2));
    printf("%d / %d = %d \n", n1, n2 , (n1 / n2));
    printf("%d / %d = %f \n", n1, n2 , (float) n1 / n2);



    return 0;
}