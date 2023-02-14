#include <bits/stdc++.h>
using namespace std;

void climbStair(int n, string ans) {
	if (n == 0) {
		cout << ans << endl;
		return;
	}
	if (n < 0) {
		return;
	}
	climbStair(n - 1, ans + "1");
	climbStair(n - 2, ans + "2");
	climbStair(n - 3, ans + "3");
}

int main()
{
	climbStair(5, "");
}