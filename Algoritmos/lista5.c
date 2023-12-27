#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// 1)Escreva uma função que recebe dois pontos x,y (Point) e devolve a distância entre os mesmos.
// Utilize sqrt() da lib <math.h> para obter a raiz quadrada:
// float distance2D(Point p1, Point p2);

struct point{
    float x;
    float y;
};

typedef struct point Point;

float distance2D(Point p1, Point p2){
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    float distance = sqrt(dx * dy + dx * dy);
    return distance;
}

        


//-------------------------------------------------------------------------------------------------------------------------------------------------------------//
// 2. Considerando a estrutura Point do exercício anterior, escreva uma função que recebe um vetor de
// pontos, bem como seu tamanho, e informa a distância a cada dois pontos consecutivos do vetor.

float distance_vector(int n, Point v[]){
    for (int i = 0; i < n; i++)
    {
        float dist = distance2D(v[i],v[i+1]);
        printf("Distância entre pontos %d e %d: %.2f\n", i, i + 1, dist);
    }
    
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------//
// 3. Escreva uma função que recebe um vetor de Point e os inicia com valores float aleatórios -50 e 50.
// Ex: para obter um número float randômico no intervalo [-2..2], dividimos o resultado de rand() por
// RAND_MAX, obtendo um float [0..1]. Com isso, basta multiplicar o resultado anterior pela
// quantidade desejada de números (de -2 a 2, temos 5 números) e, finalmente, subtrair a metade
// dessa quantidade (5/2.0f). De forma resumida:
float randf(int min, int max){
    return (float)rand()/RAND_MAX * (max - min + 1) + min;
}

void random_points(int n, Point v[]){
    for (int i = 0; i < n; i++)
    {
        v[i].x = randf(-50,50);
        v[i].y = randf(-50,50);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Ponto X%d: %.2f ",i,v[i].x);
        printf("Ponto Y%d: %.2f ",i,v[i].y);
        printf("\n");
    }
}



//-------------------------------------------------------------------------------------------------------------------------------------------------------------//
// 4. Escreva uma função que recebe um vetor de Point e encontra os dois pontos mais próximos, isto é,
// aqueles que possuem a menor distância. A função deve imprimir os dois de pontos mais próximos -
// (X1,Y1) e (X2,Y2) -, além da distância. Obviamente, você não deve considerar a distância de um
// ponto a ele mesmo, que será sempre zero.
void nearest_points(int n, Point v[]){
    float menor = 999999;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            float distance = distance2D(v[i],v[j]);
            if (distance < menor)
            {
                menor = distance;
            }    
        }
        
    }
    printf("A MENOR DISTANCIA É %.2f",menor);
    printf("\n");
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------//

// 5. Escreva uma função que recebe um Contact (ver struct abaixo) e imprime seu conteúdo. A função
// também recebe um vetor de strings contendo os nomes dos tipos, chamado type_names. O
// campo type do contato deve ser utilizado como índice no vetor type_names.
// void print_contact(Contact c, int n, char type_names[n][50])
// struct contact {
// int id;
// char name[51];
// char email[51];
// int type;
// };
// typedef struct contact Contact;
// Exemplo de uso da função:
// char types[][50] = {"família","amigo","trabalho","escola","outros"};
// Contact c = {1, "John Doe", "john.doe@email.com", 2};
// print_contact(c, 5, types);
// // saída: {1, John Doe, john.doe@email.com, trabalho}
struct contact {
    int id;
    char name[51];
    char email[51];
    int type;
};
typedef struct contact Contact;

void print_contact(Contact c, int n, char type_names[n][50]){

    printf("%d, %s, %s, %s",c.id,c.name,c.email,type_names[c.type]);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------//
// 6. Escreva uma função que recebe um vetor de Contact e imprime os contatos agrupados pelo seu
// tipo.
// void print_contact_list(int n1, Contact list[n1], int n2, char types[n2][50])
// Exemplo de uso da função:
// char types[][50] = {"Família","Amigo","Trabalho","Escola","Outros"};
// Contact list[] = {
// {1, "Marcus Fenix", "fenix@gow.com", 2},
// {41, "Blue Mary", "mary@ff3snk.net", 0},
// {17, "Barry Burton", "bburton@re.cap", 0},
// {8, "Charlie Nash", "nash@ssz.com", 2},
// {2, "Ada Wong", "wong@re2.net", 4},
// {5, "Chris Redfield", "crfield@re.cap", 0}
// };
// print_contact_list(6, list, 5, types);
// /* Saída da função: */
// /*Família
    // Blue Mary
    // Barry Burton
    // Chris Redfield
// Trabalho
    // Marcus Fenix
    // Charlie Nash
// Outros
    // Ada Wong
// */
void print_contact_list(int n1, Contact list[n1], int n2, char types[n2][50]){

    for (int i = 0; i < n2; i++) {
        int count = 0;
        for (int j = 0; j < n1; j++) {
            if (list[j].type == i) {
                count++;
            }
        }
        if (count > 0) {
            printf("%s\n", types[i]);
            for (int j = 0; j < n1; j++) {
                if (list[j].type == i) {
                    printf("%s\n", list[j].name);
                }
            }
            printf("\n");
        }
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------//
// 7. Escreva uma função que recebe uma lista de empregados (Employee) e seu tamanho. A função
// deve calcular e imprimir: o total dos salários, a média dos salários e as médias dos salários por tipo
// de empregado (“Developer”, “Designer”, “Manager” ou “Support”).
// void employees_report(int n, Employee v[n]);
// struct employee {
// char name[50];
// float salary;
// int type; // 0 - Developer, 1 - Designer, 2 - Manager, 3 - Support
// };
// typedef struct employee Employee;
struct employee {
    char name[50];
    float salary;
    int type; // 0 - Developer, 1 - Designer, 2 - Manager, 3 - Support
};
typedef struct employee Employee;

void employees_report(int n, Employee v[n]){
    float salario_total = 0;
    float media_salarial = 0;
    int salario_tipo[4] = {0};
    int count[4] = {0};
    for (int i = 0; i < n; i++)
    {
        salario_total += v[i].salary;
        salario_tipo[v[i].type] += v[i].salary;
        count[v[i].type]++;
    }
    media_salarial = salario_total / n;
    printf("Salário total: R$%.2f\n",salario_total);
    printf("Média salarial: R$%.2f\n",media_salarial);

    const char* types[] = {"Developer", "Designer", "Manager", "Support"};

    for (int i = 0; i < 4; i++)
    {
        if (count[i] > 0)
        {        
            float media_tipo = salario_tipo[i] / count[i];
            printf("Média salarial %s é R$%.2f\n",types[i],media_tipo);
        }
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------//
// 8. Escreva uma função que recebe um vetor de empregados (Employee) e seu tamanho. A função
// deve imprimir os nomes dos três empregados de maiores salários, ou seja, as pessoas que
// recebem os três maiores salários.
void print_best3(int n, Employee v[n]){
    float primeiro_maior = 0;
    float segundo_maior = 0;
    float terceiro_maior = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i].salary > primeiro_maior)
        {
            terceiro_maior = segundo_maior;
            segundo_maior = primeiro_maior;
            primeiro_maior = v[i].salary;
        }
        else if (v[i].salary > segundo_maior)
        {
            terceiro_maior = segundo_maior;
            segundo_maior = v[i].salary;
        }
        else if (v[i].salary > terceiro_maior)
        {
            terceiro_maior = v[i].salary;
        }
    }

    for (int i = 0; i < n; i++) {
        if (v[i].salary == primeiro_maior || v[i].salary == segundo_maior || v[i].salary == terceiro_maior) {
            printf("%s R$%.2f\n", v[i].name,v[i].salary);
        }
    }
    
    
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------//
// 9. Escreva uma função que recebe um nome, o verifica e corrige, se necessário. Um nome deve
// conter apenas letras, com as iniciais de cada nome em maiúscula e o restante em minúsculas.
// Deve haver somente um espaço entre cada nome e não devem haver espaços no início e final.
// void fix_name(char name[])
// Exemplo de uso da função:
// char name[] = " JoHN DOE# 23! "
// fix_name(name);
// // Após a chamada, name: "John Doe"
void fix_name(char name[]) {
    int length = strlen(name);
    int inWord = 0;
    int j = 0;

    for (int i = 0; i < length; i++) {
        if ((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z')) {
            if (!inWord) {
                name[j++] = toupper(name[i]);
                inWord = 1;
            } else {
                name[j++] = tolower(name[i]);
            }
        } else if (name[i] == ' ') {
            if (inWord) {
                name[j++] = ' ';
                inWord = 0;
            }
        }
    }

    while (j > 0 && name[j - 1] == ' ') {
        j--;
    }
    name[j] = '\0';
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------//
// 10. Escreva uma função que preenche e devolve um Contact (struct do exercício 5), definindo os
// campos da seguinte forma:
// a. id: definido pelo parâmetro id;
// b. name: definido pelo parâmetro name. Deve ser verificado e corrigido, se necessário. Para
// tanto, utilize a função do exercício anterior.
// c. email: deve ser gerado com base no nome e respeitando as seguintes característicasi.
// Todas as letras minúsculas;
// ii.
// Espaço deve ser substituído por “.” (ponto);
// iii.
// Acrescentar o sufixo “@mail.br”.
// d. type: definido pelo parâmetro type.
// Contact create_contact(int id, char name[], int type)
// Exemplo de uso da função:
// Contact c = create_contact(4, " JoHn! Do5e3 ", 1);
// // Após a chamada, c = {4, "John Doe", "john.doe@mail.br",1}
// OBS: para gerar o campo e-mail, verifique a função sprintf() do módulo <stdio.h>.
Contact create_contact(int id, char name[], int type) {
    fix_name(name);

    char email[100];
    int j = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] != ' ') {
            email[j++] = name[i];
        } else {
            email[j++] = '.';
        }
    }
    email[j] = '\0';
    strcat(email, "@mail.br");

    Contact new_contact;
    new_contact.id = id;
    strcpy(new_contact.name, name);
    strcpy(new_contact.email, email);
    new_contact.type = type;

    printf("%d %s %s %d\n", new_contact.id, new_contact.name, new_contact.email, new_contact.type);
    return new_contact;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------//
// 11. Escreva uma função que recebe um vetor de Contact e o preenche. O campo id deve ser
// preenchido incrementalmente, iniciando em 1. O campo type deve ser randomizado entre um dos 5
// tipos possíveis, exceto para contatos de pessoas da família “Doe”, que devem ser definidos com o
// tipo “Amigo”. Utilize a função do exercício anterior.
// void fill_contact_list(int n, Contact list[n])
// Exemplo de uso da função:
// Contact list[15];
// fill_contact_list(15, list);
void randomize_contact_type(Contact *contact) {
    char *types[] = {"Amigo", "Colega", "Familiar", "Conhecido", "Outro"};
    int num_types = sizeof(types) / sizeof(types[0]);
    
    strcpy(contact->type, types[rand() % num_types]);
}


void fill_contact_list(int n, Contact list[n]) {
    srand(time(NULL)); 
    int id = 1;

    for (int i = 0; i < n; i++) {
        list[i].id = id++;
        randomize_contact_type(&list[i]);
        strcpy(list[i].name, "Nome do Contato"); 
    }

    for (int i = 0; i < n; i++) {
        if (strstr(list[i].name, "Doe") != NULL) {
            strcpy(list[i].type, "Amigo");
        }
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------//
// 12. Escreva uma função que recebe um vetor de Contact e um outro vetor, com uma lista de nomes a
// buscar. A função deve retornar a quantidade de Contatos que possuem, ao menos, um dos nomes
// procurados.
// int find_by_name(int n1, Contact list[n1], int n2, char names[n2][50])
// Exemplo de uso da função:
// char names[5][10] = {"joanna", "john", "mike", "leonor", "caroline"};
// // a chamada abaixo contará os nomes em “list” que contêm ao menos
// // uma das palavras em “names”.
// int count = find_by_name(30, list, 5, names);
int find_by_name(int n1, Contact list[n1], int n2, char names[n2][50]) {
    int count = 0;

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (strstr(list[i].name, names[j]) != NULL) {
                count++;
                break;
            }
        }
    }

    return count;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------//

int main(){
    // char types[][50] = {"Developer","Designer","Manager","Support"};
    // Employee v[] = {{"Joao da Nica",1234.5,3},
    //                 {"Pedrinho Matador",2142.5,1},
    //                 {"Paulo Kogos",5512.3,0},
    //                 {"Alice", 4400, 0},  
    //                 {"Bob", 6010, 1},    
    //                 {"Charlie", 7001, 2},
    //                 {"David", 5200, 0},  
    //                 {"Eva", 3250, 3}};
    // // print_best3(8,v);
    // char name[] = {"   JoHN       ! DOE#    23 !  % "};
    // fix_name(name);
    Contact c = create_contact(4, " JoHn! Do5e3 ", 1);
    return 0;
}