#include<bits/stdc++.h>
using namespace std;

//*****************
//THIS IS THE APPLICATION OF MAXIMUM(MINIMUM) SUM SUBARRAY OF SIZE K
//*****************

int minSumSubarrayOfSizeK(vector<int> arr, int k) {
	int i = 0;
	int j = 0;
	//i --> represent start of window
	//j --> represent end of window
	//j-i+1 --> is the size of window
	long long sum = 0;
	int minSum = INT_MAX;
	while (j < arr.size()) {
		sum += arr[j];

		if (j - i + 1 < k) {
			j++; //window size is less than "k"
		}
		else if (j - i + 1 == k) {
			//the window size is "K" now perform the calculations
			minSum = min(sum, minSum);

			//now, maintain the window size
			//we are moving the window
			sum -= arr[i];
			i++;
			j++;
		}
	}
	return minSum;
}

int maximumPointsYouCanObtainfromCards(vector<int> arr, int k) {
	int totalSum = 0;
	for (int ele : arr) {
		totalSum += ele;
	}
	//edge case --> without this you'll get TLE
	if (k == arr.size()) return totalSum;

	int windowSize = arr.size() - k; //think, WV
	int minSumSubarrayAns = minSumSubarrayOfSizeK(arr, windowSize);
	return totalSum - minSumSubarrayAns; // think, logic, WV
}

int main() {
	/********************************************
	 * STRONG PREREQUISITE: maximum(minimum) sum subarray of size k
	 * VIDEO LINL: https://www.youtube.com/watch?v=U0utLw_vWGM
	 * LEETCODE: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
	 ************************************/
	vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
	int k = 3;
	//output will be the maximum sum of subarray of size "k"
	cout << maximumPointsYouCanObtainfromCards(cardPoints, k);
}