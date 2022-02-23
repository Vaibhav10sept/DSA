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

void exitPointMatrix(vector<vector<int>> arr) {
	int i = 0;
	int j = 0;
	int dir = 0;
	// dir = 0 means move east
	// dir = 1 means move south
	// dir = 2 means move west
	// dir = 3 means move north

	while (true) {
		if (arr[i][j]) dir++;
		dir = dir % 4;
		// cout << i << " " << j << " dir " << dir << " " << arr[i][j] << endl;
		if (dir == 0) { // east
			j++;
		}
		else if (dir = 1) { // south
			i++;
		}
		else if (dir == 2) { // west
			j--;
		}
		else if (dir == 3) {//north
			i--;
		}

		if (i < 0) {
			cout << "1";
			i++;
			break;
		}
		else if (j < 0) {
			cout << "2";

			j++;
			break;
		}
		else if (i == arr.size())
		{
			// cout << "breaK " << i << " " << j << " dir " << dir << endl;
			i--;
			break;
		}
		else if (j == arr[0].size()) {
			cout << "4";

			j--;
			break;
		}
	}
	cout << i << " " << j << endl;
}

int main()
{
	// ************************
	// NOTE: THIS SOLUTION IS NOT GIVING THE CORRECT ANSWER.
	// SOMETHING IS WRONG WITH THE CODE
	//**********************************
	vector<vector<int>> arr;
	arr = constructMatrix();
	displayMatrix(arr);
	cout << "result" << endl;
	exitPointMatrix(arr);
}