#include<bits/stdc++.h>
using namespace std;


// return 1 -> if mid^n == m
// return 0 -> if mid^n < m
// return 2 -> if mid^n > m
int multiplyNTimes(int mid, int n, int m) {
	long long ans = 1;
	for (int i = 1; i <= n; i++) {
		ans = ans * mid;
		if (ans > m) return 2; //overflow se bchane ke liye aesa kia gya h(wv)
	}

	if (ans == m) return 1;
	return 0;
}

int nthRootOfANumber(int m, int n) {
	//WV highly recommended
	//we are using binary search here
	int start = 1;
	int end = m;
	int mid;

	while (start <= end) {
		mid = (start + end) / 2;

		int midMultiplyN = multiplyNTimes(mid, n, m);
		// return 1 -> if mid^n == m
		// return 0 -> if mid^n < m
		// return 2 -> if mid^n > m
		if (midMultiplyN == 1) { // return 1 -> if mid^n == m
			//this is the answer
			return mid;
		}
		else if (midMultiplyN == 2) { // return 2 -> if mid^n > m
			//move left
			end = mid - 1;
		}
		else { // return 0 -> if mid^n < m
			//move right
			start = mid + 1;

		}
	}
	return -1; //not found
}

int main() {
	/*
	QUESTION: https://takeuforward.org/data-structure/nth-root-of-a-number-using-binary-search/
	VIDEO LINK: https://www.youtube.com/watch?v=rjEJeYCasHs&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=12
	*/
	int m = 16;
	int n = 2;
	//means 27 ka cube root kya hoga
	cout << nthRootOfANumber(m, n);
}