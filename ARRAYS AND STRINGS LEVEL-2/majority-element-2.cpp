#include <bits/stdc++.h>
using namespace std;

vector<int> validCandidate(vector<int> arr) {
	//this will return the potential candidates for majority element 2
	vector<int> ans;
	int val1 = arr[0];
	int count1 = 1;

	int val2 = arr[0]; //assign any random value from arr
	int count2 = 0; //rem(think)

	for (int i = 1; i < arr.size(); i++)  {
		if (arr[i] == val1) {
			count1++;
		}
		else if (arr[i] == val2) {
			count2++;
		}
		else { // arr[i] not equal to val1 and val2
			if (count1 == 0) {
				val1 = arr[i];
				count1 = 1;
			}
			else if (count2 == 0 ) {
				val2 = arr[i];
				count2 = 1;
			}
			else { //both count1 and count2 are non zero.
				count1--;
				count2--;
			}
		}
	}

	ans.push_back(val1);
	if (val1 != val2) {
		ans.push_back(val2);
	}
	return ans;
}

vector<int> majorityElement2(vector<int> arr) {
	vector<int> validCandidatesForMajorityElement = validCandidate(arr); //this will return the potential candidate for majority element
	vector<int> ans;

	//now count the freq of validCandidatesForMajorityElement
	int count1 = 0;
	int count2 = 0;
	for (int ele : arr) {
		if (ele == validCandidatesForMajorityElement[0]) count1++;
		else if (ele == validCandidatesForMajorityElement[1]) count2++;
	}

	// check if the count is greater than arr.size()/2
	if (count1 > arr.size() / 3) {
		ans.push_back(validCandidatesForMajorityElement[0]);
	}
	if (count2 > arr.size() / 3) {
		ans.push_back(validCandidatesForMajorityElement[1]);
	}

	return ans;
}

int main() {
	//*********************************
	// NOTE: similar to majorityElement1, we are using moore's voting algorithm
	// NOTE: more than one element can have freq n/3. so return the list of those element
	// NOTE: there can be 0,1 or 2 majority elements.(logic: n%3 = 0,1 or 2)
	// in majorityElement1 n/2 freq element dhundhne the vo ek hi ho skta hai(think)
	// https://www.youtube.com/watch?v=1QybAZMCYhA&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=6
	// QUESTION:
	// 1. Given an integer array of size 'n'.
	// 2. Find all elements that appear more than n / 3 times and return it in an arraylist.
	// 3. Note : solve the problem in linear time and in O(1) space.
	//*********************************
	vector<int> arr = {3, 2, 3, 2, 1};
	vector<int> majorityElement2Ans = majorityElement2(arr);
	if (majorityElement2Ans.size() != 0) {
		cout << "majority element is: " << endl;
		for (auto ele : majorityElement2Ans) cout << ele << " ";
	}
	else {
		cout << "No majority element found";
	}
}