#include <stdio.h>


void rect_left(int height){
    for (int i = 0; i < height; i++){
        for (int j = 0; j <= i; j++){
            printf("[]");
        }
        printf("\n");
    }
    
}

void rect(int height , int width){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            printf("[]");
        }
        printf("\n");
    }
    
}



int main(){

    rect_left(5);
    rect(5, 5);
    return 0;
}