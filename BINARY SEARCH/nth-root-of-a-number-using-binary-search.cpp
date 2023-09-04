#include<bits/stdc++.h>
using namespace std;

double multiplyNTimes(double mid, int n) {
	double ans = 1;
	for (int i = 0; i < n; i++) {
		ans *= mid;
	}
	return ans;
}

double nthRootOfANumber(int m, int n) {
	//WV highly recommended
	//we are using binary search here
	double start = 1;
	double end = m;
	double mid;
	double eps = 1e-7; //this is precision, for understanding WV recommended.
	//10 to the power -7 which is equal to 1/10^7 -> 0.0000001 -> means upto 6 decimal places tk ka shi result aega
	//NOTE: 1e-7 --> upto 6 decimal places ke lie ke liye, similar 1e-6 upto 5 decimal places ke liye, observe the pattern here.
	while ((end - start) > eps) {
		mid = (start + end) / 2.0;
		if (multiplyNTimes(mid, n) < m) {
			start = mid;
		}
		else {
			end = mid;
		}
	}
	return start; //you can also return end, coz both holds the same value.
}

int main() {
	/*
	QUESTION: https://takeuforward.org/data-structure/nth-root-of-a-number-using-binary-search/
	VIDEO LINK: https://www.youtube.com/watch?v=WjpswYrS2nY&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=63
	*/
	int m = 16;
	int n = 2;
	//means 27 ka cube root kya hoga
	cout << nthRootOfANumber(m, n);
}