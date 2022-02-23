#include <bits/stdc++.h>
using namespace std;


int countBinaryString(int n) {
	//Please watch attached video(link) for more understanding.
	int countZeros = 1;
	int countOnes = 1;
	for (int i = 2; i <= n; i++) {
		int temp = countOnes;
		countOnes = countOnes + countZeros;
		countZeros = temp;
	}
	return countZeros + countOnes;
}

int main()
{
	//***************************
	// video link: https://www.youtube.com/watch?v=nqrXHJWMeBc&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=485&t=283s
	//**************************************************
	int n = 6;
	cout << "count is: " << countBinaryString(n);
}