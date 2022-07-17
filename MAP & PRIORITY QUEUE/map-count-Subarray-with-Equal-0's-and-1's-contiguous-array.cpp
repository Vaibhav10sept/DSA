#include <bits/stdc++.h>
using namespace std;

int countContiguousArray(vector<int> arr) {
	//LOGIC: we are treating 0 as -1 (WV for better understanding)

	map<int, int> mp; //sum,freq
	int countSubarrays = 0;
	int sum = 0;

	mp[0] = 1; //means,0 sum ki freq 1 hai(think, CS)

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == 0) sum += -1; //0 ko -1 treat kr rhe h(logic)
		else sum += arr[i];

		if (mp.find(sum) == mp.end()) { //nhi mila
			mp[sum] = 1;
		}
		else { //mil gya
			countSubarrays += mp[sum];
			mp[sum]++;
		}
	}
	return countSubarrays;
}

int main() {
	/*
	PREREQUISITE: map-Longest-Subarray-with-Equal-0's-and-1's-contiguous-array
	VIDEO LINK: https://www.youtube.com/watch?v=svMdY6wlQ6I&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=33
	QUESTION: https://leetcode.com/problems/contiguous-array/
	*/
	vector<int> arr = {0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1}; //op:4
	cout << "ans " << countContiguousArray(arr);
}