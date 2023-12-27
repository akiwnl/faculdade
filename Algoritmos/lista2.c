#include <stdio.h>
#include <math.h>

// 1. Escreva uma função que recebe um inteiro positivo e verifica se o mesmo é um Número Perfeito.
// Um número perfeito é igual à soma de seus divisores positivos. Exemplo: 6 = 1 + 2 + 3. A função
// deve retornar 1 (número perfeito) ou 0 (não é número perfeito).
// int is_perfect_number(int a)
// Informe o numero: 6
// Divisores de 6: 1 + 2 + 3 = 6
// Numero perfeito? Sim

int is_perfect_number(int a)
{
    int soma = 0;
    for (int i = 1; i <= a / 2; i++)
    {
        if (a % i == 0)
        {
            soma += i;
        }
    }
    if (soma == a)
    {
        return 1;
    }
    return 0;
}

// // ---------------------------------------------------------------------------------------------//

// // 2. Escreva uma função que recebe um inteiro positivo e imprime seus fatores primos (e quantidades).
// // void print_factors(int a)
// // Informe o numero:
// // > 132
// // 2 x fator 2
// // 1 x fator 3
// // 1 x fator 11
void print_factors(int a)
{
    for (int divisor = 2; a > 1; divisor++)
    {
        int count = 0;
        while (a % divisor == 0)
        {
            a /= divisor;
            count++;
        }
        if (count > 0)
        {
            printf("%d x fator %d \n", count, divisor);
        }
    }
}

// // ---------------------------------------------------------------------------------------------//

// // 3. Escreva uma função que recebe um inteiro e o devolve invertido. Utilize "resto por 10" para extrair a
// // unidade e "divisão por 10" para remover a unidade.
// // int reverse_int(int a)
// // Exemplo de uso da função:
// // int rev = reverse_int(12543); // rev = 34521

int reverse_int(int a)
{
    int reversed = 0;
    while (a != 0)
    {
        reversed = reversed * 10 + a % 10;
        a /= 10;
    }
    printf("%d ", reversed);

    return 0;
}

// // ---------------------------------------------------------------------------------------------//

// 4. Escreva uma função que recebe dois inteiros positivos (A e B) e retorna o MDC (Máximo Divisor
// Comum) entre ambos. O MDC é o maior número que divide A e B (divisão exata, de resto zero).
// Dica: teste os divisores do MENOR(A, B) até encontrar o maior número que divide A e B.
// int mdc(int a, int b)
// Observe o processo para 30 e 12
// -------------------------------
// Divisores de 30: 1, 2, 3, 5, 6, 10, 15, 30
// Divisores de 12: 1, 2, 3, 4, 6, 12
// ^ MDC

int mdc(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
// // ---------------------------------------------------------------------------------------------//

// 5. Escreva uma função que recebe dois inteiros positivos (A e B) e retorna o MMC (Mínimo Múltiplo
// Comum) entre ambos. O MMC é o menor número que resulta da multiplicação de A e B por algum
// número (não necessariamente igual para ambos). Dica: teste os múltiplos do MAIOR(A, B), até
// encontrar um que seja divisível pelo MENOR(A, B). OBS: Sempre há um MMC entre dois números
// quaisquer.
// int mmc(int a, int b)
// Observe o processo para 30 e 12
// -------------------------------
// Múltiplos de 30: 30, 60, 90,120,150,...
// Múltiplos de 12: 12, 24, 36, 48, 60,...
// x1 x2 x3 x4 x5 ...
// O MMC entre 30 e 12 é 60.

int mdc(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int mmc(int a, int b)
{
    return (a * b) / mdc(a, b);
}
// // ---------------------------------------------------------------------------------------------//

// // 6. Escreva uma função que recebe um vetor vet de tamanho n e imprime apenas os valores pares.
// // void print_even(int n, int vet[])

void print_even(int n, int vet[])
{
    for (int i = 0; i < n; i++)
    {
        if (vet[i] % 2 == 0)
        {
            printf("%d \n", vet[i]);
        }
    }
}

// // ---------------------------------------------------------------------------------------------//

// // 7. Escreva uma função que recebe um vetor vet de tamanho n contendo números inteiros positivos e
// // negativos. A função deve inverter o sinal dos números negativos, passando-os para positivo.
// // void set_positive(int n, int vet[])
// // Entrada:{1, -5, 67, -45, -1, -1, 0, 48} → Saída:{1, 5, 67, 45, 1, 1, 0, 48}

void set_positive(int n, int vet[])
{
    for (int i = 0; i < n; i++)
    {
        if (vet[i] < 0)
        {
            vet[i] = vet[i] * (-1);
        }
        printf("%d ", vet[i]);
    }
}
// // ---------------------------------------------------------------------------------------------//

// 8. Escreva uma função que verifica se os elementos de um vetor estão em ordem crescente. A função
// deve retornar 1 (true), caso os elementos estejam dispostos em ordem crescente, ou 0 (false), em
// caso contrário.
// int is_sorted(int n, int vet[])
// Exemplo de uso da função:
// int v[] = {1,4,7,9,15,22,48,512};
// int res = is_sorted(8, v); // neste caso, res = 1 (true)

int is_sorted(int n, int vet[])
{
    for (int i = 1; i < n; i++)
    {
        if (vet[i] < vet[i - 1])
        {
            return 0;
        }
    }
    return 1;
}

// // ---------------------------------------------------------------------------------------------//

// // 9. Escreva uma função que recebe um vetor vet de tamanho n e devolve o maior valor contido no
// // vetor.
// // int find_max(int n, int vet[])

int find_max(int n, int vet[])
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (vet[i] > max)
        {
            max = vet[i];
        }
    }
    printf("%d", max);

    return 0;
}

// // ---------------------------------------------------------------------------------------------//

// 10. Escreva uma função que recebe um vetor vet de tamanho n, bem como, um elemento elem a ser
// procurado. A função deve substituir todas as ocorrência de elem por -1.
// void replace_all(int n, int vet[], int elem)

void replace_all(int n, int vet[], int elem)
{
    for (int i = 0; i < n; i++)
    {
        if (vet[i] == elem)
        {
            vet[i] = -1;
        }
        printf("%d ", vet[i]);
    }
}

// // ---------------------------------------------------------------------------------------------//

// 11. Escreva uma função que recebe um vetor vet de tamanho n e inverte os seus elementos (no
// próprio vetor).
// void reverse(int n, int vet[])

void reverse(int n, int vet[])
{
    int start = 0;
    int end = n - 1;
    int temp;
    while (start < end)
    {
        temp = vet[start];
        vet[start] = vet[end];
        vet[end] = temp;
        start++;
        end--;
    }
}

// // ---------------------------------------------------------------------------------------------//

// 12. Escreva uma função que faz a leitura de n números inteiros e os coloca no vetor vet fornecido.
// Considere que o vet possui tamanho n.
// void read_vector(int n, int vet[])

void read_vector(int n, int vet[])
{
    printf("Digite %d numeros inteiros \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &vet[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
}

// // ---------------------------------------------------------------------------------------------//

// 13. Escreva uma função que recebe um vetor vet de tamanho n preenchido com inteiros positivos. A
// função deve imprimir as ocorrências (contagem) de cada número no vetor. Dica: utilize um vetor
// count para armazenar a contagem de cada elemento no vetor vet, relacionando as posições de
// count aos valores em vet.
// void count_elements(int n, int vet[])

void count_elements(int n, int vet[])
{

    int max = vet[0];
    for (int i = 0; i < n; i++)
    {
        if (vet[i] > max)
        {
            max = vet[i];
        }
    }

    int count[max + 1];
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count[vet[i]]++;
    }

    for (int i = 0; i <= max; i++)
    {
        if (count[i] > 0)
        {
            printf("%d ocorre %d vez(es)\n", i, count[i]);
        }
    }
}
// // ---------------------------------------------------------------------------------------------//

// 14. Escreva uma função que recebe um valor inteiro value e um vetor notes com as possíveis cédulas.
// A função deve imprimir a quantidade mínima de cédulas equivalente ao valor.
// Dica: use um vetor auxiliar count para armazenar a contagem de cada cédula.
// void min_bills(int value, int n, int bills[]) // n é o tamanho de bills
// Exemplo:
// min_bills(209, 5, (int[]){1,5,10,50,100}); // lista de tipos de cédulas
// 2 x R$100,00
// 1 x R$5,00
// 4 x R$1,00

void min_bills(int value, int n, int vet[])
{
    int count[n];
    for (int i = 0; i < n; i++)
    {
        count[i] = 0;
    }

    int i = n - 1;
    while (i >= 0)
    {
        if (value >= vet[i])
        {
            count[i]++;
            value -= vet[i];
        }
        else
        {
            i--;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (count[i] > 0)
        {
            printf("%d x R$%d,00\n", count[i], vet[i]);
        }
    }
}

// // ---------------------------------------------------------------------------------------------//

// 15. Escreva uma função que recebe pontos X,Y em um vetor points de tamanho n. O vetor conterá os
// pontos sequencialmente: [X1, Y1, X2, Y2, X3, Y3,...]. A função deve informar a distância entre cada
// par de pontos consecutivos. Distância: sqrt( (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) ). Função square
// root: https://www.tutorialspoint.com/c_standard_library/c_function_sqrt.htm).
// void distances(int n, int points[])

void distances(int n, int points[])
{
    if (n % 2 != 0)
    {
        printf("O número de elementos no vetor deve ser par.\n");
        return;
    }

    for (int i = 0; i < n; i += 2)
    {
        int x1 = points[i];
        int y1 = points[i + 1];
        int x2 = points[i + 2];
        int y2 = points[i + 3];

        double distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        printf("Distância entre (%d, %d) e (%d, %d) é %.2f\n", x1, y1, x2, y2, distancia);
    }
}
// // ---------------------------------------------------------------------------------------------//

// 16. Escreva uma função que recebe dois vetores (vet1 e vet2) de mesmo tamanho n. A função deve
// copiar todos os elementos de vet1 para vet2.
// void vector_copy(int n, int vet2[], int vet1[])

void vector_copy(int n, int vet2[], int vet1[])
{
    for (int i = 0; i < n; i++)
    {
        vet2[i] = vet1[i];
    }
}

// // ---------------------------------------------------------------------------------------------//

// 17. Um vetor pode ser utilizado como uma lista que permite inserções e remoções de números inteiros
// positivos. No vetor, o valor -1 indica posição vazia (disponível). Escreva uma função que recebe um
// vet1 de tamanho n e um novo elemento. A função deve inserir o novo elemento na primeira
// posição válida disponível, isto é, marcada com -1. Caso não haja alguma posição disponível, a
// inserção deve ser cancelada.
// void vector_insert(int n, int vet1[], int elem)
// int vet[9] = {1, 6, -1, 9, 4, -1, -1, 2, -1}
// vector_insert(9, vet, 18); // v = {1, 6, 18, 9, 4, -1, -1, 2, -1}
// vector_insert(9, vet, 7); // v = {1, 6, 18, 9, 4, 7, -1, 2, -1}

void vector_insert(int n, int vet[], int elem)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (vet[i] == -1)
        {
            flag += 1;
        }
    }
    if (flag <= 0)
    {
        printf("Não existem posições na lista. \n");
    }
    else
    {
        for (int i = 0; i <= n; i++)
        {
            if (vet[i] == -1)
            {
                vet[i] = elem;
            }
        }
        for (int i = 0; i < n; i++)
        {
            printf("%d ", vet[i]);
        }
    }
}

// // ---------------------------------------------------------------------------------------------//

// 18. Considerando o mesmo formato de lista do exercício anterior, escreva uma função que recebe um
// vet1 de tamanho n e uma posição. A função deve “remover” o elemento da lista, marcando a
// posição com -1. Caso a posição seja inválida, nenhuma operação deve ser realizada.
// void vector_remove(int n, int vet1[], int pos)

void vector_remove(int n, int vet[], int pos)
{
    if (pos > n)
    {
        printf("Posição é maior que o tamanho do vetor.");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (vet[i] == vet[pos])
            {
                vet[pos] = -1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            printf("%d ", vet[i]);
        }
    }
}

// // ---------------------------------------------------------------------------------------------//

// 19. Considere as operações dos dois exercícios anteriores. Após algumas operações de inserção e
// remoção, o vetor ficará repleto de “buracos”. Escreva uma função que recebe um vetor vet de
// tamanho n. O vetor contém inteiros positivos e posições livres, marcadas com -1. A função deve
// desfragmentar o vetor, colocando todos os valores válidos à esquerda.
// void vector_defrag(int n, int vet[n])
// Exemplo:
// int v[9] = {1, 6, -1, 9, 4, -1, -1, 2, -1} // vetor original
// vector_defrag(9, v); // v = {1, 6, 9, 4, 2, -1, -1, -1, -1}
// int vet[] = {1,5,-1,100,-1,100,9};

void vector_defrag(int n, int vet[n])
{
    int last = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (vet[i] == -1)
        {
            while (vet[last] == -1)
            {
                last--;
            }
            if (last > i)
            {
                vet[i] = vet[last];
                vet[last] = -1;
            }
            else
            {
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
}
// // ---------------------------------------------------------------------------------------------//

// 20. Escreva uma função que recebe três vetores e seus tamanhos. A função deve concatenar (juntar) o
// conteúdo de v1 e v2 em v3. Considere que v3 tem tamanho n1 + n2. Os vetores contém apenas
// inteiros positivos.
// void vector_concat(int n1, int v1[n1], int n2, int v2[n2], int v3[])
// Exemplo:
// int v1[5] = {1,2,3,4,5};
// int v2[3] = {2,3,8};
// int v3[8];
// vecor_concat(5, v1, 3, v2, v3); // v3 = {1,2,3,4,5,2,3,8}

void vector_concat(int n1, int v1[n1], int n2, int v2[n2], int v3[])
{
    int v3_len = n1 + n2;
    int j = 0;
    for (int i = 0; i < n1; i++)
    {
        v3[i] = v1[i];
        j++;
    }

    for (int i = 0; i < n2; i++)
    {
        v3[j] = v2[i];
        j++;
    }

    for (int i = 0; i < v3_len; i++)
    {
        printf("%d ", v3[i]);
    }
}
// // ---------------------------------------------------------------------------------------------//

// 21. Escreva uma função que recebe três vetores e seus tamanhos. A função deve realizar a união
// entre os vetores v1 e v2, colocando os valores em v3. Considere que v3 tem tamanho n1 + n2. Os
// vetores contém apenas inteiros positivos e v3 deve ser iniciado com 0.
// void vector_union(int n1, int v1[n1], int n2, int v2[n2], int v3[])
// Exemplo:
// int v1[5] = {1,2,3,4,5};
// int v2[3] = {2,3,8};
// int v3[8] = {0};
// vector_union(5, v1, 3, v2, v3); // v3 = {1,2,3,4,5,8,0,0}

void vector_union(int n1, int v1[n1], int n2, int v2[n2], int v3[])
{

    for (int i = 0; i < n1 + n2; ++i)
    {
        v3[i] = 0;
    }

    for (int i = 0; i < n1; ++i)
    {
        v3[i] = v1[i];
    }

    int count = n1;
    for (int i = 0; i < n2; ++i)
    {
        int duplicata = 0;
        for (int j = 0; j < n1; ++j)
        {
            if (v2[i] == v1[j])
            {
                duplicata = 1;
                break;
            }
        }

        if (!duplicata)
        {
            v3[count] = v2[i];
            ++count;
        }
    }
}

// // ---------------------------------------------------------------------------------------------//

// 22. Escreva uma função que recebe três vetores e seus tamanhos. A função deve realizar a
// intersecção entre os vetores v1 e v2, colocando os valores em v3. Considere que v3 tem tamanho
// min(n1, n2). Os vetores contém apenas números naturais (inteiros positivos) e v3 deve ser iniciado
// com 0.
// void vector_intersection(int n1, int v1[n1], int n2, int v2[n2], int v3[])
// Exemplo:
// int v1[5] = {1,2,3,4,5};
// int v2[3] = {2,3,8};
// int v3[3] = {0};
// vector_intersection(5, v1, 3, v2, v3); // v3 = {2,3,0}

void vector_intersection(int n1, int v1[n1], int n2, int v2[n2], int v3[])
{

    int k = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (v2[j] == v1[i])
            {
                v3[k] = v2[j];
                k++;
            }
        }
    }

    for (int i = 0; i < n2; i++)
    {
        printf("%d ", v3[i]);
    }
}

// // ---------------------------------------------------------------------------------------------//

// 23. Escreva uma função que recebe dois vetores v1 e v2 ordenados crescentemente. Ela deve mesclar
// ordenadamente os conteúdos de v1 e v2, colocando em v3. Considere que v3 tem tamanho n1 +
// n2. OBS: não é permitido mesclar e ordenar.
// void merge(int n1, int v1[], int n2, int v2[], int v3[])
// Entrada: v1 = {1, 3, 4, 7, 9, 10}
// v2 = {2, 3, 5, 7, 7, 14}
// Saída: v3 = {1, 2, 3, 3, 4, 5, 7, 7, 7, 9, 10, 14}

void merge(int n1, int v1[], int n2, int v2[], int v3[])
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (v1[i] < v2[j])
        {
            v3[k] = v1[i];
            k++;
            i++;
        }
        else
        {
            v3[k] = v2[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        v3[k] = v1[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        v3[k] = v2[j];
        k++;
        j++;
    }

    int v3_len = n1 + n2;
    for (int i = 0; i < v3_len; i++)
    {
        printf("%d ", v3[i]);
    }
}

// // ---------------------------------------------------------------------------------------------//

// 24. Escreva uma função que recebe um vetor contendo números inteiros. Ela deve determinar o
// segmento de soma máxima e imprimi-lo.
// void max_sum_slice2(int n, int v[])
// Exemplo: No vetor {5, 2,-2,-7, 3,14,10,-3, 9,-6, 4, 1}, a soma do segmento é 33.

void max_sum_slice2(int n, int v[])
{
    int max_so_far = v[0];
    int max_ending_here = v[0];
    int start = 0;
    int end = 0;
    int temp_start = 0;

    for (int i = 1; i < n; ++i)
    {
        if (v[i] > max_ending_here + v[i])
        {
            max_ending_here = v[i];
            temp_start = i;
        }
        else
        {
            max_ending_here = max_ending_here + v[i];
        }

        if (max_ending_here > max_so_far)
        {
            max_so_far = max_ending_here;
            start = temp_start;
            end = i;
        }
    }

    printf("Segmento de soma máxima: ");
    for (int i = start; i <= end; ++i)
    {
        printf("%d", v[i]);
        if (i < end)
        {
            printf(", ");
        }
    }
    printf("\nSoma: %d\n", max_so_far);
}

// // ---------------------------------------------------------------------------------------------//

int main()
{
    int v[12] = {5, 2, -2, -7, 3, 14, 10, -3, 9, -6, 4, 1};
    max_sum_slice2(12, v);
    return 0;
}