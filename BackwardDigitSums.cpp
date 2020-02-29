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

const int MOD = 1000000007; // 10^9 + 7

int memo[10][10];

int comb(int n, int r) {
  if (n < r)  return 0;
  if (n == r) return 1;
  if (r == 0) return 1;
  if (r == 1) return n;
  if (memo[n][r] != -1) return memo[n][r];
  return memo[n][r] = (comb(n - 1, r - 1) + comb(n - 1, r));
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, T; cin >> N >> T;
  vector<int> v(N);
  for (int i = 1; i <= N; i++) v[i - 1] = i;

  REP(i, 10)REP(j, 10) memo[i][j] = -1;

  do {
    int sum = 0;
    for (int i = 0; i < N; i++)
      sum += comb(N - 1, i) * v[i];
    // cout << sum << endl;
    if (sum == T) {
      cout << v[0];
      for (int i = 1; i < N; i++)
        cout << " " << v[i];
      cout << endl;

      return 0;
    }
  } while (next_permutation(v.begin(), v.end()));
}