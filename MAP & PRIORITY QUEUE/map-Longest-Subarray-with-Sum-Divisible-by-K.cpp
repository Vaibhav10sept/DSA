#include <bits/stdc++.h>
using namespace std;

int LongestSubarraywithSumDivisiblebyK(vector<int> arr, int k) {
	//WV: watch video
	int sum = 0;
	int maxLengthSubarray = 0;
	map<int, int> mp; //remainder,index.
	mp[0] = -1; //think, very imp, watch video

	for (int i = 0; i < arr.size(); i++) {
		sum += arr[i];

		int rem = sum % k;
		if (rem < 0) rem += k; //convert negative rem to positive rem(WV, CS). NOTE: this is very important step otherwise you'll get wrong answer.

		if (mp.find(rem) != mp.end()) { //found
			int idx = mp[rem];
			maxLengthSubarray = max(i - idx, maxLengthSubarray);
		}
		else {
			mp[rem] = i;
		}
	}
	return maxLengthSubarray;
}

int main() {
	/*
	PREREQUISITE: check if array pair are divisible by k
	PREREQUISITE: format is similar to "subarray sum equals k"
	QUESTION LINK: https://www.geeksforgeeks.org/longest-subarray-sum-divisible-k/
	VIDEO LINK: https://www.youtube.com/watch?v=GrV3MTR_Uk0&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=30
	*/
	vector<int> arr = {2, 7, 6, 1, 4, 5};
	int k = 3;
	cout << "ans " << LongestSubarraywithSumDivisiblebyK(arr, k);
}