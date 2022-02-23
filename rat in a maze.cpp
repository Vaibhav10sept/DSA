#include <bits/stdc++.h>
using namespace std;
const int n = 1000;
int arr[n][n];
bool visit[n][n];

void rec( int n, int row, int col,  string asf) {
//bc
	if (row == n || col == n || row < 0 || col < 0 || arr[row][col] == 1) return;
	if (row == n - 1 and col == n - 1) {
		cout << asf << endl;
		return;
	}
	visit[row][col] = true;
	rec( n, row - 1, col,  asf + "U");
	rec( n, row + 1, col,  asf + "D");
	rec( n, row , col - 1,  asf + "L");
	rec( n, row , col + 1,  asf + "R");

	visit[row][col] = false;
}

int main() {
	int n;
	cin >> n;
	// int arr[n][n];
	// bool visit[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			visit[i][j] = false;
		}
	}
	rec( n, 0, 0, "");
}