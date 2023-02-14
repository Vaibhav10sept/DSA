#include <bits/stdc++.h>
using namespace std;

int targetSumRecursive(int idx, vector<int> arr, int target) {
	//BC
	if (idx == arr.size()) {
		if (target == 0) {
			return 1;
		}
		else return 0;
	}

	//recursive calls
	//LOGIC: ek call hm arr[idx] ko + krke krege or doosri call hm arr[idx] ko - krke krege
	//or dono calls ka jo ans aega uska sum return kr dege (think, WV)
	return targetSumRecursive(idx + 1, arr, target + arr[idx]) + targetSumRecursive(idx + 1, arr, target - arr[idx]);
}

int targetSum(vector<int> arr, int target) {
	return targetSumRecursive(0, arr, target);
}

int main()
{
	//***************************
	// NOTE: this recusive solution will give you TLE, other solution are also there, search
	// NOTE: there is a memoized and dp solution also.
	//       you can search it using ctrl + p.
	// VIDEO LINK: https://leetcode.com/problems/target-sum/
	// LEETCODE LINK: https://www.youtube.com/watch?v=g0npyaQtAQM
	//**************************************************
	vector<int> arr = {1, 1, 1, 1, 1};
	int target = 3;

	cout << targetSum(arr, target);
}