#include <bits/stdc++.h>
using namespace std;

int wordWrapHelper(int i, int rem, vector<int> &arr, int &k) {
	//watch video recommended
	//we can use memoization here.
	//NOTE: a memoized solution is also there.
	if (i == arr.size()) return 0;

	int ans;
	if (arr[i] > rem) {
		ans = ((rem + 1) * (rem + 1)) + wordWrapHelper(i + 1, k - arr[i] - 1, arr, k);
	}
	else { // arr[i] <= rem
		int nextLineCost = ((rem + 1) * (rem + 1)) + wordWrapHelper(i + 1, k - arr[i] - 1, arr, k);
		int thisLineCost = wordWrapHelper(i + 1, rem - arr[i] - 1, arr, k);
		ans = min(nextLineCost, thisLineCost);
	}
	return ans;
}

int wordWrap(vector<int> arr, int k) {
	return wordWrapHelper(0, k, arr, k);
}

int main()
{
	/*******************************
	 * NOTE: memo solution is also there
	 * VIDEO LINK: https://www.youtube.com/watch?v=aPdpJ_RjaXs&t=618s
	 QUESTION LINK: https://practice.geeksforgeeks.org/problems/word-wrap1646/1
	 * *************************************/
	vector<int> arr = {3, 2, 2, 5};
	int k = 6;
	cout << "result " << wordWrap(arr, k);
}