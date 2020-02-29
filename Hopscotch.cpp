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
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a[5][5];
  REP(i, 5)REP(j, 5) cin >> a[i][j];
  set<pair<int,int>> knowns;
  set<int> ans;

  REP(i, 5)REP(j, 5) {
    queue<int> qx, qy, qc, qr;
    qy.push(i);
    qx.push(j);
    qc.push(0);
    qr.push(0);

    while (!qy.empty()) {
      int y = qy.front(); qy.pop();
      int x = qx.front(); qx.pop();
      int c = qc.front(); qc.pop();
      int r = qr.front(); qr.pop();

      // cout << "y = " << y << ", x = " << x << ", " << c << ", r = " << r << endl;

      if (c == 6) {
        // if (ans.find(r) == ans.end()) {
        //   if (r == 11) cout << "i = " << i << ", j = " << j << endl;
        //   cout << r << endl;
        // }
        ans.insert(r);
        continue;
      }
      knowns.insert(make_pair(y * 100 + x * 10 + c, r));

      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        pair<int,int> pn = make_pair(ny * 100 + nx * 10 + (c + 1), r * 10 + a[ny][nx]);
        if (knowns.find(pn) == knowns.end()) {
          knowns.insert(pn);

          qx.push(nx);
          qy.push(ny);
          qc.push(c + 1);
          qr.push(r * 10 + a[ny][nx]);
        }
      }
    }
  }

  cout << ans.size() << endl;
}