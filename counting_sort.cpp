#include <iostream>
#include <vector>
#include <string>
using namespace std;

using ll = long long;

int main() {
	ll n = 0;
	cin >> n;
if (n != 0){
	vector<ll> vec(n);

	ll max = 0;
	ll min = 100000000;

	for (auto& it : vec)
	{
		cin >> it;
		if (it > max) max = it;
		if (it < min) min = it;
	}

	vector<ll> c(max - min + 1);

	for (auto& it : vec) {
		c[it - min]++;
	}

	for (int i = 1; i < c.size(); i++) {
		c[i] = c[i] + c[i - 1];
	}

	vector<ll> b(vec.size());

	for (int i = vec.size() - 1; i >= 0; --i) {
		b[c[vec[i] - min] - 1] = vec[i];
		c[vec[i] - min]--;
	}

	for (auto& it : b) {
		cout << it << " ";
	}
}
	return 0;

}