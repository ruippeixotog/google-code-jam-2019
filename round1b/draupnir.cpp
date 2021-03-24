#include <cstdio>
#include <cstdlib>
#include <tuple>
#include <utility>

#define POW2(arg) (1LL << (arg))
#define SAFEDAY 56

using namespace std;

typedef long long ll;

int sol[6];

ll ask(int day) {
  printf("%d\n", day);
  fflush(stdout);
  ll ans; scanf("%lld", &ans);
  if(ans == -1) exit(0);
  return ans;
}

void answer() {
  printf("%d", sol[0]);
  for(int i = 1; i < 6; i++) {
    printf(" %d", sol[i]);
  }
  printf("\n");
  fflush(stdout);
  int ans; scanf("%d", &ans);
  if(ans == -1) exit(0);
}

ll findMultiplier(ll& value, int pow) {
  int times = 0;
  while(value >= POW2(pow)) {
    times++;
    value -= POW2(pow);
  }
  return times;
}

// Solve pair of equations {ax+by=e, cx+dy=f}
pair<ll, ll> solveSystem(ll a, ll b, ll c, ll d, ll e, ll f) {
  ll det = a * d - b * c;
  return {(e * d - b * f) / det, (a * f - e * c) / det};
}

int main() {
  int t; scanf("%d\n", &t);
  scanf("%*d");
  for(int tc = 1; tc <= t; tc++) {
    int a1 = SAFEDAY, a2 = a1 * 3;
    ll res1 = ask(a1), res2 = ask(a2);

    sol[0] = findMultiplier(res1, a1);
    sol[1] = findMultiplier(res1, a1 / 2);
    sol[2] = findMultiplier(res2, a2 / 3);
    sol[3] = findMultiplier(res2, a2 / 4);
    tie(sol[4], sol[5]) = solveSystem(
      POW2(a1 / 5), POW2(a1 / 6),
      POW2(a2 / 5), POW2(a2 / 6),
      res1 - sol[2] * POW2(a1 / 3) - sol[3] * POW2(a1 / 4), res2
    );
    answer();
  }
  return 0;
}
