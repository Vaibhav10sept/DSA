#include<bits/stdc++.h>
using namespace std;


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

		//move kidhar krna hai, ye to same hi rhega binary search jaesa
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
	CEIL: age value(k) present hai to ceil vahi value hai
	otherwise Ceil is bade me sbse chota means 'k' se jo bhi badi
	values hai unme se jo sbse chota hoga vo Ceil hoga.

	PREREQUISITE:
	VIDEO LINK:
	*/
	vector<int> arr =  {1, 2, 8, 10, 10, 12, 19};
	int k = 11; //op --> 2
	cout << FindCeilOfAnElementInASortedArray(arr, k) << endl;
}