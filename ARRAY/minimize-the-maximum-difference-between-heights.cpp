#include <bits/stdc++.h>
using namespace std;

int minimizeMaxDiffHeight(vector<int> arr, int k) {
	int n = arr.size();
	sort(arr.begin(), arr.end());

	int smallest = arr[0] + k;
	int largest = arr[n - 1] - k;
	int ans = INT_MAX;
	int newSmallest, newLargest;
	// think why +k and -k, WV

	for (int i = 0; i < n - 1; i++) { //second last element tk iterate kro
		newSmallest = min(smallest, arr[i] + k);
		newLargest = max(largest, arr[i + 1] - k);
		if (newLargest < 0) continue;
		ans = min(ans, newLargest - newSmallest);
	}

	return ans;
}

int main()
{
	/*
	VIDEO LINK: youtube.com/watch?v=Av7vSnPSCtw
	QUESTION LINK: https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
	*/
	vector<int> arr = {1, 5, 8, 10};
	int k = 2;
	cout << minimizeMaxDiffHeight(arr, k);
}