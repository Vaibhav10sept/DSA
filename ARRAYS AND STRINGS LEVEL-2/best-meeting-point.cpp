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

int bestMeetingPoint(vector<vector<int>> &arr) {
	// best meeting point is the median of x-coordinates and y-coordinates
	// for median we need sorted array of x-coordinates and y-coordinates
	vector<int> xCoordinates;
	vector<int> yCoordinates;

	// row wise travesal to get the x-coordinates in sorted order
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			if (arr[i][j] == 1) {
				xCoordinates.push_back(i);
			}
		}
	}

	// column wise travesal to get the y-coordinates in sorted order
	for (int i = 0; i < arr[0].size(); i++) { //column as i<arr[0].size()
		for (int j = 0; j < arr.size(); j++) { //this is loop for row
			if (arr[j][i] == 1) {
				yCoordinates.push_back(i);
			}
		}
	}

	// find the median.
	int medianX = xCoordinates[xCoordinates.size() / 2];
	int medianY = yCoordinates[yCoordinates.size() / 2];

	// calculate distance of all coordinates from the best meeting point(median)
	int distance = 0;
	// for x.
	for (auto ele : xCoordinates) {
		distance += abs(medianX - ele);
	}
	// for y
	for (auto ele : yCoordinates) {
		distance += abs(medianY - ele);
	}
	return distance;
}

int main() {
	//********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=yKVzFQ4fcYA&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=18
	// QUESTION:
	// 1. A group of two or more people wants to meet and minimize the total travel distance.
	// 2. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group.
	// 3. Return min distance where distance is calculated using 'Manhattan Distance',
	// where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
	//*********************************
	vector<vector<int>> arr = {
		{1, 0, 0, 0, 1},
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0}
	};
	cout << bestMeetingPoint(arr) << endl;
}