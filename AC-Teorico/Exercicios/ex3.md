# Resolução Teste 2016

## Parte A

### Exercício 1

#### Descobrir Invariante

**Passo 1**: Assumimos `I = j == i`.
**Passo 1.1**: Tentar perceber iteração-a-iteração.


Assumindo `A = [9,5,3,2,8]`, `B = [*,*,*,*,*]`, `N=5`

```
iteração        k       i       j       B
0               0       0       3       [*,*,*,*,*]
1               1       0       2       [*,*,*,9,*]
2               2       1       2       [5,*,*,9,*]
3               3       2       2       [5,3,*,9,*]
(ACABOU, pois k == n - 1)
```

(FALTA DESCOBRIR INV.)

#### Gerar Condições de Verificação

Primeiro temos de anotar o programa na totalidade.

```c
// PRE: n > 0
i = 0; j = n - 2; k = 0;
// n > 0 && i = 0 && j == n -1 && k == 0
while(k < n - 1) {
    // I
    if(a[k] <= a[n-1]) {
        b[i] = a[k]; i = i + 1;
    }
    else {
        b[j] = a[k]; j = j + 1;
    }
    k = k + 1;
}
// POS: j == i - 1
```

CVs são:

1. `n > 0 => n > 0 && i = 0 && j == n -1 && k == 0`
2. `P => I` -- `n > 0 && i = 0 && j == n -1 && k == 0 => I`
3. `{I && c} S {I}` -- isto ramifica em 2:
   1. `{I && k < n - 1 && a[k] <= a[n-1]} b[i] = a[k]; i = i + 1; k = k + 1 {I}`
      1. `(I && k < n - 1 && a[k] <= a[n-1]) => I[k\k+1][i\i+1][b[i]\a[k]]`
   2. `{I && k < n - 1 && a[k] > a[n-1]} b[j] = a[k]; j = j + 1; k = k + 1 {I}`
      1. 1. `(I && k < n - 1 && a[k] > a[n-1]) => I[k\k+1][j\j+1][b[j]\a[k]]`
4. `(I && ~c) => Q` -- `(I && k >= n -1) => j == i -1 `

### Exercício 2

#### A)

O problema pode-se partir em 2, primeiro descobrir complexidade de `maxSomaPref`. E depois, usar em `maxSomaConseq`

Utilizando o número de acesso ao array como métrica, temos:

##### Complexidade de `maxSomaPref`

$$
T(N) = \sum_{i=0}^{N-1}1 = (N - 1 - 0 + 1) = N = \theta(N)
$$

##### Complexidade de `maxSomaConseq`

$$
T(N) 
=
\begin{cases}
0, N = 0\\
T_{maxSomaPref}(N) + T(N-1), N > 0
\end{cases}
=
\begin{cases}
0, N = 0\\
N + T(N-1), N > 0
\end{cases}
$$

```
T(N) = N + T(N-1)
     = N + N + T(N-2)
     = N + N + N + T(N-3)
     ...
     = iN + T(N-i)
```

O caso base é quando `N - i = 0 <=> i = N`. Logo, a complexidae é:

```
T(N) = NN + T(N-N) = N^2 = \theta(N^2)
```

#### B)

```c
int maxSomaConseq(int v[], int N) {
    int i, somas[N];
    somas[0] = 0

    for(i = 1; i < N; i++) {
        somas[i] = somas[i-1] + v[i]
    }

    // 3*(N-1) = 3N - 3 acessos

    max = somas[0]

    for(i = 1; i < N; i++) {
        if (somas[i] > max) {
            max = somas[i]
        }
    }
    // 3N acesso

    // 3N - 3 + 3N = \theta(N)

    return max
}

```


## Parte B

### Cenário (i)

Sabemos que o elemento existe na árvore, logo, dado N elementos, a probabilidade de o encontrar é de $\dfrac{1}{N}$. Logo, a probabilidade e não encontrar é de $1-\dfrac{1}{N}$.

- Tem custo 1 com probabilidade $\dfrac{1}{N}$.
- Tem custo 2 com probabilidade $\Big(1-\dfrac{1}{N}\Big)\dfrac{1}{N}$.
- Tem custo 3 com probabilidade $\Big(1-\dfrac{1}{N}\Big)^2\dfrac{1}{N}$.
- $\cdots$
- Tem custo de $i$ com probabilidade $\Big(1-\dfrac{1}{N}\Big)^{i-1}\dfrac{1}{N}$.
- $\cdots$
- Tem custo de $\log_2(N)$ com probabilidade ...

Logo, o custo médio pode ser dado por:

$$
\hat{T}(N) = \sum_{i=1}^{\log_2(N)} i\Big(1-\dfrac{1}{N}\Big)^{i-1}\dfrac{1}{N}
$$

### Cenário (ii)

$$
\hat{T}(N) = (1-p)\log_2(N) + p\sum_{i=1}^{\log_2(N)} i\Big(1-\dfrac{1}{N}\Big)^{i-1}\dfrac{1}{N}
$$

### Cenário (iii)

- Tem custo 1 com probabilidade $\dfrac{1}{N}$.
- Tem custo 2 com probabilidade $\Big(1-\dfrac{1}{N}\Big)\dfrac{1}{N}$.
- Tem custo 3 com probabilidade $\Big(1-\dfrac{1}{N}\Big)^2\dfrac{1}{N}$.
- $\cdots$
- Tem custo de $i$ com probabilidade $\Big(1-\dfrac{1}{N}\Big)^{i-1}\dfrac{1}{N}$.
- $\cdots$
- Tem custo de $N$ com probabilidade ...

Logo, o custo médio pode ser dado por:

$$
\hat{T}(N) = \sum_{i=1}^{N} i\Big(1-\dfrac{1}{N}\Big)^{i-1}\dfrac{1}{N}
$$