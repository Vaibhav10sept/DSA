#include <bits/stdc++.h>
using namespace std;


void maxSumSubsetOfNonAdjacentElements(vector<int> arr, string ans, int idx, bool include, int sum, int &maxSum) {
	if (idx == arr.size()) {
		cout << ans << endl;
		maxSum = std::max(sum, maxSum);
		return;
	}
	if (include) {
		maxSumSubsetOfNonAdjacentElements(arr, ans + " " + to_string(arr[idx]), idx + 1, false, sum + arr[idx], maxSum);
		maxSumSubsetOfNonAdjacentElements(arr, ans, idx + 1, true, sum, maxSum); //think about it.
	}
	else { //exclude krna hai
		maxSumSubsetOfNonAdjacentElements(arr, ans, idx + 1, true, sum, maxSum);
	}
}

int main()
{
	vector<int> arr = {5, 10, 10, 100, 5, 6};
	int maxSum = INT_MIN;
	cout << "the non adjacent subsets are:" << endl;
	maxSumSubsetOfNonAdjacentElements(arr, "" , 0, true, 0, maxSum);
	cout << "maximum sum is: " << maxSum;
}