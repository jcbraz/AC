# Resolucao EX41

- Custo 0, elemento na raiz, com probabilidade 1/N.
- Custo 1, se tiver na raiz da subarvore, com probabilidade de (1-1/N)*(1/N)
- Custo 2, (....), com prob. (1-1/N)^2*(1/N)
- ...
- Custo i, (....), com prob. (1-1/N)^i*(1/N)
- ...
- Custo log2(N), ...., com prob. ....

Meste caso, eles dizem que pode nao estar presente. Assim sendo, há dois casos com o custo maximo, i.e. log2(N). Logo, o tempo de execução médio pode ser dado por:

``` 
_
T(N) = log2(N)*(1-1/N)^(log2(N)) + sum_{i=1}^{log2(N)} i*(1-1/N)^i*(1/N)
```