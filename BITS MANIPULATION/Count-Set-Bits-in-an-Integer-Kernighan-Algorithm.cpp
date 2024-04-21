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

int main() {
	/*
	NOTE: WV highly recommended
	STRONG PREQ: right most set bit mask
	VIDEO LINK: https://www.youtube.com/watch?v=I475waWiTK4
	QUESTION LINK: https://practice.geeksforgeeks.org/problems/set-bits0143/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
	*/
	int n = 6;
	cout << countSetBits(n);
}