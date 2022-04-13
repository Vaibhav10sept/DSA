#include <bits/stdc++.h>
using namespace std;


void rec( int n, int row, int col,  string asf, vector < vector<int>> &arr, vector<vector<bool>> &visit) {
	// cout << "run";id
	if (row == n || col == n || row < 0 || col < 0 ||  visit[row][col] == true || arr[row][col] == 0) return;
	if (row == n - 1 and col == n - 1) {
		cout << asf << endl;
		return;
	}
	visit[row][col] = true;
	rec( n, row - 1, col,  asf + "U", arr, visit);
	rec( n, row + 1, col,  asf + "D", arr, visit);
	rec( n, row , col - 1,  asf + "L", arr, visit);
	rec( n, row , col + 1,  asf + "R", arr, visit);
	visit[row][col] = false;
}

int main() {
	int n;
	cin >> n;
	vector <vector<int>>arr( n , vector<int> (n));
	vector <vector<bool>>visit( n , vector<bool> (n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];

		}
	}
	cout << n << endl;

	rec( n, 0, 0, "", arr, visit);
}