#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e6 + 3;

int main()
{
	int64_t n = 0;
	cin >> n;
	if (n == 1) {
		cout << n;
		return 0;
	}
	int64_t ans = 1;
	if(n > mod){
		cout << 0;
		return 0;
	}
	for (int i = 2; i <= n; i++) {
    	ans = (ans * (i % mod)) % mod;
	}
	cout << ans;
}