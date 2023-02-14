#include <bits/stdc++.h>
using namespace std;

int maxSumNonAdjacentElementRecursion(vector<int> arr, int idx) {
	if (idx >= arr.size()) {
		return 0;
	}

	int pick = arr[idx] + maxSumNonAdjacentElementRecursion(arr, idx + 2);
	int notPick = 0 + maxSumNonAdjacentElementRecursion(arr, idx + 1);

	return max(pick, notPick);
}

int maxSumNonAdjacentElement(vector<int> arr) {
	return maxSumNonAdjacentElementRecursion(arr, 0);
}

int main()
{
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=GrMBfJNk_NY
	SIMILAR PROB: house robber
	NOTE: house robber is the use case of this question.
	*/
	vector<int> arr = {3, 2, 5, 10, 7};
	cout << maxSumNonAdjacentElement(arr);
}