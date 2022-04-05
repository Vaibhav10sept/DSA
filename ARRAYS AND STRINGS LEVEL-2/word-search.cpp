#include <bits/stdc++.h>
using namespace std;

int di[] = { -1, 0, 1, 0}; //{up,left,down,right} --> for i
int dj[] = {0, -1, 0, 1}; //{up,left,down,right} --> for j

bool recursiveExplore(vector<vector<char>> arr, int i, int j, int idx, string word) {
	//base cases starts
	if (idx == word.size()) return true;
	if (i<0 or j<0 or i >= arr.size() or j >= arr[0].size()) return false;
	if (word[idx] != arr[i][j]) return false;
	//base cases over

	char myChar = arr[i][j];
	arr[i][j] = '@'; //this will work as a visited array, '@' represent that this cell is visited

	//recursively call in all four directions
	for (int d = 0; d < 4; d++) {
		bool res = recursiveExplore(arr, i + di[d], j + dj[d], idx + 1, word);
		if (res) {
			arr[i][j] = myChar;
			return true;
		}
	}
	arr[i][j] = myChar;
	return false;
}

bool wordSearch(vector<vector<char>> arr, string word) {
	int n = arr.size();
	int m = arr[0].size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == word[0]) {
				return recursiveExplore(arr, i, j, 0, word);
			}
		}
	}
	return false;
}

int main() {
	//*********************************
	// NOTE: we use backtracking here.
	// LEETCODE LINK: https://leetcode.com/problems/word-search/
	// VIDEO LINK: https://www.youtube.com/watch?v=_RKupaYOrzI&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=81
	//*********************************
	vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
	string word = "ABCCED";
	bool ans = wordSearch(board, word);
	if (ans) {
		cout << "true";
	}
	else cout << "false";
}