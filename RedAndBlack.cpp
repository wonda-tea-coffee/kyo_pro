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

int w, h;

int dfs(string tiles[], int y, int x) {
  tiles[y][x] = '#';

  int ret = 1;
  REP(i, 4) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (0 <= nx && nx < w && 0 <= ny && ny < h && tiles[ny][nx] == '.') {
      ret += dfs(tiles, ny, nx);
    }
  }
  return ret;
}

int solve(string tiles[]) {
  int sy = -1, sx = -1;
  REP(i, h)REP(j, w) {
    if (tiles[i][j] == '@') {
      sy = i;
      sx = j;
    }
  }

  assert(sy >= 0 && sx >= 0);

  return dfs(tiles, sy, sx);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  while (true) {
    cin >> w >> h;

    if (w == 0 && h == 0) break;

    string tiles[20];
    REP(i, h) cin >> tiles[i];

    cout << solve(tiles) << endl;
  }
}