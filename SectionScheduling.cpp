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
const int MAX_N = 100000;

int N, S[MAX_N], T[MAX_N];

P itv[MAX_N];

void solve() {
  for (int i = 0; i < N; i++) {
    itv[i].first  = T[i];
    itv[i].second = S[i];
  }
  sort(itv, itv + N);

  int ans = 0, t = 0;
  for (int i = 0; i < N; i++) {
    if (t < itv[i].second) {
      ans++;
      t = itv[i].first;
    }
  }

  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  REP(i, N) cin >> S[i];
  REP(i, N) cin >> T[i];

  solve();
}