#include <bits/stdc++.h>
using namespace std;

int pairOfSongDivisibleBy60(vector<int> arr) {
	map<int, int> mp; //(arr[i]%60, frequency)
	int countOfPairs = 0;

	for (int time : arr) {
		int remainder = time % 60;
		if (remainder == 0) { //edge case (wv, cs)
			countOfPairs += mp[0];
		}
		else {
			countOfPairs += mp[60 - remainder];
		}

		mp[remainder]++;
	}

	return countOfPairs;
}

int main() {
	/********************************
	 * STRONG PREQ: 2sum(you can convert this problem to 2sum)
	 * NOTE: Calculate the time % 60 then it will be exactly same as two sum problem.
	// VIDEO LINK: https://www.youtube.com/watch?v=5gHnQ4lfDko
	QUESTION: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
	//*********************************/
	vector<int> arr = {30, 20, 150, 100, 40};
	cout << pairOfSongDivisibleBy60(arr) << endl;
}