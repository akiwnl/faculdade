// 6. Escreva uma função que recebe um float e informa, separadamente:
// a. O número com 2 casas de precisão;
// b. A parte inteira e a parte decimal;
// c. Sua representação em notação científica (mantissa/expoente)**

#include <stdio.h>

void print_float(float number){

    printf("Numero com 2 casas de precisao: %.2f\n", number);
    int parte_inteira = (int)number;
    float parte_decimal = number - parte_inteira;
    printf("Parte inteira: %d\n", parte_inteira);
    printf("Parte decimal: %.4f\n", parte_decimal);
    printf("Sua representacao em notacao cientifica: %e",number);
}

int main(){
    print_float(102.5);
    return 0;
}