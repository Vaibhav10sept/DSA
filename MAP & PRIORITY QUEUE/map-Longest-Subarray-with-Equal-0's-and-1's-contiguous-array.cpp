#include <bits/stdc++.h>
using namespace std;

int contiguousArray(vector<int> arr) {
	//LOGIC: we are treating 0 as -1 (WV for better understanding)
	map<int, int> mp; //sum,index
	int maxLen = 0;
	int sum = 0;

	mp[0] = -1;

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == 0) sum += -1;
		else sum += arr[i];

		if (mp.find(sum) == mp.end()) { //nhi mila
			mp[sum] = i;
		}
		else { //mil gya
			int len = i - mp[sum];
			if (len > maxLen) maxLen = len;
		}
	}
	return maxLen;
}

int main() {
	/*
	PREREQUISITE: some logic is similar to longest subarray with 0 sum
	VIDEO LINK: https://www.youtube.com/watch?v=1WugaISSWx8&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=32
	QUESTION: https://leetcode.com/problems/contiguous-array/
	*/
	vector<int> arr = {0, 1, 0}; //op:4
	cout << "ans " << contiguousArray(arr);
}