#include <stdio.h>
#define MAX_NODES 4
int graph[MAX_NODES][MAX_NODES], visited[MAX_NODES] = {0}, n;
void bfs(int sourceNode) {
  int queue[MAX_NODES];
  int front = 0;
  int rear = 0;
  visited[sourceNode - 1] = 1;
  queue[rear++] = sourceNode;
  while (front < rear) {
    int currentNode = queue[front++];
    printf("%d ", currentNode);
    for (int i = 0; i < MAX_NODES; i++) {
      if (graph[currentNode - 1][i] == 1 && visited[i] == 0) {
        visited[i] = 1;
        queue[rear++] = i + 1;
      }
    }
  }
}
int main() {
  int sourceNode = 1;
  int goalNode = 4;
  printf("Enter number of nodes: ");
  scanf("%d",&n);
  printf("Enter adjacency matrix: \n");
  for(int i=0; i<n; i++) {
    for(int j = 0; j<n; j++) {
        printf("ad[%d][%d]= ",i+1,j+1);
        scanf("%d",&graph[i][j]);
    }
  }
  printf("Your enterd adjacency matrix is: \n");
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        printf("%d\t",graph[i][j]);
    }
    printf("\n");
  }
  printf("BFS traversal from node %d to node %d: ", sourceNode, goalNode);
  bfs(sourceNode);
  printf("\n");

  return 0;
}