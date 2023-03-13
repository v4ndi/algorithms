#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

ll binarysearch(vector<ll>& vec, ll item, ll l, ll r) {
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (item == vec[mid]) {
			return mid + 1;
		}
		if (item > vec[mid]) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return l;
}

int main() {
	ll n = 0;
	cin >> n;
	ll ans = 0;
	vector<ll> vec(n);

	for (auto& it : vec) {
		cin >> it;
	}

	for (int i = 1; i < vec.size(); ++i) {
		ll l = 0;
		ll r = i - 1;
		ll cur = vec[i];
		
		ll pos = binarysearch(vec, cur, l, r);

		while (r >= pos) {
			vec[r + 1] = vec[r];
			r--;
			ans++;
		}
		vec[r + 1] = cur;
	}

	for (auto& it : vec) {
		cout << it << " ";
	}
	cout << endl << ans;
	return 0;
}