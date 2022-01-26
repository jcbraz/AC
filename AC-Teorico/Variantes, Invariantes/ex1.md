# Revisão de exercícios

```c
// n == n0 > 1 && f == 2
while(n%f != 0) {
    // I
    f = f + 1;
}
// n0 %f == 0 && forall(1<k<f) n0%k != 0
```

Passos a seguir:

## 1) `I && ~c => Q`

Concluimos que:

`I = n == n0 && forall(1<k<f) n0%k != 0`

## 1.1) Passos do Ciclo

Assumindo n = 5.

```
iteração            f           n       n % f
0                   2           5       1
1                   3           5       2
2                   4           5       1
```

O invariante já generaliza bem para qualquer ciclo.

## 2) `{I && c} f = f + 1 {I}`

```
*) n == n0 && forall(1<k<f) n0%k != 0 && n%f != 0 => (n == n0 && forall(1<k<f) n0%f != 0)[f\f+1]
*) n == n0 && forall(1<k<f+1) n0%k != 0 => n == n0 && forall(1<k<f+1) n0%k != 0
```

Logo é válido, porque é uma tautologia, mesma coisa à esq. e à dir.


## 3) `P => I`
Sabemos que `P = n == n0 > 1 && f == 2`, `I = n == n0 && forall(1<k<f) n0%k != 0`.

```
*) n == n0 > 1 && f == 2 => n == n0 && forall(1<k<f) n0%k != 0
                         => n == n0 && forall(1<k<2) n0%k != 0
                         => n == n0
```
