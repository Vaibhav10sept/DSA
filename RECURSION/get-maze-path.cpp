#include <bits/stdc++.h>
using namespace std;

vector<string> getMazePath(int startRow, int startCol, int endRow, int endCol) {
	if (startRow == endRow && startCol == endCol) {
		vector<string> baseResult;
		baseResult.push_back("");
		return baseResult;
	}
	if (startRow > endRow || startCol > endCol) {
		vector<string> baseResult;
		return baseResult;
	}

	vector<string> horizontalMove = getMazePath(startRow, startCol + 1, endRow, endCol);
	vector<string> verticalMove = getMazePath(startRow + 1, startCol, endRow, endCol);


	vector<string> myResult;
	for (string val : horizontalMove) {
		myResult.push_back("h" + val);
	}
	for (string val : verticalMove) {
		myResult.push_back("v" + val);
	}

	return myResult;
}

// void getMazePath(int startRow, int startCol, int endRow, int endCol, string ans) {
// 	if (startRow == endRow && startCol == endCol) {
// 		cout << ans << endl;
// 		return;
// 	}
// 	if (startRow > endRow || startCol > endCol) {
// 		return;
// 	}

// 	getMazePath(startRow, startCol + 1, endRow, endCol, ans + "h");
// 	getMazePath(startRow + 1, startCol, endRow, endCol, ans + "v");

// }



int main()
{
	//********************************
	// QUESTION VIDEO LINK: https://www.youtube.com/watch?v=hMJAlbJIS7E&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=399
	//***********************************

	getMazePath(1, 1, 3, 3, "");
}
