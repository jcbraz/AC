# Exercício

## a) usando #{swaps} qual o pior e melhor caso de cado?

### 1) Troca Direta

Temos de ver o que impede ou beneficia, a execução da nossa métrica.

#### MELHOR CASO

Se `v[i]>v[j]` for sempre falso, então, nunca vamos executar a função `swap`. Na prática, traduz-se dizendo que o melhor caso é quando o array de input já está totalmente ordenado.

$$
T(N) = 0 = \theta(1)
$$


#### PIOR CASO

Se `v[i]>v[j]` for sempre verdadeiro, então, vamos sempre executar a função `swap`. Na prática, traduz-se dizendo que o pior caso é quando o array de input está totalmente ordenado de forma decrescente.

$$
T(N) = \sum_{i=0}^{N-2}\sum_{j=i+1}^{N-1}1 \\
     = \sum_{i=0}^{N-2} (N - 1 - i - 1 + 1) \\
     = \sum_{i=0}^{N-2} (N - 1 - i) \\
     = \sum_{i=0}^{N-2} (N - 1) - \sum_{i=0}^{N-2} i \\
     = (N-2-0+1)\cdot(N-2) - \sum_{i=0}^{N-2} i \\
     = (N-1)\cdot(N-2) - \dfrac{(N-2)*(N-1)}{2} \\
     = \theta(N^2)
$$

### 2) Selection Sort

#### MELHOR CASO

O melhor caso é quando `i==m` é sempre verdade. O que implica que a condição `v[m] <= v[j]` é sempre verdade. Logo, o mesmo que dizer que o melhor caso é quando o array já está ordenado.

$$
T(N) = 0 = \theta(1)
$$

#### PIOR CASO

O melhor caso é quando `i!=m` é sempre verdade. O que implica que a condição `v[m] > v[j]` é sempre verdade. Logo, o mesmo que dizer que o pior caso é quando o array está ordenado de forma decrescente.

$$
T(N) = \sum_{i=0}^{N-2}1 = (N - 2 - 0 + 1) = N - 1 = \theta(N)
$$

### 3) Bubble Sort

#### MELHOR CASO

O melhor caso é quando `v[j-1]<=v[j]` é sempre verdade. Logo, o mesmo que dizer que o melhor caso é quando o array já está ordenado.

$$
T(N) = 0 = \theta(1)
$$

#### PIOR CASO

O pior caso é quando `v[j-1]>v[j]` é sempre verdade. Logo, o mesmo que dizer que o pior caso é quando o array está ordenado por ordem decrescente.

$$
T(N) = \theta(N^2)
$$