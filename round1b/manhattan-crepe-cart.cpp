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

#define MAXP 100000

using namespace std;

typedef long long ll;
typedef long double ld;

int x[MAXP], y[MAXP];
char d[MAXP];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int p, q; scanf("%d %d\n", &p, &q);
    for(int i = 0; i < p; i++)
      scanf("%d %d %c\n", &x[i], &y[i], &d[i]);

    map<int, int> eventsX, eventsY;
    for(int i = 0; i < p; i++) {
      switch(d[i]) {
        case 'N':
          eventsY[y[i] + 1]++;
          eventsY[q + 1]--;
          break;
        case 'S':
          eventsY[0]++;
          eventsY[y[i]]--;
          break;
        case 'E':
          eventsX[x[i] + 1]++;
          eventsX[q + 1]--;
          break;
        case 'W':
          eventsX[0]++;
          eventsX[x[i]]--;
          break;
      }
    }

    int currCntX = 0, bestX = 0, bestCntX = 0;
    for(auto e : eventsX) {
      currCntX += e.second;
      if(currCntX > bestCntX) {
        bestCntX = currCntX;
        bestX = e.first;
      }
    }
    int currCntY = 0, bestY = 0, bestCntY = 0;
    for(auto e : eventsY) {
      currCntY += e.second;
      if(currCntY > bestCntY) {
        bestCntY = currCntY;
        bestY = e.first;
      }
    }
    printf("Case #%d: %d %d\n", tc, bestX, bestY);
  }
  return 0;
}
