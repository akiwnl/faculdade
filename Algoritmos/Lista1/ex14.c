// 14. Escreva um programa que calcula a idade de uma pessoa a partir da data de nascimento, lida pelo
// terminal em três variáveis (dia, mês e ano). Para obter a data atual, utilize as funções get_day(),
// get_month() e get_year(), fornecidas pelo código em anexo.

#include <stdio.h>

int get_day();
int get_month();
int get_year();

int main()
{
    int diaNascimento, mesNascimento, anoNascimento;
    int diaAtual, mesAtual, anoAtual;
    int idade;

    printf("Digite a data de nascimento (dia mes ano): ");
    scanf("%d %d %d", &diaNascimento, &mesNascimento, &anoNascimento);

    diaAtual = get_day();
    mesAtual = get_month();
    anoAtual = get_year();

    idade = anoAtual - anoNascimento;

    if (mesAtual < mesNascimento || (mesAtual == mesNascimento && diaAtual < diaNascimento))
    {
        idade--;
    }

    printf("A idade é: %d anos\n", idade);

    return 0;
}
