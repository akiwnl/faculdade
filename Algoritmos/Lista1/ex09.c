// 9. Escreva uma função que recebe três números e os imprime em ordem crescente.
// Função: void print_sorted(int a, int b, int c)

#include <stdio.h>


void print_sorted(int a, int b, int c){

    if(a > b){
        int maior = a;
        a = b;
        b = maior;
    }
    if (a > c){
        int maior = a;
        a = c;
        c = maior;
    }
    if(b > c){
        int maior = b;
        b = c;
        c = maior;
    }

    printf("%d %d %d", a, b, c);
}
int main(){
    print_sorted(3,2,1);
    return 0;
}
