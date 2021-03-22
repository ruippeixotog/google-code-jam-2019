#include <cstdio>
#include <cstring>
#include <string>

#define NSETS 120

using namespace std;

char ask(int pos) {
  printf("%d\n", pos + 1);
  fflush(stdout);
  char ans[3]; scanf("%s", ans);
  if(ans[0] == 'N') exit(0);
  return ans[0];
}

void answer(string& res) {
  printf("%s\n", res.c_str());
  fflush(stdout);
  char ans[3]; scanf("%s", ans);
  if(ans[0] == 'N') exit(0);
}

int main() {
  int t; scanf("%d\n", &t);
  scanf("%*d");
  for(int tc = 1; tc <= t; tc++) {
    char figs[NSETS - 1][5];
    memset(figs, 0, sizeof(figs));

    string res;
    int needed = NSETS;
    for(int k = 0; k < 5; k++) {
      needed /= 5 - k;
      int hist[5] = {0, 0, 0, 0, 0};

      for(int i = 0; i < NSETS - 1; i++) {
        if(k == 0 || figs[i][k - 1] == res[k - 1]) {
          figs[i][k] = ask(i * 5 + k);
          hist[figs[i][k] - 'A']++;
        }
      }
      for(int k2 = 0; k2 < 5; k2++) {
        bool seen = find(res.begin(), res.end(), 'A' + k2) != res.end();
        if(!seen && hist[k2] != needed) {
          res.push_back('A' + k2);
        }
      }
    }
    answer(res);
  }
  return 0;
}
