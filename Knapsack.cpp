#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define REP(i,n)   for (int i = 0; i < (n); ++i)
#define SORT(a)    sort((a).begin(), (a).end());
#define UNIQ(a)    SORT(a);(a).erase(unique((a).begin(), (a).end()), (a).end());
#define FIND(a,x)  find((a).begin(), (a).end(), (x)) != (a).end()
#define REVERSE(a) reverse((a).begin(), (a).end());

using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MOD = 1000000007; // 10^9 + 7
const int MAX_N = 100;
const int MAX_W = 10000;
int N, W, w[MAX_N], v[MAX_N];
int dp[MAX_N][MAX_W];

int solve(int i, int j) {
  if (dp[i][j] > -1) return dp[i][j];

  int res;
  if (i == N) {
    res = 0;
  } else if (j < w[i]) {
    res = solve(i + 1, j);
  } else {
    res = max(solve(i + 1, j), solve(i + 1, j - w[i]) + v[i]);
  }

  return dp[i][j] = res;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  REP(i, N) cin >> w[i] >> v[i];
  cin >> W;
  memset(dp, -1, sizeof(dp));

  cout << solve(0, W) << endl;
}