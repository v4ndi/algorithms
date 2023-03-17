#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ans_w;
vector<int> ans_c;
vector<int> w, c;

void path(int i, int j, vector<vector<int>>& dp) {
	if (dp[i][j] == -1 || i <= 0 || j <= 0) {
		return;
	}
	if (dp[i - 1][j] == dp[i][j]) {
		path(i - 1, j, dp);
		return;
	}
	else {
		ans_w.push_back(w[i]);
		ans_c.push_back(c[i]);
		int cur_w = j;
		int new_j = cur_w - w[i];
		if (new_j >= 0 && dp[i][new_j] != -1) {
			path(i - 1, new_j, dp);
		}
	}

}

int main() {
	int n, m;
	cin >> n >> m;
	w.resize(n + 1), c.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
	dp[0][0] = 0;

	int ans = 0;
	int max_i = 0;
	int max_j = 0;

	for (int i = 1; i <= n; i++) {
		int wi = w[i], ci = c[i];
		for (int j = 0; j <= m; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - wi >= 0 && dp[i - 1][j - wi] != -1) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - wi] + ci);
				if (dp[i][j] > ans) {
					ans = dp[i][j];
					max_i = i;
					max_j = j;
				}
			}
		}
	}
	
	cout << ans << '\n';
	cout << max_j << '\n';

	path(max_i, max_j, dp);

	cout << ans_w.size() << '\n';

	for(auto& it: ans_w) {
		cout << it << " ";
	}

	cout << '\n';

	for (auto& it : ans_c) {
		cout <<  it << " ";
	}

	return 0;
}