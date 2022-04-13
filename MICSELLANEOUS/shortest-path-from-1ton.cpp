#include<bits/stdc++.h>
using namespace std;
int minimumStep(int n) {
	int path = 1;
	int ans = 0;
	while (1) {


		if (n % 3 == 0) {
			n /= 3;
			ans++;
		} else {
			n--;
			ans++;
		}
		if (n == 0)return --ans;
	}
}

int main() {
	int n;
	cin >> n;
	int ans;

	ans = minimumStep(n);
	cout << ans;
}