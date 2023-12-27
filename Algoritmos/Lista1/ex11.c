// 11. Escreva um programa que lê um caractere da entrada. Se não for letra, informa. Se for letra,
// verifica se é maiúscula (e passa para maiúscula se necessário). Ao final, deve informar a letra
// digitada em maiúsculo

#include <stdio.h>


int main(){
    char caracter;

    printf("Ditite um caracter: \n");
    scanf("%c", &caracter);

    if((caracter >= 'a' && caracter <= 'z') || (caracter >= 'A' && caracter <= 'Z')){
        if(caracter >= 'a' && caracter <= 'z'){
            caracter = caracter + ('A' - 'a');
            printf("Caractere digitado em maiusculo: %c\n",caracter);
        }
    }
    else{
        printf("O caractere digitado não e uma letra.\n");
    }
    return 0;
}


