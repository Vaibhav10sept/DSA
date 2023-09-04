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

int countLiveNeighbour(vector<vector<int>> arr, int r, int c) {
	int n = arr.size();
	int m = arr[0].size();
	int count = 0;
	for (int i = r - 1; i <= r + 1; i++) {
		for (int j = c - 1; j <= c + 1; j++) {
			//skipping the current index(r,c) and invalid index.
			if ((i == r and j == c) or i<0 or j<0 or i >= n or j >= m) {
				continue;
			}
			if (arr[i][j] == 1 or arr[i][j] == 3) {
				//see point 1) and 3)
				//1 or 3 means originally it was 1.
				count++;
			}
		}
	}
	// return count;
}

void gameOfLife(vector<vector<int>> &arr) {
	/*
	1. LOGIC: for the solution to be in place
	original | new | symbol
	1)	0	 |  0  |   0
	2)	1	 |  0  |   1
	3)	0	 |  1  |   2
	4)	1	 |  1  |   3

	2. LOGIC: turns 1 --> if 2,3 live neighbour, else turns 0
	          turns 0 --> if 3 live neighbour, else remain 0
	*/
	int n = arr.size();
	int m = arr[0].size();

	//FILLING UP THE ARRAY WITH THE SYMBOLS (ABOVE)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int noOfLiveNeighbour = countLiveNeighbour(arr, i, j);
			if (arr[i][j] == 1) { // originally cell is living
				if (noOfLiveNeighbour == 2 or noOfLiveNeighbour == 3) { //it will remain live
					arr[i][j] = 3; // point 4)

				}
			}
			else { //originally cell is dead
				if (noOfLiveNeighbour == 3) { //it dies
					arr[i][j] = 2; //point 3)
				}
			}
		}
	}

	//CONVERSTION SYMBOLS TO THE ACTUALL OUTPUT REQUIRED IN THE ANSWER.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				arr[i][j] = 0;
			}
			else if (arr[i][j] == 2 or arr[i][j] == 3) {
				arr[i][j] = 1;
			}
		}
	}
}


int main()
{
	/*
	LEETCODE LINK: https://leetcode.com/problems/game-of-life/
	VIDEO LINK: https://www.youtube.com/watch?v=fei4bJQdBUQ
	*/
	vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
	gameOfLife(board);
	displayMatrix(board);
}