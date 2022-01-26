# Definições recursivas

FUnções recursivas são mais díficeis de analisar.

```c
int maxInd(int v[], int N) {
    int i ;

    if (N==1) i = 0;
    else {
        i = maxInd(v,N-1); 
        if (v[N-1] > v[i]) i = N - 1;
    }
}
```


## 1) Qual a complexidade desta função relativamente ao num. de acessos à memória?

### PASSO 1 - Qual é o pior e melhor caso?

Teoricamente, o pior é quando faz mais acessos à memoria e melhor, quando faz menos. O pior e melhor caso, são o mesmo, em termos de número de acessos à memória. Logo, o tempo de execução é independente dos conteúdos do array.

***) NOTA IMPORTANTE**: Se houver pior e melhor caso, temos de seguir ramificações do programa, respectivamente para o melhor e pior caso.

### PASSO 2 - Qual a definição recursiva de complexidade da função?

$$
T(N) = 
\begin{cases}
0 , N = 1\\
T(N-1) + 2, N > 1
\end{cases}
$$

### PASSO 3 - Calcular o tempo total de execução (desdobrar o sistema, aka, deixar de ser recursivo)

Assumindo que existe um `N` inicial, tal que `N > 1`.
```
T(N) = T(N-1) + 2
     = T(N-2) + 2 + 2
     = T(N-3) + 2 + 2 + 2

Qual é a complexidade da i-ésima chamada à função?

     = ...
     = T(N-i) + 2*i
```

COm o caso geral, só podemos facilmente calcular, o número de iteração necessárias para alcançar o caso de base. Neste caso, isso acontece quando:

$$
N - i = 1 \Leftrightarrow i = N - 1
$$

Por isso, podemos concluir que a complexidade total é:

$$
T(N) = T(N-i) + 2\cdot i
     = T(N-(N-1)) + 2 \cdot(N-1)
     = T(1) + 2N - 2
     = 2N - 2 = \theta(N)
$$