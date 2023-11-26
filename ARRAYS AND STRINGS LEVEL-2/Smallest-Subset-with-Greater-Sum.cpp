#include <bits/stdc++.h>
using namespace std;

int minSubset(vector<int> &arr, int N) {
	//NOTE: i wrote this
	long long int sum = 0;
	for (auto ele : arr) sum += ele;

	long long int bigSum = 0;
	sort(arr.begin(), arr.end(), greater<int>());
	int cnt = 0;

	for (auto ele : arr) {
		bigSum += ele;
		cnt++;
		if (sum - bigSum < bigSum) {
			return cnt;
		}
	}
}

int main() {
	/*********************************
	 * //NOTE: i wrote this
	// VIDEO LINK:
	// LEETCODE LINK: https://practice.geeksforgeeks.org/problems/smallest-subset-with-greater-sum/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
	//*********************************/
	int n = 6;
	vector<int> a = {5, 3, 2, 8, 4, 1};
	cout << minSubset(a, n);
}
