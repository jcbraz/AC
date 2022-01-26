#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
//  Árvores binárias de procura
//

typedef struct btree
{
    int value;
    struct btree *left, *right;
} Node, *BTree;

// construtor
BTree btree_make(long unsigned int N)
{
    BTree a = malloc(sizeof(struct btree));
    a->value = N;
    a->left = NULL;
    a->right = NULL;
}

// deconstrutor
void btree_destroy(BTree a)
{
    if (a != NULL)
    {
        btree_destroy(a->left);
        btree_destroy(a->right);
        free(a);
    }
}

// 1
int size(BTree a)
{
    int count = 0;
    if (a != NULL)
    {
        count = 1 + size(a->right) + size(a->left);
    }
    return count;
}

// theta(N) = constante = count
int altura(BTree a)
{
    int count = 0;
    int aleft = altura(a->left);
    int aright = altura(a->right);
    if (aleft > aright)
        count = aleft + 1;
    else
    {
        count = aright + 1;
    }
    return count;
}

BTree navigate(BTree a, int x)
{
    BTree aux;
    if (a == NULL)
        return NULL;
    else
    {
        if (x > a->value)
        {
            if (a->right == NULL)
                aux = a;
            navigate(a->right, x);
        }
        else
            navigate(a->left, x);
    }
}

BTree add(BTree a, int x)
{
    navigate(a, x);
    if (a->left == NULL && a->right != NULL)
        a->left->value = x;
    else if (a->left != NULL && a->right == NULL)
        a->right->value = x;
    else if (a->left == NULL && a->right == NULL && a->value < x)
        a->right->value = x;
    else if (a->left == NULL && a->right == NULL && a->value > x)
        a->left->value = x;
    return a;
}

int search(BTree a, int x)
{
    int count = 0;
    if (a == NULL)
        return 0;
    else
    {
        if (a->value == x)
            count = 1;
        else
        {
            if (a->value < x)
                count = search(a->right, x);
            else
                count = search(a->left, x);
        }
    }
    return count;
}

int max(BTree a)
{
    int value = 0;
    if (a == NULL)
        return -1;
    else
    {
        while (a->right != NULL)
        {
            a = a->right;
        }
        value = a->value;
    }
    return value;
}

// 2

int balanceada(BTree a)
{
    int l, r;
    if (a)
    {
        l = altura(a->left);
        r = altura(a->right);
        return ((abs(l - r) <= 1) &&
                balanceada(a->left) &&
                balanceada(a->right));
    }
    else
        return 1;
}

// Melhor caso = abs(l-r) > 1,ou seja, a árvore ter o minimo de nodes possivel de forma a não ser balanceada.
// Pior caso = a condição abs(l-r) <= 1 é sempre respeitada, ou seja, a recursividade da função é sempre executada.

int alturav2(BTree a)
{
    int count = 0;
    int aleft = altura(a->left);
    int aright = altura(a->right);
    if (aleft > aright)
        count = aleft + 1;
    else
    {
        count = aright + 1;
    }
    return count;
}

// Pior caso:
// Seja l o resultado da funçao altura(a->left) e r o resultado de r = altura (a->right),
// T(N) = 1 + T(N-1) = 2 + T(N-2) + ..- = i + T(N-i)
// N-i = 0 <=> N = i
// T(0) = 1 => T(N) = i+1 => 2*(N+1) = 2N+2 -> altura
//
// T(N) = 2N+2 * l * r

int balanceada(BTree a)
{
    int p;
    return (balanceadaAux(a, &p));
}
int balanceadaAux(BTree a, int *p)
{
    int lh = 0, rh = 0;
    int l = 0, r = 0;
    if (a == NULL)
    {
        *p = 0;
        return 1;
    }

    l = balanceadaAux(a->left, &lh);
    r = balanceadaAux(a->right, &rh);

    *p = (lh > rh ? lh : rh) + 1;

    if (abs(lh - rh) >= 2)
        return 0;

    else
        return l && r;
}

/* The function returns true if root is balanced else false
   The second parameter is to store the height of tree.
   Initially, we need to pass a pointer to a location with value
   as 0. We can also write a wrapper over this function */

/* lh --> Height of left subtree
  rh --> Height of right subtree */

/* l will be true if left subtree is balanced
and r will be true if right subtree is balanced */

/* Get the heights of left and right subtrees in lh and rh
And store the returned values in l and r */

/* Height of current node is max of heights of left and
 right subtrees plus 1*/

/* If difference between heights of left and right
 subtrees is more than 2 then this node is not balanced
 so return 0 */

/* If this node is balanced and left and right subtrees
are balanced then return true */

//
// Filas com prioridades e Heaps
//

typedef int Elem; // elementos da heap.

typedef struct
{
    int size;
    int used;
    Elem *values;
} Heap;

// 2
//
//                  4
//           10            13
//     20        21   22       25
//  45   60   100
//
//
//
//
//                    4
//           6                13
//     20        10      22       25
//  45   60   100  21

int minHeapOK(Heap h)
{
    int r = 1, i, pai = (i - 1) / 2;
    if (h.size == 0)
        r = 0;
    else
    {
        if (h.values[pai] < h.values[2 * i + 1] || h.values[pai] < h.values[2 * i + 2])
            r = 0;
        else
        {
            if (h.values[pai] > h.values[2 * i + 1])
            {
                i = 2 * i + 1;
                minHeapOK(h);
            }
            if (h.values[pai] > h.values[2 * i + 2])
            {
                i = 2 * i + 2;
                minHeapOK(h);
            }
        }
    }
    return r;
}

Heap *newHeap(int size)
{
    Heap *h = malloc(sizeof(struct(Heap)));
    (*h).size = size;
    (*h).used = 0;
    (*h).values = realloc(size, sizeof(Elem));
}

void swap(int arr[], int a, int b)
{
    int tmp;
    tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int insertHeap(Heap *h, Elem x)
{
    int r = 1, pai, i = h->used + 1;
    if (h->size == 0)
        r = 0;
    else
    {
        pai = (i - 1) / 2;
        h->values[i] = x;
        while (i > 0 && i < h->size)
        {
            if (h->values[i] > h->values[pai])
            {
                swap(h->values, i, pai);
                i = pai;
            }
            else
                break;
        }
    }
    return r;
}

void bubbleUp(Elem h[], int i)
{
    int pai = (i - 1) / 2;
    while (i > 0 && h[i] < h[pai])
    {
        swap(h, i, pai);
        i = pai;
    }
}

int extractMin(Heap *h, Elem *x);
void bubbleDown(Elem h[], int N)
{
    int i, r, esq = 2 * i + 1, dir = 2 * i + 2;
    while (esq < N)
    {
        r = (dir < N && dir < esq) ? dir : esq;
        if (h[i] > h[r])
            break;
        swap(h, i, r);
        i = r;
    }
}

//
// Tabelas de Hash
//

// #define HASHSIZE 31 // numero primo
// #define EMPTY ""
// #define DELETED "-"
// typedef char KeyType[9];
// typedef void *Info;

// typedef struct entry
// {
//     KeyType key;
//     Info info;
// } Entry, HashTable[HASHSIZE];
// // OPEN ADRESSING
// // 3
// // função de hash
// int Hash(KeyType k)
// {
//     unsigned long i, chave = 0;
//     for (i = 0; i < 9; i++)
//     {
//         chave += k[i]; // soma ASCII
//     }
//     return chave%HASHSIZE;
// }

// void InsertTable_LP(HashTable h, KeyType k, Info f)
// {
//     int p = Hash(k);
//     int count;
//     for (count = HASHSIZE; count > 0 && h[p].info != EMPTY && h[p].key != k; count--)
//     {
//         p = (p + 1) % HASHSIZE;
//     }
//     if (count != 0)
//     {
//         h[p].info = f;
//     }
// }

// void DeleteTable_LP(HashTable h, KeyType k)
// {
//     int p = Hash(k);
//     int count;
//     Info tmp;
//     for (count = HASHSIZE; count > 0 && h[p].key != k; count--)
//     {
//         p = (p + 1) % HASHSIZE;
//     }
//     if (count != 0)
//     {
//         tmp = h[p].info;
//         h[p].info = NULL;
//         free(tmp);
//         //   free(h[p].info);
//     }
// }

// int RetrieveTable_LP(HashTable h, KeyType k)
// {
//     int p = Hash(k);
//     int count;
//     for (count = HASHSIZE; count > 0 && h[p].key != k; count--)
//     {
//         p = (p + 1) % HASHSIZE;
//     }
//     if (count == 0)
//         p = -1;

//     return p;
// }

// // quadratic probing

// int Hash_QP(KeyType k, int i);

// void InsertTable_QP(HashTable h, KeyType k, Info f)
// {
//     int p = Hash(k);
//     int count, d = 1;
//     for (count = HASHSIZE; count > 0 && h[p].info != EMPTY && h[p].key != k; count--)
//     {
//         p = (p + d) % HASHSIZE;
//         d++;
//     }
//     if (count != 0)
//     {
//         h[p].info = f;
//     }
// }
// void DeleteTable_QP(HashTable h, KeyType k)
// {
//     int p = Hash(h->key);
//     int count, d = 1;
//     Info tmp;
//     for (count = HASHSIZE; count > 0 && h[p].key != k; count--)
//     {
//         p = (p + d) % HASHSIZE;
//         d++;
//     }
//     if (count != 0)
//     {
//         tmp = h[p].info;
//         h[p].info = NULL;
//         free(tmp);
//         //   free(h[p].info);
//     }
// }

// int RetrieveTable_QP(HashTable h, KeyType k)
// {
//     int p = Hash(h->key);
//     int count, d = 1;
//     for (count = HASHSIZE; count > 0 && h[p].key != k; count--)
//     {
//         p = (p + d) % HASHSIZE;
//         d++;
//     }
//     if (count == 0)
//         p = -1;

//     return p;
// }

// analise assimptotica das funções

// 4 - closed adressing

#define HASHSIZE 31
typedef char KeyType[9];
typedef void *Info;
// número primo
typedef struct entry
{
    KeyType key;
    Info info;
    struct entry *next;
} Entry, *HashTable[HASHSIZE];

int Hash(KeyType k)
{
    unsigned long chave, i;
    for (i = 0; i < 9; i++)
    {
        chave += k[i];
    }
    return (chave % HASHSIZE);
}

void InitializeTable(HashTable h)
{
    int i;
    for (i = 0; i < HASHSIZE; i++)
    {
        h[i] = NULL;
    }
}

void ClearTable(HashTable h)
{
    int i;
    Entry *j, *tmp;
    if (h != NULL)
    {
        for (i = 0; i < HASHSIZE; i++)
        {
            for (j = h[i]; j != NULL;)
            {
                tmp = j;
                j = j->next;
                free(tmp);
            }
        }
    }
}

int ExistTable(HashTable h, KeyType k)
{
    int resultado = 0;
    int psi = Hash(k);
    Entry *b = h[psi];

    while (b != NULL && !resultado)
    {
        if (strcmp(b->key, k) == 0)
        {
            resultado = 1;
        }
        b = b->next;
    }
    return resultado;
}

void InsertTable(HashTable h, KeyType k, Info i)
{
    int existe = ExistTable(h, k);
    unsigned long psi = Hash(k);
    Entry b = h[psi];

    if (existe == 0)
    {
        Entry *tmp = malloc(sizeof(struct entry));
        (tmp)->key = k;
        (tmp)->info = i;
    }
}
void DeleteTable(HashTable h, KeyType k)
{
    int existe = ExistTable(h, k);
    unsigned long psi = Hash(k);
    Entry b = h[psi];

    if (existe == 0)
    {
        while (b != NULL && strcmp(b.key, k) != 0)
        {
            b = b.next;
        }
        free(b);
        b = b.next;
    }
}

Entry *RetrieveTable(HashTable h, KeyType k);

// analise assimptotica
// Closed e Open adressing --> Melhor caso = theta(1) --> Pode ter degenerado numa lista e ter de percorrer todos os elementos
//                         --> Pior caso = theta(N)  --> Todos os slots a frente estao cheios e tenho de dar a volta ao array para colocar o elemento.

// chaining
// | 1 -> 1 -> 1
// | 2
// | 3 -> 3
// | 4 -> 4 -> 4 -> 4

//
// Árvores AVL
//

typedef struct avlTree
{
    int value;
    int bal;
    struct avlTree *left, *right;
} AVLNode, *AVLTree;

// 1
int alturaAVL(AVLTree a)
{
    int altura = 0;
    if (a != NULL)
    {
        int l = alturaAVL(a->left);
        int r = alturaAVL(a->right);
        altura = 1 + (l > r ? l : r);
    }
    return altura;
}

// 2
AVLTree rotateRight(AVLTree a)
{
    AVLTree b = a->left;
    a->left = b->right;
    b->right = a;
    return b;
}

AVLTree rotateLeft(AVLTree a)
{
    AVLTree b = a->right;
    a->right = b->left;
    b->left = a;
    return b;
}

// 3 -> caderno


