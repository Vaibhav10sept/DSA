#include <bits/stdc++.h>
using namespace std;

int islandPerimeter(vector<vector<int>> arr) {
	int ans = 0;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i][j] == 1) {
				ans += 4;

				// check for upper cell
				if (i > 0 and arr[i - 1][j] == 1) {
					ans -= 2;
				}

				//check for left cell
				if (j > 0 and arr[i][j - 1] == 1) {
					ans -= 2;
				}
			}

		}
	}
	return ans;
}

int main() {
	//*********************************
	// SIMILAR: battleship in a board
	// VIDEO LINK: https://www.youtube.com/watch?v=Umnh9qUnZas&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=63
	// LEETCODE LINK: https://leetcode.com/problems/island-perimeter/
	//*********************************
	vector<vector<int>> grid = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
	cout << islandPerimeter(grid);
}