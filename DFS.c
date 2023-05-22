#include <stdio.h>
#include <stdbool.h>
#define MAX_NODES 4
int graph[MAX_NODES][MAX_NODES], n;
bool visited[MAX_NODES];
void DFS(int node) {
    visited[node] = true;
    printf("%d ", node + 1); 
    for (int i = 0; i < MAX_NODES; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}
int main() {
    int source = 0;
    int goal = 3;

    printf("Enter number of nodes: ");
      scanf("%d", &n);
 
      printf("Enter adjacency matrix:\n");
      for(int i=0; i<n; i++) {
          for(int j=0; j<n; j++) {
            printf("ar[%d][%d]= ",i+1,j+1);
            scanf("%d", &graph[i][j]);
            }
      }
       printf("your Entered adjacency matrix:\n");
       for(int i=0; i<n; i++) {
          for(int j=0; j<n; j++) {
            printf("%d\t",graph[i][j]);
          }
          printf("\n");
   }
    printf("\nDFS path from %d to %d: ", source + 1, goal + 1);
    DFS(source);
    printf("\n");
   
    if (visited[goal]) {
        printf("Goal node %d is reachable from the source node 1.\n", goal + 1);
    } else {
        printf("Goal node %d is not reachable from the source node 1.\n", goal + 1);
    }
    return 0;
}
