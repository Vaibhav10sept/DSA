#include <bits/stdc++.h>
using namespace std;

int battleshipsInABoard(vector<vector<char>> arr) {
	int countOfBattleShips = 0;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			if (arr[i][j] == 'X')
			{
				if (i == 0 and j == 0) {
					countOfBattleShips++;
				}
				else if (i == 0) {
					if (arr[i][j - 1] != 'X') {
						countOfBattleShips++;
					}
				}
				else if (j == 0) {
					if (arr[i - 1][j] != 'X') {
						countOfBattleShips++;
					}
				}
				else { // any other cell rather than 0th row or 0th column
					if (arr[i][j - 1] != 'X' and arr[i - 1][j] != 'X') {
						countOfBattleShips++;
					}
				}
			}
		}
	}
	return countOfBattleShips;
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=DCa04eCUhx0&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=65
	// LEETCODE LINK: https://leetcode.com/problems/battleships-in-a-board/
	//*********************************
	vector<vector<char>> arr = {{'X', '.', '.', 'X'}, {'.', '.', '.', 'X'}, {'.', '.', '.', 'X'}};
	cout << battleshipsInABoard(arr);
}