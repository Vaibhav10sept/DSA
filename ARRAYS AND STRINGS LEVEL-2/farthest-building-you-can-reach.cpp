#include <bits/stdc++.h>
using namespace std;

int farthestBuildingYouCanReach(vector<int> heights, int bricks, int ladders) {
	// nice question(medium) watch video.
	priority_queue<int, vector<int>, greater<int> > pq; //min heap
	for (int i = 0; i < heights.size() - 1; i++) {
		int diff = heights[i + 1] - heights[i];
		if (diff > 0) {
			pq.push(diff);
		}
		if (pq.size() > ladders) {
			//ham bricks minimum height diff ke lie hi use krege(logic)
			bricks -= pq.top();
			pq.pop();
		}
		if (bricks < 0) {
			return i;
		}
	}
	return heights.size() - 1;
}

int main() {
	//*********************************
	//NOTE: priority queue is used here.
	// VIDEO LINK: https://www.youtube.com/watch?v=7LmgzOCnZQk&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=53
	// QUESTION:
// You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.

// You start your journey from building 0 and move to the next building by possibly using bricks or ladders.

// While moving from building i to building i+1 (0-indexed),

// If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
// If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.
// Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.
	//*********************************
	vector<int> heights = {14, 3, 19, 3};
	int bricks = 17;
	int ladders = 0;
	cout << farthestBuildingYouCanReach(heights, bricks, ladders);
}