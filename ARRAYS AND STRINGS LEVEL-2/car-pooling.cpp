#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int> &a, vector<int> &b) {
	return a[1] < b[1];
}

bool carPooling(vector<vector<int>> arr, int capacity) {
	//good question, iska concept acha hai
	//getting lastDropLocation to create the array of that size
	int lastDropLocation = -1;
	for (vector<int> vec : arr) {
		lastDropLocation = max(lastDropLocation, vec[2]);
	}

	vector<int> highway(lastDropLocation + 1);
	for (vector<int> vec : arr) {
		//starting point me passenger count rakha
		highway[vec[1]] += vec[0];
		//ending point me passenger count ka negative rakha(for presum before concept)(watch video)
		highway[vec[2]] += (vec[0] * -1);
	}

	//calculation presum arr(highway)
	for (int i = 1; i < highway.size(); i++) {
		highway[i] += highway[i - 1];
	}


	//now, checking if the entries in highway exceed the given capacity or not
	for (auto ele : highway) {
		if (ele > capacity) {
			return false;
		}
	}
	return true;
}

int main() {
	//*********************************
	// NOTE: we are using "presum/cummulative sum" concept here.
	// LEETCODE LINK: https://leetcode.com/problems/car-pooling/
	// VIDEO LINK: https://www.youtube.com/watch?v=nO95uYKB-lo&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=74
	//*********************************
	vector<vector<int>> trips = {{2, 1, 5}, {3, 5, 7}};
	int capacity = 3;
	bool ans = carPooling(trips, capacity);
	if (ans) {
		cout << "true" << endl;
	}
	else {
		cout << "false";
	}
}