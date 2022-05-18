#include <bits/stdc++.h>
using namespace std;

int maxNoOfKSumPairs(vector<int> arr, int k) {
	//create freq map
	map<int, int> freqMap;
	for (auto ele : arr) freqMap[ele]++;

	//iterate over map
	int ans = 0; //count of pairs with sum k
	for (auto it : freqMap) {
		int val = it.first;
		int freq = it.second;
		if (freqMap.find(k - val) != freqMap.end() and freqMap.find(val) != freqMap.end()) {
			if (val != k - val) {
				int minPair = min(freqMap[val], freqMap[k - val]);
				ans += minPair;
				freqMap[k - val] -= minPair;
				freqMap[val] -= minPair;
			}
			else { //both are "val" and "k - val" are same(think)
				//toh isi element the pair bna lo
				int minPair = freqMap[val] / 2;
				ans += minPair;
				freqMap[val] -= minPair;
			}
		}
	}
	return ans;
}

int main() {
	/*
	SPACE: O(n)
	TIME: O(n)
	LEETCODE LINK: https://leetcode.com/problems/max-number-of-k-sum-pairs/
	VIDEO LINK: https://www.youtube.com/watch?v=FevSHchkCeo
	*/
	vector<int> arr = {1, 2, 3, 4};
	int k = 5;
	cout << maxNoOfKSumPairs(arr, k);
}