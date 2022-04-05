#include <bits/stdc++.h>
using namespace std;

int maxCandlesAllocatedToKChildren(vector<int> arr, int k) {
	int sum = 0;
	for (int ele : arr) sum += ele;
	int lowest = 0;
	int highest = sum / k;
	highest++; //don't know why he did that.
	int ans = 0;
	while (lowest < highest) {
		int mid = (lowest + highest) / 2;
		if (mid == 0) return 0; //0 candies ke lie, 0 hi return hoga(think)
		int countOfSubPiles = 0;
		for (int i = 0; i < arr.size(); i++) {
			countOfSubPiles += (arr[i] / mid);
		}
		if (countOfSubPiles >= k) {
			//move to right, for maximum answer.
			ans = max(ans, countOfSubPiles);
			lowest = mid + 1;
		}
		else {
			//move to left
			highest = mid;
		}

	}
	return ans;
}

int main() {
	//*********************************
	// NOTE:we used binary search approach here.
	// LEETCODE LINK: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
	// VIDEO LINK: https://www.youtube.com/watch?v=vSzibYJC1J0
	//*********************************
	vector<int> candies = {2, 5};
	int k = 2;
	cout << maxCandlesAllocatedToKChildren(candies, k);
}