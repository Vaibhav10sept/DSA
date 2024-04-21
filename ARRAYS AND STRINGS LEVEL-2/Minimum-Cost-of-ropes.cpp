#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n) {
	// NOTE: I wrote it myself
	priority_queue<long long, vector<long long>, greater<long long>> pq; //defualt: min heap

	//PUT ALL IN PQ
	for (int i = 0; i < n; i++) {
		pq.push(arr[i]);
	}

	long long ans = 0;
	while (!pq.empty()) {
		if (pq.size() == 1) {

			break;
		}
		else {
			long long temp = 0;
			long long first = pq.top();
			pq.pop();
			temp += first;
			long long second = pq.top();
			pq.pop();
			temp += second;
// 			cout << "fir " << first << " " << second << " " << temp << endl;
			ans += temp;
			pq.push(temp);
		}
	}
	return ans;
}

int main() {
	/*********************************
	NOTE: I wrote it myself
	SAME SOLUTION: chocola-chocolate
	// VIDEO LINK: https://www.youtube.com/watch?v=9DckVBRzuQU
	// QUESTION: https://practice.geeksforgeeks.org/problems/minimum-cost-to-cut-a-board-into-squares/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
	//*********************************/
	long long arr[] = {4, 3, 2, 6};
	long long n = 4;
	cout << minCost(arr, n);
}