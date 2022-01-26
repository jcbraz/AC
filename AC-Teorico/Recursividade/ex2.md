# Complexidade recursiva de função binária

```c
int bsearch(int x, int v[], int N) {
    int i;

    if (N <= 0) i = -1;
    else {
        m = N / 2

        if(v[m] == x) {                     // 1 comparação
            i = m;
        }
        else if(v[m] > x) {                 // 1 comparação
            i = bsearch(x, v, m)            // + algumas comparações
        }
        else {
            i = bsearch(x, v+m+1, N-m-1)    // + algumas comparações
            if (i != -1) i = i + m + 1
        }
    }

    return i;
}
```

## PASSO 1 - Existe melhor e pior caso?

Usando o número de comparações com elementos do array. O **melhor caso** acontece quando o elemento que procurar $x$, está no meio do array. O **pior caso** é quando o elemento não existe no array. 

***) NOTA IMPORTANTE:** por simplicidade vamos apenas usar o pior caso na definição recursiva, pois o melhor é imediato.

## PASSO 2 - Qual a definição recursiva de complexidade da função (PIOR CASO)?

$$
T(N) = 
\begin{cases}
0, N \leq 0\\
2 + T\bigg(\dfrac{N}{2}\bigg), N > 0
\end{cases}
$$

## PASSO 3 - Calcular o tempo total de execução (desdobrar o sistema, aka, deixar de ser recursivo)

Assumimos que se trata de um $N$ qualquer, fora do caso base.

$$
T(N) = 2 + T\bigg(\dfrac{N}{2}\bigg) = 2 + T\bigg(\dfrac{N}{2^1}\bigg)\\
T(N) = 2 + 2 + T\bigg(\dfrac{N}{4}\bigg) = 2 + 2 + T\bigg(\dfrac{N}{2^2}\bigg)\\
T(N) = 2 + 2 + 2 + T\bigg(\dfrac{N}{8}\bigg) = 2 + 2 + 2 + T\bigg(\dfrac{N}{2^3}\bigg)\\
\cdots\\
T(N) = 2i + T\bigg(\dfrac{N}{2^i}\bigg)
$$

Gostariamos de, apartir de $\dfrac{N}{2^i}$ conseguir chegar ao caso base. O caso base é quando $N \leq 0$, logo, torna problemática porque $\dfrac{N}{2^i} = 0 \Leftrightarrow N = 0$, isto não nos dá informação útil, porque no caso base, obviamente, já sbaemos que $N = 0$. O que normalmente se faz, é usar o caso mais acima, neste caso $T(1)$, sendo que facilmente chegamos que a complexidade deste é $T(1) = 2 + T(0) = 2$.

Logo, podemos calcular, quantas iteração são necessárias para chegar a $N = 1$.
$$
\dfrac{N}{2^i} = 1 \Leftrightarrow N = 2^i \Leftrightarrow \log_2(N) = \log_2(2^i) \Leftrightarrow i = \log_2(N)
$$

Substituindo o $i$ na expressão acima, temos que:

$$
T(N) = 2i + T\bigg(\dfrac{N}{2^i}\bigg)\\
T(N) = 2\cdot\log_2(N) + T\bigg(\dfrac{N}{2^{\log_2(N)}}\bigg)\\
T(N) = 2\cdot\log_2(N) + T\bigg(\dfrac{N}{N}\bigg)\\
T(N) = 2\cdot\log_2(N) + T(1)\\
T(N) = 2\cdot\log_2(N) + 2\\
T(N) = \theta(\log_2(N))\\
$$