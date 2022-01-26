#include <stdlib.h>

typedef struct node
{
    unsigned long key;
    int value;
    struct node *next;
} * Bucket;

typedef struct hashtable
{
    Bucket *arr;
    unsigned long N;
} * ClosedHashTable;

ClosedHashTable cht_make(unsigned long N)
{
    int i;
    ClosedHashTable cht = malloc(sizeof(struct hashtable));
    cht->N = N;
    cht->arr = malloc(sizeof(Bucket) * N);

    for (i = 0; i < cht->N; i++)
    {
        cht->arr[i] = NULL;
    }
}

void cht_destroy(ClosedHashTable cht)
{
    int i;
    Bucket j, tmp;

    if (cht != NULL)
    {
        for (i = 0; i < cht->N; i++)
        {
            for (j = cht->arr[i]; j != NULL;)
            {
                tmp = j;
                j = j->next;
                free(tmp);
            }
        }
    }
}

// complexidade?
// Melhor caso: 
//      1) chave existe na primeira posicao O(1).
// Pior caso: 
//      2) É quando todos as chaves deram origem ao mesmo psi e chave atual nao existe.
//          O(N)
int cht_exists(ClosedHashTable cht, unsigned long key)
{
    // 0 se nao existe
    // 1 se existe
    int resultado = 0;
    unsigned long psi = key % cht->N;
    Bucket b = cht->arr[psi];

    while (b != NULL && !resultado)
    {
        if (b->key == key)
        {
            resultado = 1;
        }

        b = b->next;
    }

    return resultado;
}

int cht_insert(ClosedHashTable cht, unsigned long key, int value)
{
    // 0 se nao fez insert, se elem com mm chave já existir.
    // 1 se fez insert.
    int existe = cht_exists(cht, key);
    unsigned long psi = key % cht->N;
    Bucket b = cht->arr[psi];

    if(existe == 0) {
        Bucket tmp = malloc(sizeof(struct node));
        tmp->key = key;
        tmp->value = value;
        tmp->next = b;
        cht->arr[psi] = tmp;
    }

    return !existe;
}

int cht_remove(ClosedHashTable cht, unsigned long key)
{
    // 0 se nao remove
    // 1 se remove
    int existe = cht_exists(cht, key);
    unsigned long psi = key % cht->N;
    Bucket *b = &cht->arr[psi];
    
    if(existe == 0) {
        while(*b != NULL && (*b)->key != key) {
            b = &(*b)->next;
        }
        free(*b);
        *b = (*b)->next;
    }

    return existe;
}