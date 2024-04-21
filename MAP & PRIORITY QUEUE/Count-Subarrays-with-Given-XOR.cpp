#include <bits/stdc++.h>
using namespace std;

int countSubarrayWithGivenXOR(vector<int> arr, int k) {
	//LOGIC: formula derivation, WV.
	//FORMULA/LOGIC: similar format to subarray sum equal k, if upto that index the jo bhi xor hoga usko k se xor krke jo value aega use map me dekhna
	//WV: watch video
	int xr = 0;
	map<int, int> mp; //xor, count
	int ans = 0;
	mp[0] = 1; //initializtion, CS, WV

	for (int ele : arr) {
		xr = xr ^ ele;
		int temp = xr ^ k;
		if (mp.find(temp) != mp.end()) { //found
			ans += mp[temp];
		}

		mp[xr]++;
	}

	return ans;
}

int main() {
	/*
	NOTE: this is a derivation problem, that means we derive the formula that we are going to use in this question
	PREREQUISITE: subarray sum equal k
	QUESTION LINK: https://www.codingninjas.com/codestudio/problems/1115652?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
	VIDEO LINK: https://www.youtube.com/watch?v=eZr-6p0B7ME&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=39
	*/
	vector<int> arr = {5, 6, 7, 8, 9};
	int k = 5;
	cout << countSubarrayWithGivenXOR(arr, k);
}