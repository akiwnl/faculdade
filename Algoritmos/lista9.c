#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

// 1. Escreva uma função que conta todas as ocorrências de uma dada palavra, em um arquivo.
int count_word(const char* filepath, const char* word){
    FILE* file = fopen(filepath,"r");
    if (file == NULL)
    {
        printf("Arquivo nao existe!\n");
        return 0;
    }
    int count = 0;
    char buffer[100];

    while (fscanf(file, "%s", buffer) != EOF) {
        if (strcmp(buffer, word) == 0) {
            count++;
        }
    }
    
    fclose(file);
    return count;
}


// 2. Escreva uma função que substitui todas as ocorrências de uma dada palavra por outra, em um
// arquivo. A função deve retornar a quantidade de substituições realizadas.
int replace_word(const char* filepath, const char* old_str, const char* new_str){
    FILE* file = fopen(filepath,"r+");
    if (file == NULL)
    {
        printf("Arquivo nao existe\n");
        return -1;
    }

    char buffer[100];
    int count = 0;
    while (fscanf(file, "%s", buffer) != EOF) {
        if (strcmp(buffer, old_str) == 0) {
            fseek(file,-strlen(old_str),SEEK_CUR);
            fprintf(file,"%s",new_str);
            count++;
        }
    }    

    fclose(file);
    return count;

}



// 3. Escreva uma função que imprime a contagem de palavras por quantidade de letras, de um arquivo.
// A contagem deve ser informada em ordem crescente de quantidade de letras.
// void report_by_chars(const char* filepath)
// Exemplo de saída da função:
// Arquivo: relatorio_final.txt
// Contagem de palavras por quantidade de letras:
// > 1 letra: 9
// > 2 letras: 17
// > 3 letras: 15
// > 5 letras: 8
// > 9 letras: 2

int is_punctuation(char c) {
    return (c == '.' || c == ',' || c == ';' || c == ':' || c == '!' || c == '?');
}

void remove_punctuation(char* word) {
    int i, j = 0;
    int length = strlen(word);

    for (i = 0; i < length; i++) {
        if (!is_punctuation(word[i])) {
            word[j++] = word[i];
        }
    }

    word[j] = '\0';
}

void report_by_chars(const char* filepath){
    FILE* file = fopen(filepath,"r");
    if (file == NULL)
    {
        printf("Arquivo nao existe\n");
        return;
    }

    char word_length[100] = {0};
    char word[100];

    while (fscanf(file,"%s",word) == 1)
    {
        remove_punctuation(word);
        
        int length = strlen(word);
        word_length[length]++;
    }
    
    fclose(file);

    for (int i = 0; i < 30; i++)
    {
        if (word_length[i] > 0)
        {
            printf("%d letra(s): %d\n", i,word_length[i]);
        }
        
    }
}

// 4. Escreva uma função que imprime a quantidade de ocorrências de cada palavra, em um arquivo.
void count_all_words(const char* filepath){
    FILE* file = fopen(filepath,"r");
    if (file == NULL)
    {
        printf("Arquivo nao existe \n");
        return;
    }
    char buffer[100];
    while (fscanf(file, "%s",buffer) != EOF)
    {
        
                
    }
    

}



// 5. Escreva uma função que retorna um vetor contendo todas as palavras (strings) que possuam um
// dado número de letras em um arquivo. O vetor deve ser alocado em heap.
// char** get_words(const char* filepath, int letters)


// 6. Considerando o tipo estruturado Product, escreva uma função que grava o conteúdo de um vetor
// de produtos em um arquivo no formato CSV (valores separados por vírgula). No arquivo, os
// registros dos produtos são armazenados em sequência, com seus campos separados por vírgula.
// A função deve retornar true (1) para sucesso ou false (0), caso contrário. OBS: ao salvar o campo
// Product::name no arquivo, substitua os espaços por '@'. Dica: Utilize a função fprintf() para facilitar
// a implementação.
// typedef struct {
// int id;
// char name[51];
// float price;
// } Product;
// int save_records(const char* filepath, int n, const Product* prods)
// Exemplo de formato no arquivo:
// 4,Monitor@Axer@23,970.000000,2,Mouse@Optron@,102.000000,...
// Curiosidade: após criado o arquivo, abra-o em um editor de planilhas, como Microsoft Excel,
// LibreOffice Calc ou Google Sheets.


// 7. Considerando o tipo estruturado Product, escreva uma função que lê um arquivo no formato do
// exercício anterior e retorna um vetor de Produtos com o conteúdo do arquivo. A função deve
// retornar o endereço do vetor de Produtos, alocado em heap. O comprimento do vetor deve ser
// preenchido pelo parâmetro de endereço 'n'. Se não for possível abrir o arquivo ou o mesmo estiver
// vazio, a função deve retornar NULL e n=0. OBS: ao carregar o campo Product::name do arquivo,
// substitua os '@' por espaços.
// Product* load_records(const char* filepath, int* n)


// 8. Escreva uma função que faz a leitura de um arquivo em formato INI e retorna um vetor de pares
// (tipo Pair) preenchido com os dados constantes no arquivo. O formato INI define pares "chave =
// valor" em cada linha do arquivo. A função deve retornar o endereço do vetor de Pares, alocado em
// heap. O comprimento do vetor deve ser preenchido pelo parâmetro de endereço 'n'. Se não for
// possível abrir o arquivo ou o mesmo estiver vazio, a função deve retornar NULL e n=0. OBS:
// poderão haver espaços, tanto na chave, quanto no valor. Espaços que estiverem antes e depois
// devem ser removidos. Sugestão: utilize a função fgets() para leitura das linhas do arquivo.
// typedef struct {
// char key[101];
// char value[101];
// } Pair;
// Pair* load_ini_file(const char* filepath, int* n)
// Exemplo de formato INI:
// target = 192.0.14.662
// file = vm_params.cfg
// name = John Doe
// description = Configuration file for Neptune VM

int main(){
    // 1-
    // const char* filepath = "/home/akiwnl/Desktop/Lista/teste.txt";
    // const char* palavra = "Ipsum";
    // int ocorrencias = count_word(filepath, palavra);
    // printf("A palavra '%s' ocorre %d vezes no arquivo.\n", palavra, ocorrencias);

    // 2-
    // const char* filepath = "/home/akiwnl/Desktop/Lista/teste.txt";
    // const char* old_word = "Kaike";
    // const char* new_word = "Lorem";

    // int substituicoes = replace_word(filepath, old_word, new_word);

    // if (substituicoes != -1) {
    //     printf("Substituições realizadas: %d\n", substituicoes);
    // }   

    const char* filepath = "/home/akiwnl/Desktop/Lista/teste.txt";
    report_by_chars(filepath);
    return 0;
}