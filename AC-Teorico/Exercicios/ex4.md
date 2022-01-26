# Resolução EX33

P(v[i] < v[i-1]) = 1/2

- Temos custo 1, i.e. v[1] < v[0], com probabilidade 1/2.
- Temos custo 2, i.e. v[1] >= v[0] && v[2] < v[1], com probabilidade 1/2^2
- Temos custo 3, i.e. v[1] >= v[0] && v[2] >= v[1] && v[3] < v[2], com probabilidade 1/2^3
- ...
- Temos custo i, i.e. forall(1<=j<=i-1) (v[j] >= v[j-1]) && v[i] < v[i-1], com probabilidade de 1/2^i
- ...
- Temos custo (N-1), (....), com probabilidade de 1/2^(N-1)

Há dois casos em que ocorrem (N-1) comparações, quando o último elemento não cumpre a inequality, e os anteriores cumprem. E quando todos cumprem. Logo, podemos resumir o numero medio de comparações a

_
T(N) = (N-1)/2^(N-1) + sum_{i=1}^{N-1} i/2^i