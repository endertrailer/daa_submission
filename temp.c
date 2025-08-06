#include <math.h>
#include <stdio.h>

int isAlreadyVisited(int path[], int pathCount, int currentNode) {
  for (int i = 0; i < pathCount; i++) {
    if (path[i] == currentNode) {
      return 1;
    }
  }
  return 0;
}

int findMinIndex(float cost[4][4], int n, int path[], int pathCount) {
  float min = INFINITY;
  int minIndex = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {

      if (cost[i][j] < min && !isAlreadyVisited(path, pathCount, j)) {
        min = cost[i][j];
        minIndex = j;
      }
    }
  }
  return minIndex;
}

int main() {
  int n = 4;
  int finalPath[4];
  int pathCount = 0;
  float minCost = 0;
  int currentNode = 0;

  float cost[4][4] = {{INFINITY, 2, 1, 4},
                      {2, INFINITY, 6, 3},
                      {1, 6, INFINITY, 5},
                      {4, 3, 5, INFINITY}};

  finalPath[pathCount++] = currentNode;

  while (pathCount < n) {
    int nextNode = findMinIndex(cost, n, finalPath, pathCount);
    if (nextNode == -1)
      break;

    minCost += cost[currentNode][nextNode];
    currentNode = nextNode;
    finalPath[pathCount++] = currentNode;
  }

  minCost += cost[currentNode][finalPath[0]];

  printf("Path: ");
  for (int i = 0; i < n; i++) {
    printf("%d -> ", finalPath[i]);
  }
  // printf("%d\n", finalPath[0]);

  printf("Minimum Cost: %.2f\n", minCost);

  return 0;
}
