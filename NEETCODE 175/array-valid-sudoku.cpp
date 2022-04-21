#include <bits/stdc++.h>
using namespace std;

bool validSudoku(vector<vector<string>> arr) {
	set<string> rows[9];
	set<string> cols[9];
	set<string> square[3][3];

	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			if (arr[i][j] != ".") {
				//if arr[i][j] is found in the rows,cols,square map respectively then return false
				if (rows[i].find(arr[i][j]) != rows[i].end() or cols[j].find(arr[i][j]) != cols[j].end() or square[i / 3][j / 3].find(arr[i][j]) != square[i / 3][j / 3].end()) {
					cout << i << j << endl;
					if (rows[i].find(arr[i][j]) != rows[i].end() ) cout << "Fir";
					if (cols[j].find(arr[i][j]) != cols[j].end() ) cout << "sec";

					return false;
				}
				//add the arr[i][j] in rows,cols and square
				rows[i].insert(arr[i][j]);
				cols[j].insert(arr[i][j]);
				square[i / 3][j / 3].insert(arr[i][j]);
			}
		}
	}
	return true;
}

int main() {
	/*
	*********************************
	NOTE: we are using set here.
	VIDEO LINK: https://www.youtube.com/watch?v=TjFXEUCMqI8&t=2s
	LEETCODE LINK: https://leetcode.com/problems/valid-sudoku/
	*********************************
	*/
	vector<vector<string>> board =
	{	{"5", "3", ".", ".", "7", ".", ".", ".", "."}
		, {"6", ".", ".", "1", "9", "5", ".", ".", "."}
		, {".", "9", "8", ".", ".", ".", ".", "6", "."}
		, {"8", ".", ".", ".", "6", ".", ".", ".", "3"}
		, {"4", ".", ".", "8", ".", "3", ".", ".", "1"}
		, {"7", ".", ".", ".", "2", ".", ".", ".", "6"}
		, {".", "6", ".", ".", ".", ".", "2", "8", "."}
		, {".", ".", ".", "4", "1", "9", ".", ".", "5"}
		, {".", ".", ".", ".", "8", ".", ".", "7", "9"}
	};

	bool ans = validSudoku(board);
	if (ans) cout << "true";
	else cout << "false";
}