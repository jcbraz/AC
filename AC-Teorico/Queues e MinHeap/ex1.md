# Filas de Espera (Queue)

Enquanto que a Stack é do tipo FIFO (first in, firt out), a Queue é quase que o oposto pois é LIFO (last in, first out). No fundo, é o que acontece numa fila do supermercado.

Gostariamos de ser possivel ter os seguintes método:

- `enqueue` : onde tentamos inserir um elemento na nossa fila de espera.
- `dequeue`: onde tiramos o próximo elemento da fila de espera.

Imaginando o seguinte exemplo:

```
No inicio temos a seguinte fila:

v = [33, 12, 29, 40]

1) O que é que dequeue(v) deveria retornar?
    dequeue(v) returns 33
    v == [12, 29, 40]

2) dequeue(v)
    dequeue(v) returns 12
    v == [29, 40]

3) enqueue(v, 13)
    v == [29, 40, 13]
```

Por isso, o algoritmo feito funciona da seguinte:
1. Array com espaço para N elemento
2. Fazemos `enqueue` na última posição disponivel, se possivel.
3. Fazemos `dequeue` no indice 0, e puxamos todos os elementos à frente para a esquerda.

## Código

```c
typedef struct queue {
    int *arr;
    int num_elems;
    int N;
} *Queue;

// assumir que construr está feito
// assumir que de-construr está feito

int enqueue(Queue q, int x) {
    int r = 1;

    if(q->num_elems == q->N) {
        r = 0;
    }
    else {
        q->arr[q->num_elems] = x;
        q->num_elems++;
    }

    return r;
}

int dequeue(Queue q, int *ex) {
    int i, r = 1;

    if(q->num_elems == 0) {
        r = 0;
    }
    else {
        *ex = q->arr[0];
        q->num_elems--;

        for(i = 0; i < q->num_elems; i++) {
            q->arr[i] = q->arr[i+1];
        }
    }

    return r;
}
```

### Qual é a complexidade de `enqueue` e `dequeue`?

Em termos de número de acesso ao array, pior caso. Assumindo que N é o número de elementos presentes no array.

- `enqueue`: $T(N) = \theta(1)$.
- `dequeue`: $T(N) = \theta(N)$.

Enqueue é muito bom, mas dequeue é mau, pos para cada inserção temos de ver todos os elementos. Normalmente, nas estruturas de dados, o que queremos é o mais próximo possível de $\theta(1)$.


## Código Optimizado

```c
typedef struct queue {
    int *arr;
    int sp;         // starting point
    int num_elems;
    int N;
} *Queue;

// assumir que construr está feito
// assumir que de-construr está feito


int enqueue(Queue q, int x) {
    int r = 1;

    if(q->num_elems == q->N) {
        r = 0;
    }
    else {
        int idx = (q->sp + q->num_elems) % q->N;
        q->arr[idx] = x;
        q->num_elems++;
    }

    return r;
}

int dequeue(Queue q, int *ex) {
    int i, r = 1;

    if(q->num_elems == 0) {
        r = 0;
    }
    else {
        *ex = q->arr[q->sp]
        q->num_elems--;
        q->sp = (q->sp + 1) % q->N;
    }

    return r;
}
```

### Complexidade?

- `enqueue`: $T(N) = \theta(1)$.
- `dequeue`: $T(N) = \theta(1)$.
