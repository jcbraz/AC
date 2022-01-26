# Procura numa RoseMap ($\psi$ ramos)

Assumimos que exste uma rose map, com ume stado arbitrário, ou seja, não ordenado. Com $\psi$ ramos pelos quais pode seguir a qualquer dado momento. Esta rosemap tem sempre $\psi$ ramos.

## PASSO 1 - Existe melhor e pior caso?

O melhor caso é quando o elemento que procurar é a raiz da árvore onde queremos procurar. O pior caso é quando não existe.

Por isso, por o melhor caso ser trivial, olhamos só para o pior caso.

## PASSO 2 - Qual a definição recursiva de complexidade da função (PIOR CASO)?
Como não sabemos o programa, assumimos que o caso base custa $c_1$ e o caso genérico custa $c_2$.

$$
T(N) = 
\begin{cases}
c_1, N \leq 0\\
c_2 + \psi\cdot T\bigg(\dfrac{N}{\psi}\bigg), N \geq 1
\end{cases}
$$

## PASSO 3 - Calcular o tempo total de execução (desdobrar o sistema, aka, deixar de ser recursivo)

Assumimos que se trata de um $N$ qualquer, fora do caso base.

$$
T(N) = c_2 + \psi\cdot T\bigg(\dfrac{N}{\psi}\bigg)\\
T(N) = c_2 + \psi\cdot \Bigg[ c_2 + \psi\cdot T\bigg(\dfrac{N}{\psi^2}\bigg)\Bigg] = (\psi + 1)\cdot c_2 + \psi^2\cdot T\bigg(\dfrac{N}{\psi^2}\bigg)\\
T(N) = c_2 + \psi\cdot \Bigg[ c_2 + \psi\cdot \Bigg[c_2 + \psi\cdot T\bigg(\dfrac{N}{\psi^3}\bigg)\Bigg]\Bigg] = c_2 + \psi\cdot \Bigg[ (\psi + 1)\cdot c_2 + \psi^2\cdot T\bigg(\dfrac{N}{\psi^3}\bigg)\Bigg]\\
T(N) = c_2 + \psi\cdot(\psi+1)\cdot c_2 + \psi^3\cdot T\bigg(\dfrac{N}{\psi^3}\bigg)\\
T(N) = (1 + \psi^2 + \psi)c_2 + \psi^3\cdot T\bigg(\dfrac{N}{\psi^3}\bigg)\\
\cdots\\
T(N) = \theta(N)
$$
