# Conjuntos

## Objetivo/Motivação

Assumindo que tens um conjunto de vários números naturais+0, seria ideal ter uma forma de eficientemente dizer se um elemento já foi visto numa sequência ou não.

Por simplicidade, assumimos que há no máximo N números naturais+0, ou seja, de 0 a N-1.

## Solução

1. Ter uma forma de armazenar N números
2. Associar a cada número o valor 0 ou 1, caso exista ou não, respetivamente.
3. Array começa com os valores todos a 0.
4. Cada elemento N está associado ao índice N.

## Código

```c
typedef struct simpleset {
    unsigned int *arr;      // Array de tamanho N.
    long unsigned int N;    // Número máximo de elementos naturais+0
} *SimpleSet;

// constructor
SimpleSet simple_set_make(long unsigned int N) {
    SimpleSet ss = malloc(sizeof(struct simpleset));
    ss->N = N;
    ss->arr = calloc(N, sizeof(unsigned int));
    return ss;
}

// de-constructor
void simple_set_destroy(SimpleSet ss) {
    free(ss->arr);
    free(ss);
}

int simple_set_contains(SimpleSet ss, unsigned int x) {
    return ss->arr[x];
}

void simple_set_add(SimpleSet ss, unsigned int x) {
    ss->arr[x] = 1;
}

void simple_set_remove(SimpleSet ss, unsigned int x) {
    ss->arr[x] = 0;
}
```


## O que é "muito eficiente"?

$$
\argmin_f T(N,f) = \theta(f)
$$

Queremos uma complexidade assimptótica que minimize, o máximo quanto possível o nosso tempo de execução.