# Exercício 2

```c
void inc (int b[], int N) {
    int i;
    i = 0;
    while ((i < N) && (b[i] == 1)) {
        b[i] = 0;
        i++;
    }
    if (i<N) b[i] = 1;
}
```

- Eu faço 1 acesso se `b[0] == 0`, com probabiliade $\dfrac{1}{2}$.
- Eu faço 2 acessos se `b[0] == 1 && b[1] == 0`, com probabilidade $\dfrac{1}{2^2}$.
- Eu faço 3 acessos se `b[0] == 1 && b[1] == 1 && b[2] == 0`, com probabilidade de $\dfrac{1}{2^3}$
- Eu faço $i$ acessos se `forall(0<=k<i) b[k] == 1 && b[i] == 0`, com probabilidade de $\dfrac{1}{2^i}$
- (NESTE MOMENTO) dá para perceber que há dois casos, em que fazemos $N$ acessos.
- Eu faço $N$ acesoss se `forall(0<=k<N) b[k] == 1`, com probabilidade de $\dfrac{1}{2^N}$

Logo, a complexidade é

$$
\hat{T}(N) = \dfrac{N}{2^N} + \sum_{i=1}^{N} \dfrac{i}{2^i}
$$