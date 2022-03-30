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


int main()
{
	//******************************************************
	// LOGIC: FIRST TRANSPOSE(ROW = COL, COL = ROW) AND THEN
	// REVERSE COLUMN
	//**********************************************
	vector<vector<int>> arr;
	arr = constructMatrix();
	displayMatrix(arr);
	//TRANSPOSE
	for (int i = 0; i < arr.size(); i++) {
		//swap in upper triangle only(logic, think about it)
		for (int j = i; j < arr[0].size(); j++) {
			//swap
			swap(arr[i][j], arr[j][i]);
		}
	}

	//REVERSE COLUMNS
	for (int i = 0; i < arr.size(); i++) {
		// int li = 0;
		// int ri = arr[i].size() - 1;

		// while (li < ri) {
		// 	int temp = arr[i][li];
		// 	arr[i][li] = arr[i][ri];
		// 	arr[i][ri] = temp;
		// 	li++;
		// 	ri--;
		// }
		reverse(arr[i].begin(), arr[i].end());
	}
	cout << "after rotation by 90 degree" << endl;
	displayMatrix(arr);
}