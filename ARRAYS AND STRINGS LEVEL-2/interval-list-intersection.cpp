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

vector<vector<int>> intervalListIntersection(vector<vector<int>> firstList, vector<vector<int>> secondList) {
	vector<vector<int>> intervals;
	int i = 0;
	int j = 0;

	while (i < firstList.size() and j < secondList.size()) {
		int commonStartingPoint = max(firstList[i][0], secondList[j][0]);
		int commonEndingPoint = min(firstList[i][1], secondList[j][1]);

		//check if the common starting and ending points are valid or not.
		if (commonStartingPoint <= commonEndingPoint) { //yes, a valid interval
			vector<int> interval = {commonStartingPoint, commonEndingPoint};
			// add to the ans 2D array
			intervals.push_back(interval);
		}
		//conditionaly increment i and j.
		//jiska ending point chota hota h, use increment krte hai(logic)
		if (firstList[i][1] < secondList[j][1]) {
			i++;
		}
		else {
			j++;
		}
	}
	return intervals;
}

int main() {
	//*********************************
	// LEETCODE LINK: https://leetcode.com/problems/interval-list-intersections/
	// VIDEO LINK: https://www.youtube.com/watch?v=fmdNUOQnhrU&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=71
	//*********************************
	vector<vector<int>> firstList = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
	vector<vector<int>> secondList = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};
	vector<vector<int>> ans;
	ans = intervalListIntersection(firstList, secondList);
	displayMatrix(ans);
}