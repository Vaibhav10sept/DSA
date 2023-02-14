#include <bits/stdc++.h>
using namespace std;

bool isItSafePlaceForaQueen(vector<vector<int>> chess, int row, int col) {
	//check vertically up
	for (int i = row - 1, j = col; i >= 0; i--) {
		if (chess[i][j] == 1) return false;
	}

	//check left diagonal up
	for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
		if (chess[i][j] == 1) return false;
	}

	//check right diagonal up
	for (int i = row - 1, j = col + 1; i >= 0 && j < chess.size(); i--, j++) {
		if (chess[i][j] == 1) return false;
	}

	return true;
}

void nQueen(vector<vector<int>> chess, string ans, int row) {
	if (row == chess.size()) {
		cout << ans << endl;
		return;
	}

	//column ka loop
	for (int col = 0; col < chess[0].size(); col++) {
		if (isItSafePlaceForaQueen(chess, row, col))
		{
			chess[row][col] = 1;
			nQueen(chess, ans + to_string(row) + "-" + to_string(col) + ", ", row + 1);

			//backtrack
			chess[row][col] = 0;
		}
	}
}



int main()
{
	//video link: https://www.youtube.com/watch?v=05y82cP3bJo&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=422
	int n = 4;
	vector<vector<int>> chess(n, vector<int>(n, 0));
	nQueen(chess, "", 0);

}