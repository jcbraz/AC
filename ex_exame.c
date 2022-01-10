#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1

#define SIZE 1009
typedef struct no
{
    char matricula[6];
    struct no *next;
} No;
typedef No *Tabela[SIZE];

// construtor
/*
Tabela hashtable_make()
{
    int i;
    Tabela hash = malloc(sizeof(No*) * SIZE); // Tabela ?
    for (i = 0; i < SIZE; i++)
    {
        hash[i] = NULL;
    }
    return hash;
}
*/

// deconstrutor
void hashtable_destroy(Tabela hash)
{
    int i;
    No *j, *tmp;
    if (hash != NULL)
    {
        for (i = 0; i < SIZE; i++)
        {
            for (j = hash[i]; j != NULL;)
            {
                tmp = j;
                j = j->next;
                free(tmp);
            }
        }
    }
}

// int hash(char matricula[6]) // 1 char = 1 byte -> 256 numeros possiveis

// int insert(Tabela t, char matricula[6]) //igual a funçao presente no closed adressing

// 3 --> ultima materia de estrutura de dados
typedef struct arvore
{
    unsigned int bal;
    struct node *esq, *dir;
} * Arvore;

void bals(Arvore a)
{
    if (!a)
        return;
    a->bal = altura(a->dir) - altura(a->esq);
    bals(a->esq);
    bals(a->dir);
}

// Melhor caso : arvore com apenas 3 nodos, 1 pai, 1 esquerda e 1 direita -> bal = 1 -> Theta(N) = 2N
// Pior caso : arvore com N nodos distribuidos tanto na esquerda como direita
//             Theta(N) = 2N + T(a->esq) + T(a->dir)
//                      = 2N + 2N + 2N + ...
//                      = (2N)^i  -> 2<i<N  //duvida

// // 9
// #define MaxH 25 // valor aleatorio
// typedef struct mHeap
// {
//     int tamanho;
//     int heap[MaxH];
// } * MinHeap;

// // esq = 2*i + 1;
// // dir = 2*i + 2;

// void swap(int arr[], int i, int j)
// {
//     int tmp;
//     arr[tmp] = arr[i];
//     arr[i] = arr[j];
//     arr[j] = tmp;
// }

// int muda(MinHeap h, int pos, int valor)
// {
//     int i, j, pai, esq, dir, r = 1;
//     if (h->tamanho == 0)
//     {
//         r = 0;
//     }
//     else
//     {
//         i = pos;
//         h->heap[i] = valor;
//         while (i > 0 && i < h->tamanho)
//         {
//             pai = (i - 1) / 2;
//             esq = 2 * i + 1;
//             dir = 2 * i + 2;

//             if (h->heap[i] < h->heap[pai])
//             {
//                 swap(h->heap, i, pai);
//                 i = pai;
//             }
//             else if (dir < h->tamanho)
//             {
//                 if (h->heap[dir] < h->heap[esq] && h->heap[i] > h->heap[dir])
//                 {
//                     swap(h->heap, i, dir);
//                 }

//                 else if (h->heap[esq] < h->heap[dir] && h->heap[i] > h->heap[esq])
//                 {
//                     swap(h->heap, i, esq);
//                 }
//             }
//             else if (h->heap[i] > h->heap[esq])
//             {
//                 swap(h->heap, i, esq);
//                 i = esq;
//             }
//             else if (h->heap[i] > h->heap[dir])
//             {
//                 swap(h->heap, i, dir);
//                 i = dir;
//             }
//             else
//                 break;
//         }
//     }
//     return r;
// }

// 7
typedef struct node
{
    int info;
    struct node *esq, *dir;
} * Node;

Node buildBST(int arr[], int n)
{
    Node a = malloc(sizeof(Node));
    int mid = n / 2;
    if (n == 0)
        a == NULL;
    else
    {
        a->info = arr[mid];
        while (mid - 1 >= 0)
        {
            a->esq = buildBST(arr, mid - 1);
        }
        while (mid < n)
        {
            a->dir = buildBST(arr, mid + 1);
        }
    }
    return a;
}

// 8
typedef long unsigned int LUI;

typedef struct simpleset
{
    LUI N;
    LUI *arr;
} * SimpleSet;

// construtor
SimpleSet simple_set_make(LUI N)
{
    SimpleSet ss = malloc(sizeof(struct simpleset));
    ss->N = N;
    ss->arr = calloc(N, sizeof(LUI));
}

void simple_set_destroy(SimpleSet ss)
{
    free(ss->arr);
    free(ss);
}

int simple_set_contains(SimpleSet ss, LUI x)
{
    return ss->arr[x];
}

void simple_set_order(SimpleSet ss)
{
    LUI i;
    for (i = 0; i < ss->N; i++)
    {
        if (ss->arr[i] != 0)
        {
            printf("%d\n", i);
        }
    }
}

typedef struct nodo *ABPInt;
struct nodo
{
    int valor;
    ABPInt esq, dir;
};

// 10
int procura(ABPInt a, int l, int u)
{
    int r = 0;
    if (a != NULL)
    {
        if (a->valor > l && a->valor < u)
            r = 1;
        else if (a->valor <= l)
            procura(a->dir, l, u);
        else if (a->valor >= u)
            procura(a->esq, l, u);
    }
    return r;
}

// 11
//
//  Melhor caso = a-> valor da raiz encontra se dentro do intervalo de l até r --> T(N) = Theta(1)
//
//
// Pior caso = todos os a->valores da arvore não pertenciam ao intervalo de l até r --> T(N) = log2(N)
//

// 12
// #define MaxH 70
// typedef struct mHeap
// {
//     int tamanho;
//     int heap[MaxH];
// } MinHeap;

// // esq = 2 * i + 1;
// // dir = 2 * i + 2;
// // pai = (i - 1) / 2;

// int maxHeap(MinHeap h)
// {
//     int max = h.heap[h.tamanho - 1];
//     int i;
//     for (i = h.tamanho - 2; (2 * i + 1) >= h.tamanho; i--) // (2 * i + 1 >= h.tamanho ???) --> esq >= h.tamanho ??
//     {
//         if (h.heap[i] > max)
//             max = h.heap[i];
//     }
//     return max;
// }

// 13
typedef struct avlnode
{
    int value, balance;
    struct avlnode *esq, *dir;
} * AVL;

int rdir(AVL *tptr)
{
    int r = 0;
    AVL b;
    if (*tptr != NULL)
    {
        b = (*tptr)->esq;
        (*tptr)->esq = b->dir;
        b->dir = *tptr;
    }
    else
        r = -1;
    return r;
}

// 19
typedef struct minHeap
{
    int size;
    int used;
    int *values;
} * MinHeap;

// MinHeap bubbledown(MinHeap h);

int *ordenador(MinHeap h)
{
    int *r = malloc(sizeof(int) * (h->used));
    int i = 0;
    while (h->used > 0)
    {
        r[i++] = h->values[0];
        h->values[0] = h->values[--(h->used)];
        bubbledown(h);
    }
    return r;
}

// 20
typedef struct entryC
{
    char key[10];
    void *info;
    struct entryC *next;
} EntryChain;

typedef struct hashT
{
    int hashsize;
    EntryChain *table;
} * HashTableChain;

int hash(int size, char key[]);

// numero medio de elementos por bucket --> n elementos da HashTable a dividir pelo numero total de posiçoes do array disponiveis
float loadFactorC(HashTableChain h)
{
    EntryChain *b;
    int i, total = 0;
    for (i = 0; i < h->hashsize; i++)
    {
        *b = h->table[i];
        for (; b != NULL; total++, b = b->next)
            ;
    }
    return (((float)total) / ((float)h->hashsize));
}

float loadFactorCv2(HashTableChain h)
{
    EntryChain *b;
    int i, total = 0;
    for (i = 0; i < h->hashsize; i++)
    {
        *b = h->table[i];
        total++;
        b = b->next;
    }
    return (((float)total) / ((float)h->hashsize));
}

// 24

#define STATUS_FREE 0
#define STATUS_USED 1
#define STATUS_DELETED 2

typedef struct entryO
{
    int status;
    char *key;
    void *info;
} EntryOAdd;

typedef struct hashT
{
    int size;
    int used;
    EntryOAdd *table;
} * HashTableOAddr;

int hashO(HashTableOAddr h, int size);

void doubleTable(HashTableOAddr h)
{
    int i, p, l = h->size * 2;
    EntryOAdd *new = malloc(sizeof(EntryOAdd) * l);

    for (i = 0; i < l; ++i)
    {
        new[i].status = STATUS_FREE;
    }

    for (i = 0; i < h->size; i++)
    {
        p = hashO(h[i].table, l);
        while (new[i].status == STATUS_USED)
        {
            p = (p + 1) % l;
        }
        new[i].info = (h[i].table)->info;
        new[i].key = (h[i].table)->key;
        new[i].status = (h[i].table)->status;
    }
    h->size *= 2;
    free(h->table);
    h->table = new;
}

// 25

typedef long unsigned int LUI;

typedef struct multiset
{
    LUI N;
    LUI *arr;
} * MultiSet;

// construtor
MultiSet multiset_make(LUI N)
{
    MultiSet ms = malloc(sizeof(struct multiset));
    ms->N = N;
    ms->arr = calloc(N, sizeof(LUI));
    return ms;
}

void multiset_destroy(MultiSet ms)
{
    free(ms->arr);
    free(ms);
}

int multiset_exists(MultiSet ms, int x)
{
    int r = 0;
    if (ms->arr[x] != 0)
        r = 1;
    return r;
}

int multiset_existsv2(MultiSet ms, int x)
{
    return ms->arr[x] > 0;
}

void multiset_insert(MultiSet ms, int x)
{
    ms->arr[x]++;
}

void multiset_show_order(MultiSet ms)
{
    int i;
    for (i = 0; i < ms->N; i++)
    {
        if (ms->arr[i] > 0)
            printf("%d", ms->arr[i]);
    }
}

// 26
typedef struct minheap
{
    int size;
    int used;
    int values[];
} * MinHeap;

//  pai = (i - 1) / 2;
//  esq = 2 * i + 1;
//  dir = 2 * i + 2;

// [4,6,21,45,10,25,22,60,100,20,13]

int minHeapOK(MinHeap h)
{
    int r = 1;
    int i;
    int pai = (i - 1) / 2;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;
    if (h->size == 0)
        r = 0;
    else
    {
        if (h->values[pai] > h->values[esq] || h->values[pai] > h->values[dir])
            r = 0;
        else
        {
            if (h->values[pai] < h->values[esq])
            {
                i = esq;
                minHeapOK(h);
            }
            if (h->values[pai] < h->values[dir])
            {
                i = dir;
                minHeapOK(h);
            }
        }
    }
    return r;
}

// 27
typedef struct entry
{
    char key[10];
    void *info;
    struct entry *next;
} * Entry;

typedef struct hashT
{
    int hashsize;
    Entry *table;
} * HashTable;

int hashT(int hashsize, int key[]);

HashTable newTable(int hashsize)
{
    int i;
    HashTable h = malloc(sizeof(struct hashT));
    h->hashsize = hashsize;
    h->table = malloc(sizeof(Entry) * hashsize);
    for (i = 0; i < h->hashsize; i++)
    {
        h->table[i] = NULL;
    }
    return h;
}

// 30
typedef struct nodo
{
    int valor;
    int altura;
    struct nodo *esq, *dir;
} Nodo, *AVL;

int max(int a, int b)
{
    int r;
    if (a >= b)
        r = a;
    else
        r = b;
}

// int altura(AVL a)
// {
//     int r = 0;
//     if (a != NULL)
//     {
//         r = a->altura;
//     }
//     return r;
// }

// AVL rotateLeft(AVL a)
// {
//     AVL b;
//     b = a->dir;
//     a->dir = b->esq;
//     a->altura = 1 + max(altura(a->esq), altura(a->dir));
//     b->esq = a;
//     b->altura = 1 + max(a->altura, altura(b->dir));
//     return b;
// }

// 29

#define Bal 0
#define Esq -1
#define Dir 1

typedef struct avlNode *AVL;

struct avlNode
{
    int bal;
    int valor;
    struct avlNode *esq, *dir;
};

int altura(AVL a)
{
    int count = 0;
    while (a != NULL)
    {
        count++;
        // if (a->bal == Dir)
        a = a->dir;
        // else
        a = a->esq;
    }
    return count;
}

// // 30

// typedef struct nodo
// {
//     int valor;
//     int altura;
//     struct nodo *esq, *dir;
// } Node, *AVL;

// AVL rotateLeft(AVL a)
// {
//     AVL b = a;
//     AVL tmp = b->dir;
//     b->dir = b->esq;
//     b->esq = tmp;
//     return b;
// }

// 31

#define Livre 0
#define Ocupado 1
#define Apagado 2

typedef struct key *Key;

struct celula
{
    Key k;
    void *info;
    int estado;
};

typedef struct shash
{
    int tamanho, ocupados, apagados;
    struct celula *Tabela;
} * THash;


int hashTHash(Key, int a);


void remApagados(THash h)
{
    int i, p;
    struct celula *new = malloc(sizeof(struct celula) * h->tamanho);

    for (i = 0; i < h->tamanho; ++i)
    {
        new[i].estado = Livre;
    }

    for (i = 0; i < h->tamanho; ++i)
    {
        if ((h->Tabela[i]).estado == Ocupado)
        {
            p = hashTHash(h->Tabela[i].k, h->tamanho);

            while (new[i].estado != Livre)
            {
                p = (p + 1) % h->tamanho;
            }
            new[i].estado = Ocupado;
            new[i].info = h->Tabela[i].info;
            new[i].k = h->Tabela[i].k;
        }
    }

    h->apagados = 0;
    free(h->Tabela);
    h->Tabela = new;
}