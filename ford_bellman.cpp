#include <vector>
#include <iostream>

using namespace std;

struct edge {
	edge(int aa, int bb, int cc) {
		a = aa;
		b = bb;
		c = cc;
	}
	int a, b, c;
};

int n, m, v;
vector<edge> e;
const int INF = 30000;

void solve() {
	vector<int> d(n, INF);
	d[v] = 0;
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < m; ++j)
			if (d[e[j].a] < INF)
				d[e[j].b] = min(d[e[j].b], d[e[j].a] + e[j].c);

	for (auto& x : d) {
		cout << x << " ";
	}
}

int main() {
	v = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		e.push_back(edge(a, b, c));
	}
	solve();
	return 0;
}