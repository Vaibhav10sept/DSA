#include <bits/stdc++.h>
using namespace std;

bool isReflected(vector<vector<int>> arr) {
	//this code is copied from net.
	if (arr.size() < 2)
		return true;

	map<int, set<int>> mp; //x-coordinate --> set containing all the y-coordinate.

	int minValue = INT_MAX;
	int maxValue = INT_MIN;

	for (vector<int> arr : arr) {
		minValue = min(minValue, arr[0]);
		maxValue = max(maxValue, arr[0]);
		//filling the map
		mp[arr[0]].insert(arr[1]);
	}

	int doublebar = (minValue + maxValue); //this is 2*mirror(think, WV)
	for (int i = 0; i < arr.size(); i ++) {
		int x = arr[i][0];
		int y = arr[i][1];
		int anotherX = doublebar - x;
		if (mp.find(anotherX) == mp.end()) { //not found
			return false;
		}
		if (mp[anotherX].find(y) == mp[anotherX].end()) { //not found in set inside map
			return false;
		}
	}

	return true;
}

int main() {
	/*
	NOTE:
	VIDEO LINK: https://www.youtube.com/watch?v=ArsRc6Wqy1o&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=61
	QUESTION LINK: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/hashmap-and-heaps/line-reflection-official/ojquestion
	*/
	vector<vector<int>> arr = {{1, 1}, { -1, 1}};
	cout << isReflected(arr);
}