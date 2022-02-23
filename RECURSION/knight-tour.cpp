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
void knightTour(vector<vector<int>> chess, int row, int col, int move) {
	if (row >= chess.size() || col >= chess[0].size() || row < 0 || col < 0 || chess[row][col] > 0) {
		return;
	}
	if (move == (chess.size() * chess[0].size())) {
		chess[row][col] = move;
		displayMatrix(chess);
		cout << endl;
		chess[row][col] = 0;
		return;
	}
	//total 8 moves are possible think and watch the video
	//video link: https://www.youtube.com/watch?v=SP880DBRJ_8&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=424

	chess[row][col] = move;
	knightTour(chess, row - 2, col + 1, move + 1);
	knightTour(chess, row - 1, col + 2, move + 1);
	knightTour(chess, row + 1, col + 2, move + 1);
	knightTour(chess, row + 2, col + 1, move + 1);
	knightTour(chess, row + 2, col - 1, move + 1);
	knightTour(chess, row + 1, col - 2, move + 1);
	knightTour(chess, row - 1, col - 2, move + 1);
	knightTour(chess, row - 2, col - 1, move + 1);

	//backtrack
	chess[row][col] = 0;


}



int main()
{
	//video link: https://www.youtube.com/watch?v=SP880DBRJ_8&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=424
	int n = 5;
	vector<vector<int>> chess(n, vector<int>(n, 0));
	knightTour(chess, 0, 2, 1);

}