#include <bits/stdc++.h>
using namespace std;

//****************************
// NOTE: INPUT FOR CONSTRUCT MATRIX.
// 2
// 3
// 11
// 12
// 13
// 21
// 22
// 23
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

void waveTraversal(vector<vector<int>> arr) {
	for (int j = 0; j < arr[0].size(); j++) {
		if (j % 2 == 0) {
			//even column, row 0 to end
			for (int i = 0; i < arr.size(); i++) {
				cout << arr[i][j] << endl;
			}
		}
		else {
			//odd column, row end to 0
			for (int i = arr.size() - 1; i >= 0; i--) {
				cout << arr[i][j] << endl;
			}
		}
	}
}


int main()
{
	vector<vector<int>> arr;
	arr = constructMatrix();
	displayMatrix(arr);
	cout << "result" << endl;
	waveTraversal(arr);
}