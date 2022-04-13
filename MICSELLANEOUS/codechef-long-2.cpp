#include <bits/stdc++.h>
using namespace std;

void fun(int D, int d, int p , int q) {
	long ans = 0;
	long temp = D / d;
	// ans = temp * q * p * D;
	long inc = p;

	for (int i = 1; i <= temp; i++) {
		ans += inc * d;
		inc = p + i * q;
	}
	int again = D % d;

	cout << ans + again*inc << endl;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int D, d, p, q;
		cin >> D >> d >> p >> q;
		fun(D, d, p, q);
	}
}


