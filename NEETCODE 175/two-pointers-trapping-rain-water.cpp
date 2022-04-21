#include <bits/stdc++.h>
using namespace std;



int trappingRainWater(vector<int> arr) {
	//creating the right max array
	vector<int> rightMax(arr.size());
	rightMax[rightMax.size() - 1] = arr[arr.size() - 1];

	//filling up the right max array
	for (int i = arr.size() - 2; i >= 0; i--) {
		rightMax[i] = max(arr[i], rightMax[i + 1]);
	}

	//finding ans using rightmax and leftmax(which we will create while traversing)
	int ans = 0;
	int leftMax = INT_MIN;
	for (int i = 0; i < arr.size(); i++) {
		leftMax = max(leftMax, arr[i]);
		int minHeight = min(leftMax, rightMax[i]);
		int reducedArea = minHeight - arr[i];
		ans += reducedArea;
	}
	return ans;
}

int main() {
	/*
	VIDEO LINK:

	*/
	vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	cout << trappingRainWater(arr);
}