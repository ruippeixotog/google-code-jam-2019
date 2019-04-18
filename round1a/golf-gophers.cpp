#include <cstdio>
#include <map>
#include <vector>

#define MAXM 1000000

using namespace std;

vector<int> queries = {18, 17, 16, 15, 14, 13, 12};
map<vector<int>, int> table;

void preprocess() {
  for(int i = 1; i <= MAXM; i++) {
    vector<int> key(queries.size());
    for(int q : queries) {
      key.push_back(i % q);
    }
    table[key] = i;
  }
}

int askSum(int mod) {
  printf("%d", mod);
  for(int i = 1; i < 18; i++) {
    printf(" %d", mod);
  }
  printf("\n");
  fflush(stdout);
  int sum = 0;
  for(int i = 0; i < 18; i++) {
    int bi; scanf("%d", &bi);
    if(bi == -1) {
      exit(1);
    }
    sum = (sum + bi) % mod;
  }
  return sum;
}

void answer(int solution) {
  printf("%d\n", solution);
  fflush(stdout);
  int res; scanf("%d", &res);
  if(res == -1) {
    exit(1);
  }
}

int main() {
  preprocess();

  int t; scanf("%d %*d %*d", &t);
  for(int tc = 1; tc <= t; tc++) {
    vector<int> key(queries.size());
    for(int q : queries) {
      key.push_back(askSum(q));
    }
    answer(table[key]);
  }
  return 0;
}
