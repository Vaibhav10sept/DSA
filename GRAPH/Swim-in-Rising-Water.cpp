#include <bits/stdc++.h>
using namespace std;

class Util {
public:
	int r;
	int c;
	int maxSoFar;

	Util(int row, int col, int max) {
		r = row;
		c = col;
		maxSoFar = max;
	}
};

class Comparator {
public:
	bool operator() (Util obj1, Util obj2) {
		//we have to minimize the max in a path
		//return the min
		//min heap
		return obj1.maxSoFar > obj2.maxSoFar;
	}
};

int swimInRisingWater(vector<vector<int>> arr) {
	int n = arr.size();
	//we are using dijsktra's algorithm similar code here.
	//here we have to minimize the maximum in the path, means we have find a path in which the maximum value is minimum
	priority_queue<Util, vector<Util>, Comparator> pq;
	pq.push(Util(0, 0, arr[0][0])); //start from 0,0
	vector<vector<bool>> visited(n, vector<bool>(n, false));

	while (!pq.empty()) {
		Util removed = pq.top();
		pq.pop();
		int row = removed.r;
		int col = removed.c;
		int maxSoFar = removed.maxSoFar;

		//if we reach the last node
		if (row == n - 1 and col == n - 1) {
			//this is the answer
			return max(arr[n - 1][n - 1], maxSoFar);
		}

		if (visited[row][col]) {
			continue;
		}

		//mark visited
		visited[row][col] = true;

		//explore all paths
		vector<vector<int>> directions = {{0, 1}, {1, 0}, { -1, 0}, {0, -1}};
		for (auto dir : directions) {
			int newR = row + dir[0];
			int newC = col + dir[1];

			if (newR >= 0 and newC >= 0 and newR < n and newC < n) {
				pq.push(Util(newR, newC, max(maxSoFar, arr[newR][newC])));
			}
		}
	}
	return -1;
}

int main() {
	/************************************************************
	 * NOTE: I wrote this code after WV
	 * QUESTION: https://leetcode.com/problems/swim-in-rising-water/description/
	 VIDEO: https://www.youtube.com/watch?v=amvrKlMLuGY&t=699s
	//************************************************************/
	vector<vector<int>> grid = {{0, 1, 2, 3, 4}, {24, 23, 22, 21, 5}, {12, 13, 14, 15, 16}, {11, 17, 18, 19, 20}, {10, 9, 8, 7, 6}};
	cout << "ans " << swimInRisingWater(grid);

}