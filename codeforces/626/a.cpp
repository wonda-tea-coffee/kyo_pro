#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstring>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define fix(n) cout<<fixed<<setprecision(n);
#define rep(i,n)   for (int i = 0; i < (n); ++i)
#define sort(a)    sort((a).begin(), (a).end());
#define uniq(a)    SORT(a);(a).erase(unique((a).begin(), (a).end()), (a).end());
#define reverse(a) reverse((a).begin(), (a).end());
#define out(d) cout << (d);
#define outl(d) std::cout<<(d)<<"\n";
#define Yes() printf("Yes\n");
#define No() printf("No\n");
#define YES() printf("YES\n");
#define NO() printf("NO\n");
#define ceil(x, y) ((x + y - 1) / (y))

using namespace std;
using ll = long long;
using P = pair<ll,ll>;

const ll MOD = 1000000007; // 10^9 + 7

static const int MAX_N = 105;
int a[MAX_N], n;

void solve() {
  if (n == 1 && a[0] % 2 == 1) {
    outl(-1)
    return;
  }

  vector<int> odds;
  for (int i = 0; i < n; i++) {
    // cout << "a[" << i << "] = " << a[i] << endl;
    if (a[i] % 2 == 0) {
      outl(1)
      outl(i + 1)
      return;
    } else {
      odds.push_back(i + 1);
      if (odds.size() == 2) break;
    }
  }

  outl(2)
  cout << odds[0] << " " << odds[1] << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12)

  ll t; cin >> t;
  rep(i, t) {
    cin >> n;
    rep(j, n) cin >> a[j];

    solve();
  }
}
