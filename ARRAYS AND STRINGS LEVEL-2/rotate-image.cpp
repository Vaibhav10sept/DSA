#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>  constructMatrix() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int> (m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	return arr;
}

void displayMatrix(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void rotateImage(vector<vector<int>> arr) {
	//step1. do the transpose
	for (int i = 0; i < arr.size(); i++) {
		for (int j = i; j < arr[0].size(); j++) {
			swap(arr[i][j], arr[j][i]);
		}
	}

	cout << "after transpose " << endl;
	displayMatrix(arr);

	//step2. reverse every row
	for (int i = 0; i < arr.size(); i++) {
		reverse(arr[i].begin(), arr[i].end());
	}
	cout << "after rotation by 90 degree: " << endl;
	displayMatrix(arr);
}

int main() {
	//*********************************
	//STEPS:
	// 1. first transpose the NXN matrix.
	// 2. then reverse every row.
	// VIDEO LINK: https://www.youtube.com/watch?v=pqDZdKd1uLQ&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=22
	// QUESTION:
	// 1. You are given an n x n 2D matrix representing an image.
	// 2. rotate the image by 90 degrees (clockwise).
	// 3. You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
	// 4. DO NOT allocate another 2D matrix and do the rotation.
	//*********************************
	//****************************
// NOTE: INPUT FOR CONSTRUCT MATRIX.
	// 3
	// 3
	// 11
	// 12
	// 13
	// 21
	// 22
	// 23
	// 31
	// 32
	// 33
//*******************************
	vector<vector<int>> arr;
	arr = constructMatrix();
	displayMatrix(arr);
	rotateImage(arr);
}