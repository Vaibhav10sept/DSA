#include <bits/stdc++.h>
using namespace std;

int gcdRecusive(int a, int b) {
	if (a == 0) return b;
	else if (b == 0) return a;

	return gcdRecusive(b, a % b);
}

int main()
{
	//NOTE: gcd and hcf both are same thing
	int a = 40;
	int b = 20;
	cout << gcdRecusive(a, b);
}