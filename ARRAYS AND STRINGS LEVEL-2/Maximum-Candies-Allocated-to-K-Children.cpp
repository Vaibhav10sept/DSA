#include <bits/stdc++.h>
using namespace std;

int maxCandlesAllocatedToKChildren(vector<int> A, int k) {
	//this code is copied from leetcode
	int left = 0, right = 1e7;
	while (left < right) {
		long sum = 0, mid = (left + right + 1) / 2;
		for (int& a : A) {
			sum += a / mid;
		}
		if (k > sum)
			right = mid - 1;
		else
			left = mid;
	}
	return left;
}

int main() {
	//*********************************
	// NOTE: we used binary search approach here.
	// LEETCODE LINK: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
	// VIDEO LINK: https://www.youtube.com/watch?v=vSzibYJC1J0
	//*********************************
	vector<int> candies = {2, 5};
	int k = 2;
	cout << maxCandlesAllocatedToKChildren(candies, k);
}