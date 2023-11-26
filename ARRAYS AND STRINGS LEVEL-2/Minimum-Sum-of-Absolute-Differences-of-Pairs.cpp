#include <bits/stdc++.h>
using namespace std;

long long findMinSum(vector<int> &a, vector<int> &b, int n) {
	// * NOTE: i wrote it
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += abs(a[i] - b[i]);
	}
	return ans;
}

int main() {
	/*********************************
	 * NOTE: i wrote it
	// VIDEO LINK:
	// LEETCODE LINK: https://practice.geeksforgeeks.org/problems/minimum-sum-of-absolute-differences-of-pairs/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
	//*********************************/
	int n = 4;
	vector<int> a = {4, 1, 8, 7};
	vector<int> b = {2, 3, 6, 5};
	cout << findMinSum(a, b, n);
}
