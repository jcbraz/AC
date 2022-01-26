# Procura numa árvore binária

## PASSO 1 - Existe melhor e pior caso?

O melhor caso é quando o elemento que procurar é a raiz da árvore onde queremos procurar. O pior caso é quando não existe.

Por isso, por o melhor caso ser trivial, olhamos só para o pior caso.

## PASSO 2 - Qual a definição recursiva de complexidade da função (PIOR CASO)?
Como não sabemos o programa, assumimos que o caso base custa $c_1$ e o caso genérico custa $c_2$.

$$
T(N) = 
\begin{cases}
c_1, N \leq 0\\
c_2 + 2\cdot T\bigg(\dfrac{N}{2}\bigg), N \geq 1
\end{cases}
$$

## PASSO 3 - Calcular o tempo total de execução (desdobrar o sistema, aka, deixar de ser recursivo)

Assumimos que se trata de um $N$ qualquer, fora do caso base.

$$
T(N) = c_2 + 2\cdot T\bigg(\dfrac{N}{2}\bigg)\\
T(N) = c_2 + 2\cdot \Bigg[ c_2 + 2\cdot T\bigg(\dfrac{N}{2^2}\bigg)\Bigg] = 3c_2 + 2^2\cdot T\bigg(\dfrac{N}{2^2}\bigg)\\
T(N) = c_2 + 2\cdot \Bigg[ c_2 + 2\cdot \Bigg[c_2 + 2\cdot T\bigg(\dfrac{N}{2^3}\bigg)\Bigg]\Bigg] = c_2 + 2\cdot \Bigg[ 3c_2 + 4\cdot T\bigg(\dfrac{N}{2^3}\bigg)\Bigg] = 7c_2 + 2^3\cdot T\bigg(\dfrac{N}{2^3}\bigg)\\
\cdots\\
T(N) = (2^i-1)\cdot c_2 + 2^i \cdot T\bigg(\dfrac{N}{2^i}\bigg)
$$

Tentar igualar a nossa função um qualquer $i$ ao nosso caso base, neste caso, o caso base **possível** é 1. No caso base temos $T(1) = c_2 + 2\cdot T(0) = c_2 + 2c_1$.

$$
\dfrac{N}{2^i} = 1 \Leftrightarrow N = 2^i \Leftrightarrow \cdots \Leftrightarrow i = \log_2(N)
$$

Por isso, podemos substuir $i$ na nossa expressão acima e obtemos:

$$
T(N) = (2^{\log_2(N)}-1)\cdot c_2 + 2^{\log_2(N)} \cdot T\bigg(\dfrac{N}{2^{\log_2(N)}}\bigg) = (N-1)\cdot c_2 + N\cdot T(\dfrac{N}{N}) = (N-1)\cdot c_2 + N\cdot T(1)\\
T(N) = (N-1)\cdot c_2 + N\cdot (c_2 + 2c_1) = Nc_2 - c_2 + Nc_2 + 2Nc_1 = \theta(N)
$$