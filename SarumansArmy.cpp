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
  int ans = 0;
  int covered = -1;
  int left = a[0];

  for (int i = 1; i < N; i++) {
    if (a[i] <= covered) continue;

    if (left == -1) left = a[i];

    if (a[i] - left > R) {
      covered = a[i - 1] + R;
      left = -1;
      ans++;
    } else if (a[i] - left == R) {
      covered = a[i] + R;
      left = -1;
      ans++;
    }
  }
  if (a[N - 1] > covered) ans++;

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