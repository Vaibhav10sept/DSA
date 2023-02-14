#include <bits/stdc++.h>
using namespace std;

bool recursiveExplore(vector<vector<char>> arr, int i, int j, int idx, string word) {
	//base cases starts
	if (idx == word.size()) return true;
	if (i<0 or j<0 or i >= arr.size() or j >= arr[0].size()) return false;
	if (word[idx] != arr[i][j]) return false;
	if (arr[i][j] == '@') return false;
	//base cases over

	char myChar = arr[i][j];
	arr[i][j] = '@'; //this will work as a visited array, '@' represent that this cell is visited

	bool res = recursiveExplore(arr, i + 1, j, idx + 1, word) or recursiveExplore(arr, i - 1, j, idx + 1, word) or recursiveExplore(arr, i, j + 1, idx + 1, word) or recursiveExplore(arr, i, j - 1, idx + 1, word);
	//backtrack
	arr[i][j] = myChar;
	return res;
}

bool wordSearch(vector<vector<char>> arr, string word) {
	int n = arr.size();
	int m = arr[0].size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == word[0]) {
				if (recursiveExplore(arr, i, j, 0, word)) {
					return true;
				}
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