# Exercício 2

```c
int prod (int x, int y) {
    int r;
    r = 0;
    while (y>0) {                   // 1 op
        r = r+x;                    // 1 op
        y = y-1;                    // 1 op
    }
    return r;
}
```

```c
int bprod (int x, int y) {
    int r;
    r = 0;
    while (y>0) {                   // 1 op
        if (y%2 != 0) r = r+x;      // 3 op
        x = x*2;                    // 1 op
        y = y/2;                    // 1 op
    }
return r;
}
```

## a) quantas operações primitivas vao ser executados

### `prod`

Metemos `+1` de parte pois, no fim, a condição é falsa, mas a comparação é feita.

$$
T(N) = 1 + \sum_{p=1}^{N} 3 \\
     = 1 + 3\cdot\sum_{p=1}^{N} 1 \\
     = 1 + 3\cdot(N-1+1) \\
     = 1 + 3\cdot N \\
     = \theta(N)
$$


### `bprod`

O ciclo vai executar tantas vezes, como áquelas que eu consigo dividir $y$ por 2, que corresponde ao logaritmo de base2, i.e. $\log_2(y) + 1$.

$$
T(N) = 1 + \sum_{p=1}^{\log_2(N) + 1} 6 \\
     = 1 + 6\cdot\sum_{p=1}^{\log_2(N) + 1} 1 \\
     = 1 + 6\cdot(\log_2(N)-1+1) \\
     = 1 + 6\cdot \log_2(N) \\
     = \theta(\log_2(N))
$$

### Sumário

Em ambas as funções, $N$ representa o valor do número inteiro $y$ passado como input. Isto obviamente não é melhor solução, inteiros facilmente são bits, deixar de olhar par ao valor inteiro e sim para os respetivos bits. Agora assumindo N como número de bits, N = 8 permite tratar de 255 números diferentes.

Com N sendo o valor inteiro, concluimos que `bprod` é a solução mais adequado em termos de complexidade assimptótica.

## b) 

Agora consideramos N como sendo o número de bits. Alguns exemplos:

### Exemplo Nº1
```
N = 5

10000
10001
10010
...
11110
11111
```
### Exemplo Nº2
```
N = 3

100 = 4
101 = 5
110 = 6
111 = 7
```
### Como funciona o programa

#### `prod`

O pior caso desta função é quando os bits do número estão todos a 1. Pois, nesse caso.

$$
T(N) = 1 + 2^N - 1
     = 2^N
     = \theta(2^N)
$$

#### `bprod`


* 111 / 2 = 111 >> 1 = 11

* 1010 / 2 = 1010 >> 1 = 101

* 1ª iteração
  * `y = 110 ; y = y / 2 = y >> 1; y = 11` 
* 2ª iteração
  * `y = 11 ; y = y / 2 = y >> 1; y = 1`
* 3ª iteração
  * `y = 1 ; y = y / 2 = y >> 1; y = 0`

O pior caso desta função é quando os bits do número estão todos a 1. Pois, nesse caso.

$$
T(N) = 1 + 6N
     = \theta(N)
$$
