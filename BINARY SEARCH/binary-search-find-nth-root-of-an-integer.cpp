#include<bits/stdc++.h>
using namespace std;

int sqrt(int n) {
	//edge case
	if (n == 0) return 0;

	int start = 1, end = n;
	int ans = 1;

	while (start <= end) {
		int mid = start + (end - start) / 2;

		if (mid * mid <= n) {
			ans = mid;
			//move to right: we are looking for largest mid which is mid*mid <= n
			start = mid + 1;
		}

		else { // mid * mid > n
			//move to left
			end = mid - 1;
		}
	}

	return ans;
}


int main() {

	/*
	PREREQUITE:
	QUESTION: https://www.codingninjas.com/studio/problems/nth-root-of-m_1062679
	VIDEO LINK: https://www.youtube.com/watch?v=rjEJeYCasHs&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=12
	*/
	int n = 3;
	int m = 27;
	cout << nthRootOfANumber(n) << endl;
}