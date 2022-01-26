# Complexidade

Que a funcao consiga correr no menor tempo possivel, com o menor numero de recursos e da forma mais ~correta~ e eficiente possível.


1. Minimizar tempo de execução.         
2. Minimizar utilização de recursos.
3. Maximizar eficiência.                (Complexidade Assimptótica)


## 1) Minimizar tempo de execução

Na prática, diferentes funções tem um tempo de execxução por operação distinto. Por isso i++ custa c1 na arquitetura X, mas na Y custa c2.

## 2) Utilização de recursos

Por isso, é maioritariamente ignorado. Programas nunca devem usar demasiados recursos. 

Caso #1: orderanção simplista de arrays. Pegamos num array de tamanho N e calculamos todas as sequeências, vou precisar de N! sequências. Logo, preciso de espaço para N! arrays e para N!*N elementos. Gastar o mais perto possivel de N.

## 3) Complexidade Assimptótica

Fixar um contador para análise.

  * Número de vezes que ciclo corre
  * Número de ifs
  * Numero de atribuição

Permite chegar a uma função `T(N)`

### 3.1) Exemplo #1

```c
x = 0           // (1 atribuição)
x = x + 1       // (1 atribuição)
                // Total = 2
```

Para definir a complexidade do programa, usamos o número de atribuição como contador. Logo, o tempo de execução é:

`T(N) = 1 + 1 = 2`

### 3.2) Exemplo #2

Assumindo `N` como sendo um número `>= 0`.

```c
i = 0

while(i < N) {
    i = i + 1
}
```

Definimos a complexidade como sendo o número de somas. `T(N) = ...`.

```
N           T(N)
0           0
1           1
2           2
3           3
...
i           i
```

A complexidade desta função é `T(N) = N`

### 3.3) Exemplo #3

Assumindo `N` como sendo um número `>= 0`.

```c
i = 0; j = 0

while(i < N) {
    i = i + 1;          // 1 soma
    j = j + 1;          // 1 soma
}
                        // 2 somas por ciclo
```

Pelo que se pode definir `T(N) = sum(0<=i<=N-1) 2 = (N - 1 + i +1)*2 = 2*N`
.

#### 3.3.1) Prova

```
S = sum(a<=i<=b) 1
  = a + (a + 1) + (a + 2) + ... + (b - 2) + (b - 1) + b
```

Ou, pode ser escrito como:

```
S = sum(a<=i<=b) i
  = b + (b - 1) + (b - 2) + ... + (a + 2) + (a + 1) + a
```

O que se pode simpificar como:

```
S+S = (a+b) + ((a+1)+(b - 1)) + ((a+2)+(b - 2)) + ... + ((a + 2)+(b-2)) + ((a + 1)+(b-1)) + (a+b)
2*S = a+b + a+b + ... + a+b + a+b
    = (a+b)(b-a+1)
```

Logo, podemos concluir que `S = ((a+b)*(b-a+1)/2)`

## 4) Análise Assimptótica a Prática

Queremos sempre analisar o melhor, pior e caso médio.

### 4.1) (MELHOR) Qual a complexidade de ordenar um array ordenado?

Ou seja, `T(N) = N = \theta(N)`.

### 4.2) (PIOR) Qual é a complexidade de ordenar um array decrescente de forma crescente?

Ou seja, `T(N) = N*N = N^2 = \theta(N^2)`.

### 4.3) Caso Médio

Só veremos mais adiante como funciona.

## 5) Família de Funções Assimptóticas

```
T(N) = 2*n + 3   \in theta(N)
     = 4*n + 7   \in theta(N)
     = 5*n       \in theta(N)
     = n         \in theta(N)
```

1. "Ah esta função como em tempo constante" - `f = \theta(1)`
2. "Esta função corre em tempo linear" - `f = \theta(N)`
3. "Esta função corre em tempo quadrático" - `f = \theta(N^2)`
4. "esta função corre em tempo logaritmo" - `f = \theta(log2(N))`