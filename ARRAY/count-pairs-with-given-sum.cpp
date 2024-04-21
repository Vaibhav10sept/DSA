#include <bits/stdc++.h>
using namespace std;

int targetSumPair(vector<int> arr, int sum) {
	map<int, int> freqMap;
	int ans = 0;

	for (int ele : arr) {
		int ElementToFind = sum - ele;
		if (freqMap.find(ElementToFind) != freqMap.end()) { //we found an element using which we can sum to "sum"
			ans += freqMap[ElementToFind];
		}

		//increment the count ele in the freqMap
		freqMap[ele]++;
	}
	return ans;
}

int main()
{
	//*****************************
	// QUESTION LINK: https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1
	//*****************************************
	vector<int> arr = {1, 1, 1, 1};
	int sum = 2;
	cout << targetSumPair(arr, sum);
}