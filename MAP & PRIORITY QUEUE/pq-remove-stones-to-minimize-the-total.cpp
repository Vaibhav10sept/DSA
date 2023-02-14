#include <bits/stdc++.h>
using namespace std;

int removeStones(vector<int> arr, int k) {
	//this code is copied from leetcode
	priority_queue<int> pq(arr.begin(), arr.end());

	for (int i = 0; i < k; i++) {
		int tp =  pq.top();
		pq.pop();
		tp = tp - (tp / 2);
		pq.push(tp);
	}
	int ans = 0;
	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}
	return ans;
}

int main() {
	/*
	NOTE: PQ is used here.
	VIDEO LINK:
	QUESTION LINK: https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/
	*/
	vector<int> piles = {5, 4, 9};
	int k = 2;
	cout << removeStones(piles, k);
}