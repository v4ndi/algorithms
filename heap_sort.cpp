#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

vector<ll> vec;

void heapify(vector<ll>& vec, ll N, ll root) {

	ll max_root = root;
	ll left_child = root * 2 + 1;
	ll right_child = root * 2 + 2;

	if (left_child < N && vec[max_root] < vec[left_child]) {
		max_root = left_child;
	}

	if (right_child < N && vec[max_root] < vec[right_child]) {
		max_root = right_child;
	}

	if (max_root != root) {
		swap(vec[root], vec[max_root]);

		heapify(vec, N, max_root);
	}

}

void heapsort(vector<ll>& vec) {
	ll N = vec.size();

	for (int i = N / 2 - 1; i >= 0; --i) 
	{
		heapify(vec, N, i);
	}

	for (int i = N - 1; i >= 0; i--) {
		swap(vec[i], vec[0]);
		heapify(vec, i, 0);
	}
}

int main()
{
	ll n = 0;
	cin >> n;

	vec.resize(n);
	for (auto& it : vec) {
		cin >> it;
	}

	heapsort(vec);

	for (auto& it : vec) {
		cout << it << " ";
	}

	return 0;
}