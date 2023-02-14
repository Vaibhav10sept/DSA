#include <bits/stdc++.h>
using namespace std;

int maxValueOfEquations(vector<vector<int>> arr, int k) {
	//WV video recommended
	priority_queue<pair<int, int>> pq; //max heap
	// pair --> sum of two things(wv), x coordinate ki value
	int ans = INT_MIN;
	//after watching video --> ek equation bnegi, pen paper se bna ke dekho ya video dekhlo

	for (int i = 0; i < arr.size(); i++) {
		while ((!pq.empty()) and (arr[i][0] - pq.top().second > k)) pq.pop();

		if (!pq.empty()) {
			ans = max(ans, arr[i][0] + arr[i][1] + pq.top().first);
		}

		pq.push({arr[i][1] - arr[i][0], arr[i][0]});
	}
	return ans;
}

int main() {
	/*********************************
	 VIDEO LINK: https://www.youtube.com/watch?v=hOTpn8jE9jI
	 QUESTION LINK: https://leetcode.com/problems/max-value-of-equation/description/
	*********************************/

	vector<vector<int>> points = {{1, 3}, {2, 0}, {5, 10}, {6, -10}};
	int k = 1;
	cout << maxValueOfEquations(points, k);
}