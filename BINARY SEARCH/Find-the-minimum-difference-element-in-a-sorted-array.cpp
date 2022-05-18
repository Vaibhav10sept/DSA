#include<bits/stdc++.h>
using namespace std;

int FindFloorOfAnElementInASortedArray(vector<int> &arr, int k) {
	/*
	FLOOR: age value(k) present hai to floor vahi value hai
	otherwise floor is chote me sbse bada means k se jo chote
	value hai unme se jo sbse bada hoga vo floor hoga.
	*/
	int start = 0;
	int end = arr.size() - 1;
	int validCandidate = INT_MIN; //logic

	while (start <= end) {
		int mid = start + (end - start) / 2; //we are not using (start + end) / 2, to prevent int overflow

		if (arr[mid] <= k) { //this is a valid candidate for floor
			validCandidate = max(validCandidate, arr[mid]);
			//move to right coz we need greatest in smaller(floor)
			start = mid + 1;
		}

		//move kidhar krna hai
		else if (k < arr[mid]) { //move left
			end = mid - 1;
		}
		else if (k > arr[mid]) { //move right
			start = mid + 1;
		}
	}
	return validCandidate;
}

int FindCeilOfAnElementInASortedArray(vector<int> &arr, int k) {
	/*
	Ceil: agr value(k) present hai to Ceil vahi value hai,
	otherwise Ceil is bade me sbse chota means 'k' se jo badi
	values hai unme se jo sbse choga hoga vo Ceil hoga.
	*/
	int start = 0;
	int end = arr.size() - 1;
	int validCandidate = INT_MAX; //logic

	while (start <= end) {
		int mid = start + (end - start) / 2; //we are not using (start + end) / 2, to prevent int overflow

		if (arr[mid] >= k) { //this is a valid candidate for Ceil
			validCandidate = min(validCandidate, arr[mid]);
			//move to left coz we need smaller in greatest(Ceil)
			end = mid - 1;
		}

		//move kidhar krna hai
		else if (k < arr[mid]) { //move left
			end = mid - 1;
		}
		else if (k > arr[mid]) { //move right
			start = mid + 1;
		}
	}
	return validCandidate;
}

int FindTheMinimumDifferenceElementInaSortedArray(vector<int> &arr, int k) {
	// LOGIC: find ceil and floor of k and then return which has the min difference with k
	int ceil = FindCeilOfAnElementInASortedArray(arr, k);
	int floor = FindFloorOfAnElementInASortedArray(arr, k);

	//jiska difference kam hoga, use return krege.
	if ((k - floor) < (ceil - k)) {
		return floor;
	}
	return ceil;
}

int main() {

	/*
	NOTE: this is finding FLOOR and CEIL (think)
	NOTE: min difference element nikalna hai
	PREREQUISITE: FLOOR and CEIL question done before
	VIDEO LINK: https://www.youtube.com/watch?v=8x6dmO6XW8k&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=14
	*/

	vector<int> arr = {2, 5, 10, 12, 15};
	int k = 20;
	cout << FindTheMinimumDifferenceElementInaSortedArray(arr, k) << endl;
}