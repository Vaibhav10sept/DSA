#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int> arr, int hours, int mid) {
	//mid --> is the k(bananas-per-hour eating speed)
	int requiredHours = 0;
	for (auto ele : arr) {
		requiredHours += ceil((double)ele / mid);

		if (requiredHours > hours) {
			return false;
		}
	}
	return true;
}

int KokoEatingBananas(vector<int> arr, int hours) {
	//watch video recommended
	//k --> bananas-per-hour eating speed
	//start --> min value that k(bananas-per-hour eating speed) can have
	//end --> max in arr(denotes that max value that k(bananas-per-hour eating speed) can have)
	int n = arr.size();
	int end = *max_element(arr.begin(), arr.end());
	int start = 1;
	int ans = hours;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		//mid --> is the k(bananas-per-hour eating speed)
		//and we are trying to minimize k(mid)

		if (isValid(arr, hours, mid)) {
			ans = mid; //always minimum hi hoga, std::min() ki jrurt nhi, lga bhi doge toh koi farak nhi pdega
			end = mid - 1; //moving left, kyoki hame mid(k(bananas-per-hour eating speed)) ko minimize krna hai
		}
		else { //not valid, means mid-->k(bananas-per-hour eating speed) ko use krke ham h(hours) <= me sare piles nhi kha pae toh move right to increase mid(k)
			//move right
			start = mid + 1;
		}
	}
	return ans;
}

int main() {
	/*
	SIMILAR TO: allocate mimimum number of pages
	LEETCODE LINK: https://leetcode.com/problems/koko-eating-bananas/
	VIDEO LINK: https://www.youtube.com/watch?v=U2SozAs9RzA
	*/

	vector<int> piles = {30, 11, 23, 4, 20};
	int h = 5;
	cout << KokoEatingBananas(piles, h);
}