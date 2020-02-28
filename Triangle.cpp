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
#include <tuple>
#include <vector>

#define REP(i,n)  for (int i = 0; i < (n); ++i)
#define SORT(a)   sort((a).begin(), (a).end());
#define UNIQ(a)   SORT(a);(a).erase(unique((a).begin(), (a).end()), (a).end());
#define FIND(a,x) find((a).begin(), (a).end(), (x)) != (a).end()

using namespace std;
using ll = long long;
using P = pair<int,int>;
using namespace std;

const int MOD = 1000000007; // 10^9 + 7

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  vector<ll> a(n);
  REP(i, n) cin >> a[i];

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double d = sqrt(a[i] * a[i] + a[j] * a[j]);
      if (d != (ll)d) continue;

      ll k = (ll)d;
      if (FIND(a, k)) {
        ans = max(ans, a[i] + a[j] + k);
      }
    }
  }

  cout << ans << endl;
}