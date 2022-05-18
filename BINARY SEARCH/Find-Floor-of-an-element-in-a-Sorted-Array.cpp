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

		//move kidhar krna hai, same rhega as binary search
		else if (k < arr[mid]) { //move left
			end = mid - 1;
		}
		else if (k > arr[mid]) { //move right
			start = mid + 1;
		}
	}
	return validCandidate;
}

int main() {
	/*
	FLOOR: age value(k) present hai to floor vahi value hai
	otherwise floor is chote me sbse bada means k se jo chote
	value hai unme se jo sbse bada hoga vo floor hoga.

	PREREQUISITE:
	VIDEO LINK:
	*/
	vector<int> arr =  {1, 2, 8, 10, 10, 12, 19};
	int k = 8; //op --> 2
	cout << FindFloorOfAnElementInASortedArray(arr, k) << endl;
}