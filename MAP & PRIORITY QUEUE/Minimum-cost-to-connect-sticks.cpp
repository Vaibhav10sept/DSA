#include <bits/stdc++.h>
using namespace std;

int minimumCostToConnectSticks(vector<int> arr) {
	//WV recommended
	priority_queue <int, vector<int>, greater<int> > pq;//min heap

	//add all sticks in pq
	for (auto stick : arr) {
		pq.push(stick);
	}

	int minCost = 0;
	while (pq.size() > 1) {
		int s1 = pq.top();
		pq.pop();
		int s2 = pq.top();
		pq.pop();

		int cost = s1 + s2;
		minCost += cost;
		pq.push(cost);
	}

	return minCost;
}

int main() {
	/*
	NOTE: priority queue is used here.
	VIDEO LINK: https://www.youtube.com/watch?v=wxBp_rFU7SY&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=62
	QUESTION LINK: https://www.geeksforgeeks.org/connect-n-ropes-minimum-cost/
	*/
	vector<int> len = { 4, 3, 2, 6 }; //29
	cout << "Total cost for connecting sticks is "
	     << minimumCostToConnectSticks(len);
}