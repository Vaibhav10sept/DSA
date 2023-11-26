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

void rec(int ind, int sum, vector<int> currAns, vector<int> &arr, int target, vector<vector<int>> &ans) {
	if (sum > target or ind > arr.size()) return;
	if (ind == arr.size()) {
		if (sum == target) {
			// currAns.pop_back();
			ans.push_back(currAns);
		}
		return;
	}
	//BC ends

	//recursive calls
	//take not increasing ind
	currAns.push_back(arr[ind]);
	rec(ind, sum + arr[ind], currAns, arr, target, ans);

	//backtrack
	currAns.pop_back();

	//but here we have to stop the generation of duplicate subsets
	while (ind + 1 < arr.size() and arr[ind] == arr[ind + 1]) {
		ind++;
	}

	//not taking increasing ind
	rec(ind + 1, sum, currAns, arr, target, ans);
	return;
}

//Function to return a list of indexes denoting the required
//combinations whose sum is equal to given number.
vector<vector<int> > combinationSum(vector<int> arr, int target) {
	sort(arr.begin(), arr.end()); //requirement in the given question, bina sort kre bhi shi answer ata, but format me sorted bola hai
	vector < vector<int>> ans;
	vector<int> currAns;
	rec(0, 0, currAns, arr, target, ans);
	return ans;
}

int main()
{
	/*
	SAME CODE: backtracking combination sum 2
	NOTE: I wrote this code
	VIDEO: https://www.youtube.com/watch?v=Vn2v6ajA7U0
	QUESTION: https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1
	*/
	vector<int> arr = {8, 1, 8, 6, 8};
	int target = 12;
	vector<vector<int>> ans = combinationSum(arr, target);
	displayMatrix(ans);
}