# Multi-Conjuntos

Imagina que queriamos ser capazes de, para além de ver se um elemento já foi visto, ver quantas vezes é que ele foi visto, obviamente da forma mais eficiente possivel. Ou seja, idealmente cada operação deve ser apenas na ordem de $\theta(1)$.

Respeitando as seguintes restrições:

- Apenas podem ser utilizados `unsigned int`, ou sejas, naturais+0.
- Cada índice está associado ao respetivo número. Ou seja, indice 0 é do num. 0 e assim sucessivamente.

## Exemplos

```
[0,1,0,0,1] - número 1 e 4 já foram vistos.
[3,0,1,0,0] - número 0 visto 3 vezes, número 2 visto 1 vez.
```

## Especificação

Deveria ser possível as seguintes funcionalidades:

- Teste de pertence, ver se um número já foi visto.
- Remoção
- Adição
- Contagem
- `[constructor]`
- `[deconstructor]`

## Código

```c
typedef long unsigned int LUI;

typedef struct multiset {
    LUI N;
    LUI *arr;
} *MultiSet;

MultiSet multi_set_new(LUI N) {
    MultiSet ms = malloc(sizeof(struct multiset));
    ms->arr = calloc(N, sizeof(LUI));
    ms->N = N;
    return ms;
}

void multi_set_destroy(MultiSet ms) {
    free(ms->arr);
    free(ms);
}

int multi_set_exists(MultiSet ms, LUI idx) {
    return ms->arr[idx] > 0;
}

void multi_set_remove(MultiSet ms, LUI idx) {
    if(ms->arr[idx] > 0) {
        ms->arr[idx]--;
    }
}

void multi_set_add(MultiSet ms, LUI idx) {
    ms->arr[idx]++;
}

LUI multi_set_get(MultiSet ms, LUI idx) {
    return ms->arr[idx];
}

```