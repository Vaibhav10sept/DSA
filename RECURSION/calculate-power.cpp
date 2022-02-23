#include <bits/stdc++.h>
using namespace std;

int calculatePower(int n, int p) {
	if (p == 0) return 1;
	return calculatePower(n, p - 1) * n;
}

int main()
{
	cout <<	calculatePower(5, 3);
}