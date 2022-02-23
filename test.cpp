#include <bits/stdc++.h>
using namespace std;
int fun(int n) {
	if (n > 0) {
		return n + fun(n - 2);
	}
}
int main() {
	cout << fun(10);
}