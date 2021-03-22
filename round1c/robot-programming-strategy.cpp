#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>

#define MAXA 255

using namespace std;

string c[MAXA];

map<char, char> winner = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
bool done[MAXA];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int a; scanf("%d\n", &a);
    for(int i = 0; i < a; i++)
      cin >> c[i];

    memset(done, false, sizeof(done));
    
    string res;
    for(int i = 0; i <= MAXA; i++) {
      set<char> seen;
      for(int j = 0; j < a; j++) {
        if(!done[j]) seen.insert(c[j][i % c[j].size()]);
      }

      if(seen.size() == 1) {
        res.push_back(winner[*seen.begin()]);
        break;

      } else if(seen.size() == 2) {
        char next = winner[*seen.begin()] == *seen.rbegin() ?
          *seen.rbegin() : *seen.begin();
        res.push_back(next);

        for(int j = 0; j < a; j++) {
          done[j] = done[j] || (c[j][i % c[j].size()] != next);
        }

      } else {
        res = "IMPOSSIBLE";
        break;
      }
    }
    printf("Case #%d: %s\n", tc, res.c_str());
  }
  return 0;
}
