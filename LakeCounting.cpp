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
// 上、右上、右、右下、下、左下、左、左上
const int dx[8] = {0,   1, 1, 1, 0, -1, -1, -1};
const int dy[8] = {-1, -1, 0, 1, 1,  1,  0, -1};

int N, M;
string m[100];
bool visited[100][100] = {{false}};

void dfs(int y, int x) {
  REP(i, 8) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
    if (visited[ny][nx]) continue;
    if (m[ny][nx] == '.') continue;

    visited[ny][nx] = true;
    dfs(ny, nx);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  REP(i, N) cin >> m[i];

  int ans = 0;
  REP(i, N)REP(j, M) {
    if (visited[i][j])  continue;
    if (m[i][j] == '.') continue;

    visited[i][j] = true;
    dfs(i, j);
    ans++;
  }

  cout << ans << endl;
}