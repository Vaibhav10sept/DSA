#include <bits/stdc++.h>
using namespace std;

void displayMatrix(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int wordWrapHelper(int i, int rem, vector<int> arr, int k, vector<vector<int>> &memo) {
	//watch video recommended
	//BC
	if (i == arr.size()) return 0;
	//memo
	if (memo[i][rem] != -1) {
		return memo[i][rem];
	}

	int ans;
	if (arr[i] > rem) {
		ans = ((rem + 1) * (rem + 1)) + wordWrapHelper(i + 1, k - arr[i] - 1, arr, k, memo);
	}
	else { // arr[i] <= rem
		int nextLineCost = ((rem + 1) * (rem + 1)) + wordWrapHelper(i + 1, k - arr[i] - 1, arr, k, memo);
		int thisLineCost = wordWrapHelper(i + 1, rem - arr[i] - 1, arr, k, memo);
		ans = min(nextLineCost, thisLineCost);
	}

	return memo[i][rem] = ans;
}

int wordWrap(vector<int> arr, int k) {
	vector<vector<int>> memo(arr.size(), vector<int>(k + 1, -1));

	int ans = wordWrapHelper(0, k, arr, k, memo);
	displayMatrix(memo);
	return ans;
}

int main()
{
	/*******************************
	 * PREREQUISITE: word wrap rec solution
	 * NOTE: this is memo solution, a rec solution is also there
	 * VIDEO LINK: https://www.youtube.com/watch?v=aPmemoJ_RjaXs&t=618s
	 QUESTION LINK: https://practice.geeksforgeeks.org/problems/word-wrap1646/1
	 * *************************************/
	vector<int> arr = {3, 2, 2, 5};
	int k = 6;
	cout << "result " << wordWrap(arr, k);
}