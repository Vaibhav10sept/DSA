#include <bits/stdc++.h>
using namespace std;

int countSubsetsWithSumKRecursive(int idx, vector<int> arr, int target) {
	// if (target == 0) return 1;
	if (target < 0) return 0;
	if (idx == arr.size()) {
		if (target == 0) return 1;
		else return 0;
	}
	// BC ends

	//recursive call as in subsets(pick and non pick vali)(think, crucial part)

	int ansWhenPicked = countSubsetsWithSumKRecursive(idx + 1, arr, target - arr[idx]);
	int ansWhenNotPicked = countSubsetsWithSumKRecursive(idx + 1, arr, target);

	return ansWhenNotPicked + ansWhenPicked;
}

int countSubsetsWithSumK(vector<int> arr, int target) {
	return countSubsetsWithSumKRecursive(0, arr, target);
}

int main()
{
	/***************************
	VIDEO LINK: https://www.youtube.com/watch?v=ZHyb-A2Mte4&t=46s
	QUESTION LINK: https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/
	subset/subsequence: 2^n; har element ke pass 2 option hai ya toh subset me aae
	ya na aae
	subarray: N*(N+1)/2; subarray continuous hote hai
	//**************************************************/
	vector<int> arr =  {0, 0, 1};
	int target = 1;
	cout << countSubsetsWithSumK(arr, target);

}