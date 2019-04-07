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

#define MAXN 10000
#define MAXL 100

using namespace std;

typedef long long ll;
typedef long double ld;

int a[MAXL];

int primeFactor(int n) {
  for(int i = 2; i <= MAXN; i++) {
    if(n % i == 0) {
      return i;
    }
  }
  return -1;
}

vector<int> tryDecode(int p0, int p1, int l) {
  vector<int> decoded = {p0, p1};
  for(int i = 1; i < l; i++) {
    if(a[i] % *decoded.rbegin() != 0) {
      return {};
    }
    decoded.push_back(a[i] / *decoded.rbegin());
  }
  return decoded;
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, l; scanf("%d %d\n", &n, &l);
    for(int i = 0; i < l; i++) {
      scanf("%d", &a[i]);
    }

    int p0 = primeFactor(a[0]), p1 = a[0] / p0;
    vector<int> decoded = tryDecode(p0, p1, l);
    if(decoded.empty()) {
      decoded = tryDecode(p1, p0, l);
    }

    vector<int> key = decoded;
    sort(key.begin(), key.end());
    unique(key.begin(), key.end());
    map<int, char> table;
    for(int i = 0; i < 26; i++) {
      table[key[i]] = 'A' + i;
    }

    string ct;
    for(int d : decoded) {
      ct.push_back(table[d]);
    }
    printf("Case #%d: %s\n", tc, ct.c_str());
  }
  return 0;
}
