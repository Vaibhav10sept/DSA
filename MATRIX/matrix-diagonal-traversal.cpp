#include <bits/stdc++.h>
using namespace std;

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

void diagonalTraversal(vector<vector<int>> arr) {
	for (int gap = 0; gap < arr.size(); gap++) {
		for (int i = 0, j = gap; j < arr.size(); i++, j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}


int main()
{
	//*********************
	// NOTE: ONLY WORKS FOR SQUARE MATRIX.
	//******************************
	vector<vector<int>> arr;
	arr = constructMatrix();
	displayMatrix(arr);
	cout << "diagonal traversal" << endl;
	diagonalTraversal(arr);
}