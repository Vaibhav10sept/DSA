#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int> a, vector<int> b) {
	//inc order of departure
	return a[1] < b[1];
}

int maxTrains(vector<vector<int>> arr, int n, int m) {
	// n is the no of platforms

	vector<int> platform(n, -1); //store the end time only
	sort(arr.begin(), arr.end(), comparator);
	int cntOfTrains = 0;
	for (int i = 0; i < arr.size(); i++) {
		vector<int> vec = arr[i];
		int plat = vec[2] - 1;
		if (platform[plat] == -1) {
			platform[plat] = vec[1];
			cntOfTrains++;
		}
		else {
			if (platform[plat] <= vec[0]) {
				cntOfTrains++;
				platform[plat] = vec[1];
			}
		}
	}

	return cntOfTrains;
}

int main() {
	/*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=naDecrj9Cyc
	// QUESTION: https://practice.geeksforgeeks.org/problems/maximum-trains-for-which-stoppage-can-be-provided/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
	//*********************************/
	int n = 3; //no of platforms
	int m = 6; //no of trains
	vector<vector<int>> trains = {{1000, 1030, 1}, {1010, 1030, 1}, {10000, 1020, 2}, {1030, 1230, 2}, {1200, 1230, 3}, {900, 1005, 1}};
	cout << maxTrains(trains, n, m);
}