#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

// 1. Escreva uma função que imprime o conteúdo de uma matriz.
// void print_matrix(int rows, int cols, int m[rows][cols])
// Ex: int mat[3][3] = { // 3 linhas x 3 colunas
// {1, 2, 3},
// {4, 5, 6},
// {7, 8, 9}
// };
// print_matrix(3, 3, mat); // imprime do 1 ao 9 na matriz exemplo

void print_matrix(int rows, int cols, int m[rows][cols]){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// 2. Escreva uma função que imprime o conteúdo de uma matriz ao contrário, isto é, do último elemento
// para o primeiro. Considerando a matriz do exemplo anterior, a função imprimiria do 9 ao 1.
// void print_reversed(int rows, int cols, int m[rows][cols])
void print_reversed(int rows, int cols, int m[rows][cols]){
    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = cols - 1; j >= 0; j--)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");      
    }
}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// 3. Escreva uma função que encontra e imprime o maior e o menor valores contidos em uma matriz.
void print_min_max(int rows, int cols, int m[rows][cols]){
    int max = m[0][0];
    int min = m[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (m[i][j] > max)
            {
                max = m[i][j];
            }
            if (m[i][j] < min)
            {
                min = m[i][j];
            }
            
        }
    }
    printf("MAIOR: %d \nMENOR: %d \n",max,min);
}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// 4. Escreva uma função que retorna a média aritmética simples de todos os elementos da matriz.

float average(int rows, int cols, int m[rows][cols]){
    int dividendo = 0;
    int divisor = rows * cols;
    for (int i = 0; i < rows; i++)
    {
        for(int j =0; j < cols; j++)
        {
            dividendo += m[i][j];
        }
    }
    float media = (float)dividendo / divisor;
    printf("%.2f ", media);
    return media;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// 5. Escreva uma função que inicia uma matriz com valores inteiros, iniciando em start e progredindo com step.
// void init_values(int rows, int cols, int m[rows][cols], int start, int step)
// Ex: int v[4][6];
// init_values(4, 6, v, 10, 2); // start=10, step=2
// // 10,12,14,16,18,20 << Matriz após chamada da função:
// // 22,24,26,28,30,32
// // 34,36,38,40,42,44
// // 46,48,50,52,54,56

void init_values(int rows, int cols, int m[rows][cols], int start, int step){
    int value = start;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            m[i][j] = value;
            value += step;
        }
        
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
      
}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// 6. Escreva uma função que inicia uma matriz com valores aleatórios, sorteados entre min e max, isto
// é [min..max]. Utilize a função rand() da biblioteca <stdlib.h> para obter os valores:
// void init_random(int rows, int cols, int m[rows][cols], int min, int max)
// Ex: int v[4][6];
// // matriz deve ser preenchida com valores aleatórios entre 5 e 50
// init_random(4, 6, v, 5, 50); // min=5, max=50

void init_random(int rows, int cols, int m[rows][cols], int min, int max){
    srand(time(NULL));
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++){
            m[i][j] = min + rand() % (max - min + 1);
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
      
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// 7. Escreva uma função que retorna o total da linha de maior soma em uma matriz. A função deve
// somar todos os elementos em cada linha da matriz, para então encontrar a linha de maior soma.
// int max_line(int rows, int cols, int m[rows][cols])
// Exemplo:
// int mat[5][5] = {
// { 1, 2, 3, 4, 5}, // soma: 15
// { 2, 4, 6, 8,10}, // soma: 30 ← esta linha possui a maior soma
// { 1, 2, 3, 4, 7}, // soma: 17
// { 2, 0, 6, 1,10}, // soma: 19
// { 7, 3, 4, 0, 0} // soma: 14
// };
// int res = max_line(5, 5, mat);
// printf("Maior soma: %d\n", res); // imprime 30
int max_line(int rows, int cols, int m[rows][cols]) {
    int maxSum = 0;
    int maxIndex = -1;

    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += m[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxIndex = i;
        }
    }

    return maxIndex;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// 8. Escreva uma função que recebe uma matriz e coloca as somas de cada linha na última coluna.
// void put_totals(int rows, int cols, int m[rows][cols])
// Exemplo:
// int mat[4][5] = {
// { 1, 2, 3, 4, 0},
// { 2, 4, 6, 8, 0},
// { 3, 6, 9, 12, 0},// O último elemento de cada linha receberá a soma
// { 4, 8, 12,16, 0} // da linha.
// };
// put_totals(4, 5, mat);
// // Após a chamada da função, a matriz ficará desta forma:
// // 1, 2, 3, 4, 10
// // 2, 4, 6, 8, 20
// // 3, 6, 9, 12,30 << O último elemento de cada linha recebeu a soma
// // 4, 8, 12,16,40 da linha.

void put_totals(int rows, int cols, int m[rows][cols]){
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += m[i][j];
            if (j == cols - 1)
            {
                m[i][j] = sum;
            }
        }
        sum = 0;
    }
    
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                printf("%d ",m[i][j]);
            }
            printf("\n");
        }
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// 9. Escreva uma função que verifica a igualdade entre duas matrizes. Ele deve retornar 1 (true) se as
// matrizes forem iguais ou 0 (false), caso sejam diferentes. Matrizes iguais possuem os mesmos
// elementos e as mesmas dimensões.
int matrix_equals(int r1, int c1, int m1[r1][c1], int r2, int c2, int m2[r2][c2]){
    if (r1 != r2 || c1 != c2)
    {
        printf("0\n");
        return 0;
    }
    else {
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < r2; j++)
            {
                if (m1[i][j] != m2[i][j])
                {
                    printf("0\n");
                    return 0;
                }
            }
        }
    }
    printf("1\n");
    return 1;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// 10. Escreva uma função que realiza a adição de duas matrizes m1 e m2, colocando o resultado em
// m3. Considere que todas as matrizes possuem as mesmas dimensões (rows x cols).
// Exemplo para matriz 3x2:
// m1 m2 m3
void sum(int rows, int cols, int m1[rows][cols], int m2[rows][cols]){
    int m3[rows][cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ",m3[i][j]);
        }
        printf("\n");
    }
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// 11. Escreva uma função que monta a transposta da matriz m1 em m2. Observe que deve haver uma
// compatibilidade entre as dimensões das matrizes.
// void transpose(int r1, int c1, int m1[r1][c1], int r2, int c2, int m2[r2][c2]).
// Exemplo para matriz 2x3:
// m1 m2
void transpose(int r1, int c1, int m1[r1][c1], int r2, int c2, int m2[r2][c2]){
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            m2[j][i] = m1[i][j];
        }   
    }

    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d ",m2[i][j]);
        }
        printf("\n");
    } 
    
}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// 12. Escreva uma função que troca as diagonais de uma matriz. Considere que a matriz é quadrada,
// com dimensões d.
void switch_diagonals(int d, int m1[d][d]){
    int n = d - 1;
    int temp;
    for (int i = 0; i < d; i++)
    {
        temp = m1[i][i];
        m1[i][i] = m1[i][n];
        m1[i][n] = temp;
        n--;

    }
    
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            printf("%d ",m1[i][j]);
        }
        printf("\n");
    }
    
    
}
// Exemplo para matriz 3x3:

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// 13. Escreva uma função que cria o Triângulo de Pascal em uma matriz e depois o imprime. A função
// deve receber o número de linhas desejado para o triângulo.
// void pascal_triangle(int n).
// DICA: Na função, declare uma matriz com n linhas e n+1 colunas (int m[n][n+1]).
// Inicie a primeira linha com zeros, exceto na posição 1. No triângulo de Pascal,
// cada dois números consecutivos (na mesma linha) devem ser somados, e o resultado
// deve ser colocado na posição abaixo, isto é, m[i+1][j+1] = m[i][j] + m[i][j+1]
// 21,2 11,3 ==> m[1+1][2+1] = m[1][2] + m[1][2+1]
// 32,3
// Ex: lines = 6
void pascal_triangle(int n) {
    int m[n][n + 1];
    
    m[0][1] = 1;
    for (int i = 2; i <= n; i++) {
        m[0][i] = 0;
    }

    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i + 1; j++) {
            m[i][j] = m[i - 1][j - 1] + m[i - 1][j];
        }
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= i + 1; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// 14. Escreva uma função que verifica se uma matriz contém um triângulo superior e devolve 1 (true) ou
// 0 (false). Considere que a matriz é quadrada, com dimensões d. Dica: nesta matriz, todos os
// elementos do triângulo esquerdo inferior, nos quais row > col, devem ser iguais a zero.
// int check_upper_triangle(int d, int m[d][d]).
// Exemplo para matrizes 2x2 e 3x3
int check_upper_triangle(int d, int m[d][d]){
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (i > j && m[i][j] != 0)
            {
                return 0;
            }   
        }
    }
    return 1;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// 15. Escreva uma função que verifica se uma matriz é identidade e devolve 1 (true) ou 0 (false).
// int check_identity(int rows, int cols, int m[rows][cols]).
// Exemplo para matriz 3x3
int check_identity(int rows, int cols, int m[rows][cols]){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if ((i == j && m[i][j] != 1) || (i != j && m[i][j] != 0))
            {
                return 0;
            }   
        }
    }
    return 1;
}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// 16. Escreva uma função que verifica se uma matriz é simétrica e devolve 1 (true) ou 0 (false). Em uma
// matriz simétrica os valores são espelhados em relação à diagonal principal. Considere que a matriz
// é quadrada, com dimensões d.
// int check_symmetric(int d, int m[d][d]).
// Exemplo para matriz 3x3
int check_symmetric(int d, int m[d][d]){
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if ((i != j) && m[i][j] != m[j][i])
            {
                return 0;
            }   
        }
    }
    return 1;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// 17. Escreva uma função que imprime um array de n strings de até len-1 letras.
// void print_strings(int n, int len, char list[n][len]).
// Ex: char v[6][20] = {"John", "Mary", "Jake", "Finn", "Ada", "Michael"};
// print_strings(6, 20, v);
void print_strings(int n, int len, char list[n][len]){
        for (int i = 0; i < n ; i++)
        {
            for (int j = 0; j < len-1; j++)
            {
                printf("%c",list[i][j]);
            }
            printf("\n");
        }
        
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// 18. Escreva uma função que imprime as palavras de maior e menor tamanhos em um array de n
// strings de até len-1 letras.
// void print_strings_minmax(int n, int len, char list[n][len]).
// Ex: char v[6][20] = {"Johnny", "Mariane", "Jak", "Samuel", "Ada", "Michelangelo"};
// print_strings_minmax(6, 20, v);
// // A função imprimirá:
// // Menor: Jak, Ada
// // Maior: Michelangelo
void print_strings_minmax(int n, int len, char list[n][len]){
    char menor[len];
    char maior[len];
    strcpy(menor,list[0]);
    strcpy(maior,list[0]);

    for (int i = 1; i < n; i++)
    {
        if (strlen(list[i]) < strlen(menor))
        {
            strcpy(menor,list[i]);
        }
        if (strlen(list[i]) > strlen(maior))
        {
            strcpy(maior,list[i]);
        }
        
    }
    printf("Menor: ");
    for (int i = 0; i < n; i++) {
        if (strlen(list[i]) == strlen(menor)) {
            printf("%s ", list[i]);
        }
    }

    printf("\n");
    printf("Maior: ");
    for (int i = 0; i < n; i++)
    {
        if (strlen(list[i]) == strlen(maior))
        {
            printf("%s ",list[i]);
        }
        
    }
      
}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// 19. Escreva uma função que retorna a quantidade de palavras em um array de n linhas de texto
// (strings de até len-1 letras). Considere que poderá haver mais de um espaço entre cada palavra,
// bem como, espaços no início ou final de cada string.
// int count_words(int n, int len, char lines[n][len]).
// Ex:
// char v[2][200] = {
// " Computer programming is the process of designing and building an
// executable computer program for accomplishing a specific computing task.",
// " Programming involves tasks such as analysis, generating algorithms,
// profiling algorithms accuracy and resource consumption, and the
// implementation of algorithms in a chosen programming language."
// };
// int count = count_words(2, 200, v);
// printf("Numero de palavras: %d\n", count);
int is_space(char a){
    return a == ' ';
}

int count_words(int n, int len, char lines[n][len]){
    int count = 0;
    bool in_word = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < len; j++)
        {
            char current_char = lines[i][j];
            if (!is_space(current_char) && current_char != '\0')
            {
                in_word = true;
            }
            else if (in_word)
            {
                count++;
                in_word = false;
            }
        }
    }
    return count;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// 20. Escreva uma função que conta e devolve o número de ocorrências de uma palavra word em um
// array de n linhas de texto (strings de até len-1 letras).
// int count_occurrences(int n, int len, char lines[n][len], char word[]).
// Ex:
// char v[5][200] = {
// "computer programming is the process of designing and building an
// executable computer program for accomplishing a specific computing task.",
// "programming involves tasks such as analysis, generating algorithms,
// profiling algorithms accuracy and resource consumption, and the
// implementation of algorithms in a chosen programming language.",
// "the source code of a program is written in one or more programming
// languages.",
// "the purpose of programming is to find a sequence of instructions that
// will automate the performance of a task for solving a given problem.",
// "the process of programming thus often requires expertise in several
// different subjects, including knowledge of the application domain,
// specialized algorithms, and formal logic."
// };
// int count = count_occurrences(5, 200, v, "programming");
// printf("Numero de ocorrencias: %d\n", count);
int count_occurrences(int n, int len, char lines[n][len], char word[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        char *token = strtok(lines[i], " ");
        while (token != NULL) {
            if (strcmp(token, word) == 0) {
                count++;
            }
            token = strtok(NULL, " ");
        }
    }
    return count;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int main(){
int mat[4][5] = {
{ 1, 2, 3, 5, 0},
{ 2, 4, 12, 5, 0},
{ 1, 2, 3, 1, 0},
{ 1, 2, 1, 1, 0},
};
int m1[2][3] = {
{ 1, 2, 3}, 
{ 2, 4, 6}, 
};
int m2[3][2];
    char v[6][20] = {"John", "Mary", "Jake", "Finn", "Ada", "Michael"};
    print_strings(6, 20, v);
    return 0;
}