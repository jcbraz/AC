# Resolucao EX12

Assumindo a métrica a considerando como sendo o número de operações de divisão, então, temos que:

        --> 0, N = 1
T(N)
        --> 1 + 2*T(N/2), N > 1

```
T(N) = 1 + 2*T(N/2)
     = 1 + 2*(1 + 2*T(N/4)) = 3 + 4*T(N/4)
     = 3 * 4*(1+2*T(N/8)) = 7 + 8T(N/8)
     = ...
     ≃ (2^i-1) + 2^i*T(N/2^i)
```

O caso base o é N = 1, logo

N/2^i = 1 <=> i = log2(N)

Logo, tempo de execução total é:

T(N) = N - 1 = THETA(N)