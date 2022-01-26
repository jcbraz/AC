# Add in Procura Binária

```c
typedef struct btree
{
    int value;
    struct btree *left, *right;
} Node, *BTree;

BTree navigate(BTree a, int x, int *flag)
{
    // se flag == -1, arvore é vazia
    // se flag == 0, adicionar na esq.
    // se flag == 1, adicionar na dir.
    BTree aux = NULL;

    if (a == NULL) {
        *flag = -1;
    }
    else
    {
        if (x > a->value)
        {
            if (a->right == NULL) {
                *flag = 1;
                aux = a;
            }
            else {
                aux = navigate(a->right, x);
            }
        }
        else {
            if (a->left == NULL) {
                *flag = 0;
                aux = a;
            }
            else {
                aux = navigate(a->left, x);
            }
        }
            
    }

    return aux;
}

BTree iterative_navigate(BTree a, int x, int *flag) {
    if(a != NULL) {
        BTree p = a;
        while(p != NULL) {
            a = p;

            if(p->value < x) {
                p = p->right;

                if(p == NULL) {
                    *flag = 1;
                }
            }
            else {
                p = p->left;

                if (p == NULL) {
                    *flag = 0;
                }
            }
        }
    }

    if(a == NULL) {
        *flag = -1;
    }

    return a;
}

BTree add(BTree a, int x)
{
    int flag = -2;
    BTree t = navigate(a, x, &flag);

    switch(flag) {
        case -1:
            a = btree_make(x);
            break;
        case 0:
            t->esq = btree_make(x);
            break;
        case 1:
            t->dir = btree_make(x);
            break;
    }
    
    return a;
}
``` 