#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> used;
vector<int> path;
int start_c = 0, end_c = 0;

bool dfs(vector<vector<int>>& vec, int v = 0, int p = -1) {
	used[v] = 1;
	for (int i = 0; i < vec[v].size(); i++) {
		int to = vec[v][i];
		if (p == to) continue;
		if (used[to] == 0) {
			path[to] = v;
			if (dfs(vec, to, v)) return true;
		}
		else if(used[to] == 1) {
			end_c = v;
			start_c = to;
			return true;
		}
	}
	used[v] = 2;
	return false;
}

int main()
{
	int n = 0;
	cin >> n;
	vector<vector<int>> vec(n, vector<int>(n));
	used.resize(n);
	path.resize(n);
	start_c = -1;

	for (auto& it : vec) {
		for (auto& at: it) {
			cin >> at;
		}
	}
	vector<vector<int>> in(n);
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			if (vec[i][j] != 0) {
				in[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (dfs(in, i)) break;
	}

	if (start_c == -1)
		cout <<"NO";
	else {
		cout << "YES" << endl;
		vector<int> cycle;
		for (int v = end_c; v != start_c; v = path[v])
			cycle.push_back(v);
		cycle.push_back(start_c);
		//reverse(cycle.begin(), cycle.end());
		cout << cycle.size() << endl;
		for (size_t i = 0; i < cycle.size(); ++i)
			cout  << cycle[i] + 1 << " ";
	}

	return 0;
}