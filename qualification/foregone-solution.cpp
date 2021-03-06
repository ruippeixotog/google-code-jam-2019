#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    string n; cin >> n;

    string b(n.size(), '0');
    int first = n.size() - 1;
    for(int i = 0; i < n.length(); i++) {
      if(n[i] == '4') {
        first = min(first, i);
        n[i] = b[i] = '2';
      }
    }
    printf("Case #%d: %s %s\n", tc, n.c_str(), b.substr(first).c_str());
  }
  return 0;
}
