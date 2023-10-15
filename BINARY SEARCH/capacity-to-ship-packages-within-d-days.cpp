#include<bits/stdc++.h>
using namespace std;

int sumOfAllValues(vector<int> arr) {
	int sum = 0;
	for (int ele : arr) sum += ele;
	return sum;
}

bool isValid(vector<int> arr, int mid, int days) {
	//mid --> capacity of conveyor belt
	int consecutiveSum = 0;
	int dayCount = 1;
	for (int ele : arr) {
		if (consecutiveSum + ele > mid) { //capacity cross ho gae, increase daycount
			dayCount++;
			consecutiveSum = ele;
		}
		else {
			consecutiveSum += ele;
		}
	}
	return dayCount <= days;
}

int capacityToShipPackages(vector<int> arr, int days) {
	//watch video recommended
	//edge case:if we cannot form the m number of bouquets, return -1
	// if ((long)m * k > arr.size()) return -1; //long coz leetcode me overflow ho rha tha for a testcase.


	//days --> this is the threshold means itne hi din hai hmare paas
	//return: min number of days to ship all the packages
	//end --> sum of all values in the arr(max hm sare packages ko ship kr skte hai)(think, cs, wv)
	int n = arr.size();
	int end = sumOfAllValues(arr);
	int start = *max_element(arr.begin(), arr.end());
	int ans = 0;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		//mid --> is the weight(capacity) of conveyor, mtlb ek in me converyor max mid weight ke packages(sum of wieght of packages) ko hi ship kr skta hai
		//and we are trying to minimize conveyor weight(capacity)(mid)

		if (isValid(arr, mid, days)) {
			ans = mid; //always minimum hi hoga, std::min() ki jrurt nhi, lga bhi doge toh koi farak nhi pdega
			end = mid - 1; //moving left, kyoki hame weight(capacity) ko minimize krna hai
		}
		else { //not valid, means conveyor belt ki capacity is not enough to ship the consecutive packages in less then or equal to days(parameter)
			//move right
			start = mid + 1;
		}
	}
	return ans;
}


int main() {
	/*
	NOTE: binary search is used here.
	NOTE: i wrote code after wv
	SIMILAR TO: min number of days to make m bouquets
	LEETCODE LINK: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
	VIDEO LINK: https://www.youtube.com/watch?v=MG-Ac4TAvTY&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=16
	*/

	vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int days = 5;
	cout << capacityToShipPackages(weights, days);
}