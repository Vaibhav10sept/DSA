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
	vector<vector<int>> transposedMatrix(arr[0].size(), vector<int>(arr.size()));

	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			transposedMatrix[j][i] = arr[i][j];
		}
	}
	cout << "after transpose: " << endl;
	displayMatrix(transposedMatrix);
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=wtYv5vg6iD8&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=21
	// QUESTION:
	// 1. You have a matrix of M*N Dimension.
	// 2. You have to return a Transpose matrix, where The transpose of a matrix is the matrix flipped over its main diagonal.
	//*********************************
	//****************************
// NOTE: INPUT FOR CONSTRUCT MATRIX.
// 3
// 4
// 11
// 12
// 13
// 14
// 21
// 22
// 23
// 24
// 31
// 32
// 33
// 34
//*******************************
	vector<vector<int>> arr;
	arr = constructMatrix();
	displayMatrix(arr);
	transposeOfMXNMatrix(arr);
}