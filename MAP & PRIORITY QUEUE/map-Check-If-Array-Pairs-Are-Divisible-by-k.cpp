
#include <bits/stdc++.h>
using namespace std;

bool checkIfArrayPairIsDivByK(vector<int> arr, int k) {
	map<int, int> remainderFreqMap;

	for (int val : arr) {
		// int rem = ((val % k) + k) % k;
		int rem = val % k;
		//below,negative remainder ko positive me convert kia h.
		if (rem < 0) rem += k; //to handle negative remainder
		remainderFreqMap[rem]++;
	}

	// for (auto it : remainderFreqMap) cout << it.first << " " << it.second << endl;

	for (int val : arr) {
		int rem = val % k;
		//NOTE: there can be 3 cases

		if (rem == 0) {
			if (remainderFreqMap[rem] % 2 == 1) { //odd freq of rem, even honi chahie thi
				//return false
				return false;
			}
		}
		else if (2 * rem == k) { //why? 2*rem, not rem == k/2.(think, watch video)
			if (remainderFreqMap[rem] % 2 == 1) { //odd freq of rem, even honi chahie thi
				//return false
				return false;
			}
		}
		else {
			int freq = remainderFreqMap[rem];
			int otherFreq = remainderFreqMap[k - rem];
			if (otherFreq != freq) return false;
		}
	}
	return true;
}

int main() {
	/*
	PREREQUISITE: Longest Subarray with Sum Divisible by K
	VIDEO LINK: https://www.youtube.com/watch?v=BvKv-118twg&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=4
	QUESTION LINK: https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
	*/
	// vector<int> arr = {1, 2, 3, 4, 5, 10, 6, 7, 8, 9};
	// int k = 5;

	vector<int> arr = { -1, 1, -2, 2, -3, 3, -4, 4};
	int k = 3;
	cout << checkIfArrayPairIsDivByK(arr, k);
}