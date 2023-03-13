#include <iostream>

using namespace std;

double binpow(double a, int64_t n) {
	if (n == 0) return 1;
	if (n == 1) {
		return a;
	}
	if (n % 2 == 0) {
		a = binpow(a * a, n / 2);
	}
	else {
		a = a * binpow(a, n - 1);
	}
	return a;
}

int main()
{
	double a;
	int64_t n;
	cin >> a >> n;
	cout << binpow(a, n);
}