#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define MAXN 2000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int c[MAXN], d[MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, k; scanf("%d %d\n", &n, &k);
    for(int i = 0; i < n; i++)
      scanf("%d", &c[i]);
    for(int i = 0; i < n; i++)
      scanf("%d", &d[i]);

    int cnt = 0;
    for(int l = 0; l < n; l++) {
      for(int r = l; r < n; r++) {
        int bestC = 0, bestD = 0;
        for(int i = l; i <= r; i++) {
          bestC = max(bestC, c[i]);
          bestD = max(bestD, d[i]);
        }
        if(abs(bestC - bestD) <= k) {
          cnt++;
        }
      }
    }
    printf("Case #%d: %d\n", tc, cnt);
  }
  return 0;
}
