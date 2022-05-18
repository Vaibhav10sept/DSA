#include <bits/stdc++.h>
using namespace std;

int trappingRainWater(vector<int> arr) {
	//here we use two pointers.
	int n = arr.size();
	int i = 0;
	int j = n - 1;
	int rightMax = 0;
	int leftMax = 0;
	int ans = 0;

	while (i < j) {
		if (arr[i] <= arr[j]) {
			if (arr[i] >= leftMax) {
				leftMax = arr[i];
			}
			else {	//arr[i] < leftMax
				ans += leftMax - arr[i];
			}
			i++;
		}
		else { // arr[j] < arr[i]
			if (arr[j] >= rightMax) {
				rightMax = arr[j];
			}
			else {	//arr[j] < rightMax
				ans += rightMax - arr[j];
			}
			j--;
		}
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