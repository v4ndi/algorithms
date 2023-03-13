#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int main() {
	ll n, k = 0;
	cin >> n >> k;
	vector<ll> first(n);
	vector<ll> second(k);
	
	for (auto& it : first) {
		cin >> it;
	}

	for (auto& it : second) {
		cin >> it;
		ll l = 0;
		ll r = n - 1;
		while (l <= r) {
			ll mid = (l + r) / 2;
			if (first[mid] == it) {
				ll beg = mid;
				ll end = mid;
				ll ansl = mid;
				ll ansr = mid;
				while (true) {
					
					if (beg >= 0 && first[beg] == first[mid]) {
						ansl = beg;
						beg--;
					}
					if (end < n && first[end] == first[mid]) {
						ansr = end;
						end++;
					}
					if (beg < 0 || first[beg] != first[mid]) {
						if (end >= n || first[end] != first[mid]) {
							break;
						}
					}
				}
				cout << ansl + 1 << " " << ansr + 1 << endl;
				break;
			}

			if (it > first[mid]) {
				l = mid + 1;
			}
			if (it < first[mid]) {
				r = mid - 1;
			}
			if (l > r) {
				cout << 0 << endl;
			}
		}
	}


	return 0;
}