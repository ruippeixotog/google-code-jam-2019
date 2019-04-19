#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>

#define MAXN 1000

using namespace std;

string w[MAXN];

struct Trie {
  map<char, Trie> children;
  int count;

  Trie(): count(0) {}

  void add(const string& str, int idx = 0) {
    count++;
    if(idx < str.length()) {
      children[str[idx]].add(str, idx + 1);
    }
  }

  int findRhymes(bool initial = true) {
    int res = 0;
    for(auto& entry : children) {
      res += entry.second.findRhymes(false);
    }
    return !initial && count - res >= 2 ? res + 2 : res;
  }
};

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    for(int i = 0; i < n; i++)
      cin >> w[i];

    Trie trie;
    for(int i = 0; i < n; i++) {
      reverse(w[i].begin(), w[i].end());
      trie.add(w[i]);
    }
    printf("Case #%d: %d\n", tc, trie.findRhymes());
  }
  return 0;
}
