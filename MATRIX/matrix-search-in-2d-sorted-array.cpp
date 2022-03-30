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

void searchInSortedMatrix(vector<vector<int>> arr, int data) {
	int i = 0;
	int j = arr[0].size() - 1;
	// means top right corner pe hai i,j
	while (i < arr.size() && j >= 0) {
		if (data == arr[i][j]) {
			cout << data << " found at " << i << "," << j << endl;
			return;
		}
		else if (data > arr[i][j]) i++;
		else if (data < arr[i][j]) j--;
	}
	cout << data << " not found" << endl;
}

int main()
{
	vector<vector<int>> arr;
	arr = constructMatrix();
	displayMatrix(arr);
	//************************
	//LOGIC: SIMILAR TO BINARY SEARCH
	// NOTE: SQUARE MATRIX IS GIVEN.
	//*****************************
	searchInSortedMatrix(arr, 42);
}