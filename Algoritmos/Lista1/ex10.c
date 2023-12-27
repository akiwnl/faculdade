// 10. Escreva uma função que recebe três notas escolares n1, n2 e n3 (0..10). A função deve calcular e
// imprimir a média aritmética simples das três notas, bem como, o conceito que o aluno obteve pela
// média, segundo estes critérios:
// a. Conceito A, se média no intervalo [8,5..10]
// b. Conceito B, se média no intervalo [7,0..8,5[
// c. Conceito C, se média no intervalo [5,5..7,0[
// d. Conceito F, se média inferior a 5,5
// Função: void print_grade(float n1, float n2, float n3)

#include <stdio.h>


void print_grade(float n1, float n2, float n3){

    float media = (n1 + n2 + n3) / 3;
    printf("media = %.2f \n", media);

    if (media >= 8.5 && media <= 10){
        printf("A");
    }
    else if(media >= 7.0 && media < 8.5){
        printf("B");
    }
    else if(media >= 5.5 && media < 7.0){
        printf("C");
    }
    else if(media < 5.5){
        printf("F");
    }
}





int main(){
    print_grade(5.0, 4.5, 3.5);
    return 0;
}