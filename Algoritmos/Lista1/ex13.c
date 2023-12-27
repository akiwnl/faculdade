// 13. Escreva um programa que lê um inteiro de até 4 dígitos (positivo ou negativo) e o imprime por
// extenso. OBS: para extrair os dígitos do número, utilize resto por 10 (para obter a unidade) e
// divisão por 10 (para remover a unidade).

#include <stdio.h>

int main()
{
    char *unidades[] = {"Zero", "Um", "Dois", "Três", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove"};
    char *dezenas[] = {"", "", "Vinte", "Trinta", "Quarenta", "Cinquenta", "Sessenta", "Setenta", "Oitenta", "Noventa"};
    char *centenas[] = {"", "Cem", "Duzentos", "Trezentos", "Quatrocentos", "Quinhentos", "Seiscentos", "Setecentos", "Oitocentos", "Novecentos"};

    int num, unidade, dezena, centena, milhar;

    printf("Digite um inteiro de até 4 dígitos: ");
    scanf("%d", &num);

    if (num < -9999 || num > 9999)
    {
        printf("Número fora da faixa permitida.\n");
    }
    else
    {
        if (num < 0)
        {
            printf("Menos ");
            num = -num;
        }

        milhar = num / 1000;
        centena = (num / 100) % 10;
        dezena = (num / 10) % 10;
        unidade = num % 10;

        if (milhar > 0)
        {
            printf("%s Mil ", unidades[milhar]);
        }

        if (centena > 0)
        {
            printf("%s ", centenas[centena]);
            if ((dezena > 0 || unidade > 0) && centena != 1)
            {
                printf("e ");
            }
        }

        if (dezena == 1)
        {
            printf("%s ", unidades[10 + unidade]);
        }
        else
        {
            if (dezena > 1)
            {
                printf("%s ", dezenas[dezena]);
            }
            if (unidade > 0)
            {
                printf("%s ", unidades[unidade]);
            }
        }

        if (num == 0)
        {
            printf("%s", unidades[0]);
        }

        printf("\n");
    }

    return 0;
}
