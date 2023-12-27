// 3. Escreva um programa que lê o raio (r) de um círculo. O programa deve informar: o diâmetro (2r), a circunferência (2πr) e a área do círculo (πr^2)
// Crie uma macro: #define PI 3.141593


#include <stdio.h>
#include <stdlib.h>



int main(){
    const double PI = 3.141593;
    float raio;

    printf("Qual o valor do raio?\n");
    scanf("%f", &raio);


    float diametro = (raio*2);
    printf("Diametro = %.2f \n", diametro);

    float circunferencia = 2 * PI * raio;
    printf("Circunferencia = %.2f \n", circunferencia);

    float area = PI*raio;
    printf("Area = %.2f \n", area);



    return 0;
}