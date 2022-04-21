#include<bits/stdc++.h>
using namespace std;

int maxSumSubarrayOfSizeK(vector<int> arr, int k) {
	int i = 0;
	int j = 0;
	//i --> represent start of window
	//j --> represent end of window
	//j-i+1 --> is the size of window
	int sum = 0;
	int maxSum = INT_MIN;
	while (j < arr.size()) {
		sum += arr[j];

		if (j - i + 1 < k) {
			j++; //window size is less than "k"
		}
		else if (j - i + 1 == k) {
			//the window size is "K" now perform the calculations
			maxSum = max(sum, maxSum);

			//now, maintain the window size
			//we are moving the window
			sum -= arr[i];
			i++;
			j++;
		}
	}
	return maxSum;
}

int main() {
	vector<int> arr = {1, 4, 2, 10, 23, 3, 1, 0, 20};
	int k = 4;
	//output will be the maximum sum of subarray of size "k"
	cout << maxSumSubarrayOfSizeK(arr, k);
}