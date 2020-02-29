#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <set>
#include <queue>

using namespace std;

int pow10[] = {1,10,100,1000,10000,100000};
int n, digits[10];

typedef pair<int, int> P;

struct State {
	int a, b;
	int used;
	int max_dist;
	int min_dist;
	int k;

	State(int a, int b, int used, int k): a(a), b(b), used(used), k(k) {
    // (a - b) * 10^k + 10^k - 1
    // = 10^k * (a - b + 1) - 1
		max_dist = (a - b) * pow10[k] + pow10[k] - 1;
    // (a - b) * 10^k + 1 - 10^k
    // = 10^k * (a - b - 1) + 1
		min_dist = (a - b) * pow10[k] + 1 - pow10[k];
	}
};

bool operator<(const State &a, const State &b) {
	return a.min_dist > b.min_dist;
}

int solve() {
	int ans = 9999999;
	priority_queue<State> que;
	set<P> ac;

	if (digits[n - 1] != 0) {
		// 個数が2の倍数
		for (int i = 0; i < n; i++) {
			if (digits[i] == 0) continue;
			for (int j = i + 1; j < n; j++) {
				que.push(State(digits[j], digits[i], (1 << i) | (1 << j), n / 2 - 1));
			}
		}
	} else {
		// 個数が2の倍数ではない
    // 例えば、
    // 1 2 3 4 5
    // のときは
    // (1, 0), (2, 0), (3, 0), (4, 0), (5, 0) がpushされる
		for (int i = 0; i < n - 1; i++) {
			if (digits[i] == 0) continue;
			que.push(State(digits[i], digits[n - 1], (1 << (n - 1) | (1 << i)), n / 2 - 1));
		}
	}

	while (!que.empty()) {
		State now = que.top(); que.pop();

		if (ans < now.min_dist) break;

		ans = min(ans, now.max_dist);

		if (now.used == (1 << n) - 1) continue; // もう使える数が無い

    // 使われていない数から適当に選ぶ
		for (int i = 0; i < n; i++) {
			if ((now.used >> i) & 1) continue;

			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				if ((now.used >> j) & 1) continue;

				// 二つの数を選ぶ
				int na = now.a * 10 + digits[i];
				int nb = now.b * 10 + digits[j];
				if (ac.find(P(na, nb)) == ac.end()) {
					ac.insert(P(na, nb));
					que.push(State(na, nb, now.used | (1 << i) | (1 << j), now.k - 1));
				}
			}
		}
	}
	return ans;
}

int dfs(int left = -1, int y = -1, int used = 0) {
	if (used == (1 << n) - 1 && left != -1 && y != -1) {
		return abs(left - y);
	}

	int ans = 99999999;
	for (int i = 0; i < n; i++) {
    // i番目が未使用か
		if (((used >> i) & 1) == 0) {
			if (left == -1)    ans = min(ans, dfs(            digits[i], y, used | (1 << i)));
      else if (left > 0) ans = min(ans, dfs(left * 10 + digits[i], y, used | (1 << i)));

			if (y == -1)    ans = min(ans, dfs(left,          digits[i], used | (1 << i)));
			else if (y > 0) ans = min(ans, dfs(left, y * 10 + digits[i], used | (1 << i)));
		}
	}
	return ans;
}

int main() {
	int tcase;
	string in;
	getline(cin, in);
	tcase = atoi(in.c_str());

	for (int T = 0; T < tcase; T++) {
		n = 0; getline(cin, in);
		stringstream ss(in);

		while (ss >> digits[n]) n++;
    // nが5未満ならbit全探索
		if (n < 5) {
			cout << dfs() << endl;
		} else {
      // nが偶数、つまり配列全体が半分に割れるように調整している
			if (n & 1) digits[n++] = 0;
			cout << solve() << endl;
		}
	}
	return 0;
}
