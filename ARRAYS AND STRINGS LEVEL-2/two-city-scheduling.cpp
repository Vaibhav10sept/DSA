#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int> v1, vector<int> v2) {
	//decreasing order of profit if you choose city A rather then city B
	return v1[1] - v1[0] > v2[1] - v2[0];
}

int twoCityScheduling(vector<vector<int>> costs) {
	sort(costs.begin(), costs.end(), comparator);
	int n = costs.size();
	int ans = 0;
	for (int i = 0; i < costs.size(); i++) {
		if (i < n / 2) {
			ans += costs[i][0];
		}
		else {
			ans += costs[i][1];
		}
	}
	return ans;
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=vtNoP43hGJA
	// QUESTION:
// A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.
// Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.
	//*********************************
	vector<vector<int>>	costs = {{10, 20}, {30, 200}, {400, 50}, {30, 20}};
	cout << twoCityScheduling(costs);
}