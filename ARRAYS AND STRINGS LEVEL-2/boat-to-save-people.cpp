#include <bits/stdc++.h>
using namespace std;

int boatsToSavePeople(vector<int> arr, int limit) {
	sort(arr.begin(), arr.end());
	int left = 0;
	int right = arr.size() - 1;
	int countOfBoat = 0;
	while (left < right) {
		//now, there would be 3 cases same as in "target sum unique pair"
		int sum = arr[left] + arr[right];
		if (limit >= sum) {
			//pair found
			countOfBoat++;
			left++;
			right--;
		}
		else {
			countOfBoat++;
			right--;
		}
	}
	return countOfBoat;
}

int main() {
	//*********************************
	// PREREQUISITE: "2sum-target-sum-unique-pair"
	// VIDEO LINK: https://www.youtube.com/watch?v=_KRgvkkxTzQ&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=39
	// QUESTION:
	// 1. You are given an array people where people[i] is the weight of the ith person.
	// 2. You have infinite number of boats where each boat can carry a maximum weight of limit.
	// 3. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
	// 4. Return the minimum number of boats to carry every given person.
	//*********************************
	vector<int> people = {3, 2, 2, 1};
	int limit = 3;
	cout << boatsToSavePeople(people, limit);
}