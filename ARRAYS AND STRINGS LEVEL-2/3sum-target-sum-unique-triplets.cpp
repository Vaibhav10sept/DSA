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

vector<vector<int> > threeSum(vector<int> &num) {
	vector<vector<int> > res;
	std::sort(num.begin(), num.end());

	for (int i = 0; i < num.size(); i++) {
		int target = -num[i];
		int front = i + 1;
		int back = num.size() - 1;

		while (front < back) {
			int sum = num[front] + num[back];

			// Finding answer which start from number num[i]
			if (sum < target)
				front++;

			else if (sum > target)
				back--;

			else { // sum == target
				vector<int> triplet = {num[i], num[front], num[back]};
				res.push_back(triplet);

				// Processing duplicates of Number 2
				// Rolling the front pointer to the next different number forwards
				while (front < back && num[front] == triplet[1]) front++;

				// Processing duplicates of Number 3
				// Rolling the back pointer to the next different number backwards
				while (front < back && num[back] == triplet[2]) back--;
			}

		}
		// Processing duplicates of Number 1
		while (i + 1 < num.size() && num[i + 1] == num[i])
			i++;
	}
	return res;
}

int main() {
	//*********************************
	// PREREQUISITE: "2sum-target-sum-unique-pair"
	// VIDEO LINK: https://www.youtube.com/watch?v=1IBgYGJqKP8&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=40
	// QUESTION:
	// 1. Given an integer array 'nums', and a 'target', return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k.
	// 2. Another thing is nums[i] + nums[j] + nums[k] == target.
	// 3. Notice that the solution set must not contain duplicate triplets.
	//*********************************
	// vector<int> arr = { -2, -1, 1, 2};
	vector<int> arr = { -1, 0, 1, 2, -1, -4};
	// vector<int> arr = {0, 0, 0};
	vector<vector<int>> ans = threeSum(arr);
	cout << "ans" << endl;
	displayMatrix(ans);
}