#include <bits/stdc++.h>
using namespace std;

int carFleet(vector<int> position, vector<int> speed, int target) {
	int n = position.size();
	vector<pair<int, int>> fleet;

	for (int i = 0; i < n; i++) {
		fleet.push_back({position[i], speed[i]});
	}

	//sorting in increasing order of position.
	sort(fleet.begin(), fleet.end());
	stack<double> st;

	for (int i = n - 1; i >= 0; i--) {
		//int also works IDK why they used double maybe because of int overflow.
		//fleet.first --> position
		//fleet.second --> speed.
		//using time = distance/speed
		double time = (double)(target - fleet[i].first) / (double)fleet[i].second;
		if (st.empty() or time > st.top())
			st.push(time);
	}

	return st.size();
}

int main() {
	//*********************************
	// NOTE: kinda similar logic as in "merge intervals"
	// VIDEO LINK: https://www.youtube.com/watch?v=PemeYPadst4&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=32
	// QUESTION:
	// There are n cars going to the same destination along a one-lane road. The destination is target miles away.

	// You are given two integer array position and speed, both of length n, where position[i] is the position of the ith car and speed[i] is the speed of the ith car (in miles per hour).

	// A car can never pass another car ahead of it, but it can catch up to it and drive bumper to bumper at the same speed. The faster car will slow down to match the slower car's speed. The distance between these two cars is ignored (i.e., they are assumed to have the same position).

	// A car fleet is some non-empty set of cars driving at the same position and same speed. Note that a single car is also a car fleet.

	// If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.

	// Return the number of car fleets that will arrive at the destination.
	//*********************************
	vector<int>	position = {10, 8, 0, 5, 3};
	vector<int> speed = {2, 4, 1, 1, 3};
	int target = 12;
	cout << "no of fleets are: " << carFleet(position, speed, target);
}