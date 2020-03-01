#include <algorithm>
#include <cstdio>
#include <map>
#include <iostream>

using namespace std;

typedef pair<int,int> pii;

int N, T;
pii s[25010];

int main() {
  cin >> N >> T;
  for (int i = 0; i < N; i++) {
    int a, b; cin >> a >> b;
    s[i] = pii(a - 1, b);
  }
  sort(s, s + N);

  int ans = 0, r = 0, si = 0;

  while (r < T) {
    int mr = 0;
    while (si < N && s[si].first <= r)
      mr = max(mr, s[si++].second);
    ans++;
    if (si == N) {
      if (mr < T) ans = -1;
      break;
    }
    if (mr == 0) {
      ans = -1;
      break;
    }
    r = mr;
  }

  cout << ans << endl;
}
