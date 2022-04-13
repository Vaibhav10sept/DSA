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

vector<vector<int>> spiralMatrix2(int n) {
	vector<vector<int>> arr(n, vector<int>(n));
	int square = pow(n, 2);
	int ele = 1;

	int minr = 0;
	int minc = 0;
	int maxr = n - 1;
	int maxc = n - 1;
	while (ele <= square) {
		//top wall
		for (int i = minc; i <= maxc and ele <= square; i++) {
			arr[minr][i] = ele;
			ele++;
		}
		minr++;

		//right wall
		for (int i = minr; i <= maxr and ele <= square; i++) {
			arr[i][maxc] = ele;
			ele++;
		}
		maxc--;

		//bottom wall
		for (int i = maxc; i >= minc and ele <= square; i--) {
			arr[maxr][i] = ele;
			ele++;
		}
		maxr--;

		//left wall
		for (int i = maxr; i >= minr and ele <= square; i--) {
			arr[i][minc] = ele;
			ele++;
		}
		minc++;
	}
	return arr;
}


int main()
{
	/*
		LEETCODE LINK: https://leetcode.com/problems/spiral-matrix-ii/
	*/
	int n = 3;
	vector<vector<int>> ans = spiralMatrix2(n);
	displayMatrix(ans);
}