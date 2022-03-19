#include <bits/stdc++.h>
using namespace std;

vector<string> getMazePathWithJumps(int startRow, int startCol, int endRow, int endCol) {
	if (startRow == endRow && startCol == endCol) {
		vector<string> baseResult;
		baseResult.push_back("");
		return baseResult;
	}
	if (startRow > endRow || startCol > endCol) {
		vector<string> baseResult;
		return baseResult;
	}
	//ms = move size
	vector<string> myResult;

	// horizontal moves
	for (int ms = 1; ms <= endCol; ms++) {
		vector<string> hpaths = getMazePathWithJumps(startRow, startCol + ms, endRow, endCol);
		for (string val : hpaths) {
			char intToChar = ms + '0';
			string s;
			s = intToChar;
			myResult.push_back("h" + s  + val);

		}
	}

	//vertical moves
	for (int ms = 1; ms <= endRow; ms++) {
		vector<string> vpaths = getMazePathWithJumps(startRow + ms, startCol, endRow, endCol);
		for (string val : vpaths) {
			char intToChar = ms + '0';
			string s;
			s = intToChar;

			myResult.push_back("v" + s + val);

		}
	}

	//diagonal moves
	for (int ms = 1; ms <= endRow && ms <= endCol; ms++) {
		vector<string> dpaths = getMazePathWithJumps(startRow + ms, startCol + ms, endRow, endCol);
		for (string val : dpaths) {
			char intToChar = ms + '0';
			string s;
			s = intToChar;
			myResult.push_back("d" + s + val);

		}
	}
	return myResult;
}



int main()
{
	//********************************
	// QUESTION VIDEO LINK: https://www.youtube.com/watch?v=VaGBRiSdtFI&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=404
	//***********************************
	vector<string> ans;
	ans = getMazePathWithJumps(1, 1, 3, 3);
	for (auto val : ans) cout << val << endl;
}