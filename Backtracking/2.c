#include <stdio.h>

void gen(int, int, int, int *, int);

int main(void) {
  int n = 0, k;
  scanf("%d%d", &n, &k);
  int ans[n];
  gen(0, k, n, ans, k);
}

void gen(int i, int k, int n, int *ans, int c) {
  if (i == n) {
    for (int x = 0; x < n; x++)
      printf("%d", ans[x]);
    printf("\n");
    return;
  }
  for (int j = 0; j < 2; j++) {
    if (j == 0) {
      if (n - i == c)
        continue;
      if (n - i < c)
        return;
    } else if (j == 1) {
      if (c == 0)
        continue;
      else
        c--;
    }
    ans[i] = j;
    gen(i + 1, k, n, ans, c);
  }
}
