#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 1. Escreva um programa em C que declara três variáveis (char, int e double) e imprime seus
// endereços.

void exercicio_um(char a, int b, double c){

    printf("%p \n%p \n%p \n", &a,&b,&c);
}
// 2. Escreva uma função que recebe o endereço de duas variáveis inteiras. A função deve somar os
// valores contidos nessas variáveis por meio de seus endereços, colocando o resultado na primeira.
void add(int* a, int* b){
    *a = *a + *b;
    printf("%d \n", *a);
}


// 3. Escreva uma função que recebe o comprimento e o endereço de um vetor, e imprime o seu
// conteúdo, sem utilizar o operador de índice [ ] para acessar os elementos do vetor.
void print_vector(int n, const int* v){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *v);
        v++;
    }
    
}    


// 4. Escreva uma função que recebe o comprimento e o endereço de um vetor, e imprime o seu
// conteúdo em ordem reversa, sem utilizar o operador de índice [ ] para acessar os elementos do
// vetor.
void print_vector_reverse(int n, const int* v){
    v += n -1;

    for (int i = 0; i < n; i++)
    {
        printf("%d ",*v);
        v--;
    }
    
}


// 5. Escreva uma função que recebe o comprimento e o endereço de um vetor. A função deve retornar,
// via parâmetros min e max, o maior e o menor valor contido no vetor. Você não deve utilizar o
// operador de índice [ ] para acessar os elementos do vetor.
void get_min_max(int n, const int* v, int* min, int* max){
    *min = 999999;
    *max = 0;
    for (int i = 0; i < n; i++)
    {
        if (*v < *min)
        {
            *min = *v; 
        }
        if (*v > *max)
        {
            *max = *v;
        }
        v++;
    }
    printf("MAIOR: %d \nMENOR:%d ",*max,*min);
}

// 6. Escreva uma função que recebe as dimensões e o endereço de uma matriz (vetor bidimensional).
// A função deve imprimir seu conteúdo, sem utilizar o operador de índice [ ] para acessar os
// elementos da matriz.
// void print_vector2D(int rows, int cols, const int* v)
// Exemplo de uso da função:
// int v[3][4] = {
// {1, 2, 3, 4},
// {5, 6, 7, 8},
// {9,10,11,12}
// };
// print_vec2(3, 4, (int*)v);
// Saída:
// 01 02 03 04
// 05 06 07 08

void print_vector2D(int rows, int cols, const int* v){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf(" %02d", *v);
            v++;
        }
        printf("\n");
    }
}
// 7- Escreva uma função que recebe o endereço de uma string. A função deve concatenar, ao final da
// string original, uma barra vertical, seguida do conteúdo da string de forma invertida. Considere que
// o vetor possui comprimento suficiente para a adição dos novos caracteres. Você não deve utilizar o
// operador de índice [ ] para acessar os caracteres da string.
// void make_mirrored(char* str)
// Exemplo de uso da função:
// char name[40] = "John Doe";
// make_mirrored(name);
// printf("%s\n", name);
// // Saída "John Doe|eoD nhoJ"
void make_mirrored(char* str){
    char *p = str;
    int count = 0;

    while (*p != '\0')
    {
        printf("%c",*p);
        p++;
        count++;
    }
    printf("|");
    char *v = str + (count-1);
    while (*v != *p)
    {
        printf("%c",*v);
        v--;
    }
    printf("\n");
}
// 8-Escreva uma função que recebe o endereço de duas strings e calcula a distância de Hamming
// entre ambas. A distância de Hamming corresponde à quantidade de caracteres diferentes em
// posições correspondentes nas duas strings. Considere que as strings terão o mesmo comprimento,
// mas certifique-se de que o código não acessa posições inválidas para strings de tamanhos
// distintos.
// void get_hamming_distance(const char* str1, const char* str2)
// Exemplo de uso da função:
// int dist = get_hamming_distance("banana", "cabana"); // dist = 2
// /*
// banana
// << distância de Hamming é 2
// cabana
// */
void get_hamming_distance(const char* str1, const char* str2){
    int distance = 0;
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
        {
            distance++;
        }
        str1++;
        str2++;
    }
    return distance;
}
// 9. Escreva uma função que recebe o endereço de uma string str e de um vetor de strings words (de
// até 49 caracteres). A função deve devolver o endereço da string de words que seja mais similar à
// str, isto é, com a menor distância de Hamming. OBS: faça chamadas à função do exercício anterior
// para encontrar as distâncias entre str e cada uma das palavras em words.
// char* find_most_similar(const char* str, int n, char list[n][50]);
// Exemplo de uso da função:
// char words[][50] = {"cabana", "savana", "bacana", "halana"};
// char* most_similar = find_most_similar("banana", 4, words);
// printf("%s\n", most_similar);
// // "bacana"
int hamming_distance(const char* str1, const char* str2) {
    int distance = 0;
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            distance++;
        }
        str1++;
        str2++;
    }
    
    while (*str1) {
        distance++;
        str1++;
    }
    while (*str2) {
        distance++;
        str2++;
    }
    return distance;
}

char* find_most_similar(const char* str, int n, char list[n][50]) {
    int min_distance = hamming_distance(str, list[0]);
    char* most_similar = list[0];

    for (int i = 1; i < n; i++) {
        int distance = hamming_distance(str, list[i]);
        if (distance < min_distance) {
            min_distance = distance;
            most_similar = list[i];
        }
    }

    return most_similar;
}


// 10. Escreva uma função que recebe o endereço de um Rect e imprime um tablado de acordo com a
// posição x,y e as dimensões width e height. Você pode considerar cada caractere do terminal
// como uma unidade para posição/tamanho.
// struct rect {
// int x, y, width, height; // é possível declarar os campos em uma só linha
// };
// typedef struct rect Rect;
// void print_board(Rect* board);
// Exemplo de uso da função:
// Rect rect = {5,5,10,10}; // posição 5,5 (x,y) e dimensões 10x10 (width,height)
// print_board(&rect);
struct rect {
    int x, y, width, height;
};

typedef struct rect Rect;

void print_board(Rect* board) {
    for (int i = 0; i <= board->height; i++) {
        for (int j = 0; j <= board->width; j++) {
            if ((i >= board->y && i < board->y + board->height) &&
                (j >= board->x && j < board->x + board->width)) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// 11. Modifique a função do exercício anterior para que receba o endereço de um Point e o imprima
// dentro de um tablado de dimensões definido por um Rect. As coordenadas do Point devem ser
// relativas à do Rect, isto é, um Point na posição (0,0) deve ser desenhado no canto esquerdo
// superior do Rect. Caso a posição do Point extrapole os limites do Rect, não deve ser desenhado.
// struct point {
// int x, y;
// char symbol;
// };
// typedef struct point Point;
// // é possível declarar os campos em uma só linha
// void print_board2(Point* point, Rect* board);

struct point {
    int x, y;
    char symbol;
};

typedef struct point Point;

struct rect {
    int x, y, width, height;
};

typedef struct rect Rect;

void print_board2(Point* point, Rect* board) {
    for (int i = 0; i <= board->height; i++) {
        for (int j = 0; j <= board->width; j++) {
            if ((i >= board->y && i < board->y + board->height) &&
                (j >= board->x && j < board->x + board->width)) {
                if (i == point->y - board->y && j == point->x - board->x) {
                    printf("%c", point->symbol);
                } else {
                    printf("."); 
                }
            } else {
                printf(" "); 
            }
        }
        printf("\n");
    }
}

// 12. Modifique a função do exercício anterior para que receba o endereço de vetor de Point. A função
// deve imprimir todos os pontos dentro do tablado, seguindo as mesmas orientações do exercício
// mencionado.
// void print_board3(Point* points, Rect* board);
// Exemplo de uso da função:
// Rect rect = {5,5,10,10}; // posição 5,5 (x,y) e dimensões 10x10 (width,height)
// Point points[] = { {0,0,'A'}, {2,7,'B'}, {9,9,'C'} };
// print_board3(points, &rect);
void print_board3(Point* points, Rect* board, int num_points) {
    for (int i = 0; i <= board->height; i++) {
        for (int j = 0; j <= board->width; j++) {
            int point_found = 0;
            for (int k = 0; k < num_points; k++) {
                Point* point = &points[k];
                if ((point->x == j + board->x) && (point->y == i + board->y)) {
                    printf("%c", point->symbol);
                    point_found = 1;
                    break;
                }
            }
            if (!point_found) {
                if ((i >= board->y && i < board->y + board->height) &&
                    (j >= board->x && j < board->x + board->width)) {
                    printf(".");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}




int main(){
    int *min;
    int *max;
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    return 0;
}