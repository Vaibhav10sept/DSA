#include <bits/stdc++.h>
using namespace std;

bool nonDecreasingArray(vector<int> arr) {
	//see question first using below link
	bool changed = false;

	for (int i = 1; i < arr.size(); i++) {
		if (arr[i - 1] > arr[i]) { //voilation
			if (changed) return false; //coz only one change is allowed
			changed = true;

			//watch video recommended
			if (i == 1 or arr[i - 2] <= arr[i])
				arr[i - 1] = arr[i];

			else
				arr[i] = arr[i - 1];
		}
	}
	return true;
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=RegQckCegDk
	// QUESTION: https://leetcode.com/problems/non-decreasing-array/
	//*********************************
	vector<int> arr = {4, 2, 3};
	cout << nonDecreasingArray(arr);
}