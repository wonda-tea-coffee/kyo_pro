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

string reverse(string s) {
  string ret = "";
  for (int i = s.size() - 1; i >= 0; i--)
    ret += s[i];
  return ret;
}

void show(string s) {
  int i = 0, lim = s.size() - 1;
  for (int i = 0; i < s.size(); i++) {
    cout << s[i];
    if ((i + 1) % 80 == 0) cout << endl;
  }
  if (lim % 80 != 0) cout << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N; cin >> N;
  string s = "";
  REP(i, N) {
    string tmp; cin >> tmp;
    s += tmp;
  }

  string t = "";
  int head = 0, tail = N - 1;
  REP(i, N) {
    char hs = s[head];
    char ts = s[tail];
    if (hs < ts) {
      t += hs;
      head++;
    } else if (hs > ts) {
      t += ts;
      tail--;
    } else {
      string sub = s.substr(head, tail - head + 1);
      // cout << "sub = " << sub << endl;
      if (reverse(sub) < sub) {
        t += ts;
        tail--;
      } else {
        t += hs;
        head++;
      }
    }
  }

  show(t);
}