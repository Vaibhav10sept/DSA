#include <bits/stdc++.h>
using namespace std;

int trappingRainWater(vector<int> arr) {
	//here we use two pointers, WV recommended
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
	NOTE: this is the most efficient solution, one less eff solution is also there(which is very intuitive). but please stick to this one,
	VIDEO LINK: https://www.youtube.com/watch?v=m18Hntz4go8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=43
	*/
	vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	cout << trappingRainWater(arr);
}