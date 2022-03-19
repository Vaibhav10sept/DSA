#include <bits/stdc++.h>
using namespace std;

int validCandidate(vector<int> arr) {
	//this will return the potential candidate for majority element
	int val = arr[0];
	int count = 1;

	for (int i = 1; i < arr.size(); i++)  {
		if (arr[i] == val) {
			count++;
		}
		else {
			count--;
		}

		if (count == 0) {
			val = arr[i];
			count = 1;
		}
	}

	return val;
}

int majorityElement1MooreVotingAlgo(vector<int> arr) {
	int validCandidateForMajorityElement = validCandidate(arr); //this will return the potential candidate for majority element

	//now count the freq of validCandidateForMajorityElement
	int count = 0;
	for (int ele : arr) {
		if (ele == validCandidateForMajorityElement) count++;
	}

	// check if the count is greater than arr.size()/2
	if (count > arr.size() / 2) {
		return validCandidateForMajorityElement;
	}
	//no majority element found
	else return -1;
}

int main() {
	//*********************************
	// https: https://www.youtube.com/watch?v=u3A64HQq_Dw&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=4
	// QUESTION:
// 1. Give an array of size 'n'.
// 2. Find Majority element and print it(if exist), otherwise print "No Majority Element exist".
// 3. Majority element-> if frequency of an element is more than n/2, then that element is majority element.
// 3. Note : solve the problem in linear time and in O(1) space.
	//*********************************
	vector<int> arr = {1, 1, 5, 5, 3, 6};
	int majorityElement = majorityElement1MooreVotingAlgo(arr);
	if (majorityElement != -1) {
		cout << "majority element is: " << majorityElement << endl;
	}
	else {
		cout << "No majority element found";
	}
}