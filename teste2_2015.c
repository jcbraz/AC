#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1

typedef struct data
{
    int dados;
} Data;
typedef struct node
{
    int balance; // -1 left higher, 0 balanced, 1 right higher
    char key[11];
    Data info;
    struct node *left, *right;
} Node;
typedef Node *Dictionary;

// a --> caderno

// b

// int allCopies(Dictionary dic, char key[11])
// {
//     int ret = 0, r = 0, l = 0, inc = 0;
//     if (dic != NULL)
//     {
//         if (strcmp(dic->key, key) == 0)
//         {
//             dic = dic->left;
//             if (strcmp((dic->left)->key, key) == 0)
//             {
//                 inc++;
//                 if (dic->left != NULL)
//                     dic = dic->left;
//             }
//             if (strcmp((dic->right)->key, key) == 0)
//             {
//                 inc++;
//                 if (dic->right != NULL)
//                     dic = dic->right;
//             }
//         }
//         r = allCopies(dic->right, key);
//         l = allCopies(dic->left, key);
//         ret = inc + l + r;
//     }
//     return ret;
// }

int allCopies(Dictionary dic, char key[11])
{
    int num = 0;
    if (dic != NULL)
    {
        if (strcmp(key, dic->key) == 0)
        {
            num += 1;
            if (dic->left != NULL && strcmp(key, dic->left->key) == 0)
            {
                num += allCopies(dic->left, key);
            }
            if (dic->right != NULL && strcmp(key, dic->right->key) == 0)
            {
                num += allCopies(dic->right, key);
            }
        }
        else if (strcmp(key, dic->key) < 0)
        {
            num += allCopies(dic->left, key);
        }
        else if (strcmp(key, dic->key) > 0)
        {
            num += allCopies(dic->right, key);
        }
    }
    return num;
}

// 3

#define NV 100
typedef struct aresta
{
    int dest;
    struct aresta *prox;
} * LAdj, *Grafo[NV];
typedef int GrafoM[NV][NV];

int quantosDepois(Grafo g, int v, int dist)
{
    int distance[NV];
    int i;
    int queue[NV];
    int front = 0;
    int end = 0;
    for (i = 0; i < NV; ++i)
        distance[i] = 0;

}

// int minEdgeBFS(int u, int v, int n)
// {
//     // visited[n] for keeping track of visited
//     // node in BFS
//     bool visited[n] = {0};

//     // Initialize distances as 0
//     int distance[n] = {0};
 
//     // queue to do BFS.
//     queue  Q;
//     distance[u] = 0;
    
//     Q.push(u);
//     visited[u] = true;
//     while (!Q.empty())
//     {
//         int x = Q.front();
//         Q.pop();
 
//         for (int i=0; i<edges[x].size(); i++)
//         {
//             if (visited[edges[x][i]])
//                 continue;

//             // update distance for i
//             distance[edges[x][i]] = distance[x] + 1;
//             Q.push(edges[x][i]);
//             visited[edges[x][i]] = 1;
//         }
//     }
//     return distance[v];
// }