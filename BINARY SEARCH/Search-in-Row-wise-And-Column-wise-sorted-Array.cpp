#include<bits/stdc++.h>
using namespace std;

void SearchinRowwiseAndColumnwiseSortedArray(vector<vector<int>> arr, int k) {
	//start from first row and last column
	//watch video recommended
	int n = arr.size();
	int m = arr[0].size();
	int i = 0;
	int j = m - 1;
	// top right corner pe hai i,j
	while (i < n && j >= 0) {
		if (k == arr[i][j]) {
			cout << k << " found at " << i << "," << j << endl;
			return;
		}
		else if (k > arr[i][j]) i++;
		else if (k < arr[i][j]) j--;
	}
	cout << k << " not found" << endl;
}

int main() {
	/*
	VIDEO LINK:
	*/
	vector<vector<int>> arr =  {{10, 20, 30, 40},
		{15, 25, 35, 45},
		{27, 29, 37, 48},
		{32, 33, 39, 50}
	};
	int k = 50;
	SearchinRowwiseAndColumnwiseSortedArray(arr, k);
}