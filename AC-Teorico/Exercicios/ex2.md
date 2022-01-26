# `msort`

$$
T(N) 
= 
\begin{cases}
0 , N = 1\\
T_{mergeH}(N) + 2\cdot T\Big(\dfrac{N}{2}\Big), N > 1
\end{cases}
=
\begin{cases}
0 , N = 1\\
2N + 2\cdot T\Big(\dfrac{N}{2}\Big), N > 1
\end{cases}
$$

Logo, assumindo $N>1$, temos que:

$$
T(N) = 2N + 2\cdot T\Big(\dfrac{N}{2}\Big)\\
T(N) = 2N + 2\cdot \Bigg[N + 2\cdot T\Big(\dfrac{N}{4}\Big)\Bigg] =2N+2N+4\cdot T\Big(\dfrac{N}{4}\Big)=4N+4\cdot T\Big(\dfrac{N}{4}\Big)\\
T(N) = 2N + 2\cdot \Bigg[N + 2\cdot \Bigg[\dfrac{N}{2} + 2\cdot T\Big(\dfrac{N}{8}\Big)\Bigg]\Bigg] = 2N + 2\cdot \Bigg[2N + 4\cdot T\Big(\dfrac{N}{8}\Big)\Bigg]\\
T(N) = 2N + 4N + 8\cdot T\Big(\dfrac{N}{8}\Big) = 6N + 8\cdot T\Big(\dfrac{N}{8}\Big)
$$

Logo, no caso geral $i$, podemos definir como:

$$
T(N) = 2iN + 2^i\cdot T\Big(\dfrac{N}{2^i}\Big)
$$

Sabemos que o caso de paragem é $N=1$, logo $\dfrac{N}{2^i} = 1 \Leftrightarrow N = 2^i \Leftrightarrow i = \log_2{N}$. Assim sendo, temos que:

$$
T(N) = 2\log_2(N)N + 2^{\log_2(N)}\cdot T\Big(\dfrac{N}{2^{\log_2(N)}}\Big) = 2\log_2(N)N + N\cdot T\Big(\dfrac{N}{N}\Big) \\
T(N) = 2\log_2(N)N = \theta(N\log_2(N))
$$
