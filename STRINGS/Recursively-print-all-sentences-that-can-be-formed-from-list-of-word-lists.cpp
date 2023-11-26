#include <bits/stdc++.h>
using namespace std;

void displayMatrix(vector<vector<string>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

vector<vector<string>> rec(int row, vector<vector<string>> &arr) {
	// * NOTE: i worte myself no video no reading
	if (row == arr.size() - 1) {
		vector<vector<string>> base;
		for (int j = 0; j < arr[0].size(); j++) {

			base.push_back({arr[row][j]});
		}


		// cout << "pr " << endl;
		// for (auto vec : base) {
		// 	for (auto ele : vec) cout << ele << endl;
		// }
		// cout << endl;

		return base;
	}

	vector<vector<string>> RecAns = rec(row + 1, arr);
	vector<vector<string>> currAns;

	for (int j = 0; j < arr[row].size(); j++) {
		for (auto vec : RecAns) {
			// cout << "vec " << RecAns.size() << endl;
			// cout << "arr[row][j] "  << arr[row][j] << endl;
			vector<string> temp;
			temp.push_back(arr[row][j]);
			for (auto ele : vec) {
				temp.push_back(ele);
			}
			currAns.push_back(temp);

		}
	}

	return currAns;
}

vector<vector<string>> recForm(vector<vector<string>> arr) {
	// * NOTE: i worte myself no video no reading
	vector<vector<string>> ans = rec(0, arr);
	return ans;
}

int main() {
	/************************************
	 * NOTE: i worte myself no video no reading
	 * QUESTION: https://practice.geeksforgeeks.org/problems/recursively-print-all-sentences-that-can-be-formed-from-list-of-word-lists/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
	// VIDEO LINK:
	//************************************/
	vector<vector<string>> L =
	{
		{"you", "we", "human"},
		{"have", "are", "good"},
		{"sleep" , "eat", "drink"}
	};
	vector<vector<string>> ans = recForm(L);
	displayMatrix(ans);
}


