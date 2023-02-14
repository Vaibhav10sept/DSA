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
	else { //include = false --> means exclude krna hai
		maxSumSubsetOfNonAdjacentElements(arr, ans, idx + 1, true, sum, maxSum);
	}
}

int main()
{
	/********************************************
	SIMILAR: there is also a similar quest for DP ie. max sum non adjacent element
	recusion vale question me hm sare non adjacent subsets print krte h + max sum bhi nikalte h, or isme hm max sum print krte h non adjacent subset ka
	****************************************/
	vector<int> arr = {5, 10, 10, 100, 5, 6};
	int maxSum = INT_MIN;
	cout << "the non adjacent subsets are:" << endl;
	maxSumSubsetOfNonAdjacentElements(arr, "" , 0, true, 0, maxSum);
	cout << "maximum sum is: " << maxSum;
}