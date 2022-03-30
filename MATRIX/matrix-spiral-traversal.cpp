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

void spiralTraversal(vector<vector<int>> arr) {
	int minr = 0;
	int minc = 0;
	int maxr = arr.size() - 1 ;
	int maxc = arr[0].size() - 1;

	int totalElement = arr.size() * arr[0].size();
	int cnt = 1;
	while (cnt <= totalElement) {
		//left wall
		for (int i = minr; i <= maxr && cnt <= totalElement; i++) {
			cout << arr[i][minc] << endl;
			cnt++;
		}
		minc++;

		//bottom wall
		for (int i = minc; i <= maxc && cnt <= totalElement; i++) {
			cout << arr[maxr][i] << endl;
			cnt++;

		}
		maxr--;

		//right wall
		for (int i = maxr; i >= minr && cnt <= totalElement; i--) {
			cout << arr[i][maxc] << endl;
			cnt++;

		}
		maxc--;

		//top wall
		for (int i = maxc; i >= minc && cnt <= totalElement; i--) {
			cout << arr[minr][i] << endl;
			cnt++;

		}
		minr++;
	}
}


int main()
{
	vector<vector<int>> arr;
	arr = constructMatrix();
	displayMatrix(arr);
	cout << "result" << endl;
	spiralTraversal(arr);
}