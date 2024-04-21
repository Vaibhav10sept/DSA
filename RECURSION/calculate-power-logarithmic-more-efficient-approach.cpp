#include <bits/stdc++.h>
using namespace std;

int calculatePowerLogarithmic(int n, int p) {
	if (p == 0) return 1;
	int res = calculatePowerLogarithmic(n, p / 2);
	int ans = res * res;
	if (p % 2 == 1) { // p(power) is odd, then do one extra multiplication of 'n'.
		ans *= n;
	}
	return ans;
}

int main()
{
	//*********************
	// LOGIC: X^N = X^N/2 * X^N/2
	//******************************
	cout <<	calculatePowerLogarithmic(5, 3);
}