#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

void print_vector(int n, int v[]){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
}

// 1. Escreva uma função que aloca na heap um array de inteiros de tamanho n, preenchido com zeros,
// e retorna seu endereço.
// int* create_vector(int n)
// Exemplo de uso da função:
// int* v1 = create_vector(7);
// print_vector(7, v1);
// free(v);
// // aloca array de 7 inteiros na heap
// // imprime 0,0,0,0,0,0,0
// // libera array alocado na heap

int* create_vector(int n){
    int *ptr = malloc(n * sizeof(int));

    if (ptr)
    {
        for (int i = 0; i < n; i++)
        {
            ptr[i] = 0;
        }
        return ptr;
    }
    else
    {
        printf("Ocorreu um erro na alocação de memória \n");
    }
}


//-----------------------------------------------------------------------------------------------------------------------------------//

// 2. Escreva uma função que receba um vetor de inteiros e seu tamanho n. A função deve retornar o
// endereço de um novo vetor, alocado na heap, contendo os max maiores elementos contidos no
// vetor original. OBS: você pode modificar o conteúdo do vetor original, se necessário.
// int* get_largest(int n, int* v, int max)
// Exemplo de uso da função:
// int v0[] = {6,10,2,1,2,3,9}
// int* v1 = get_largets(7, v0, 2); // retorna vetor com os 2 maiores valores de v0
// print_vector(2, v1);
// // imprime 10,9
// free(v1);
// // libera array alocado na heap

int* get_largest(int n, int* v, int max){
    int *ptr = malloc(max * sizeof(int));

    for (int i = 0; i < max; i++)
    {
        int largest = INT_MIN;
        int largest_index = -1;
        for (int j = 0; j < n; j++)
        {
            if (v[j] > largest)
            {
                largest = v[j];
                largest_index = j;
            }
        }

        ptr[i] = largest;
        v[largest_index] = INT_MIN;
    }
    return ptr;
}

//-----------------------------------------------------------------------------------------------------------------------------------//


// 3. Escreva uma função que receba o endereço de uma string. A função deve retornar o endereço de
// uma cópia da string alocada na heap.
// char* copy_string(const char* str) // 'const' indica que o vetor original não
// // pode ser modificado dentro da função

char* copy_string(const char* str){
    int lenght = strlen(str);

    char* copy = malloc((lenght + 1) * sizeof(char));

    if (copy == NULL) {
        perror("Erro ao alocar memória");
        return NULL;
    }

    strcpy(copy,str);

    return copy;
}

//-----------------------------------------------------------------------------------------------------------------------------------//

// 4. Escreva uma função que receba o endereço de uma string. A função deve retornar o endereço de
// uma cópia reversa da string alocada na heap.
// char* copy_reverse(const char* str)
char* copy_reverse(const char* str){
    int lenght = strlen(str);

    char* reverse = malloc((lenght + 1) * sizeof(char));

    int j = lenght - 1;
    for (int i = 0; str[i] != '\0' ; i++)
    {
        reverse[i] = str[j--];
    }
    
    return reverse;
}


//-----------------------------------------------------------------------------------------------------------------------------------//

// 5. Escreva uma função que concatene duas strings e retorne o resultado em uma nova string, alocada
// na heap.
// char* concat_string(const char* str1, const char* str2)
char* concat_string(const char* str1, const char* str2){

    char* vet = malloc(((strlen(str1) + strlen(str2))+ 1) * sizeof(char));
    
    strcpy(vet,str1);
    strcat(vet,str2);

    return vet;
}



//-----------------------------------------------------------------------------------------------------------------------------------//

// 6. Escreva uma função que realize a união entre dois vetores, retornado o resultado em um vetor
// alocado na heap.
int* unionn(int n1, const int* v1, int n2, const int* v2){
    int* vet = malloc((n1+n2)*sizeof(int));

    int i, j;
    for (int k = 0; k < n1; k++)
    {
        vet[i++] = v1[k];
    }
    
    for (int k = 0; k < n2; k++)
    {
        int duplicado = 0;
        for (int j = 0; j < i; j++)
        {
            if (v2[k] == vet[j])
            {
                duplicado = 1;
                break;
            }
        }
        if (!duplicado)
        {
            vet[i++] = v2[k];
        }   
    }
    vet = realloc(vet, i * sizeof(int));
    return vet;
}

//-----------------------------------------------------------------------------------------------------------------------------------//

// 7. Escreva uma função que realize a intersecção entre dois vetores, retornado o resultado em um
// vetor alocado na heap.
int* intersection(int n1, const int* v1, int n2, const int* v2){
    int maxSize = (n1 < n2) ? n1 : n2;
    int *v3 = malloc((maxSize + 1) * sizeof(int));

    int k = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (v1[i] == v2[j])
            {
                v3[k++] = v1[i];
                break;
            }
        }
    }
    v3[k] = -1; //opcional
    return v3;
}

//-----------------------------------------------------------------------------------------------------------------------------------//

// 8. Escreva uma função que recebe o endereço e as dimensões de uma matriz alocada na heap. A
// função deve imprimir seu conteúdo. Lembre-se: dentro da função, o acesso aos elementos da
// matriz v ocorre normalmente por meio do operador de índice. Ex: v[0][2].
void print_vector2D(int m, int n, const int** v){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------//

// 9. Escreva uma função que aloca na heap uma matriz de inteiros de dimensões mxn e retorna o seu
// endereço. A matriz deve ser preenchida com uma sequência crescente de inteiros.
int** create_vector2D(int m, int n){
    int** v = malloc(m * sizeof(int*));

    int k = 1;
    for (int i = 0; i < m; i++)
    {
        v[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            v[i][j] = k;
            k++;
        }
        
    }
    return v;
}


//-----------------------------------------------------------------------------------------------------------------------------------//

// 10. Escreva uma função que receba uma matriz na stack como entrada e retorne o endereço de sua
// transposta, alocada na heap.
int** transpose(int rows, int cols, int v[rows][cols]){
    int** v2 = (int**)malloc(cols * sizeof(int*));
    for (int i = 0; i < cols; i++)
    {
        v2[i] = (int*)malloc(rows * sizeof(int));
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            v2[j][i] = v[i][j];
        }
    }
    
    return v2;
}

//-----------------------------------------------------------------------------------------------------------------------------------//

// 11. Escreva uma função que receba o endereço de uma string contendo palavras separadas por
// espaços. A função deve retornar o endereço de um vetor de strings (matriz de caracteres) contendo
// as palavras separadas. Além disso, deve retornar, via parâmetro, o número de palavras
// encontradas.
// char** split(const char* str, int* n)
// Exemplo de uso da função:
// char str[] = " Texto de
// teste com várias palavras ";
// int size = 0;
// char** tokens = split(str, &size); // devolve vetor de strings com as palavras
// for (int i = 0; i < size; i++)
// printf("%s\n", tokens[i]);
// // imprime as palavras encontradas
// // libera vetor de strings alocado na heap
// for (int i = 0; i < size; i++)
// free(tokens[i]);
// free(tokens);

int main(){
    // 1-
    // int* v1 = create_vector(7);
    // print_vector(7, v1);
    // free(v1);

    // 2-
    // int v0[] = {6, 10, 2, 1, 2, 3, 9};
    // int* v1 = get_largest(7, v0, 5);
    // print_vector(5, v1);
    // free(v1);

    // 3-
    // const char *str = "Hello, World!";
    // char *str1 = copy_string(str);
    // printf("%s\n",str1);
    // free(str1);

    // 4-
    // const char *str = "Kaike";
    // char *str1 = copy_reverse(str);
    // printf("%s\n",str1);
    // free(str1);

    // 5-
    // const char *str = "Kaike";
    // const char *str1 = "Carvalho";
    // char *str2 = concat_string(str,str1);
    // printf("%s\n",str2);
    // free(str2);    

    // 6-
    // int v1[] = {1, 2, 3, 4, 5};
    // int v2[] = {3, 4, 5, 6, 7};

    // int n1 = sizeof(v1) / sizeof(v1[0]);
    // int n2 = sizeof(v2) / sizeof(v2[0]);

    // int* resultado = unionn(n1, v1, n2, v2);

    // if (resultado != NULL) {
    //     printf("Resultado da União: ");
    //     for (int i = 0; i < n1 + n2; i++) {
    //         printf("%d ", resultado[i]);
    //     }

    //     free(resultado);
    // }

    // 7-
    // int array1[] = {7, 2, 3, 4, 5, 6, 1};
    // int array2[] = {3, 4, 5, 6, 7};
    // int* result = intersection(7, array1,5, array2);
    // printf("Intersection: ");
    // for (int i = 0; result[i] != -1; ++i) {
    //     printf("%d ", result[i]);
    // }
    // free(result);

    // 8-
    // int v[3][4] = { {1,2,3,4},
    //                 {5,6,7,8},
    //                 {9,10,11,12}
    //             };

    // int rows = 3;
    // int cols = 4;

    // int** myMatrix = malloc(rows * sizeof(int*));
    // for (int i = 0; i < rows; i++) {
    //     myMatrix[i] = malloc(cols * sizeof(int));
    // }
    // for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < cols; j++) {
    //         myMatrix[i][j] = i * cols + j + 1;
    //     }
    // }
    // print_vector2D(3,4,myMatrix);

    // for (int i = 0; i < rows; i++) {
    //     free(myMatrix[i]);
    // }
    // free(myMatrix);

    // 9-
    // int m = 3;
    // int n = 4;
    // int** matrix = create_vector2D(m, n);
    // if (matrix != NULL) {
    //     print_vector2D(3,4,matrix);
    //     for (int i = 0; i < m; i++) {
    //         free(matrix[i]);
    //     }
    //     free(matrix);
    // } 

    // 11-
    

    return 0;
}