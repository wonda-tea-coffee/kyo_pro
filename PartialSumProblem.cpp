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

int n, k;
vector<int> a(20);

bool solve(int i, int sum) {
  if (n == i) return sum == k;

  if (solve(i + 1, sum)) return true;
  if (solve(i + 1, sum + a[i])) return true;
  return false;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  REP(i, n) cin >> a[i];
  cin >> k;

  if (solve(0, 0)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}