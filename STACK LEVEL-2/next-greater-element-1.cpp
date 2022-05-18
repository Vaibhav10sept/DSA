#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement1(vector<int> arr1, vector<int> arr2) {
	int n = arr2.size();
	vector<int> nextGreaterNumber(n);
	vector<int> ans;
	stack<int> st; //store the actual value

	st.push(arr2[n - 1]);
	nextGreaterNumber[n - 1] = -1;
	//traverse from right of arr2
	for (int i = n - 2; i >= 0; i--) {
		while (!st.empty() and st.top() < arr2[i]) st.pop();
		if (st.empty()) nextGreaterNumber[i] = -1;
		else nextGreaterNumber[i] = st.top();
		st.push(arr2[i]);
	}

	//create map as key--> number, value-->next greater number
	map<int, int> mp;
	for (int i = 0; i < arr2.size(); i++) {
		mp[arr2[i]] = nextGreaterNumber[i];
	}

	// for (auto ele : nextGreaterNumber)cout << ele << " ";

	//running query using arr1 and map...see question on leetcode
	for (int ele : arr1) {
		ans.push_back(mp[ele]);
	}
	return ans;
}

int main() {
	/*
	LEETCODE LINK: https://leetcode.com/problems/next-greater-element-i/
	*/
	vector<int> nums1 = {2, 4};
	// vector<int> nums2 = {1, 3, 4, 2};
	vector<int> nums2 = {1, 2, 3, 4};
	vector<int> ans = nextGreaterElement1(nums1, nums2);
	cout << "res" << endl;
	for (auto ele : ans)cout << ele << " ";
}