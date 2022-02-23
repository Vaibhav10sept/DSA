#include <bits/stdc++.h>
using namespace std;

int tilingWithMx1TilesRecursive(int m, int n) {
	if (n < m) { //sirf vertically hi rakh skte hai -- think
		return n;
	}
	if (n == m) { //sare vertically rakh do ya sare horizontally, so 2 ways hai -- think
		return 2;
	}
	//Bc ends

	return tilingWithMxNTilesRecursive(m, n - 1) + tilingWithMxNTilesRecursive(m, n - m);
}


int main()
{
	//***************************
	// video link: https://www.youtube.com/watch?v=_c_R-uIi-zU&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=512
	//**************************************************
	int n = 4;
	int m = 10;
	cout << "no of ways in which mx1 tiles can be laid down: " << tilingWithMx1TilesRecursive(m, n);
}