#include <bits/stdc++.h>
using namespace std;


int arrangeBuildings(int n) {
	//Please watch attached video(link) for more understanding.
	int countBuildings = 1;
	int countSpaces = 1;
	for (int i = 2; i <= n; i++) {
		int temp = countSpaces;
		countSpaces = countSpaces + countBuildings;
		countBuildings = temp;
	}
	int totalForOneSide = countBuildings + countSpaces;
	return totalForOneSide * totalForOneSide;
}

int main()
{
	//***************************
	// NOTE: similar to before question "COUNT BINARY STRINGS"
	// video link: https://www.youtube.com/watch?v=0nF-BMYy7tc&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=485
	//**************************************************
	int n = 5;
	cout << "count is: " << arrangeBuildings(n);
}