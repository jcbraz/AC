# Problema da Correção

Assumir que temos dois quaisqueres `P` e `Q`, e que `I = TRUE`

```c
// P
while(true) {
    // TRUE
    continue;
}
// Q
```

## 1) `P => I`

```
P => True 
(VALIDO)
```

## 2) `{I && c} continue; {I}`

```
*) I && c => I
*) True && True => True
(VALIDO)
```

## 3) `I && ~c => Q`

```
*) True && False => Q
*) False => Q
(VALIDO)
```

Distinguimos entre 2 tipos de correção: Correção parcial e correção total.

* **Correção parcial**: Que todas as CVs associadas ao programa são válidas.
* **Correção Total**: Sendo parcialmente correto, o programa é finito (chega ao fim,aka, numero de execuções tem um limite)

# Variante

Uma expressão inteira que cumpre os seguintes requisitos:

1. Decrescer a todas as iterações.
2. Tem um limite inferior (tipicamente 0).

## Condições de Verificação

```c
// {P}
while(c) {
    // {I}[V]
    
    // Programa S
    // ...
}
// {Q}
```

### 1) Parcial

1. `(I && ~c) => Q`
2. `{I && c} S {I}`
3. `P => I`

### 2) Total

1. `P => I`
2. `I && c => V >= 0`
3. `[I && c && v0 = V] S [I && V < v0]`
4. `(I && ~c) => Q`

## Exemplo #1

```c
// forall(0 <= i < N) A[i] = a_i
s = 0; 
p = 0;
// forall(0 <= i < N) A[i] = a_i && s = 0 && p = 0
while (p<N) {
    // {I}[V]
    s = s + A[p]; 
    p = p+1;
}
// s = sum(0 <= i < N) a_i
```

### Encontrar Invariante

#### 1) `(I && ~c) => Q`

```
*) (I && ~c) => Q
*) I && p >= N => s = sum(0 <= i < N) a_i
```

Temos de assumir que `I == s = sum(0 <= i < N) a_i`.


#### 1.1) Perceber de ciclo para ciclo

Assumimos que `A = [5,2,8,7]`, logo `N = 4`.

```
iteração            s                       p
0                   0 = -                   0
1                   5 = 5                   1
2                   7 = 5 + 2               2
3                   15 = 5 + 2 + 8          3
4                   22 = 5 + 2 + 8 + 7      4
...
i                   sum(0 <= t < p) a_t     i = p
```

Logo, chegamos a que `I == s = sum(0 <= i < p) a_i`. Será que continua a verificar `(I && ~c) => Q`?

```
*) (I && ~c) => Q
*) s = sum(0 <= i < p) a_i && p >= N => s = sum(0 <= i < N) a_i
```

Gostariamos de ter um mecanismo que, no último caso, garante que `p = N`. Sabemos, no último caso, que `p >= N` ou seja, adicionar a condição `p <= N` no invariante, garante que, no último caso, `p = N`.

Chegamos à conclusão que:

```
I == s = sum(0 <= i < p) a_i && p <= N
```



#### 2) `{I && c} S {I}`

Chegamos à conclusão que, dentro do invariante, temos de fixar todos os valores. Logo,

```
I == s = sum(0 <= i < p) a_i && p <= N && forall(0 <= i < N) A[i] = a_i
```

Como tal, assumimos que abaixo, o valor de A[i] está fixo.

```
*) {I && c} S {I}
*) {s = sum(0 <= i < p) a_i && p <= N && p < N} s = s + A[p]; p = p + 1 {s = sum(0 <= i < p) a_i && p <= N}
*) (s = sum(0 <= i < p) a_i && p < N) => (s = sum(0 <= i < p) a_i && p <= N)[p\p+1][s\s+A[p]]
                                      => s + A[p] = sum(0 <= i < p + 1) a_i && p + 1 <= N
                                      => s + A[p] = a_p + sum(0 <= i < p) a_i && p < N
                                      => s = sum(0 <= i < p) a_i && p < N
                                      (VALIDO)
```

#### 3) `P => I`

```
*) P => I
*) forall(0 <= i < N) A[i] = a_i && s = 0 && p = 0 => s = sum(0 <= i < p) a_i && p <= N && forall(0 <= i < N) A[i] = a_i
                                                   => 0 = sum(0 <= i < 0) a_i && 0 <= N && forall(0 <= i < N) A[i] = a_i
                                                   => 0 = 0 && 0 <= N && forall(0 <= i < N) A[i] = a_i
                                                   (VALIDO)
```

#### Conclusão

No fim chegamos à conclusão que:

```
I == s = sum(0 <= i < p) a_i && p <= N && forall(0 <= i < N) A[i] = a_i
```

### Encontrar Variante

Encontrar uma exporessão inteira `V` que: 1) decresce estritamente (ou seja, em todas as iterações); 2) tem um limite inferior de 0. Podemos usar a tabela para descobrir isto.

Assumimos que `A = [5,2,8,7]`, logo `N = 4`.

```
iteração            s                p      N       V
0                   0                0      4       4 - 0 = 4
1                   5                1      4       4 - 1 = 3
2                   7                2      4       4 - 2 = 2
3                   15               3      4       4 - 3 = 1
4                   22               4      4       4 - 4 = 0
...
i                   s                p      4       N - p
```

Há fortes indicios que `V = N - p` seja um variante adequado. As CVs associadas a verificação total são:

1. `P => I`: Não vale a pena verificar, não introduz `V` logo continua válida.
2. `I && c => V >= 0`: Não fizemos nada parecido.
3. `[I && c && v0 = V] S [I && V < v0]`: Nos já sabemos que parte desta CV é verdade, por isso, desde que `v0` e `V` não estejam incluidas no `I` ou `c`, então podemos simplificar o programa a `{v0 = V} S {V < v0}`.
4. `(I && ~c) => Q`: Não vale a pena verificar, não introduz `V` logo continua válida.

Assim sendo, falta verificar:

#### 1) `I && c => V >= 0`

```
*) I && c => V >= 0
*) s = sum(0 <= i < p) a_i && p <= N && forall(0 <= i < N) A[i] = a_i && p < N => N - p >= 0
                                                                               => p <= N
                                                                               (VALIDO)
```

#### 2) `{v0 = V} S {V < v0}`

```
*) {v0 = V} S {V < v0}
*) {v0 = N - p} s = s + A[p]; p = p +1 {N - p < v0}
*) (v0 = N - p) => (N - p < v0)[p\p+1][s\s+A[p]]
                => N - (p+1) < v0
                => N - p - 1 < v0
                => N - p - 1 < N - p
                => -1 < 0
                (VALIDO)
```

#### Conclusão

Logo, concluimos que com o invariante `I` e `V = N - p` este programa é totalmente correto, ou seja, é parcial coreto e termina.

## Exemplo #2

```c
// N >= 0
i = 0
// N >= 0 && i = 0
while(i < N) {
    // {True}[V]
    i = i + 1;
}
// i = N
```

### Verificar Invariante

#### 1) `(I && ~c) => Q`

```
*) (I && ~c) => Q
*) i >= N => i = N
*) (ADICIONAMOS NOVA CONDIÇÃO)
   i <= N && i >= N => i = N
                    (VALIDO)
```

Por isso temos de adicionar ao invariante a condição `i <= N`. Neste momento sabemos que `I = i <= N`

#### 2) `{I && c} S {I}`

```
*) {I && c} S {I}
*) i <= N && i < N => (i <= N)[i\i+1]
                   => i + 1 <= N
                   => i < N
                   (VALIDO)
```
#### 3) `P => I`

```
*) P => I
*) N >= 0 && i = 0 => i <= N
                   => 0 <= N
                   (VALIDO)
```

### Verificiar Variante

```
iteração        i       N       V
0               0       5       5 - 0 = 5
1               1       5       5 - 1 = 4
2               2       5       5 - 2 = 3
3               3       5       5 - 3 = 2
...
t               t       5       N - t
```

Logo, podemos definir o variante como sendo `V = N - t`. Logo só precisamos de ver 2 outras CVs (tendo em conta que as restantes já foram vistas). Que são:

#### 1) `I && c => V >= 0`

```
*) I && c => V >= 0
*) i <= N && i < N => N - i >= 0
*) i < N => N >= i
         (VALIDO)
```

#### 2) `{v0 = V} S {V < v0}`

```
*) {v0 = V} S {V < v0}
*) (v0 = N - i) => (N - i < v0)[i\i+1]
                => N - i - 1 < v0
                (VALIDO)
```