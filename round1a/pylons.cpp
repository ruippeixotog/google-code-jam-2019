#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>

#define MAXR 20
#define MAXC 20

using namespace std;

int r, c;

bool grid[MAXR + 1][MAXC + 1];
int neighbors[MAXR + 1][MAXC + 1];
vector<pair<int, int>> sol;

bool validMove(int i0, int j0, int i1, int j1) {
  return i0 != i1 && j0 != j1 && i0 + j0 != i1 + j1 && i0 - j0 != i1 - j1;
}

void initialize() {
  sol.clear();
  memset(grid, false, sizeof(grid));
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      for(int i1 = 0; i1 < r; i1++) {
        for(int j1 = 0; j1 < c; j1++) {
          neighbors[i][j] += validMove(i, j, i1, j1);
        }
      }
    }
  }
}

bool navigate(int i, int j) {
  grid[i][j] = true;
  sol.emplace_back(i, j);
  if(sol.size() == r * c) {
    return true;
  }

  int nextI = -1, nextJ = -1; 
  for(int i1 = 0; i1 < r; i1++) {
    for(int j1 = 0; j1 < c; j1++) {
      if(grid[i1][j1] || !validMove(i, j, i1, j1)) continue;

      neighbors[i1][j1]--;
      if(nextI == -1 || neighbors[i1][j1] < neighbors[nextI][nextJ]) {
        nextI = i1; nextJ = j1;
      }
    }
  }
  return nextI == -1 ? false : navigate(nextI, nextJ);
}

bool dfs() {
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      initialize();
      if(navigate(i, j)) return true;
    }
  }
  return false;
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    scanf("%d %d\n", &r, &c);

    bool res = dfs();
    if(!res) {
      printf("Case #%d: IMPOSSIBLE\n", tc);
    } else {
      printf("Case #%d: POSSIBLE\n", tc);
      for(auto& e : sol) {
        printf("%d %d\n", e.first + 1, e.second + 1);
      }
    }
  }
  return 0;
}
