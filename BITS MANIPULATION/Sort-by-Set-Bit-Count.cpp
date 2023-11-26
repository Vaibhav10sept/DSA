#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n) {
	//right most set bit mask is the number & (twos complement)
	//note: -n and two complement(~n + 1) are same
	//twos complement --> ~n + 1; (add 1 to ones complement(~n))
	//ones complement --> ~n;

	int cnt = 0;
	while (n != 0) {
		int rightMostMask = n & -n; //for this go to strong preq;
		n = n - rightMostMask;
		cnt++;
	}
	return cnt;
}

bool comp(int a, int b) { //decreasing order
	return countSetBits(a) > countSetBits(b); //this will give TLE Of gfg
	//or use also use below code(will not give TLE)
	// return __builtin_popcount(a) > __builtin_popcount(b);
}

void sortBySetBitCount(int arr[], int n) {
	stable_sort(arr, arr + n, comp);
}



int main() {
	/*
	NOTE: WV highly recommended
	STRONG PREQ: count set bits in an integer karnighan algorithm
	VIDEO LINK: https://www.youtube.com/watch?v=I475waWiTK4
	QUESTION LINK: https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1
	*/
	int arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
	int n = 9;
	sortBySetBitCount(arr, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}