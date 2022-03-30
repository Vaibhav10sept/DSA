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

void findSaddlePoint(vector<vector<int>> arr) {
	int minRowIdx = 0;
	int maxCol = INT_MIN;
	for (int i = 0; i < arr.size(); i++) {
		minRowIdx = min_element(arr[i].begin(), arr[i].end())  - arr[i].begin();
		for (int j = 0; j < arr[i].size(); j++) {
			maxCol = std::max(maxCol, arr[j][minRowIdx]);
		}
		int minRow = arr[i][minRowIdx];
		if (minRow == maxCol) {
			cout << "saddle point: " << maxCol << endl;
			return;
		}
	}
	cout << "couldn't find any saddle point" << endl;
}

int main()
{
	vector<vector<int>> arr;
	arr = constructMatrix();
	displayMatrix(arr);
	//**************************************
	// NOTE: SADDLE POINT IS A NUMBER WHICH IS MINIMUM IN ITS
	// ROW AND MAXIMUM IN ITS COLUMN.
	// NOTE: THERE CAN BE ONLY ONE SADDLE POINT IN A MATRIX(THINK)
	// NOTE: A SQUARE MATRIX IS GIVEN.
	//**************************************

	findSaddlePoint(arr);
}