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

void countSort(vector<vector<int>> &arr, int r, int c) {
	int n = arr.size();
	int m = arr[0].size();

	vector<int> freq(101, 0); //given in question, value in matrix does not exceed 100.
	int i = r;
	int j = c;
	//fill freq vector
	while (i < n and j < m) {
		freq[arr[i][j]]++;
		i++;
		j++;
	}

	//sorting using count sort logic.
	i = r;
	j = c;
	for (int k = 1; k < freq.size(); k++) {
		while (freq[k]--) {
			arr[i][j] = k;
			i++;
			j++;
		}
	}
}

void sortMatrixDiagonally(vector<vector<int>> arr) {
	int n = arr.size();
	int m = arr[0].size();
	//for 0 th row
	for (int j = 0; j < m; j++) {
		countSort(arr, 0, j);
	}

	// for 0th column, leaving the 0th, "i" is starting from 1 (think)
	for (int i = 1; i < n; i++) {
		countSort(arr, i, 0);
	}

	displayMatrix(arr);
}

int main() {
	//*********************************
	// PREREQUISITE: count sort(before)(becoz elements are in range given in question)
	// VIDEO LINK: https://www.youtube.com/watch?v=MwDM7XYjidc&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=58
	// LEETCODE LINK: https://leetcode.com/problems/sort-the-matrix-diagonally/
	//*********************************
	vector<vector<int>> mat = {{3, 3, 1, 1}, {2, 2, 1, 2}, {1, 1, 1, 2}};
	displayMatrix(mat);
	cout << "after diagonally sorting" << endl;
	sortMatrixDiagonally(mat);

}