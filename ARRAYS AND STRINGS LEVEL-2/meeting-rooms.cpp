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

bool comparator(vector<int> v1, vector<int> v2) {
	return v1[0] < v2[0];
}

bool meetingRoom(vector<vector<int>> &arr) {
	sort(arr.begin(), arr.end(), comparator);
	for (int i = 0; i < arr.size() - 1; i++) {
		if (arr[i][1] <= arr[i + 1][0]) continue;
		else return false;
	}
	return true;
}

int main() {
	//*********************************
	// PREREQUISITE: "Merge-intervals"
	// VIDEO LINK: https://www.youtube.com/watch?v=r9KCHmciaUw&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=68
	// LEETCODE LINK: NOT FOUND
	//*********************************
	vector<vector<int>> arr = {{1, 3}, {8, 10}, {7, 8},  {3, 6}};
	sort(arr.begin(), arr.end(), comparator);
	displayMatrix(arr);
	bool ans = meetingRoom(arr);
	if (ans) {
		cout << "yes";
	}
	else {
		cout << "no";
	}
}