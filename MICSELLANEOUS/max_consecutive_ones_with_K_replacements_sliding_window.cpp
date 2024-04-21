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
	//this is my code.
	int i = 0;
	int j = 0;
	int countOfZeros = 0;
	int ans = INT_MIN;

	while (j < arr.size()) {
		if (arr[j] == 0) countOfZeros++;
		if (countOfZeros <= k) ans = max(ans, j - i + 1);
		if (countOfZeros > k) {
			while (countOfZeros > k) {
				if (arr[i] == 0) countOfZeros--;
				i++;
			}
		}
		j++;
	}
	return ans == INT_MIN ? 0 : ans;
}

int main() {
	std::vector<int> arr = {1, 1, 0, 0, 1, 1, 1, 1};
	int k = 0;
	fun(arr, k, arr.size());
}