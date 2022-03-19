#include <bits/stdc++.h>
using namespace std;

int CantainerWithMaxWater(vector<int> heights) {
	int i = 0;
	int j = heights.size() - 1;
	int maxCapacity = INT_MIN;

	while (i < j) {
		// jiski height kam hogi vo ++ hoga(think)
		// j-i => width
		if (heights[i] < heights[j]) {
			maxCapacity = std::max(maxCapacity, (j - i) * heights[i]);
			i++;
		}
		else { // heights[i] > heights[j]
			maxCapacity = std::max(maxCapacity, (j - i) * heights[j]);
			j--;
		}
	}
	return maxCapacity;
}

int main() {
	//*********************************
	// NOTE: two pointer approach is used here
	// https://www.youtube.com/watch?v=qUDp8IUbZto&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=3
	// QUESTION:
	// 1. Given n non-negative integers a1, a2, ..., an.
	// 2. Each represents a point at coordinate (i, ai).
	// 3. 'n' vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0).
	// 4. Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
	// 5. (Not volume because we are working with 2D so amount of water is basically Area).
	// Note : that you may not slant the container.
	//*********************************

	vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	cout << CantainerWithMaxWater(heights);

}