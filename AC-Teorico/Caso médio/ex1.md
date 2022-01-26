# Exercício 1

Há um total de $N$ elementos no array, cada inteiro é representado por $W$ bits. Neste caso, qual é a probabilidade de, numa qualquer posição, estar um inteiro especifico?

$$
p = \dfrac{1}{2^W}
$$

Qual é a probilidade do elemento $x$ estar contido num array de tamanho $N$. 

$$
p = \dfrac{N}{2^W}
$$

## `xlsearch`

```c
int xlsearch (int a[], int N, int x) {
    int i = 0;

    while (i<N && a[i]!=x)
        i++;

    if (i<N) return i;
    else return (-1);
}
```

- Se o elemento $x$ estiver no índice 0, eu faço 1 acesso. Com probabilidade de $\dfrac{1}{2^W}$.
- Se o elemento $x$ estiver no índice 1, eu faço 2 acesso. Com probabilidade de $\Bigg(1-\dfrac{1}{2^W}\Bigg)\dfrac{1}{2^W}$.
- Se o elemento $x$ estiver no índice 2, eu faço 3 acesso. Com probabilidade de $\Bigg(1-\dfrac{1}{2^W}\Bigg)^2\dfrac{1}{2^W}$.
- $\cdots$
- Se o elemento $x$ estiver no índice $i$, eu faço $i$ acesso. Com probabilidade de $\Bigg(1-\dfrac{1}{2^W}\Bigg)^i\dfrac{1}{2^W}$.
- Se o elemento não estiver no array, eu faço $N$ acessos. Com probabilidade de $\Bigg(1-\dfrac{1}{2^W}\Bigg)^{N}$

Agora, podemos calcular a complexidade, a pesar o custos, relativamente à probabilidade. Ou seja, é uma média pesada dos acessos à memória.


$$
\hat{T}(N,W) = N\Bigg(1-\dfrac{1}{2^W}\Bigg)^{N} + \sum_{i=0}^{N-1} i\Bigg(1-\dfrac{1}{2^W}\Bigg)^i\dfrac{1}{2^W}\\
\hat{T}(N,W) = N\Bigg(1-\dfrac{1}{2^W}\Bigg)^{N} + \dfrac{1}{2^W}\sum_{i=0}^{N-1} i\Bigg(1-\dfrac{1}{2^W}\Bigg)^i
$$

## `lsearch`

```c
int lsearch (int a[], int N, int x) {
    int i = 0;

    while (i<N && a[i]<x)
        i++;

    if (i<N && a[i]==x) return i;
    else return (-1);
}
```
[1,4,7,9]

E se tiver?
- Se o elemento $x$ estiver no índice 0, eu faço 1 acesso. Com probabilidade de $\dfrac{1}{2^W}$.
- Copiar igual ao de cima.

E se não estiver?
- Se o elemento $x$ for menor que o elemento do índice 0, eu faço 1 acesso. Com probabilida de $\dfrac{1}{2^W}$.
- Se o elemento $x$ for menor que o elemento do índice 1, eu faço 2 acesso. Com probabilida de $\dfrac{2}{2^W}$.
- Se o elemento $x$ for menor que o elemento do índice $i$, eu faço $i+1$ acesso. Com probabilida de $\dfrac{i+1}{2^W}$.

- Se o elemento for maior que todos os outros.

$$
\hat{T}(N,W) = \{CORRETOS\} + \{ERRADOS\}
$$


## `bsearch`

```c
int bsearch (int a[], int N, int x) {
    int l, u, m;
    l = 0;
    u = N-1;
    while (l<u) {
        m = (l+u)/2;
        if (a[m]==x)
            l = u = m;
        else if (a[m]>x)
            u = m-1;
        else
            l = m+1;
    }
    if (a[m]==x) return m;
    else return (-1);
}
```

- Se o elemento $x$ estiver no meio da $1$-ésima divisão, eu faço 1 acesso. Com probabilidade $\dfrac{1}{2^W}$
- Se o elemento $x$ estive no meio da $2$-ésima divisão, eu faço 2 acesso. Com probabilidade $\Bigg(1-\dfrac{1}{2^W}\Bigg)\dfrac{1}{2^W}$
- Se o elemento $x$ estive no meio da $i$-ésima divisão, eu faço $i$ acesso. Com probabilidade $\Bigg(1-\dfrac{1}{2^W}\Bigg)^{i-1}\dfrac{1}{2^W}$

Quantas divisões é posso fazer no máximo? $i = \log_2(N)$

- Se o elemento não estiver no array, faço $\log_2(N)$, com probabiliade de $\Bigg(1-\dfrac{1}{2^W}\Bigg)^{\log_2(N)-1}$

Logo, 

$$
\hat{T}(W,N) = \Bigg(1-\dfrac{1}{2^W}\Bigg)^{\log_2(N)-1} + \sum_{i=1}^{\log_2(N)} i\Bigg(1-\dfrac{1}{2^W}\Bigg)^{i-1}\dfrac{1}{2^W}
$$
