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

int R, N;

int solve(vector<int> a) {
  SORT(a)

  int i = 0, ans = 0;
  while (i < N) {
    int s = a[i++];
    while (i < N && a[i] <= s + R) i++;

    int p = a[i - 1];
    while (i < N && a[i] <= p + R) i++;

    ans++;
  }

  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  while (true) {
    cin >> R >> N;
    if (R == -1 && N == -1) break;
    vector<int> a(N);
    REP(i, N) cin >> a[i];
    cout << solve(a) << endl;
  }
}