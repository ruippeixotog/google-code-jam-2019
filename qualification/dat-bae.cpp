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

int n, b, f;

string ask(const string& bits) {
//  cerr << "ask: " << bits << endl;
  printf("%s\n", bits.c_str());
  fflush(stdout);
  string ans; cin >> ans;
//  cerr << "ans: " << ans << endl;
  if(ans == "-1") {
    exit(0);
  }
  return ans;
}

void sendSolution(const vector<int>& numbers) {
//  cerr << "answer" << endl;
  for(int a : numbers) {
    printf("%d ", a);
//    cerr << a << endl;
  }
  printf("\n");
  fflush(stdout);
  int ans; scanf("%d", &ans);
//  cerr << "res: " << ans << endl;
  if(ans == -1) {
    exit(0);
  }
}

string buildReq(int k) {
  string res;
  for(int i = 0; i < n; i++) {
    res += ((i >> k) & 1) ? '1' : '0';
  }
  return res;
}

void fillBroken(int partIdx, int resIdx, int numWorking, vector<string> responses, vector<int>& res) {
  set<int> found;
  for(int i = 0; i < numWorking; i++) {
    int value = 0;
    for(int j = 0; j < 4; j++) {
      value = (value << 1) | (responses[j + 1][resIdx + i] == '1');
    }
//    cerr << "found " << value << endl;
    found.insert(value);
  }

  int partSize = min(n, (partIdx + 1) * 16) - (partIdx * 16);
//  cerr << "partSize " << partSize << endl;
  for(int i = 0; i < partSize; i++) {
    if(!found.count(i)) {
      res.push_back(partIdx * 16 + i);
    }
  }
}

int main() {
//  cerr << "start!" << endl;

  int t; scanf("%d", &t);
  for(int tc = 1; tc <= t; tc++) {
    scanf("%d %d %d", &n, &b, &f);

//    cerr << "received" << endl;

    vector<string> responses;
    for(int k = 4; k >= 0; k--) {
      responses.push_back(ask(buildReq(k)));
    }

    vector<int> res;
    int resIdx = 0, partIdx = 0;
    for(int i = 1; i <= n - b; i++) {
      if(i == n + b || responses[0][i] != responses[0][i - 1]) {
        fillBroken(partIdx, resIdx, i - resIdx, responses, res);
        resIdx = i;
        partIdx++;
      }
    }
    sendSolution(res);
  }
  return 0;
}
