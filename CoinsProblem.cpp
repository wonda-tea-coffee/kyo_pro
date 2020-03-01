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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int coins[6] = {1, 5, 10, 50, 100, 500};
  int nums[6]; REP(i, 6) cin >> nums[i];
  int A; cin >> A;

  int ans = 0;

  for (int i = 5; i >= 0; i--) {
    int m = min(A / coins[i], nums[i]);
    ans += m;
    A -= m * coins[i];
  }

  cout << ans << endl;
}