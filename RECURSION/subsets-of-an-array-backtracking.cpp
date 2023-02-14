#include <bits/stdc++.h>
using namespace std;


void printSubsetsRecursive(vector<int> arr, vector<int> ans, int idx) {
	if (idx >= arr.size()) {
		for (int ele : ans) cout << ele << " ";
		cout << endl;
		return;
	}
	ans.push_back(arr[idx]);
	printSubsetsRecursive(arr, ans, idx + 1);
	//backtrack(think)
	ans.pop_back();
	printSubsetsRecursive(arr, ans, idx + 1);
}

int main()
{
	int test = 10;
	vector<int> arr = {1, 2, 3};
	vector<int> ans;
	printSubsetsRecursive(arr, ans, 0);
}