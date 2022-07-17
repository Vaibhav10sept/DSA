#include <bits/stdc++.h>
using namespace std;

int minBrickCrossed(vector<vector<int>> arr) {
	//WV
	map<int, int> mp; // x-coordinte --- us "x" me kitne split hai
	//ham maximum no of split nikalege, fir maxSplit ko x-length(arr.size()) se minus kr dege to find min no of brick cross(answer)
	int maxSplit = 0;
	for (vector<int> vec : arr) {
		int preSum = 0; // this will help us find the x-coordinate where a split is presend
		for (int i = 0; i < vec.size() - 1; i++) { //we don't calculate for last val, think WV
			preSum += vec[i];
			mp[preSum]++;
			maxSplit = max(maxSplit, mp[preSum]);
		}
	}
	return arr.size() - maxSplit; 	//ham maximum no of split nikalege, fir maxSplit ko x-length(arr.size()) se minus kr dege to find min no of brick cross(answer)
}

int main() {
	/*
	NOTE: min no of bricks crossed = maximum no of split crossed.
	PREREQUISITE: presum technique
	VIDEO LINK: https://www.youtube.com/watch?v=bKt63YABdNw&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=52
	QUESTION LINK: https://leetcode.com/problems/brick-wall/
	*/
	vector<vector<int>>  wall = {{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2}, {2, 4}, {3, 1, 2}, {1, 3, 1, 1}};
	cout << minBrickCrossed(wall);
}