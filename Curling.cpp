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
// using ll = long long;
// using P = pair<int,int>;

const int MOD = 1000000007; // 10^9 + 7

int m[20][20];
int h, w, gy, gx;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
const int MAX = 100000000;

void show() {
  REP(i, h) {
    REP(j, w) {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int dfs(int y, int x, int move) {
  if (y == gy && x == gx) {
    return move;
  }
  if (move >= 10) return MAX;

  int ret = MAX;
  // スライドさせる方向を決める
  REP(i, 4) {
    int nx = x;
    int ny = y;
    // ぶつかるまでスライドさせる
    while (0 <= nx && nx < w && 0 <= ny && ny < h && m[ny][nx] != 1) {
      nx += dx[i];
      ny += dy[i];
      if (ny == gy && nx == gx) return move + 1;
    }
    // 動けなかった
    if (abs(nx - x) + abs(ny - y) == 1) continue;
    // 飛び出した
    if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;

    // ブロックが消滅
    m[ny][nx] = 0;

    ret = min(ret, dfs(ny - dy[i], nx - dx[i], move + 1));

    m[ny][nx] = 1;
  }
  return ret;
}

int solve() {
  int sy = -1, sx = -1;

  REP(i, h)REP(j, w) {
    if (m[i][j] == 2) {
      sy = i;
      sx = j;
    } else if (m[i][j] == 3) {
      gy = i;
      gx = j;
    }
  }

  assert(sy >= 0 && sx >= 0 && gy >= 0 && gx >= 0);

  int ret = dfs(sy, sx, 0);
  return ret == MAX ? -1 : ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  while (true) {
    cin >> w >> h;

    if (w == 0 && h == 0) break;

    REP(i, h)REP(j, w) cin >> m[i][j];

    cout << solve() << endl;
  }
}