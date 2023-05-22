#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int adj[MAX][MAX], parent[MAX], rank[MAX], n;

void makeSet() {
    int i;
    for(i=0; i<n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int x) {
    if(parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSet(int x, int y) {
    int xRoot = find(x);
    int yRoot = find(y);

    if(xRoot == yRoot) {
        return;
    }

    if(rank[xRoot] < rank[yRoot]) {
        parent[xRoot] = yRoot;
    } else if(rank[xRoot] > rank[yRoot]) {
        parent[yRoot] = xRoot;
    } else {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }
}

void kruskal() {
    int i, j, k, u, v, min, cost = 0;
    int edgeCount = 0;
    int edge[2][MAX];
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(adj[i][j] != 0) {
                edge[0][edgeCount] = i;
                edge[1][edgeCount] = j;
                edgeCount++;
            }
        }
    }
    for(i=0; i<edgeCount-1; i++) {
        min = i;
        for(j=i+1; j<edgeCount; j++) {
            if(adj[edge[0][j]][edge[1][j]] < adj[edge[0][min]][edge[1][min]]) {
                min = j;
            }
        }
        if(min != i) {
            int temp = edge[0][i];
            edge[0][i] = edge[0][min];
            edge[0][min] = temp;

            temp = edge[1][i];
            edge[1][i] = edge[1][min];
            edge[1][min] = temp;
        }
    }
    int treeEdges = 0;
    i = 0;
    while(treeEdges < n-1 && i < edgeCount) {
        u = edge[0][i];
        v = edge[1][i];
        i++;
        
        if(find(u) != find(v)) {
            unionSet(u, v);
            printf("(%d, %d)\n", u+1, v+1);
            cost += adj[u][v];
            treeEdges++;
        }
    }
    printf("Minimum cost: %d\n", cost);
}

int main() {
    int i, j;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("ad[%d][%d]= ",i+1,j+1);
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Your Entered adjacency matrix is\n");
     for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%d\t",adj[i][j]);
        }
        printf("\n");
    }
    makeSet();
    printf("The minimum spanning tree has edges:\n");
    kruskal();
    return 0;
}
