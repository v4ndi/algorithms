#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

vector<ll> z_function(string& s) {
	ll n = s.size();
	vector<ll> z(n);
	for (ll i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str = "";
	cin >> str;
	vector<ll> ans = z_function(str);
	ans[0] = str.size();

	for (auto& it :ans) {
		cout << it << " ";
	}
	return 0;
}