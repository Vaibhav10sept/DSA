// Given a binary array a[] and a number k, we need to find
// length of the longest subsegment of ‘1’s possible by changing
// at most k ‘0’s.
// Input : a[] = {1, 0, 0, 1, 0, 1, 0, 1, 0, 1},
//          k = 2.
// Output : 5
// this is a dynamic sliding window problem.
// logic: we need to find the window having zeros <= k
#include <bits/stdc++.h>
using namespace std;

void fun (std::vector<int> arr, int k , int n ) {
	int zerocnt = 0;
	int ans = INT_MIN;
	int i = 0;
	//sliding window where i marks the beginning of window and
	// j marks the ending of window.
	for (int j = 0; j < n; j++) {
		if (arr[j] == 0)zerocnt++;
		while (zerocnt > k) {
			if (arr[i] == 0) zerocnt--;
			i++;
		}
		//zerocnt <= k
		// j-i+1 is the window size.
		ans = max(ans, j - i + 1);
	}
	cout << ans;
}
int main() {
	std::vector<int> arr = {1, 1, 0, 0, 1, 1, 1, 1};
	int k = 0;
	fun(arr, k, arr.size());
}