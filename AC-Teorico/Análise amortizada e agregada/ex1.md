# 1) Tempo Médio

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

Assumindo a complexidade como uma análise ao número de acessos à memória, temos que:

## A&B) Melhor e Pior caso?


- **MELHOR CASO**: O bit no índice 0, o menos significativo, é 0. Logo, $T(N) = \theta(1)$.
- **PIOR CASO**: Qualquer que seja o índice, o valor do correspondente bit é 1. Logo, o corpo do ciclo é sempre executado. $T(N) = \sum_{i=0}^{N-1} 2 = (N-1-0+1)\cdot2 = 2N = \theta(N)$

## C) Tempo Médio

### Passo 1 - Tentar fazer inferência sobre diferentes custos e respetivas probabiliades

- Com custo de 1, que acontece quando `b[0] == 0`, com probabiliade de $\dfrac{1}{2}$.
- Com custo de 2, que acontece quando `b[1] == 0 && b[0] == 1`, com probabiliade de $\dfrac{1}{2^2}$.
- Com custo de 3, que acontece quando `b[2] == 0 && b[1] == b[0] == 1`, com probabiliade de $\dfrac{1}{2^3}$.
- $\cdots$
- Com custo de $i$, que acontece quando `b[i-1] == 0 && forall(0<=k<i-1) b[k] == 1`, com probabiliade de $\dfrac{1}{2^i}$.
- $\cdots$
- Com custo de $N$, que acontece quando `b[N-1] == 0 && forall(0<=k<N-1) b[k] == 1`, com probabiliade de $\dfrac{1}{2^N}$.

Para além disso, existe um outro caso, o pior caso, em que o custo é de $N$, com probabilidade de $\dfrac{1}{2^N}$. Logo, o tempo médio de execução é:

$$
\hat{T}(N) = \dfrac{N}{2^N} + \dfrac{1}{2}^{N-1}\Bigg[\dfrac{−N - 2}{2}\Bigg] + 2\\
\lim\hat{T}(N) = 2 = \theta(1)
$$

#### Como simplificar o sumatório?

$$
\sum_{i=1}^{N}\dfrac{i}{2^i} = \sum_{i=0}^{N}\dfrac{i}{2^i} = \sum_{i=1}^{N}i\bigg(\dfrac{1}{2}\bigg)^i = \dfrac{N\dfrac{1}{2}^{N+2} − (N + 1)\dfrac{1}{2}^{N+1} + \dfrac{1}{2}}{(\dfrac{1}{2} − 1)^2}\\
= 4\Bigg[N\dfrac{1}{2}^{N+2} − (N + 1)\dfrac{1}{2}^{N+1}\Bigg] + 2\\
= 4\Bigg[\dfrac{N}{2}\cdot\dfrac{1}{2}^{N+1} − (N + 1)\dfrac{1}{2}^{N+1}\Bigg] + 2\\
= 4\cdot\dfrac{1}{2}^{N+1}\Bigg[\dfrac{N}{2} − N - 1\Bigg] + 2\\
= 4\cdot\dfrac{1}{2}^{N+1}\Bigg[\dfrac{N− 2N - 2}{2}\Bigg] + 2\\
= 4\cdot\dfrac{1}{2}^{N+1}\Bigg[\dfrac{−N - 2}{2}\Bigg] + 2\\
= \dfrac{1}{2}^{-2}\cdot\dfrac{1}{2}^{N+1}\Bigg[\dfrac{−N - 2}{2}\Bigg] + 2\\
= \dfrac{1}{2}^{N-1}\Bigg[\dfrac{−N - 2}{2}\Bigg] + 2\\
$$

# 1) Análise Amortizada

Amealhar custos para pagar depois. Há 2 métodos principais de fazer isto:

- **Análise Agregada**: Há funções que nem sempre (em todos as iterações), possuem o mesmo custo. Por exemplo, um array que quando chega ao máximo duplica de tamanho. Logo, queremos conseguir calcular um custo total, $C_N$ das execuções da função, e fazer uma estimativa sobre o tempo de execução, custo, da função $\hat{c}_i = \dfrac{C_N}{N}$
- **Método Contrabilístico**: Nos fazemos a previsão de $\hat{c}_i$, de formal a obter uma estimativa de custo, que seja, no mínimo superior ao custo real. "Amealhar custos para pagar depois", ou seja, se tenho 2 de saldo diário, e gasto 1 hoje, amanhã vou ter 3 para gastar.

## A) Análise Agregada

Assumindo que a função `inc` é chamada para um input de $N = 5$, sucessivamente. Na análise amortizada, temos de fixar o número de chamadas, por isso assumimos $N=5$ chamadas.

```
Id  |   INPUT           |   custo
0       10000               1
1       10001               2 = 1 + 1
2       10010               1
3       10011               3 = 1 + 1 + 1
4       10100               1
```

- Em $N$ casos eu tenho, pelo menos, custo de 1.
- Em $\dfrac{N}{2}$ tem $+1$ que o anterior.
- Em $\dfrac{N}{4}$ tem $+1$ que o anterior.

Logo, nos poderiamos calcular o custo total como sendo...

$$
C_N = N + \dfrac{N}{2} + \dfrac{N}{4} + \dfrac{N}{8} + \cdots\\
C_N = \sum_{i=0}^{??} \dfrac{N}{2^i}\\
C_N = \sum_{i=0}^{\log_2(N)} \dfrac{N}{2^i}\\
$$

Queremos o custo estimado por operação, que é dado por:

$$
\hat{c}_i = \dfrac{C_N}{N} = \dfrac{\sum_{i=0}^{\log_2(N)} \dfrac{N}{2^i}}{N} = \sum_{i=0}^{\log_2(N)} \dfrac{1}{2^i} = \dfrac{\dfrac{1}{2}^{\log_2(N)+1} − 1}{\dfrac{1}{2}-1} = \dfrac{\dfrac{1}{2}\cdot\dfrac{1}{N} − 1}{\dfrac{1}{2}-1} =\\
 \dfrac{\dfrac{1-2N}{2N}}{-\dfrac{1}{2}} = -\dfrac{2(1-2N)}{2N} =-\dfrac{1-2N}{N} = 2 -\dfrac{1}{N} = \theta(1)
$$

## B) Método Contabilistico

Queremos estimar qual será o custo por operação. A ideia é que os custos passem a funcionar como um banco. Num banco, nos temos a possibilida de $B$, ver qual o balanço do banco, $W$ de withdrawal, levantamento de dinheiro,  $D$ depósitos.

Motivação: TOdo o custo que eu consigo poupar, fica armazenado para depois, no meu $B$. A ideia, mais geral, é que o nosso custo estimado seja maior que o custo real. por isso.

$$
\sum_{i=1}^{N}c_i \leq \sum_{i=1}^{N}\hat{c}_i\\
\Leftrightarrow \sum_{i=1}^{N}\hat{c}_i -  \sum_{i=1}^{N}c_i \geq 0\\
$$

Por isso, podemos generalizar e dizer que $D_k$ corresponde ao nosso contributo para o calculo do custo. Logo, neste caso, $D_k = \sum_{i=1}^{k}\hat{c}_i$. E tudo, o que nos levantamos, o que verdadeiramente gastamos, pode ser dado por $W_k = \sum_{i=1}^{N}c_i$. Assim sendo, num qualquer momento $k$, podemos calcular o nosso balanço como sendo $B_k$.

$$
B_k = D_k - W_k\\
B_k = B_{k-1} + (\hat{c}_k - c_k)
$$

Claro que, isto só faz sentido, se houver uma base, aka caso de paragem, normalmente assumimos como sendo $B_0 = 0$.

### 1) Assumindo $\hat{c} = 1$

```
Id  |   INPUT           |   c_i     |   ĉ_i     | B_i
---------------------------------------------     0
0       10000               1           1         0
1       10001               2           1         -1 (FALHA)

```

Logo, verifica-se que a previsão é insuficiente, pois o balanço chega a negativo.

### 1) Assumindo $\hat{c} = 2$

```
Id  |   INPUT           |   c_i     |   ĉ_i     | B_i
---------------------------------------------     0
0       10000               1           2         1
1       10001               2           2         1
2       10010               1           2         2
3       10011               3           2         1
4       10100               1           2         2
```

Chegamos à conclusão, através do nosso universo de amostras, que o custo previsto é suficiente para garantir um balanço positivo.

Uma possível justificação poderia ser que: Nos já sabemos que todos gastam pelo menos 1, logo por aí, assumir $\hat{c}_i = 1$ dificilmente funcionaria, pois não há espaço para poupança.

Com $\hat{c} = 2$ todas as operações que apenas custam $1$ poupam um total de $1$. Nos podemos provar que isto funciona, desde que consigamos provar que há suficientes operações com custo $1$ para suprimir as necessidades de todas as operações com custo $> 1$.

- Quantas operações de custo $1$ há? Para cada par de operações, existe 1 operação que apenas tem custo de 1. Ou seja, há pelo menos $\dfrac{N}{2}$ operações com custo de 1.
- A cada par, há 1 operação que não contribui, ou contribui negativamente para o saldo.