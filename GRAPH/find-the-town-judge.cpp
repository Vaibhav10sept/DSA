#include <bits/stdc++.h>
using namespace std;

int findTownJudge(vector<vector<int>> arr, int n) {
	// * NOTE: wrote it myself no video no reading no help;
	//find the indegree and outdegree
	vector<int> indegree(n, 0);
	vector<int> outdegree(n, 0);

	for (auto vec : arr) {
		indegree[vec[1] - 1]++;
		outdegree[vec[0] - 1]++;
	}

	//iterate through indegree and outdegree
	for (int i = 0; i < indegree.size(); i++) {
		if (indegree[i] == n - 1 and outdegree[i] == 0) return i + 1;
	}

	return -1;
}

int main() {
	/************************************************************
	 * NOTE: wrote it myself no video no reading no help;
	VIDEO LINK:
	QUEST: https://leetcode.com/problems/find-the-town-judge/
	//************************************************************/

	int n = 3;
	// vector<vector<int>> trust = {{1, 3}, {2, 3}};
	vector<vector<int>> trust = {{1, 3}, {2, 3}, {3, 1}};
	cout << "ans " << findTownJudge(trust, n);
}