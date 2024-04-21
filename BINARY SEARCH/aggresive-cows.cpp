#include<bits/stdc++.h>
using namespace std;

bool validMinimumDistance(vector<int> arr, int minDist, int cows) {
	int cntCows = 1;
	int lastPlacedCow = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] - lastPlacedCow >= minDist) {
			cntCows++;
			lastPlacedCow = arr[i];
		}
	}
	if (cntCows >= cows) return true;
	return false;
}

int aggresiveCows(vector<int> arr, int k) {
	//watch video recommended
	//search space(jisme hm binary search lgaege) -> min distance between two stalls, jise hme maximize krna h, to search space hmari 0 to diff of min and max position of stall hogi
	//start --> 0
	//end --> diff of min and max postion of stalls in the given arr.
	sort(arr.begin(), arr.end());
	int start = 1; //min distance between two stalls
	int end = arr[arr.size() - 1] - arr[0];  //max - min --> max distance between two stalls
	int ans = 0;
	while (start <= end) {
		int mid = (start + end) / 2;

		if (validMinimumDistance(arr, mid, k)) {
			//we want to maximize the min distance, so move to the right
			ans = mid;
			start = mid + 1; //move right
		}
		else { //move left
			//kyoki ye min distance(mid) possible ni hora, to isse bda kya hi hoga, islie move left to reduce min distance(mid)
		}	end = mid - 1;
	}

	return ans;
}

int main() {
	/*
	SAME PATTERN PROBLEMS:
	1. aggresive cows
	2. allocate minimum number of pages
	3. painter's partition problem
	4. split array largest sum
	MUST PREREQUISITE: allocate minimum number of pages
	NOTE: array can be unsorted.
	QUESTION: https://takeuforward.org/data-structure/aggressive-cows-detailed-solution/
	NOTE: one of the best question of binary search
	VIDEO LINK: https://www.youtube.com/watch?v=wSOfYesTBRk&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=71
	*/
	vector<int> stalls = {1, 2, 8, 4, 9};
	int k = 3; // no of cows

	cout << aggresiveCows(stalls, k);
}