#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

const int INF = 10e8;

int main() {
    int n;
	cin >> n;
	vector<vector<int>> vec(n, vector<int>(n));

	for (auto& it : vec) {
		for (auto& x : it) {
			cin >> x;
		}
	}

	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (vec[i][k] < INF && vec[k][j] < INF)
					vec[i][j] = min(vec[i][j], vec[i][k] + vec[k][j]);

	for (auto& it : vec) {
		for (auto& x : it) {
			cout << x << " ";
		}
		cout << '\n';
	}

    return 0;
}