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

void transposeOfMXNMatrix(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = i; j < arr[0].size(); j++) {
			swap(arr[i][j], arr[j][i]);
		}
	}
	cout << "after transpose: " << endl;
	displayMatrix(arr);
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=pqDZdKd1uLQ&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=22
	// QUESTION:
	// 1. You have a matrix of N*N Dimension.
	// 2. You have to convert matrix into transpose.
	// 3. Transpose matrix is defined as, matrix flipped over its main diagonal.
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
	transposeOfMXNMatrix(arr);
}