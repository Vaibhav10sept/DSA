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

void setMatrixZeroes(vector<vector<int>> arr) {
	int n = arr.size();
	int m = arr[0].size();
	bool isRowZero = false;
	bool isColZero = false;

	//check for 0 in 0th row and column

	//iterating on 0th column
	for (int i = 0; i < n; i++) if (arr[i][0] == 0) isColZero = true;
	//iterating on 0th row
	for (int j = 0; j < m; j++) if (arr[0][j] == 0) isRowZero = true;

	//check for the rest of the cells
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (arr[i][j] == 0) {
				arr[0][j] = 0;
				arr[i][0] = 0;
			}
		}
	}

	//row
	for (int i = 1; i < n; i++) {
		if (arr[i][0] == 0) {
			//set the entire row as 0.
			for (int j = 0; j < m; j++) {
				arr[i][j] = 0;
			}
		}
	}
	//column
	for (int j = 1; j < m; j++) {
		if (arr[0][j] == 0) {
			//set the entire column as 0.
			for (int i = 0; i < n; i++) {
				arr[i][j] = 0;
			}
		}
	}

	//now, fill zero for the 0th row and 0th column using isRowZero and isColZero.
	if (isRowZero) {
		//set entire 0th row as 0
		for (int j = 0; j < m; j++) {
			arr[0][j] = 0;
		}
	}
	if (isColZero) {
		//set the entire 0th col as 0
		for (int i = 0; i < n; i++) {
			arr[i][0] = 0;
		}
	}

	displayMatrix(arr);
}

int main() {
	//*********************************
	// NOTE:
	// LEETCODE LINK: https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/
	// VIDEO LINK: https://www.youtube.com/watch?v=PIs1EArGpIQ&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=76
	//*********************************
	vector<vector<int>>	matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
	setMatrixZeroes(matrix);
}