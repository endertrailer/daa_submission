
#include <stdio.h>
#include <stdlib.h>
struct Box {
  int weight;
  int profit;
};

int compProfit(const void *a, const void *b) {
  struct Box *b1 = (struct Box *)a;
  struct Box *b2 = (struct Box *)b;
  return (b2->profit - b1->profit);
}
int compWeight(const void *a, const void *b) {
  struct Box *b1 = (struct Box *)a;
  struct Box *b2 = (struct Box *)b;
  return (b2->weight - b1->weight);
}
int compProfitByWeight(const void *a, const void *b) {
  struct Box *b1 = (struct Box *)a;
  struct Box *b2 = (struct Box *)b;
  return (b2->profit / b2->weight - b1->profit / b1->weight);
}
// int comp(const void *a, const void *b) {
//   struct Box *b1 = (struct Box *)a;
//   struct Box *b2 = (struct Box *)b;
//   return (b2->profit - b1->profit);
// }
int main(int argc, char *argv[]) {

  int n = 50;
  int weight[50] = {7,  0,  30, 22, 80, 94, 11, 81, 70, 64, 59, 18, 0,
                    36, 3,  8,  15, 42, 9,  0,  42, 47, 52, 32, 26, 48,
                    55, 6,  29, 84, 2,  4,  18, 56, 7,  29, 93, 44, 71,
                    3,  86, 66, 31, 65, 0,  79, 20, 65, 52, 13};
  int profit[50] = {360, 83,  59,  130, 431, 67,  230, 52,  93,  125,
                    670, 892, 600, 38,  48,  147, 78,  256, 63,  17,
                    120, 164, 432, 35,  92,  110, 22,  42,  50,  323,
                    514, 28,  87,  73,  78,  15,  26,  78,  210, 36,
                    85,  189, 274, 43,  33,  10,  19,  389, 276, 312};
  struct Box arr[50];
  int capacity = 850;
  for (int i = 0; i < 50; i++) {
    arr[i].weight = weight[i];
    arr[i].profit = profit[i];
  }
  qsort(arr, n, sizeof(arr[0]), compProfit);

  for (int i = 0; i < 50; i++) {
    printf("%d ", arr[i].profit);
    printf("%d \n", arr[i].weight);
  }
  return 1;
}
