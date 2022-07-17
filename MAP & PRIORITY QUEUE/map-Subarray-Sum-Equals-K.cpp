#include <bits/stdc++.h>
using namespace std;

int countOfSubarraySumEqualsK(vector<int> arr, int k) {
	//LOGIC: we use presum technique here.
	//WV: watch video
	int sum = 0;
	int count = 0;
	map<int, int> mp; //sum,freq.
	mp[0] = 1; //think, very imp, watch video
	for (int ele : arr) {
		sum += ele;
		if (mp.find(sum - k) != mp.end()) { //found
			//means, sum - k exist krta h, we found subarray having k sum
			count += mp[sum - k];
		}
		mp[sum]++;
	}
	return count;
}

int main() {
	/*
	PREREQUISITE: count Subarray With 0 Sum
	QUESTION LINK: https://leetcode.com/problems/subarray-sum-equals-k/
	VIDEO LINK: https://www.youtube.com/watch?v=20v8zSo2v18&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=28
	*/
	vector<int> arr = {1, 1, 1};
	int k = 2;
	cout << countOfSubarraySumEqualsK(arr, k);
}