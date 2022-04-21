#include <bits/stdc++.h>
using namespace std;

long ThreeSumMultiplicity(vector<int> arr, int target) {
	unordered_map<int, long> freqMap;
	int mod = 1e9 + 7;
	long ans = 0;
	//filling up the freq map
	for (auto ele : arr) freqMap[ele]++;

	//iterating through map using two pointers(two for loop)
	for (auto it1 : freqMap) {
		for (auto it2 : freqMap) {
			int i = it1.first;
			int j = it2.first;
			int k = target - i - j;
			//if new target(k) is not in freq map then continue
			if (freqMap.find(k) == freqMap.end()) continue;
			//else there can be three cases
			//case 1: all three tuples are same
			if (i == j and j == k) {
				ans += freqMap[i] * (freqMap[i] - 1 ) * (freqMap[i] - 2) / 6;
			}
			//case 2: if two of the tuples are same.
			else if (i == j and j != k) {
				ans += freqMap[i] * (freqMap[i] - 1 ) / 2 * freqMap[k];
			}
			//case 3: all three tuples are different, i<j<k is important as it is given in question
			else if (i < j and j < k) {
				ans += freqMap[i] * freqMap[j] * freqMap[k];
			}
		}
		// ans = ans % mod;
	}
	return ans % mod;
}

int main() {
	/*
	LEETCODE LINK: https://leetcode.com/problems/3sum-with-multiplicity/
	VIDEO LINK: https://www.youtube.com/watch?v=DiWpfOorDaA
	*/
	vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
	int target = 8;
	cout << "answer" << endl;
	cout << ThreeSumMultiplicity(arr, target);
}