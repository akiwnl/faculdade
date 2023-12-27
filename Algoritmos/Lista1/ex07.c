// 7. Escreva uma função que recebe um número de dias e informa a quantidade correspondente em:
// anos + semanas + dias.
// a. Considere:
// i. Ano = 365 dias
// ii. Semana = 7 dias
// b. Exemplo:
// Dias: 427 = 1 ano(s), 8 semana(s) e 6 dia(s)
// Função: void print_days(int days)


#include <stdio.h>

void print_days(int days){

    int anos = days / 365;
    int restoAnos = days % 365;

    int semanas = restoAnos / 7;
    int dias = restoAnos % 7;
    printf("Dias: %d = %d ano(s), %d semana(s) e %d dia(s)\n", days, anos, semanas, dias);

}

int main(){
    print_days(427);

    return 0;
}