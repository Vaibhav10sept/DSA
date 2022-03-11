#include <bits/stdc++.h>
using namespace std;

int factorial(int val) {
	if (val == 0) return 1;
	return  val * factorial(val - 1);
}

void stringPermutationsIterative(string &str) {
	int n = str.size();
	int fac = factorial(n); //itne permutations possible hogi

	for (int i = 0; i < fac; i++) {
		string tempStr = str;
		int temp = i;

		for (int div = n; div >= 1; div--) {
			int q = temp / div;
			int r = temp % div;

			cout << tempStr[r] << " ";
			tempStr.erase(r, 1);

			temp = q;
		}
		cout << endl;
	}
}

int main()
{
	//******************************************
	// NOTE: total no of permutations: size!
	// VIDEO LINK: 	https://www.youtube.com/watch?v=39SKIuA-ieY&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=549
	//******************************************
	string str = "abc";
	stringPermutationsIterative(str);
}