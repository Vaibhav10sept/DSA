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

int dfs(int i, int j, vector<vector<int>> &arr, int &uniqueId, unordered_map<int, int> &mp) {
	if (i<0 or j<0 or i >= arr.size() or j >= arr[0].size()) return 0;
	if (arr[i][j] != 1) return 0; //means already visited
	//BC ends

	//marking the cell with the unique id
	arr[i][j] = uniqueId;

	//rec call in all the four direction
	vector<vector<int>> directions = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}};
	int totalArea = 0;
	for (vector<int> dir : directions) {
		int i_ = i + dir[0];
		int j_ = j + dir[1];
		totalArea += dfs(i_, j_, arr, uniqueId, mp);
	}

	return totalArea + 1;
}

int makingLargeIsland(vector<vector<int>> arr) {
	int n = arr.size();
	int uniqueId = 2;
	unordered_map<int, int> mp; //uniqueId, size of that island.

	//har island ko ek unique id di jaege or us island ke sare cells me vo unique id hogi, or map me uss id ke liye uss island ka size store hoga.
	//we are doing some precomputations here.(read above line)(wv)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				int area = dfs(i, j, arr, uniqueId, mp);
				mp[uniqueId] = area;
				uniqueId++;
			}
		}
	}


	//this is edge case for one testcase: if all are 0 in the array
	if (mp.size() == 0) { //means ek bhi 1 ni mila, all are 0
		return 1; //sirf ek 0 ko 1 bna kr hme 1 ka area milega
	}

	int maxArea = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				//get all the unique id from the four directions of i, j
				unordered_set<int> set;
				vector<vector<int>> directions = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}};
				int areaAfterConvertingToOne = 0;
				for (vector<int> dir : directions) {
					int i_ = i + dir[0];
					int j_ = j + dir[1];
					if (i_ >= 0 and j_ >= 0 and i_ < n and j_ < n
					        and arr[i_][j_] != 0 and set.find(arr[i_][j_]) == set.end()) {
						set.insert(arr[i_][j_]);
						areaAfterConvertingToOne += mp[arr[i_][j_]];
					}
				}
				areaAfterConvertingToOne++; //+1 coz, ek size toh ye arr[i][j] ke 0 ko 1 me convert krne pr milega

				//find the maximum area
				maxArea = max(maxArea, areaAfterConvertingToOne);
			}
		}
	}
	if (maxArea == 0) {
		//means koi 0 nhi h arr me
		//means sare 1 hai
		//edge case: agr sare 1 hi ho arr me to vhi maxarea hoga, so return that area only
		return n * n; //n size ka arr h to n*n will return the area of n size arr containing all one.
	}

	return maxArea;
}

int main() {
	/************************************************************
	 * NOTE: we use DFS here
	 * LEETCODE: https://leetcode.com/problems/making-a-large-island/description/
	 VIDEO: https://www.youtube.com/watch?v=lJvsjam1guY
	//************************************************************/
	vector<vector<int>> grid = {{1, 1}, {1, 1}};

	cout << makingLargeIsland(grid);
}