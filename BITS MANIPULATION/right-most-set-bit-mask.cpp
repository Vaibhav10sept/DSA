#include <bits/stdc++.h>
using namespace std;

int rightMostMask(int n) {
	//right most set bit mask is the number & (twos complement)
	//note: -n and two complement(~n + 1) are same
	//twos complement --> ~n + 1; (add 1 to ones complement(~n))
	//ones complement --> ~n;

	return n & -n;
	//below code also do the job
	// return n & (~n + 1);
}

int main() {
	/*
	NOTE: WV highly recommended
	NOTE: ye question is used in Count Set Bits in an Integer Kernighan Algorithm
	VIDEO LINK: https://www.youtube.com/watch?v=XcSr6TIMl7w
	QUESTION LINK:
	*/
	int n = 58;
	cout << rightMostMask(n);
}