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

  int N; cin >> N;
  vector<ll> a(N), aOrigin(N);

  REP(i, N) {
    cin >> a[i];
    aOrigin[i] = a[i];
  }

  SORT(a)

  // REP(i, N) {
  //   cout << a[i] << ":" << aOrigin[i] << endl;
  // }

  vector<ll> sums(N);
  ll sum = 0;
  for (int i = N - 1; i >= 0; i--) {
    sum += a[i];
    sums[i] = sum;
  }

  // REP(i, N) {
  //   cout << sums[i] << endl;
  // }

  vector<ll> b(N);
  for (int i = 0; i < N; i++) {
    auto it = upper_bound(a.begin(), a.end(), aOrigin[i]);
    int index = it - a.begin();

    // cout << "index = " << index << ", a[i] = " << aOrigin[i] << endl;

    b[i] = index == N ? 0 : sums[index];
  }

  cout << b[0];
  for (int i = 1; i < N; i++) {
    cout << " " << b[i];
  }
  cout << endl;
}