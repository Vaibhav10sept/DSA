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

vector<vector<int>> mergeIntervals(vector<vector<int>> &arr) {
	sort(arr.begin(), arr.end(), comparator);
	stack<pair<int, int>> st;
	st.push({arr[0][0], arr[0][1]});
	int i = 1;
	while (i < arr.size()) {
		if (!st.empty() and st.top().second >= arr[i][0]) {
			st.top().second = max(st.top().second, arr[i][1]);
		}
		else {
			st.push({arr[i][0], arr[i][1]});
		}
		i++;
	}

	//filling up the ans array
	vector<vector<int>> ans;
	while (!st.empty()) {
		pair<int, int> p = st.top();
		st.pop();
		vector<int> temp = {p.first, p.second};
		ans.push_back(temp);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	//*********************************
	// NOTE: we use stack here
	// VIDEO LINK: https://www.youtube.com/watch?v=2JzRBPFYbKE
	// LEETCODE LINK: https://leetcode.com/problems/merge-intervals/
	//*********************************
	vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
	vector<vector<int>> ans = mergeIntervals(arr);
	displayMatrix(arr);
	cout << "result" << endl;
	displayMatrix(ans);
}