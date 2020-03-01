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
    // sはカバーされていない一番左の点
    int s = a[i++];
    // sから距離Rを超える点まで進む
    while (i < N && a[i] <= s + R) i++;

    // pは新しく印をつける点
    int p = a[i - 1];
    // pから距離Rを超える点まで進む
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