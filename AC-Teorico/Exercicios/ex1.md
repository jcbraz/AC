# Recorrencia do `isort`

## 1) MELHOR CASO

$$
T(N) = 
\begin{cases}
0 , N = 0\\
T(N-1) + 2, N > 0
\end{cases}
$$

Assumindo $N > 0$.

$$
T(N) = T(N-1) + 2 = T(N-2) + 2 + 2 = T(N-3) + 2 + 2 + 2 = T(N-i) + 2i
$$ 

Sabemos que o caso que paragem é quando $N=0$. Logo, podemos $N-i=0 \Leftrightarrow i = N$

Então:

$$
T(N) = T(N-N) + 2N = T(0) + 2N = 2N = \theta(N)
$$

## 2) PIOR CASO

$$
T(N) = 
\begin{cases}
0 , N = 0\\
T(N-1) + N-1, N > 0
\end{cases}
$$

```
T(N) = T(N-1) + N-1
     = T(N-2) + N-2 + N-1       = T(N-2) + 2N - (1+2)
     = T(N-3) + N-3 + N-2 + N-1 = T(N-3) + 3N - (1+2+3)
     ...
     (NO CASO GERAL i)
     = T(N-i) + iN - sum_{k=1}^{i} k
     = T(N-i) + iN - (i^2+i)/2
```

O caso de paragem é quando $N=0$, logo $N-i=0 \Leftrightarrow i =N$. Logo, a complexidade fica:

$$
T(N) = T(N-N) + N\cdot N + \dfrac{N^2+N}{2} = N^2 + \dfrac{N^2+N}{2} = \theta(N^2)
$$

# REFERÊNCIAS

## Como derivar soma #2
$$
\sum_{k=1}^{i} k = \dfrac{(i-1+1)(i+1)}{2} = \dfrac{i^2+i}{2}
$$

$$
S = \sum_{i=a}^{b} i = a + (a+1) + (a+2) + \cdots + (b-2) + (b-1) + b
$$

$$
S = \sum_{i=a}^{b} i = b + (b-1) + (b-2) + \cdots + (a+2) + (a+1) + a
$$

$$
S+S = (a+b) + ((a+1)+(b-1)) +  ((a+2)+(b-2)) + \cdots + ((b-2)+(a+2)) + ((b-1)+(a+1)) = (b+a)\\
$$

$$
2S = (a+b) + (a+b) + (a+b) + \cdots + (a+b) + (a+b) + (a+b)\\
2S = (b-a+1)(a+b)\\
S = \dfrac{(b-a+1)(a+b)}{2}
$$