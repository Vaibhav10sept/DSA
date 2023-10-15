#include<bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(vector<int> grumpy, vector<int> customers, int k) {
	int i = 0;
	int j = 0;
	//i --> represent start of window
	//j --> represent end of window
	//j-i+1 --> is the size of window
	int sum = 0;
	int maxSum = INT_MIN;

	int initialSatisfied = 0;
	for (int i = 0; i < grumpy.size(); i++) {
		if (grumpy[i] == 0) {
			initialSatisfied += customers[i];
		}
	}

	while (j < grumpy.size()) {
		if (grumpy[j] == 1) {
			sum += customers[j];
		}
		if (j - i + 1 == k) {
			//the window size is "K" now perform the calculations
			maxSum = max(maxSum, sum + initialSatisfied);

			//now, maintain the window size
			//we are moving the window
			if (grumpy[i] == 1) {
				sum -= customers[i];
			}
			i++;
		}
		j++;
	}
	return maxSum;
}

int main() {
	/*
	NOTE: I derive the code of this question from maximum sum subarray of size k
	STRONG PREQ: maximum sum subarray of size k
	QUESTION: maximum sum subarray of size k
	NOTE: sliding windows is used here.
	VIDEO LINK:
	*/
	vector<int> customers = {4, 10, 10};
	vector<int> grumpy = {1, 1, 0};
	int k = 2;
	cout << "res " << maxConsecutiveOnes(grumpy, customers, k);
}