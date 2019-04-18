#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int n, b, f;

string ask(const string& bits) {
  printf("%s\n", bits.c_str());
  fflush(stdout);
  string ans; cin >> ans;
  if(ans == "-1") {
    exit(0);
  }
  return ans;
}

void sendSolution(const vector<int>& numbers) {
  for(int a : numbers) {
    printf("%d ", a);
  }
  printf("\n");
  fflush(stdout);
  int ans; scanf("%d", &ans);
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
    found.insert(value);
  }

  int partSize = min(n, (partIdx + 1) * 16) - (partIdx * 16);
  for(int i = 0; i < partSize; i++) {
    if(!found.count(i)) {
      res.push_back(partIdx * 16 + i);
    }
  }
}

int main() {
  int t; scanf("%d", &t);
  for(int tc = 1; tc <= t; tc++) {
    scanf("%d %d %d", &n, &b, &f);

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
