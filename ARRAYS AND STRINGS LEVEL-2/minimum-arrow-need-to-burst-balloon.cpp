#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int> &a, vector<int> &b) {
	return a[1] < b[1];
}

int minArrowToBurstBalloon(vector<vector<int>> arr) {
	//sorting with respect to the end point
	sort(arr.begin(), arr.end(), comparator); //sorting on the basis of inc endpoitn
	int arrowCount = 1;
	int endPoint = arr[0][1];
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i][0] > endPoint) {
			arrowCount++;
			endPoint = arr[i][1];
		}
		else {
			//do nothing
		}
	}
	return arrowCount;
}

int main() {
	//*********************************
	// PREREQUISITE: merge intervals
	// LEETCODE LINK: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
	// VIDEO LINK: https://www.youtube.com/watch?v=Z9o-lqwgSWA&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=73
	//*********************************
	vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
	// vector<vector<int>> points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
	cout << minArrowToBurstBalloon(points);
}