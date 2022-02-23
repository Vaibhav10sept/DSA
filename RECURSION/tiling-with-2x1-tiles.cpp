#include <bits/stdc++.h>
using namespace std;

int tilingWithDominoesRecursive(int n, string ans) {
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 2;
	}

	return tilingWithDominoesRecursive(n - 1, ans + "V") + tilingWithDominoesRecursive(n - 2, ans + "H");
}

int main()
{
	//***************************
	// video link: https://www.youtube.com/watch?v=dVT9JeUMMDE&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=511
	//**************************************************
	int n = 4;
	cout << "no of ways in which tiles can be laid down: " << tilingWithDominoesRecursive(n, "");
}