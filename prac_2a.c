
#include <stdio.h>
#include <stdlib.h>

struct Activity {
  int start, finish, name, profit;
};

int comp(const void *a, const void *b) {
  const struct Activity *a1 = (const struct Activity *)a;
  const struct Activity *a2 = (const struct Activity *)b;
  return (a1->finish - a2->finish);
}
int activitySelection(int n, struct Activity arr[n], int selected[n]) {
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      if (arr[i].start >= arr[k].finish) {
        selected[k] = i;
      }
    }
  }
}
int main(void) {
  int n = 11;
  struct Activity arr[] = {{1, 4, 1, 10},   {3, 5, 2, 15},   {0, 6, 3, 14},
                           {5, 7, 4, 12},   {3, 9, 5, 20},   {5, 9, 6, 30},
                           {6, 10, 7, 32},  {8, 11, 8, 28},  {8, 12, 9, 30},
                           {2, 14, 10, 40}, {11, 45, 11, 50}};
  int selected[n];
  int totalProfit = 0;
  qsort(arr, n, sizeof(arr[0]), comp);
  activitySelection(n, arr, selected);
  for (int i = 0; i < n; i++) {
  }

  return 0;
}
