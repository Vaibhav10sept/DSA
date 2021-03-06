#include <bits/stdc++.h>
using namespace std;

void displayMatrix(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void printPascalTriangle(int n) {
	vector<vector<int>> pascal;

	for (int i = 0; i < n; i++) {
		vector<int> row;
		for (int j = 0; j <= i; j++) {
			if (j == 0 or j == i) {
				row.push_back(1);
			}
			else {
				row.push_back(pascal[i - 1][j] + pascal[i - 1][j - 1]);
			}
		}
		pascal.push_back(row);
	}

	displayMatrix(pascal);
}

int main() {
	//*********************************

	//*********************************
	int n = 5;
	printPascalTriangle(n);

}