/* --------------------------------------------------------------------------------------
   Programa: Trabalho Pratico 1 (2022): A Mega Quadra
   Link: https://www.inf.ufpr.br/vvsbt20

   Autor: Vincent Tomio
   Disciplina: Algoritmos II
   Data da ultima atualizacao: 2022/7
----------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <time.h> //Inclusao da biblioteca para randomizacao dos numeros

long inspecoes = 0; // Quantida de inspecoes que um algoritmo faz

int valida_entrada(int min, int max);                              // Verifica se a entrada respeita certas condicoes
void aposta(int *vet, int valormax);                               // Le numeros apostados
void imprime_vetor(int vet[], int i, int tam);                     // Imprime qualque vetor
void sorteio(int *vet, int tam, int max);                          // Sorteia numeros nao repetidos
void checando_aposta(int jogo[], int vet[], int tam, int bus_bin); // Checa se numeros apostados foram sorteados

int busca_binaria(int vet[], int l, int r, int x); // Faz busca binaria em um vetor ordenado
int busca_sequencial(int[], int, int);             // Faz busca sequecial em um vetor desodenado
void troca(int *xp, int *yp);                      // Troca dois numeros de posicao
void selectionSort(int vet[], int n);              // Ordena vetor usando SectSort
void bubbleSort(int vet[], int n);                 // Ordena vetor usando BubbleSort
int particao(int A[], int inicio, int fim);        // Particao para QuickSort
void quickSortRec(int A[], int inicio, int fim);   // Ordena vetor usando QuickSort recursivo
void quickSortIterative(int vet[], int l, int h);  // Ordena vetor usando QuickSort iterativo

void main()
{
    int choice;
    int tamanhovetor = 100,
        valormaximo = 0,
        resultado = 0,
        i = 0;

    int vetor[tamanhovetor],
        copia[tamanhovetor],
        jogo[4];

    // Abertura do programa
    puts("\t=============================================================================");
    puts("\t\tTrabalho: Pratico 1 (2022): A Mega Quadra ");
    puts("\t\tAutor:    Vincent Tomio");
    puts("\t\tLink:     https://www.inf.ufpr.br/vvsbt20 ");
    puts("\t=============================================================================");
    puts("\n");

    srand(time(NULL));

    // Verifica se o player quer jogar ou sair do programa
    while (1)
    {
        // Menu do jogo
        puts(".....................");
        puts("\tMENU\n");
        puts("(1) Jogar MegaQuadra");
        puts("(0) Sair\n");
        puts(".....................");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0: // Saida do programa
        {
            puts("\n\tTchau, volte sempre! \n \t\t ;) \n");
            exit(0);
        }
        case 1: // Inicio do jogo
        {

            puts("Entre com o tamanhao do vetor.");
            tamanhovetor = valida_entrada(4, 100); // Le quantidade de numeros a ser sorteados

            puts("Entre com o numero maximo.");
            valormaximo = valida_entrada(tamanhovetor, 1000); // Le numero maximo a ser sorteado

            printf("\nTamanho do Vetor: %d\nValor maximo: %d\n\n", tamanhovetor, valormaximo);

            aposta(&jogo, valormaximo); // Le numeros apostados pelo jogador
            puts("\nSua aposta foi: ");
            imprime_vetor(jogo, 0, 3); // Imprime a aposta do jogador
            puts("BOA SORTE!\n");

            puts("Sorteando os Numeros...");
            sorteio(&vetor, tamanhovetor, valormaximo); // Sorteia numeros e coloca no vetor

            puts("Imprimindo vetor com numeros sorteado:");
            imprime_vetor(vetor, 0, tamanhovetor - 1); // Imprime numeros sorteados

            puts("Criando uma copia deste vetor\n");
            memcpy(copia, vetor, sizeof(vetor)); // Copia vetor desordena para utilizar Busca Sequencial

            puts("Ordenando Vetor usando SelectionSort...");
            selectionSort(vetor, tamanhovetor);                                       // Ordena vetor usando SelectSort
            printf("Numero de inspecoes realizadas pelo Algoritmo: %d\n", inspecoes); // Qunatidade de inspecoes que SelectSort fez
            inspecoes = 0;

            puts("Imprimindo vetor ordenado pelo SelectionSort");
            imprime_vetor(vetor, 0, tamanhovetor - 1); // Imprime vetor ordenado por  SelectSort

            puts("Ordenando Vetor usando BubbleSort...");
            bubbleSort(vetor, tamanhovetor);                                          // Ordena vetor usando BubbleSort
            printf("Numero de inspecoes realizadas pelo Algoritmo: %d\n", inspecoes); // Quantidade de inspecoes que BubbleSort fez
            inspecoes = 0;

            puts("Imprimindo vetor ordenado pelo BubbleSort");
            imprime_vetor(vetor, 0, tamanhovetor - 1); // Imprime vetor ordenado por BubbleSort

            puts("Ordenando Vetor usando QuickSort Iterativo...");
            quickSortIterative(vetor, 0, tamanhovetor);                               // Ordena vetor usando QuickSort iterativo
            printf("Numero de inspecoes realizadas pelo Algoritmo: %d\n", inspecoes); // Quantidade de inspecoes que QuickSort iterativo fez
            inspecoes = 0;

            puts("Imprimindo vetor ordenado pelo QuickSort Iterativo");
            imprime_vetor(vetor, 1, tamanhovetor); // Imprime vetor ordenado por QuickSort iterativo

            puts("Ordenando Vetor usando QuickSort Recursivo...");
            quickSortRec(vetor, 0, tamanhovetor);                                     // Ordena vetor usando QuickSort recursivo
            printf("Numero de inspecoes realizadas pelo Algoritmo: %d\n", inspecoes); // Quantidade de inspecoes que QuickSort recursivo fez
            inspecoes = 0;

            puts("Imprimindo vetor ordenado pelo QuickSort Recursivo");
            imprime_vetor(vetor, 1, tamanhovetor); // Imprime vetor ordenado por QuickSort recursivo

            puts("Verificando se Ganhou o jogo (USANDO BINARY SEARCH)");
            checando_aposta(jogo, vetor, tamanhovetor, 1); // Procura os numeros apostados no vetor de numeros sorteados ordenado usando Busca Binaria

            puts("Verificando se Ganhou o jogo (USANDO SEQUENCIAL SEARCH)");
            checando_aposta(jogo, copia, tamanhovetor - 1, 0); // Procura numeros apostados no vetor de numeros sorteados desordenados usando Busca Sequecial

            break;
        }
        default:
            puts("Entrada Incorreta\n"); // Usuario digitou entrada incorreta para iniciar o jogo
        }
    }
}

int valida_entrada(int min, int max) // leitura de entrada e verifica se a entrada esta entre 2 limites
{
    int numero = 0;

    while (1)
    {

        printf("(A entrada deve ser entre %d e %d)\nDigite a entrada:\n", min, max);
        scanf("%i", &numero);

        if (numero < min) // Verifica se a entrada eh menor que o permitido
            continue;
        else if (numero > max) // Verifica se a entrada eh maior que o permitido
            continue;
        else
            return numero;
    }
}

void aposta(int *vet, int valormax) // Le as apostas do usuario e verifica se sao validas
{
    int valmx[4];
    int i = 1,
        numero = 0,
        invalido = 1,
        repetido = 1;

    for (int i = 0; i < 4; i++)
    {
        valmx[i] = 0;
    }

    // Le e verifica a validez das apostas
    while (i <= 4)
    {

        printf("Digite o %d numero que voce deseja jogar: \n", i);
        numero = valida_entrada(1, valormax); // Chama valida entrada

        // impedir que a aposta tenha numeros repetidos
        if (valmx[0] == numero)
        {
            printf("\nDigite um numero diferente de %d! \n", valmx[0]);
        }
        else if (valmx[1] == numero)
        {
            printf("\nDigite um numero diferente de %d! \n", valmx[1]);
        }
        else if (valmx[2] == numero)
        {
            printf("\nDigite um numero diferente de %d! \n", valmx[2]);
        }
        else // Numero apostado eh valido entra na aposta
        {
            valmx[i - 1] = numero;
            i++;
        }
    }

    for (i = 0; i < 4; i++) // Passa por ponteiro as apostas para um vetor
    {
        *vet = valmx[i];
        vet++;
    };
}

// Imprime vetor na tela
void imprime_vetor(int arr[], int i, int tam)
{
    for (; i <= tam; i++)
    {
        printf("%d ", arr[i]);
    };

    puts("\n");
}

// Faz o sorteio dos numeros que deveram ser acertados na aposta
void sorteio(int *vet, int tam, int max)
{
    int valmx[max];
    int i = 0,
        j = 0,
        t = 0;

    // Criar um Vetor de 0 ateh o valor max digitado pelo usuario (Exemplo criando as bolinhas do bingo)
    for (i = 0; i < max; i++)
    {
        valmx[i] = i + 1;
    };

    // Embaralha o vetor aleatoriamente (Exmplo classico: Misturando as bolinhas do Bingo)

    for (i = 0; i < max; i++)
    {
        j = rand() % max;

        t = valmx[i];
        valmx[i] = valmx[j];
        valmx[j] = t;
    };

    // Colocando numeros sorteados no vetor
    for (i = 0; i < tam; i++)
    {
        *vet = valmx[i];
        vet++;
    };
}

// Checa se os numeros apostados foram sorteados
void checando_aposta(int jogo[], int vet[], int tam, int bus_bin)
{
    int i = 0,
        resultado = -1,
        num_sorteados = 0;

        puts("Imprimindo sua aposta");
        imprime_vetor(jogo, 0, 3);

    if (bus_bin) // vetor ordenado usa busca binaria
    {
        puts("Imprimindo Sorteio");
        imprime_vetor(vet, 1, tam);

        for (i; i < 4; i++) // busca binaria no vetor de numeros aleatorios ordenado para cada numero apostado
        {
            resultado = busca_binaria(vet, 0, tam - 1, jogo[i]);
            (resultado == -1) ? printf("Numero: %d Nao Sorteado\n", jogo[i])
                              : printf("Numero: %d Sorteado, Parabens! Localizacao Vetor[%d]\n", jogo[i], resultado-1) && num_sorteados++;
        }
        printf("Numero de inspecoes realizadas pelo Algoritmo: %d\n", inspecoes); // Quantidade de inspecoes que Busca Binaria fez
        inspecoes = 0;
        puts("");
    }
    else // Vetor desordenado usa busca sequencial
    {
        puts("Imprimindo Sorteio");
        imprime_vetor(vet, 0, tam);
        
        for (i; i < 4; i++) // Busca sequecial no vetor de numeros aleatorios desordenado para cada numero apostado
        {
            resultado = busca_sequencial(vet, tam, jogo[i]);
            (resultado == -1) ? printf("Numero: %d Nao Sorteado\n", jogo[i])
                              : printf("Numero: %d Sorteado, Parabens! Localizacao Vetor[%d]\n", jogo[i], resultado) && num_sorteados++;
        }
        printf("Numero de inspecoes realizadas pelo Algoritmo: %d\n", inspecoes); // Quantidade de inspecoes que Busca Linear fez
        inspecoes = 0;
        puts("");
    }

    if (num_sorteados == 4) // Ganhou o jogo se acertou 4 numeros apostados
        printf("WOW VOCE GANHOU!\nAcertou todos os numeros!\n");
    else
        printf("Voce acertou %d numeros\nBoa sorte na proxima\n", num_sorteados);

    puts("\n\n");
}

// Busca binaria recursiva no vetor ordenado
int busca_binaria(int vet[], int esq, int dir, int chave)
{
    if (dir >= esq) // Condicao de entrada
    {
        int meio = esq + (dir - esq) / 2; // Acha o meio de um vetor ordenado

        if (vet[meio] == chave)
        { // Verifica se numero no meio do vetor igual a chave
            inspecoes++;
            return meio;
        }

        if (vet[meio] > chave)
        { // Se numero maior que chave usa a esquerda do meio do vetor
            inspecoes++;
            return busca_binaria(vet, esq, meio - 1, chave);
        }
        // Numero menor que chave usa direita do meio do vetor
        inspecoes++;
        return busca_binaria(vet, meio + 1, dir, chave);
    }
    return -1;
}

// Busca sequencial sem sentinela no vetor desordenado
int busca_sequencial(int vet[], int n, int chave)
{
    int i;
    for (i = 0; i < n; i++) // Passa por cada elemento no vetor
    {
        inspecoes++;
        if (chave == vet[i]) // Verifica se numero no indice i do vetor igual a chave
            return (i);
    }
    return (-1);
}

// Troca 2 numeros de posicao em um vetor
void troca(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Ordenacao de um vetor por SelectSort
void selectionSort(int vet[], int n)
{
    int i, j, min;

    for (i = 0; i < n - 1; i++) // Avança posicao ordenada
    {
        inspecoes++;
        min = i;
        for (j = i + 1; j < n; j++) // Verifica todos os elementos de um vetor a partir de i+1
        {
            inspecoes++;
            if (vet[j] < vet[min]) // Verifica se o elemento na posicao j eh menor que elemento na posicao min
                min = j;
        }

        troca(&vet[min], &vet[i]); // Troca elemento na posicao min com elemento na posicao i
    }
}

// Ordenaçao de um vetor por Bubble Sort
void bubbleSort(int vet[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) // Limita ate onde j ja ordenou
    {
        inspecoes++;
        for (j = 0; j < n - i - 1; j++)
        { // Move j ate posicao ordenada
            inspecoes++;
            if (vet[j] > vet[j + 1]) // Troca elemento na pos j se for maior que proximo elemento no vetor
                troca(&vet[j], &vet[j + 1]);
        }
    }
}

// Seleciona o pivo como a mediana de tres elememtnos em um vetor
int particao(int vetor[], int inicio, int fim)
{
    int meio = (inicio + fim) / 2;
    int a = vetor[inicio];
    int b = vetor[meio];
    int c = vetor[fim];
    int medianaIndice;

    // Acha a mediana entre inicio,meio e fim
    inspecoes++;
    if (a < b)
    {
        inspecoes++;
        if (b < c)
        {
            medianaIndice = meio;
        }
        else
        {
            inspecoes++;
            if (a < c)
            {
                medianaIndice = fim;
            }
            else
            {
                medianaIndice = inicio;
            }
        }
    }
    else
    {
        inspecoes++;
        if (c < b)
        {
            medianaIndice = meio;
        }
        else
        {
            inspecoes++;
            if (c < a)
            {
                medianaIndice = fim;
            }
            else
            {
                medianaIndice = inicio;
            }
        }
    }
    troca(&vetor[medianaIndice], &vetor[fim]); // Coloca mediana no final do vetor

    int pivo = vetor[fim];
    int i = inicio - 1;
    int j;
    for (j = inicio; j <= fim - 1; j++)
    { // Ajeita vetor para posicionar pivo
        if (vetor[j] <= pivo)
        {
            i = i + 1;
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i + 1], &vetor[fim]); // Posiciona pivo em sua correta posicao
    return i + 1;
}

// Ordenar vetor usando QuickSort recursivo
void quickSortRec(int A[], int inicio, int fim)
{
    inspecoes++;
    if (inicio < fim)
    {
        int q = particao(A, inicio, fim); // Acha o pivo e faz a partiçao do vetor
        quickSortRec(A, inicio, q - 1);   // Chama QuickSort para vetor ah esquerda do pivo
        quickSortRec(A, q + 1, fim);      // Chama QuickSort para vetor ah direita do pivo
    }
}

// Oderna vetor usando QuickSort iterativo
void quickSortIterative(int vet[], int l, int h)
{
    int stack[h - l + 1];
    int top = -1;

    stack[++top] = l;
    stack[++top] = h;

    while (top >= 0)
    {
        inspecoes++;

        h = stack[top--];
        l = stack[top--];

        int p = particao(vet, l, h);

        if (p - 1 > l)
        {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        if (p + 1 < h)
        {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}
