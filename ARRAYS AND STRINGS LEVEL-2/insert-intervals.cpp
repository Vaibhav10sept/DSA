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

vector<vector<int>> insertInterval(vector<vector<int>> intervals, vector<int> newInterval) {
	// follow up question of "merge-intervals"
	vector<vector<int>> ans;
	int idx = 0;
	while (idx < intervals.size()) {
		//add all the interval that has starting point less than given new interval
		if (intervals[idx][0] < newInterval[0]) {
			ans.push_back(intervals[idx]);
			idx++;
		}
		else {
			break;
		}
	}

	//here we are inserting the new interval.
	//handling a edge case, where the new interval is the first interval(think) || new interval is not overlapping with the last interval that is present in the ans array
	if (ans.size() == 0 || newInterval[0] > ans[ans.size() - 1][1]) {
		//new interval is added without merging
		ans.push_back(newInterval);
	}
	else {
		//merging occur
		ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], newInterval[1]);
	}

	//now, new interval has been added to ans array.
	//add the rest of the intervals(merge if required)
	while (idx < intervals.size()) {
		if (ans[ans.size() - 1][1] >= intervals[idx][0]) {
			//merging occur
			ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], intervals[idx][1]);
		}
		else {
			//add without merging
			ans.push_back(intervals[idx]);
		}
		idx++;
	}
	return ans;
}

int main() {
	//*********************************
	// PREREQUISITE: "merge-intervals"
	// LEETCODE LINK: https://leetcode.com/problems/insert-interval/
	// VIDEO LINK: https://www.youtube.com/watch?v=dxbRB6gWCqg&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=72
	//*********************************
	vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
	vector<int>  newInterval = {4, 8};
	vector<vector<int>> ans;
	ans = insertInterval(intervals, newInterval);
	displayMatrix(ans);
}