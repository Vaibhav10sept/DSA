#include <bits/stdc++.h>
using namespace std;

int recursiveHelper(vector<int> arr, int idx, string path, string &ansPath) {
	//******************
	// this is my own solution
	//THIS recursive-memoized solution WILL GIVE YOU TLE, A DP SOLUTION IS ALSO THERE
	//*************************

	if (idx == arr.size() - 1) {
		path += to_string(arr[idx]);
		if (path.size() < ansPath.size() or ansPath.size() == 0) {
			ansPath = path;
		}
		return 0;
	}

	int jump = arr[idx];
	int minJumps = 1e9;
	for (int i = 1; i <= jump and idx + i < arr.size(); i++) {
		minJumps = min(recursiveHelper(arr, i + idx, path + to_string(arr[idx]), ansPath), minJumps);
	}
	minJumps++;
	return minJumps;
}

int jumpGame2(vector<int> arr) {
	string ansPath = "";
	int ans = recursiveHelper(arr, 0, "", ansPath);
	cout << "path " << ansPath << endl;
	return ans;
}

int main() {
	/**************************
	 * STRONG PREREQUSITE: jump game dp solution
	NOTE: THIS IS THE DP SOLUTION MORE SOLUTION ARE ALSO THERE
	 * LEETCODE LINK: https://leetcode.com/problems/jump-game-ii/
	 VIDEO LINK: https://www.youtube.com/watch?v=phgjL7SbsWs
	 * ******************************/
	// vector<int> nums = {3, 3, 0, 2, 1, 2, 4, 2, 0, 0};
	vector<int> nums = {2, 3, 1, 1, 4};
	cout << "Min no of jumps " << jumpGame2(nums);
}