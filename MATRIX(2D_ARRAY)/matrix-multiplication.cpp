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
			// int newVal;
			// cin>>newVal;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
vector<vector<int>> matrixMultiplication(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	if (arr1.size() != arr2[0].size()) {
		cout << "incompatible to multiply" << endl;
		vector<vector<int>> arr;
		return arr;
	}
	vector<vector<int>> res(arr1.size(), vector<int>(arr2[0].size(), 0));
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++) {
			int k = 0;
			int ans = 0;
			for (k = 0; k < arr1[0].size(); k++) {
				ans += arr1[i][k] * arr2[k][j];
			}
			res[i][j] = ans;
		}
	}
	return res;
}


int main()
{
	vector<vector<int>> arr1;
	vector<vector<int>> arr2;
	vector<vector<int>> res;

	arr1 = constructMatrix();
	arr2 = constructMatrix();
	cout << "1st matrix" << endl;
	displayMatrix(arr1);
	cout << "2nd matrix" << endl;
	displayMatrix(arr2);
	res = matrixMultiplication(arr1, arr2);
	cout << "resultant matrix" << endl;
	displayMatrix(res);
}