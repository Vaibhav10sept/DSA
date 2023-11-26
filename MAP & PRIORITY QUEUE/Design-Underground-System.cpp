#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem {
public:
	unordered_map<int, pair<string, int>> checkInMap; //id, pair -> start station name, start time
	unordered_map<string, vector<int>> checkOutMap; //combination string of startstation and endstation vs vector of all the time diff (to calculate the avg time)
	UndergroundSystem() {

	}

	void checkIn(int id, string startStation, int t) {
		checkInMap[id] = {startStation, t};
	}

	void checkOut(int id, string endStation, int t) {
		string startStation = checkInMap[id].first;
		int startTime = checkInMap[id].second;
		string combinedString = startStation + '_' + endStation;
		int diffOfTime = t - startTime;
		checkOutMap[ combinedString].push_back(diffOfTime);
	}

	double getAverageTime(string startStation, string endStation) {
		vector<int> arr = checkOutMap[ startStation + '_' + endStation];
		int sum = 0;
		for (auto ele : arr) {
			sum += ele;
		}
		return (double)sum / arr.size();
	}
};

int main() {
	/*
	NOTE: ho jaege khud se thoda socho, no need to WV
	VIDEO LINK: https://www.youtube.com/watch?v=AdRVFQo0l7w&t=541s
	QUESTION LINK: https://leetcode.com/problems/design-underground-system/
	*/

}