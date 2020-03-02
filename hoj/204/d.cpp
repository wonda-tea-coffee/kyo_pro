#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstring>
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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));

  ll n; cin >> n;
  priority_queue<ll> x;
  priority_queue<ll, vector<ll>, greater<ll>> y;

  REP(i, n) {
    ll t; cin >> t;

    if (y.empty() || y.top() <= t) {
      y.push(t);
    } else {
      x.push(t);
    }

    while (abs((int(x.size()) - int(y.size()))) > 1) {
      if (x.size() < y.size()) {
        x.push(y.top());
        y.pop();
      } else {
        y.push(x.top());
        x.pop();
      }
    }

    if (x.size() == y.size()) {
      cout << (x.top() + y.top()) / 2 << "\n";
    } else if (x.size() > y.size()) {
      cout << x.top() << "\n";
    } else {
      cout << y.top() << "\n";
    }
  }
}