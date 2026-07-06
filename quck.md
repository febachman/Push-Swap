Quick Sort adaptado para Push Swap — resumo
1. O que precisa estar pronto antes

Antes de começar o Quick Sort, você precisa ter:

parser validando argumentos
stack A e stack B funcionando
operações funcionando: sa, sb, pa, pb, ra, rb, rra, rrb
rank_convert funcionando
função para verificar se a stack está ordenada
contador/lista de operações

O rank_convert transforma os valores reais em posições ordenadas. Isso facilita o algoritmo, porque você passa a trabalhar com ranks de 0 até n - 1, em vez de números negativos, positivos ou muito grandes. Essa ideia é recomendada no artigo do chunk adaptado.

2. Ideia do Quick Sort

O Quick Sort faz:

pegar um grupo grande
dividir em grupos menores
ordenar os grupos menores
juntar tudo na ordem correta

No Push Swap, esses grupos são chamados de chunks.

3. O que é um chunk

Um chunk é um pedaço da stack que você quer ordenar.

Ele precisa guardar:

posição onde está
tamanho
menor rank
maior rank

Exemplo:

chunk inicial:
posição = TOP_A
tamanho = 100
min = 0
max = 99
4. Posições úteis

Pense que existem quatro posições:

TOP_A
BOTTOM_A
TOP_B
BOTTOM_B

Isso ajuda porque as rotações permitem mandar valores para o topo ou para o fundo das stacks.

5. Caso base

A recursão precisa parar quando o chunk for pequeno.

Casos base:

se tamanho == 0:
    não faz nada

se tamanho == 1:
    mover para TOP_A

se tamanho == 2:
    ordenar direto

se tamanho == 3:
    usar sort_three
6. Escolher pivôs

Para dividir um chunk em 3 partes, use dois pivôs.

Exemplo:

chunk:
min = 0
max = 99
tamanho = 100

Pivôs:

pivo1 = min + tamanho / 3
pivo2 = min + tamanho * 2 / 3

Resultado:

pequenos: 0 até 32
médios:   33 até 65
grandes:  66 até 99
7. Dividir o chunk

Durante o split:

se valor >= pivo2:
    vai para o grupo grande

se valor >= pivo1 e valor < pivo2:
    vai para o grupo médio

se valor < pivo1:
    vai para o grupo pequeno

Exemplo de distribuição:

grandes  -> BOTTOM_A
médios   -> TOP_B
pequenos -> BOTTOM_B
8. Chamada recursiva

Depois de dividir, chama o Quick Sort de novo.

Ordem:

quick_sort(grandes)
quick_sort(médios)
quick_sort(pequenos)

Pseudocódigo:

quick_sort(chunk):

    se chunk for pequeno:
        ordenar direto
        retornar

    dividir chunk em:
        grandes
        médios
        pequenos

    quick_sort(grandes)
    quick_sort(médios)
    quick_sort(pequenos)
9. Fluxo completo do programa
main:

    validar entrada

    montar stack A

    converter valores para rank

    se tamanho <= 3:
        usar sort pequeno

    senão:
        criar chunk inicial com todos os valores em TOP_A

        quick_sort(chunk inicial)

    imprimir operações
10. Ordem de implementação
1. Fazer rank_convert

2. Criar struct de chunk

3. Criar enum de posições:
   TOP_A
   BOTTOM_A
   TOP_B
   BOTTOM_B

4. Criar função para escolher pivôs

5. Criar função split_chunk

6. Criar quick_sort recursivo

7. Criar sort para chunks pequenos:
   tamanho 1
   tamanho 2
   tamanho 3

8. Testar com poucos números

9. Testar com 100 números

10. Testar com 500 números

11. Só depois otimizar
11. Meta inicial

Não tente fazer a versão otimizada primeiro.

Primeira meta:

conseguir dividir um chunk em 3 partes
e chamar quick_sort para cada parte

Depois que funcionar, melhore:

casos base
pivôs
rotações
operações duplas
remoção de operações inúteis

O subject aceita Quick Sort como estratégia complexa O(n log n) usando particionamento com stacks.


DIVISAO DE FUNCOES
- definir tamanho chunk_size
