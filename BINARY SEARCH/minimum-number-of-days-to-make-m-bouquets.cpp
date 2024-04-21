#include<bits/stdc++.h>
using namespace std;

int getNumberOfBouquetForm(int mid, vector<int> arr, int k) {
	//k --> consecutive k flowers are required to make 1 bouquet
	//mid --> is the day
	int countOfConsecutiveFlowerBloomed = 0;
	int numberOfBouquetFormed = 0;

	for (auto day : arr) {
		if (day <= mid) { //flower is bloomed
			countOfConsecutiveFlowerBloomed++;
		}
		else {
			numberOfBouquetFormed += countOfConsecutiveFlowerBloomed / k;
			countOfConsecutiveFlowerBloomed = 0;
		}
	}

	numberOfBouquetFormed += countOfConsecutiveFlowerBloomed / k;
	return numberOfBouquetFormed;
}

int minNumberOfDaysToMakeMBouquets(vector<int> arr, int m, int k) {
	//watch video recommended
	//edge case:if we cannot form the m number of bouquets, return -1
	if ((long)m * k > arr.size()) return -1; //long coz leetcode me overflow ho rha tha for a testcase.


	//k --> consecutive k flowers are required to make 1 bouquet
	//m --> no of bouquet we need to make
	//arr --> arr[i] represent the day at which the ith flower blooms
	//return the min number of days required to make 'm' number of bouquets
	//start --> min value that arr(min day at which 1st flower bloom)
	//end --> max in arr(max day at which the last flower bloom)
	int n = arr.size();
	int end = *max_element(arr.begin(), arr.end());
	int start = *min_element(arr.begin(), arr.end());
	int ans = 0;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		//mid --> is the day
		//and we are trying to minimize day(mid)

		if (getNumberOfBouquetForm(mid, arr, k) >= m) {
			ans = mid; //always minimum hi hoga, std::min() ki jrurt nhi, lga bhi doge toh koi farak nhi pdega
			end = mid - 1; //moving left, kyoki hame mid(days) ko minimize krna hai
		}
		else { //not valid, means number of bouquets formed is less than m so we need to increase the mid(days)
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
	SIMILAR TO: koko eating bananas
	LEETCODE LINK: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
	VIDEO LINK: https://www.youtube.com/watch?v=TXAuxeYBTdg&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=14
	*/

	vector<int>	bloomDay = {1, 10, 3, 10, 2};
	int m = 3;
	int k = 1;
	cout << minNumberOfDaysToMakeMBouquets(bloomDay, m, k);
}