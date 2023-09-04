#include <bits/stdc++.h>
using namespace std;

int minNoOfCoins(int val) {
	//this code is written by me, no need to WV, very easy approach just think.
	vector<int> coins = { 1000, 500, 100, 50, 20, 10, 5, 2, 1};
	int noOfCoins = 0;

	for (int coin : coins) {
		if (coin <= val) {
			noOfCoins += val / coin;
			val = val % coin;
		}
		if (val == 0) break;
	}
	return noOfCoins;
}

int main() {
	//*********************************
	// VIDEO LINK:
	// QUESTION: https://takeuforward.org/data-structure/find-minimum-number-of-coins/
	//*********************************
	int V = 121;
	cout << minNoOfCoins(V);
}