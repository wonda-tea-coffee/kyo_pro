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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int d; cin >> d;
  REP(i, d) {
    int L, n; cin >> L >> n;
    vector<int> x(n); REP(j, n) cin >> x[j];

    int minVal = 0, maxVal = 0;
    for (int j = 0; j < n; j++) {
      minVal = max(minVal, min(x[j], L - x[j]));
      maxVal = max(maxVal, max(x[j], L - x[j]));
    }
    cout << minVal << " " << maxVal << endl;
  }
}