#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& arr) {
	// 4 steps process
	// 1) a[i] < a[i+1] --> traverse from right to left
	// 2) a[j] > a[i] --> traverse from right to left
	// 3) swap(a[i],a[j])
	// 4) reverse(i+1,last index)
	//NOTE: if step1 fails means breakpoint nhi mila, so directly move to 4th step ie, reverse the array and that will be the answer

	//step1
	int n = arr.size();
	int i = n - 2;
	while (i >= 0 and arr[i] >= arr[i + 1]) i--;

	if (i < 0) { //means step1 fail, so do step4-> reverse the whole array
		reverse(arr.begin(), arr.end());
	}
	else { //step1 find the arr[i] < arr[i+1], do step 2
		int j = n - 1;
		while (j >= 0 and arr[j] <= arr[i]) j--;
		//now, we find j ie, arr[j] > arr[i]
		//NOTE: this is sure that we find j (CS, WV)
		//step3
		swap(arr[i], arr[j]);

		//step4
		reverse(arr.begin() + i + 1, arr.end());
	}
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=LuLCLgMElus
	// QUESTION LINK: https://leetcode.com/problems/next-permutation/submissions/672953070/
	//*********************************
	vector<int> arr = {1, 2, 3};
	nextPermutation(arr);
	cout << "res" << endl;
	for (auto ele : arr) {
		cout << ele << " ";
	}
}