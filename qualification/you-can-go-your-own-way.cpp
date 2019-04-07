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

int x[MAXN], y[MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    string p; cin >> p;

    string p2;
    for(char ch : p) {
      p2.push_back(ch == 'S' ? 'E' : 'S');
    }
    printf("Case #%d: %s\n", tc, p2.c_str());
  }
  return 0;
}
