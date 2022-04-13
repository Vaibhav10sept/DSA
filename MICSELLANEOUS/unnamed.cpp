#include<bits/stdc++.h>
using namespace std;



int main() {
	int n, m;
	cin >> n;
	cin >> m;
	cout << n << m;
	while (n <= m) {
		if (!(n % 10 == 5))
			// cout << n << endl;

			n++;
	}
}