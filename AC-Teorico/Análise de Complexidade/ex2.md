# Exercícios

## Ficha 2, 1.1.

### a)

#### `xlsearch`

Assumimos que a condição `a[i] != x` é sempre falsa. Logo, vamos ter de percorrer o array todo.

Quantos acessos de array faço por ciclo?

`T(N) = sum(0<=i<=N-1) 1 = (N-1+0+1)*1 = N = \theta(N)`

#### `lsearch`

Assumimos que a condição `a[i] < x` é sempre falsa. Logo, vamos ter de percorrer o array todo.

Quantos acessos de array faço por ciclo?

`T(N) = 1 + sum(0<=i<=N-1) 1 = 1 + (N-1+0+1)*1 = N + 1 = \theta(N)`

### b)


#### `xlsearch`

##### MELHOR CASO

O melhor caso é quando `a[0] == x`, logo `T(N) = 1 = \theta(1)`.

##### PIOR CASO

O pior caso é quando `x` não se encontra no array, logo `T(N) = N = \theta(N)`.

#### `lsearch`

##### MELHOR CASO

Há 2 melhores casos, 1) quando o elemento `x` é menor que o mínimo (primeiro elemento, devido a ordenação) 2) quando `a[0] == x`.

Ambas produzem complexidade de `T(N) = 1 + 1 = \theta(1)`.

##### PIOR CASO

Quando `x` é maior que o maior elemento do array, ou seja, `x > a[n-1]`. Logo, `T(N) = N + 1 = \theta(N)`.

### c)

Com base nos dados acima, os dois algoritmo parecem ser idênticos em termos de complexidade assimptótica de melhor e pior caso. No entanto, o 2o algoritmo oferece um melhor caso a mais que o 1o.

### d)

#### MELHOR CASO

Elemento do meio é o elemento que eu quero, logo `T(N) = 1 = \theta(1)`.


#### PIOR CASO

Elemento não existe, logo `T(N) = log2(N)`.