# Filas com Prioridade

Fazer uma forma da fila ter prioridade implictamente, por exemplo, idosos servem servidos primeiro que pessoas novas  e pessoas de cadeiras de rodas depois de idosos mas antes de pessoas comuns.

Uma solucao naive era ordenar um array de forma crescente pela prioridade, não funciona pois a complexidade de inserçao no pior caso é linear.

## Código

```c
typedef struct minheap {
    int *arr;
    int num_elems;
    int N;
} *MinHeap;

// constructor
// de-constructor

int enqueue(MinHeap q, int x) {
    int i, r = 1;

    if(q->num_elems == q->N) {
        r = 0;
    }
    else {
        q->arr[q->num_elems] = x;

        i = q->num_elems;
        q->num_elems++;

        while(i > 0) {
            pai = (i - 1) / 2;

            if(q->arr[i] < q->arr[pai]) {
                swap(q->arr, i, pai);
            }
            else {
                break;
            }

            i = pai;
        }
    }

    return r;
}

int dequeue(MinHeap q, int *ex) {
    int i,j, r = 1;

    if(q->num_elems == 0) {
        r = 0;
    }
    else {
        i = 0
        *ex = q->arr[0];

        while(1) {
            j = i;
            esq = 2*i + 1;
            dir = 2*i + 2;

            if(esq >= q->num_elems) {
                break;
            }
            else {
                if(dir >= q->num_elems) {
                    i = esq;
                }
                else {
                    if(q->arr[dir] < q->arr[esq])
                        i = dir;
                    else 
                        i = esq;
                }
                swap(q->arr,i,j)
            }
        }
        
        q->num_elems--;
    }

    return r;
}
```