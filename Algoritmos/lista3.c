#include <stdio.h>
#include <string.h>
// 1. Escreva uma função que recebe uma string (como parâmetro) e a imprime na tela, com cada
// caractere separado por um espaço. Você não pode utilizar strlen().
// void print_string(char str[])

void print_string(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        printf("%c ", str[i]);
    }
}

// -----------------------------------------------------------------------------//

// 2. Escreva uma função que recebe uma string e a imprime ao contrário (da direita para esquerda).
// Faça duas versões da função: uma utilizando strlen() <string.h>, e outra, sem utilizar a função.
// void print_string_reversed(char str[])
void print_string_reversed(char str[])
{

    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }

    for (int i = length - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
}

// -----------------------------------------------------------------------------//
// 3. Escreva uma função que recebe uma string e imprime seus caracteres separados por um outro
// caractere, fornecido como segundo parâmetro da função. Note que o separador não deve ser
// impresso ao final.
// void print_hyphenated(char str[], char separator)
// Ex: char s[] = “hyphenization”
// print_hyphenated(s, '$'); // saída: h$y$p$h$e$n$i$z$a$t$i$o$n

void print_hyphenated(char str[], char separator)
{

    for (int i = 0; str[i] != '\0'; i++)
    {
        printf("%c%c", str[i], separator);
    }
    printf("\b ");
}
// -----------------------------------------------------------------------------//
// 4. Escreva uma função que recebe uma string e imprime:
// a. A quantidade de letras (maiúsculas ou minúsculas);
// b. A quantidade de dígitos;
// c. A quantidade de símbolos.
// OBS: considere apenas a porção dos caracteres imprimíveis da tabela ASCII, isto
// é, dos índices 32 ao 126.
// void string_report(char str[])

void string_report(char str[])
{
    int qnt_letras = 0;
    int qnt_digitos = 0;
    int qnt_simbolos = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90))
        {
            qnt_letras++;
        }
        if (str[i] >= '0' && str[i] <= '9')
        {
            qnt_digitos++;
        }
        if ((str[i] >= 33 && str[i] <= 47) || (str[i] >= 58 && str[i] <= 64) || (str[i] >= 123 && str[i] <= 126))
        {
            qnt_simbolos++;
        }
    }
    printf("%d \n", qnt_letras);
    printf("%d \n", qnt_digitos);
    printf("%d \n", qnt_simbolos);
}
// -----------------------------------------------------------------------------//

// 5. Escreva uma função que recebe uma string e a converte para letras maiúsculas. Atenção: a string
// poderá conter letras maiúsculas e símbolos.
// void string_to_upper(char str[])
// Ex: char s[] = “All your BASE are Belong to US!”;
// stringToUpper(s);
// printf(“%s”, s); // saída: ALL YOUR BASE ARE BELONG TO US!

void string_to_upper(char str[])
{

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }
}

// -----------------------------------------------------------------------------//

// 6. A função strcmp(str1, str2) compara duas strings alfabeticamente. Ela devolve:
// a. res < 0 se str1 < str2 << str1 vem antes de str2
// b. res = 0 se str1 = str2
// c. res > 0 se str1 > st2 << str1 vem depois de str2
// Escreva uma função que compara duas strings independente do caso (maiúsculo ou minúsculo).
// Ela deve retornar os mesmos tipos de valores que strcmp(). Dica: com a função do exercício
// anterior, você poderá passar ambas strings para maiúsculas e, então, compará-las com strcmp().
// int strcmp_plus(char s1[], char s2[])
// Ex: int res = strcmp_plus(“JOanna”, “joanna”); // res:0 (strings iguais)

int strcmp_plus(char str1[], char str2[])
{
    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] >= 'A' && str1[i] <= 'Z')
        {
            str1[i] += 32;
        }
    }
    for (int i = 0; str2[i] != '\0'; i++)
    {
        if (str2[i] >= 'A' && str2[i] <= 'Z')
        {
            str2[i] += 32;
        }
    }

    int resultado = strcmp(str1, str2);

    if (resultado == 0)
    {
        printf("As strings sao iguais.\n");
    }
    else if (resultado < 0)
    {
        printf("str1 e menor que str2.\n");
    }
    else
    {
        printf("str1 e maior que str2.\n");
    }

    return 0;
}
// -----------------------------------------------------------------------------//
// 7. Escreva uma função que conta e devolve o número de palavras em uma string. Considere que
// haverá somente um espaço entre as palavras.
// int count_words(char str[])
// Ex: char s[] = “first things first, second things latter“;
// printf(“%d”, count_words(s)); // saída: 6

int count_words(char str[])
{
    int space = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            space++;
        }
    }
    int palavras = space + 1;
    printf("A string possui %d palavras", palavras);

    return 0;
}

// -----------------------------------------------------------------------------//
// 8. Escreva uma função que conta e devolve o número de palavras em uma string. Considere que
// poderá haver mais de um espaço entre as palavras, bem como, no início e final da string.
// int count_words_plus(char str[])
// Ex: char s[] = “ first things first, second things latter “;
// printf(“%d”, count_words_plus(s)); // saída: 6

int count_words_plus(char str[])
{
    int palavra = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            str[i] += str[i + 1];
            break;
        }
        palavra++;
    }
    int palavras = palavra + 1;
    printf("A string possui %d palavras", palavras);
    return 0;
}

// -----------------------------------------------------------------------------//
// 9. Escreva uma função que recebe uma string composta de várias palavras. A função deve modificar
// a letra inicial de cada palavra para maiúscula e, as demais, para minúsculas. Considere que
// sempre haverá ao menos um espaço entre cada palavra.
// void string_capitalize(char str[])
// Ex: char s[] = “welCOME To COMPUTER programming!!”;
// string_capitalize(s);
// printf(“%s”, s); // saída: Welcome To Computer Programming!!

void string_capitalize(char str[])
{
    // joga tudo pra minuscula
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == str[0] && (str[i] >= 'a' && str[i] <= 'z'))
        {
            str[i] -= 32;
        }
        if (str[i - 1] == ' ' && (str[i] >= 'a' && str[i] <= 'z'))
        {
            str[i] -= 32;
        }
    }
    printf("%s", str);
}

// -----------------------------------------------------------------------------//
// 10. Escreva uma função que implementa um comportamento similar à strcmp(). Entretanto, você não
// deve utilizar strcmp() em sua implementação. A função criada deve retornar:
// a. res = -1 se str1 < str2 << str1 vem antes de str2
// b. res = 0 se str1 = str2
// c. res = 1 se str1 > st2 << str1 vem depois de str2
// int string_compare(char str1[], char str2[])

int string_compare(char str1[], char str2[])
{
    string_to_upper(str1);
    string_to_upper(str2);

    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] == str2[i])
        {
            i++;
        }
        if (str1[i] > str2[i])
        {
            return 1;
        }
        if (str1[i] < str2[i])
        {
            return -1;
        }
    }
    return 0;
}
// -----------------------------------------------------------------------------//
// 11. Escreva uma função que recebe uma string e imprime o número de ocorrências de cada letra da
// tabela ASCII (26 possibilidades), bem como, seu percentual sobre o todo (desconsiderando
// espaços). A contagem deve desconsiderar letras maiúsculas e minúsculas.
// void string_count(char str[])

void string_count(char str[])
{
    string_to_upper(str);
    int count[26] = {0};
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            length++;
        }
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        count[str[i] - 65] += 1;
    }

    for (int i = 0; i < 26; i++)
    {
        float porcentagem = (count[i] / (float)length) * 100;
        if (count[i] != 0)
        {
            printf("%c x%d (%.0f%%)\n", i + 65, count[i], porcentagem);
        }
    }
}
// -----------------------------------------------------------------------------//
// 12. Escreva uma função que remove os espaços que possam existir antes e depois de uma string.
// void string_trim(char str[])
// Ex: char s[] = “ hello world “;
// string_trim(s);
// printf(“%s”, s); // saída: “hello world”

void string_trim(char str[])
{
    int start = 0;
    int end = 0;
    int length = 0;

    while (str[start] != '\0' && isspace(str[start]))
    {
        start++;
    }

    end = start;
    while (str[end] != '\0')
    {
        if (!isspace(str[end]))
        {
            length = end - start + 1;
        }
        end++;
    }

    for (int i = 0; i < length; ++i)
    {
        str[i] = str[start + i];
    }

    str[length] = '\0';
}

// -----------------------------------------------------------------------------//

// 13. Escreva uma função que informa, com 1 (true) ou 0 (false), se uma string está contida em outra.
// int find_substring(char str[], char sub[])
// Ex: char s[] = “first things first, second things latter“;
// int check = find_substring(s, “second”);
// // neste caso, deve devolver 1, pois a string contém a palavra “second”

int find_substring(char str[], char sub[])
{
    int i, j;
    int str_len = 0;
    int sub_len = 0;

    while (str[str_len] != '\0')
    {
        str_len++;
    }

    while (sub[sub_len] != '\0')
    {
        sub_len++;
    }

    for (i = 0; i <= str_len - sub_len; i++)
    {

        if (str[i] == sub[0])
        {

            for (j = 1; j < sub_len; j++)
            {
                if (str[i + j] != sub[j])
                {
                    break;
                }
            }

            if (j == sub_len)
            {
                return 1;
            }
        }
    }

    return 0;
}
// -----------------------------------------------------------------------------//

// 14. Escreva uma função que corta uma string após uma dada palavra. As posições após a palavra
// devem ser preenchidas com o caractere '\0' (int 0), até o final do vetor.
// void cut_string(char str[], char target[])
// Ex: char s[] = “first things first, second things latter“;
// cut_string(s, “second”);
// printf(“%s”, s); // s = “first things first, second”

void cut_string(char str[], char target[])
{
    int target_length = strlen(target);
    int str_length = strlen(str);
    int position = -1;

    for (int i = 0; i <= str_length - target_length; i++)
    {
        if (strncmp(str + i, target, target_length) == 0)
        {
            position = i;
            break;
        }
    }

    if (position != -1)
    {
        for (int i = position + target_length; i < str_length; i++)
        {
            str[i] = '\0';
        }
    }
}

// -----------------------------------------------------------------------------//

// 15. Escreva uma função que converte um número inteiro (parâmetro de entrada number) para uma
// string (parâmetro de saída converted).
// void int_to_string(int number, char converted[])
// Ex: char num[11];
// int_to_string(512, num);
// printf(“%s”, num); // saída: “512” (string)

void reverse_string(char str[], int length)
{
    int start = 0;
    int end = length - 1;
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void int_to_string(int number, char converted[])
{
    int i = 0;
    int is_negative = 0;

    if (number < 0)
    {
        is_negative = 1;
        number = -number;
    }

    while (number != 0)
    {
        int digit = number % 10;
        converted[i++] = digit + '0';
        number = number / 10;
    }

    if (is_negative)
    {
        converted[i++] = '-';
    }

    converted[i] = '\0';

    reverse_string(converted, i);

    if (i == 0)
    {
        converted[i++] = '0';
        converted[i] = '\0';
    }
}
// -----------------------------------------------------------------------------//

// 16. Escreva uma função que converte uma string para um inteiro. Utilize a notação posicional para
// montar o número inteiro. Ex: 2506 = 2 x 10
// 3 + 5 x 10
// 2 + 0 x 10
// 1 + 6 x 10
// 0
// .
// int string_to_int(char textNumber[])
// Ex: int n = string_to_int(“1024”);
// printf(“%d”, n); // saída: 1024 (inteiro)

int string_to_int(char textNumber[])
{
    int length = strlen(textNumber);
    int result = 0;

    for (int i = 0; i < length; ++i)
    {

        char digitChar = textNumber[length - 1 - i];

        int digit = digitChar - '0';

        result += digit * pow(10, i);
    }

    return result;
}

// -----------------------------------------------------------------------------//

int main()
{
    char str1[] = "   Hello World   ";

    string_count(str1);
    return 0;
}