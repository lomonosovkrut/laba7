#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
int** createG(int size) {
    int** G = NULL;
    G = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        G[i] = (int*)malloc(size * sizeof(int));
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            G[i][j] = rand() % 2;
            if (i == j) {
                G[i][j] = 0;
            }
            G[j][i] = G[i][j];
        }
    }
    return G;
}

void printG(int** G, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d", G[i][j]);
        }
        printf("\n");
    }
    return;
}

void dfs(int s, int** G, int size, int* vis) {
    vis[s] = 1;
    printf("%d", s);
    for (int i = 0; i < size; i++) {
        if (G[s][i] == 1 && vis[i] == 0) {
            dfs(i, G, size, vis);
        }
    }
}
int main()
{
    setlocale(LC_ALL, "Rus");
    int size = 5;
    int** G1 = createG(size);
    printf("Введите размер матрицы \n");
    scanf("%d", &size);
    printf("Матрица 1\n");
    printG(G1, size);

    int* vis = NULL;
    vis = (int*)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        vis[i] = 0;
    }
    printf("Список посещенных вершин: ");
    dfs(0, G1, size, vis);
    return 0;
}