#include <bits/stdc++.h>
using namespace std;

struct compare {
	bool operator() (const vector<int> vec1, const vector<int> vec2) {
		// min heap, see if we overload < operator for this we would have used ">" in return for implementing min heap(observe kia h maene ye, rem)
		return vec1[0] * vec1[0] + vec1[1] * vec1[1] < vec2[0] * vec2[0] + vec2[1] * vec2[1];
	}
};

vector<vector<int>> kClosestPointsToOrigin(vector<vector<int>> arr, int k) {
	priority_queue<vector<int>, vector<vector<int>>, compare> pq;
	for (vector<int> vec : arr) {
		pq.push(vec);
	}

	//pop untill the size of pq is k
	while (pq.size() > k) {
		pq.pop();
	}

	vector<vector<int>> ans;
	while (!pq.empty()) {
		ans.push_back(pq.top());
		pq.pop();
	}
	return ans;
}

int main() {
	/*
	VIDEO LINK:
	QUESTION LINK: https://leetcode.com/problems/k-closest-points-to-origin/
	*/
	vector<vector<int>> points = {{1, 3}, { -2, 2}};
	int k = 1;

	vector<vector<int>> ans = kClosestPointsToOrigin(points, k);
	for (auto ele : ans) cout << ele[0] << " " << ele[1] << endl;
}