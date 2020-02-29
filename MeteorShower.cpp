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
const int INF = 10100;
const int LIM = 305;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int m; cin >> m;
  int times[LIM][LIM]; REP(i, LIM)REP(j, LIM) times[i][j] = INF;
  int mins[LIM][LIM];  REP(i, LIM)REP(j, LIM) mins[i][j]  = INF;
  REP(i, m) {
    int x, y, t;
    cin >> x >> y >> t;

    times[y][x] = min(times[y][x], t);
    REP(j, 4) {
      int nx = x + dx[j];
      int ny = y + dy[j];

      if (0 <= nx && 0 <= ny) {
        times[ny][nx] = min(times[ny][nx], t);
      }
    }
  }

  // REP(i, 5) {
  //   REP(j, 5) {
  //     cout << times[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  queue<int> qx, qy, qt;
  qx.push(0);
  qy.push(0);
  qt.push(0);
  mins[0][0] = 0;

  if (times[0][0] == 0) {
    cout << -1 << endl;
    return 0;
  }

  while (!qx.empty()) {
    int x = qx.front(); qx.pop();
    int y = qy.front(); qy.pop();
    int t = qt.front(); qt.pop();

    if (times[y][x] == INF) {
      // cout << "y = " << y << ", x = " << x << endl;
      cout << t << endl;
      return 0;
    }

    REP(i, 4) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (0 <= nx && 0 <= ny && t + 1 < min(mins[ny][nx], times[ny][nx])) {
        qx.push(nx);
        qy.push(ny);
        qt.push(t + 1);

        mins[ny][nx] = t + 1;
      }
    }
  }

  cout << -1 << endl;
}