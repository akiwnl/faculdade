// 5. Escreva uma função que imprime a tabuada de um número informado. Dica: lembre-se que você
// pode alinhar os valor na saída com %2d (dois dígitos, alinhados à direita)

#include <stdio.h>
void print_mult_table(int number){

    int i;

    for (i = 1 ; i<=10 ; i++)
    {
        printf("%d x %d = %2d \n",number,i,number*i);
    }



}


int main(){
    print_mult_table(9);
    return 0;   
}