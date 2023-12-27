#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>


// 1. Escreva uma função que verifica se o arquivo de caminho informado existe (retorna 1). Caso
// contrário, retorna 0.
// int file_exists(const char* filepath)
// Exemplo de uso da função:
// int res = file_existis("C:\documentos\programa.exe"); // retorna 1 se existir

int file_exists(const char* filepath){

    FILE* file = fopen(filepath,"r");
    if (file != NULL)
    {
        fclose(file);
        return 1;
    }
    return 0;
}


// 2. Escreva uma função que receba um caminho de arquivo. Se o mesmo existir, faz nada. Se o
// arquivo não existir, tenta criá-lo. A função deve retornar 1 (um) caso arquivo exista ou tenha sido
// criado e, 0 (zero), caso contrário.
// int check_or_create(const char *filepath)
int check_or_create(const char *filepath){
    FILE* file = fopen(filepath, "r");
    if (file == NULL)
    {
        file = fopen(filepath, "w");
        return 0;
    }
    fclose(file);
    return 1;
}


// 3. Escreva uma função que receba um caminho de arquivo e imprima seu conteúdo no terminal.
// Retorna 1 para sucesso ou 0, caso o arquivo não exista.
// int print_content(const char *filepath)
int print_content(const char *filepath){
    FILE* file = fopen(filepath, "r");
    if (file == NULL)
    {
        printf("O arquivo nao existe.\n");
        return 0;
    }

    char ch = fgetc(file);
    while(ch != EOF){
        printf("%c", ch);
        ch = fgetc(file);
    }
    printf("\n");

    fclose(file);
    return 1;
}


// 4. Escreva uma função que receba um caminho de arquivo e retorna a quantidade de linhas de texto
// contidas no arquivo. Dica: o caractere '\n' define a quebra de linha no texto.
// int count_lines(const char *filepath)
int count_lines(const char *filepath){
    FILE* file = fopen(filepath,"r");
    if (file == NULL)
    {
        printf("O arquivo nao foi encontrado.\n");
        return 0;
    }

    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            count++;
        }
    }

    printf("%d\n", count);
    fclose(file);
    return 1;
}

// 5. Escreva uma função que receba um caminho de arquivo e escreva uma string no mesmo. A função
// deve (re)criar o arquivo especificado. Retorna 1 para sucesso ou 0, em caso de erro.
// int save_string(const char *filepath, const char* text)
int save_string(const char *filepath, const char* text){
    FILE* file = fopen(filepath, "w");
    if (file != NULL)
    {
        for (int i = 0; text[i] != '\0'; i++)
        {
            fputc(text[i],file);
        }
        fclose(file);
        return 1;
    }
    return 0;
}

// 6. Escreva uma função que receba um caminho de arquivo e acrescenta uma string no mesmo. A
// função deve criar o arquivo especificado, caso não exista. Retorna 1 para sucesso ou 0, em caso
// de erro. Dica: observe o modo de abertura 'a' (slide no. 5 do material).
int append_string(const char *filepath, const char* text){
    FILE* file = fopen(filepath, "a");
    if (file != NULL)
    {
        for (int i = 0; text[i] != '\0'; i++)
        {
            fputc(text[i],file);
        }
        fclose(file);
        return 1;
    }
    return 0;
}


// 7. Escreva uma função que receba um caminho de arquivo e escreva linhas de strings no mesmo. Ela
// deve (re)criar o arquivo especificado. A função recebe um vetor de strings e cada uma deve ser
// escrita em uma linha do arquivo. Retorna 1 para sucesso ou 0, em caso de erro.
int add_string(const char *filepath, const char** text_lines){
    FILE* file = fopen(filepath,"w");
    if (file != NULL)
    {
        for (int i = 0; text_lines[i] != NULL; i++) 
        {
            fprintf(file, "%s\n", text_lines[i]);
        }
            fclose(file);
            return 1;
    }
    return 0;
}


// 8. Escreva uma função que receba um caminho de arquivo e retorna uma string (vetor de caracteres
// terminado em nulo) alocada em heap contendo o conteúdo do arquivo. Caso ocorra algum
// problema, retorna NULL.
// char* get_content(const char *filepath)


// 9. Escreva uma função que receba um caminho de arquivo e retorna um vetor de strings contendo
// todas as palavras do arquivo. Considere como separadores de palavras o caractere de espaço e a
// quebra de linha '\n'. "Caso ocorra algum problema, retorna NULL.
// char** get_words(const char *filepath)
// Exemplo:
// Arquivo 'texto.txt':
// C is a general-purpose programming language, widely used and very influential.
// By design, C reflects the capabilities of the targeted CPUs, such as types,
// operations and memory access.
// Retorno da função:
// {"C", "is", "a", "general-purpose", "programming", "language,", "widely",
// "used", "and", "very", "influential.", "By", "design,", "C", "reflects", "the",
// "capabilities", "of", "the", "targeted", "CPUs,", "such", "as", "types,",
// "operations", "and", "memory", "access."}


// 10. Escreva uma função que receba um caminho de arquivo e retorna um vetor de strings contendo
// todas as palavras do arquivo. A string de separadores é passada como argumento à função. "Caso
// ocorra algum problema, retorna NULL.
// char** get_words_sep(const char *filepath, const char* separators)
// Considerando exemplo do exercício anterior, este seria o retorno da função para
// os separadores " ,;.:?!-":
// {"C", "is", "a", "general-purpose", "programming", "language", "widely", "used",
// "and", "very", "influential", "By", "design", "C", "reflects", "the",
// "capabilities", "of", "the", "targeted", "CPUs", "such", "as", "types",
// "operations", "and", "memory", "access."}


int main(){
    // 1-
    // int res = file_exists("/home/akiwnl/Desktop/lista8/arquivo.txt");

    // if (res == 1) {
    //     printf("O arquivo existe.\n");
    // } else {
    //     printf("O arquivo nao existe.\n");
    // }

    // 2-
    // int res = check_or_create("/home/akiwnl/Desktop/lista8/teste.txt");

    // if (res == 1) {
    //     printf("O arquivo existe ou foi criado com sucesso.\n");
    // } else {
    //     printf("O arquivo nao existe, portanto foi criado.\n");
    // }

    // 3-
    // print_content("/home/akiwnl/Desktop/lista8/teste.txt");

    // 4-
    // count_lines("/home/akiwnl/Desktop/lista8/teste.txt");

    // 5-
    // char text[] = {"Hello World!"};
    // save_string("/home/akiwnl/Desktop/lista8/testee.txt", text);

    // 6-
    // char text[] = {"Hello World!"};
    // append_string("/home/akiwnl/Desktop/lista8/teste.txt", text);

    // 7-
    // const char* text[] = {"Hello","World","oioi",NULL};
    // add_string("/home/akiwnl/Desktop/lista8/teste.txt",text);
    return 0;
}