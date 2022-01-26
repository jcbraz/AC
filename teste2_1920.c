#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NV 1000
typedef struct aresta
{
    int dest;
    int custo;
    struct aresta *prox;
} * LAdj, *GrafoL[NV];
typedef int GrafoM[NV][NV];

// 4
int pesoC(GrafoM g, int v[], int k)
{
    int i, j, counter = 0;

    for (i = 0; i < k - 1; ++i)
    {
        for (j = i + 1; j < k - 1; ++j)
        {
            if ((g[i][j]) == NULL)
                return -1;
            else
            {
                counter += g[i][j];
            }
        }
    }
    return counter;
}