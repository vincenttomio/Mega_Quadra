# A Mega Quadra (2022)

Este repositório contém o código-fonte em C para o Trabalho Prático 1 (2022) intitulado "A Mega Quadra". O programa simula um jogo de loteria em que o jogador aposta em números e tenta acertar os números sorteados. Ele implementa diferentes algoritmos de ordenação e busca para analisar o desempenho e verificar se os números apostados foram sorteados.

## Informações Gerais

- **Autor:** Vincent Tomio
- **Disciplina:** Algoritmos II
- **Data da última atualização:** 2022/7

## Compilação e Execução

Para compilar e executar o programa, siga as etapas abaixo:

1. Certifique-se de ter um ambiente de desenvolvimento C instalado.
2. Salve o código-fonte em um arquivo chamado `main.c`.
3. Abra um terminal e navegue até o diretório onde o arquivo `main.c` está localizado.
4. Execute os seguintes comandos:

```bash
gcc -o programa main.c
./programa
```

## Funcionalidades

### Jogar MegaQuadra: 
O programa oferece a opção de jogar a Mega Quadra. O jogador pode escolher o tamanho do vetor de números sorteados e o valor máximo dos números sorteados.

### Métodos de Ordenação: 
O programa implementa quatro métodos de ordenação diferentes:
1. Selection Sort
2. Bubble Sort
3. QuickSort Recursivo
4. QuickSort Iterativo

### Verificação de Apostas: 
O programa verifica se os números apostados pelo jogador foram sorteados. Ele utiliza busca binária para o vetor ordenado e busca sequencial para o vetor desordenado de números sorteados

## Estrutura do Código

O código está estruturado da seguinte forma:

- **Header:** Informações gerais sobre o programa, incluindo autor, disciplina e data.
- **Inclusões:** Inclusão das bibliotecas necessárias (`stdio.h` e `time.h`).
- **Declarações de Funções:** Declarações das funções utilizadas no programa.
- **Função main:** Função principal que executa o jogo e as análises.
- **Funções Auxiliares:** Funções auxiliares para validação de entrada, leitura de apostas, impressão de vetores, sorteio de números e verificação de apostas.
- **Métodos de Ordenação:** Implementações dos algoritmos de ordenação: Selection Sort, Bubble Sort, QuickSort Recursivo e QuickSort Iterativo.
- **Busca Binária e Sequencial:** Implementações das funções de busca binária e busca sequencial.
- **Compilação:** Código para compilar e executar o programa.

## Uso do Programa

1. O programa exibirá um menu onde você pode escolher entre jogar a Mega Quadra ou sair do programa.
2. Se escolher jogar, você poderá definir o tamanho do vetor de números sorteados e o valor máximo dos números sorteados.
3. Em seguida, você deverá apostar em quatro números diferentes.
4. O programa realizará o sorteio dos números e aplicará diferentes algoritmos de ordenação, exibindo o vetor ordenado e o número de inspeções feitas por cada algoritmo.
5. Por fim, o programa verificará se os números apostados por você foram sorteados, utilizando busca binária para o vetor ordenado e busca sequencial para o vetor desordenado.

## Notas

- O programa utiliza busca binária para verificar se os números apostados foram sorteados no vetor ordenado. Para o vetor desordenado, é utilizada busca sequencial.
- O código pode ser estendido ou aprimorado, por exemplo, adicionando mais métodos de ordenação ou aprimorando a interface do usuário.