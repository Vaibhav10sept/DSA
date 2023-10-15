#include<bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(vector<int> arr, int k) {
	//this is my code, no video, no solution
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
	/*
	QUESTION: https://leetcode.com/problems/max-consecutive-ones-iii/description/
	NOTE: sliding windows is used here.
	VIDEO LINK: https://www.youtube.com/watch?v=QPfalDbqa4A&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=15
	*/
	vector<int> arr = {1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1};
	int k = 1;
	cout << "max length " << maxConsecutiveOnes(arr, k);
}