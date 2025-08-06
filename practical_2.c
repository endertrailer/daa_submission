#include <math.h>
#include <stdio.h>

int isAlreadyVisited(int path[], int pathCount, int node) {
  for (int i = 0; i < pathCount; i++) {
    if (path[i] == node) {
      return 1;
    }
  }
  return 0;
}

int findMinIndex(float cost[4][4], int n, int unlockedNodes[], int pathCount,
                 float *minCost) {
  // float min = INFINITY;
  // int minIndex = -1;
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++)
  //     ;
  //
  //   if (cost[i] < min && isAlreadyVisited(unlockedNodes, pathCount, i) != 1)
  //   {
  //     // printf("%f\n", cost[i]);
  //     printf("%i\n %i \n", i, i);
  //     min = cost[i];
  //     minIndex = i;
  //   }
  // }
  // return minIndex;

  float min = INFINITY;

  int minIndex = -1;
  int from;
  for (int i = 0; i < pathCount; i++) {
    for (int j = 0; j < n; j++) {
      if (cost[unlockedNodes[i]][j] < min &&
          !isAlreadyVisited(unlockedNodes, pathCount, j)) {
        min = cost[unlockedNodes[i]][j];
        minIndex = j;
        from = i;
        // printf("%f\n", min);
      }
    }
  }

  printf("Edge selected: %d -> %d, Cost: %.2f\n", from, minIndex, min);
  *minCost += min;
  return minIndex;
}
int main() {
  int n = 4;
  int visitedNodes[4];
  int pathCount = 0;
  float minCost = 0;
  pathCount = 1;
  // int currentNode = 0;

  float cost[4][4] = {{INFINITY, 2, 1, 4},
                      {2, INFINITY, 6, 3},
                      {1, 6, INFINITY, 5},
                      {4, 3, 5, INFINITY}};

  // visitedNodes[pathCount++] = currentNode;
  visitedNodes[0] = 0;
  while (pathCount < n) {
    int nextNode = findMinIndex(cost, n, visitedNodes, pathCount, &minCost);
    visitedNodes[pathCount] = nextNode;
    pathCount++;
    if (nextNode == -1)
      break;
  }

  printf("Minimum Cost: %.2f\n", minCost);

  return 0;
}
