#include <cstdio>

#define MAXN 50000

char p[2 * MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    scanf("%s\n", p);

    for(int i = 0; i < 2 * n - 2; i++) {
      p[i] = p[i] == 'S' ? 'E' : 'S';
    }
    printf("Case #%d: %s\n", tc, p);
  }
  return 0;
}
