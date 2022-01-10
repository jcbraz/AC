#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// Representações
//

// 1
#define NV 1000
typedef struct aresta
{
    int dest;
    int custo;
    struct aresta *prox;
} * LAdj, *GrafoL[NV];

typedef int GrafoM[NV][NV];

void fromMat(GrafoM in, GrafoL out)
{
    int i, j;
    LAdj tmp;

    for (i = 0; i < NV; ++i)
    {
        out[i] = NULL;
    }

    for (j = NV - 1; j >= 0; ++j)
    {
        if (in[i][j] != 0)
        {
            tmp = malloc(sizeof(struct aresta));
            tmp->dest = j;
            tmp->custo = in[i][j];
            tmp->prox = out[i];
            out[i] = tmp;
        }
    }
}

// 2

void swap(int arr[], int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void inverte(GrafoL in, GrafoL out)
{
    int i, a = 0, b = NV - 1;
    GrafoL aux = in;

    for (i = 0; a != b; ++i, ++a, --b)
    {
        swap(aux, a, b);
    }

    out = aux;
}

// 3
int deGree(GrafoL in)
{
    int i, m = 0;
    int arr[NV] = {0};
    LAdj l;

    for (i = 0; i < NV; ++i)
    {
        for (l = in[i]; l; l = l->prox)
        {
            arr[l->dest]++;
        }
    }

    for (i = 0; i < NV; ++i)
    {
        if (arr[i] > m)
            m = arr[i];
    }

    return m;
}

// 4

int colorOK(GrafoL g, int cor[])
{
    int i, r = 0;
    LAdj d;

    for (i = 0; i < NV; ++i)
    {
        for (d = g[i]; d; d = d->prox)
        {
            if (cor[i] != cor[d->dest])
                r = 0;
        }
    }
    return r;
}

// 5

int homomorfOK(GrafoL g, GrafoL h, int f[])
{
    int i, r = 0, dest;
    LAdj a, b;

    for (i = 0; i < NV; ++i)
    {
        for (a = g[i]; a; a = a->prox)
        {
            for (b = h[f[a]]; b; b = b->prox)
            {
                if (a->dest != f[b->dest]) // este passo ?
                    r = 0;
            }
        }
    }
    return r;
}

//
// Travessias
//

// 1

///// Enunciado /////

int DF(GrafoL g, int or, int v[], int p[], int l[])
{
    int i;
    for (i = 0; i < NV; i++)
    {
        v[i] = 0;
        p[i] = -1;
        l[i] = -1;
    }
    p[or] = -1;
    l[or] = 0;
    return DFRec(g, or, v, p, l);
}
int DFRec(GrafoL g, int or, int v[], int p[], int l[])
{
    int i;
    LAdj a;
    i = 1;
    v[or] = -1;
    for (a = g[or];
         a != NULL;
         a = a->prox)
        if (!v[a->dest])
        {
            p[a->dest] = or ;
            l[a->dest] = 1 + l[or];
            i += DFRec(g, a->dest, v, p, l);
        }
    v[or] = 1;
    return i;
}

int BF(GrafoL g, int or, int v[], int p[], int l[])
{
    int i, x;
    LAdj a;
    int q[NV], front, end;
    for (i = 0; i < NV; i++)
    {
        v[i] = 0;
        p[i] = -1;
        l[i] = -1;
    }
    front = end = 0;
    q[end++] = or ; // enqueue
    v[or] = 1;
    p[or] = -1;
    l[or] = 0;
    i = 1;
    while (front != end)
    {
        x = q[front++]; // dequeue
        for (a = g[x]; a != NULL; a = a->prox)
            if (!v[a->dest])
            {
                i++;
                v[a->dest] = 1;
                p[a->dest] = x;
                l[a->dest] = 1 + l[x];
                q[end++] = a->dest; // enqueue
            }
    }
    return i;
}

////// Enunciado ///////

// 1
int maisLonga(GrafoL g, int or, int p[])
{
    int i, r, max = or ;
    LAdj vis[NV], pai[NV], dist[NV];

    BF(g, or, vis, pai, dist);

    for (i = 0; i < NV; ++i)
    {
        if (dist[i] > dist[max])
            max = i;
    }

    r = dist[max];

    for (i = dist[max] - 1; i >= 0; --i)
    {
        p[i] = max;
        max = pai[max];
    }

    return r;
}

// 2

int componentes(GrafoL g, int c[])
{
    int i, comp = 0;
    for (i = 0; i < NV; ++i)
    {
        c[i] = -1;
    }

    for (i = 0; i < NV; ++i)
    {
        if (c[i] == -1)
        {
            DF_aux(g, i, c, comp); // g->grafo, i -> origem, c -> array, comp -> verificação
            comp++;
        }
    }
    return c;
}

void DF_aux(GrafoL g, int or, int c[], int comp)
{
    int i;
    c[or] = comp;
    LAdj l;

    for (i = 0; i < NV; i++)
    {
        for (l = c[or]; l; l = l->prox)
        {
            if (c[l->dest] == -1)
                DF_aux(g, l->dest, c, comp);
        }
    }
}

// 3

void deGreev2(GrafoL g, int arr[])
{
    int i, m = 0;
    LAdj l;

    for (i = 0; i < NV; i++)
    {
        arr[i] = 0;
    }

    for (i = 0; i < NV; ++i)
    {
        for (l = g[i]; l; l = l->prox)
        {
            arr[l->dest]++;
        }
    }
}

int ordTop(GrafoL g, int ord[])
{
    int deg[NV];
    int i, j, p = 0, r = 1;
    deGreev2(g, deg);

    for (i = 0; deg[i] != 0; ++i)
        ;
    if (i == NV)
        r = 0;

    for (i = 0; i < NV; ++i, ++p)
    {
        for (j = 0; j < NV; ++j)
        {
            if (deg[j] == p)
            {
                ord[i] = j;
            }
        }
    }
    return r;
}

// 4
int caminho(int L, int C, char *mapa[L], int ls, int cs, int lf, int cf);
