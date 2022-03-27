#include <bits/stdc++.h>
using namespace std;

vector<int> whereWillBallFall(vector<vector<int>> arr) {
	// nice question(medium) watch video.
	int n = arr.size();
	int m = arr[0].size();
	vector<int> ans(m);

	for (int j = 0; j < m; j++) { //columns
		int currPosition = j;
		int newPosition = -1;
		for (int i = 0; i < n; i++) {
			newPosition = currPosition + arr[i][j];
			if (newPosition < 0 || newPosition >= m
			        || arr[i][currPosition] != arr[i][newPosition]) {
				currPosition = -1;
				break;
			}
			currPosition = newPosition;
		}
		ans[j] = currPosition;
	}
	return ans;
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=qCKXRsIItG8&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=54
	// QUESTION:
// You have a 2-D grid of size m x n representing a box, and you have n balls. The box is open on the top and bottom sides.

// Each cell in the box has a diagonal board spanning two corners of the cell that can redirect a ball to the right or to the left.

// A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and is represented in the grid as 1.
// A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is represented in the grid as -1.
// We drop one ball at the top of each column of the box. Each ball can get stuck in the box or fall out of the bottom. A ball gets stuck if it hits a "V" shaped pattern between two boards or if a board redirects the ball into either wall of the box.

// Return an array answer of size n where answer[i] is the column that the ball falls out of at the bottom after dropping the ball from the ith column at the top, or -1 if the ball gets stuck in the box.
	//*********************************
	vector<vector<int>> grid = {{1, 1, 1, -1, -1}, {1, 1, 1, -1, -1}, { -1, -1, -1, 1, 1}, {1, 1, 1, 1, -1}, { -1, -1, -1, -1, -1}};

	vector<int> ans = whereWillBallFall(grid);
	for (auto ele : ans) cout << ele << " ";
}