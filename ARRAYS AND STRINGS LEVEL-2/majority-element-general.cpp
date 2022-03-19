#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElementGeneral(vector<int> arr, int k) {
	vector<int> ans;
	int n = arr.size();

	map<int, int> mp;
	for (int ele : arr) {
		mp[ele]++;
	}

	for (auto i : mp) {
		if (i.second > n / k) {
			ans.push_back(i.first);
		}
	}
	return ans;
}

int main() {
	//*********************************
	// NOTE: prerequisite is majorityElement1 and majorityElement2
	// NOTE: we are using map here.
	// VIDEO LINK: https://www.youtube.com/watch?v=ChK9pQDhIrk&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=7
	// QUESTION:
	// 1. Given an array of size 'N' and an element K.
	// 2. Task is to find all elements that appears more than N/K times in array.
	// 3. Return these elements in an ArrayList in sorted order.
	//*********************************
	vector<int> arr = {3, 1, 2, 2, 1, 2, 3, 3};
	int k = 4;
	vector<int> majorityElementGeneralAns = majorityElementGeneral(arr, k);
	if (majorityElementGeneralAns.size() != 0) {
		cout << "majority elements are: " << endl;
		for (auto ele : majorityElementGeneralAns) cout << ele << " ";
	}
	else {
		cout << "No majority element found";
	}
}