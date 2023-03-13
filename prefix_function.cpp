#include<iostream>
#include <vector>
#include <string> 
#include <algorithm>

using namespace std;
using ll = long long;

vector<ll> prefix(string& s){
	ll n = s.size();
	vector<ll> pr(n);
	for (int i = 1; i < n; i++) {
		ll j = pr[i - 1];
		while (j > 0 && s[i] != s[j]) {
			j = pr[j - 1];
		}
		if (s[i] == s[j]) j++;
		pr[i] = j;
	}
	return pr;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str = "";
	cin >> str;
	vector<ll> ans = prefix(str);

	for (auto& it :ans) {
		cout << it << " ";
	}
	return 0;
}