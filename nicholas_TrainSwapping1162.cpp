#include <stdio.h>
#include <stdlib.h>

int bubble_sort(int vetor[], int n) {
  int i, j;
  int aux, x = 0;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (vetor[j] > vetor[j + 1]) {
        aux = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = aux;
        x++;
      }
    }
  }
  return x;
}

int main() {
  int n = 0, l = 0, trc = 0;
  int  i = 0, j = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &l);
    int num[l];
    for (j = 0; j < l; j++) {
      scanf("%d", &num[j]);
    }
    trc = bubble_sort(num, l);
    printf("Optimal train swapping takes %d swaps.\n", trc);
  }
  return 0;
}


