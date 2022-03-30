#include <bits/stdc++.h>
using namespace std;

int buldSwitcher(int n) {
	//logic: return the number which has odd number of factors
	//observation: jo number perfect squares hai, unhi ke odd no of factors hote hai(watch video)
	return sqrt(n);
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=9XQxIvdqIt0
	// LEETCODE LINK: https://leetcode.com/problems/bulb-switcher/
	//*********************************
	int n = 25;
	cout << buldSwitcher(n);
}