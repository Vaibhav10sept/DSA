#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int a, int b, int c, int n) {
	// a is source disk
	// b is intermediatery/helper disk
	// c is destination disk
	if (n == 0 ) return;
	towerOfHanoi(a, c, b, n - 1);
	cout << n << "[" << a << " to " << c << "]" << endl;
	towerOfHanoi(b, a, c, n - 1);
}

int main()
{
	towerOfHanoi(1, 2, 3, 3);
}