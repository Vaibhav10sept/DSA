#include <bits/stdc++.h>
using namespace std;

int bestTimeToSellStock(vector<int> arr) {
	int minLeft = INT_MAX;
	int maxProfit = INT_MIN;
	for (int ele : arr) {
		minLeft = min(minLeft, ele);
		int profit = ele - minLeft;
		maxProfit = max(maxProfit, profit);
	}
	return maxProfit;
}

int main() {
	/*
	LEETCODE LINK: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/1735493/JavaC%2B%2B-best-ever-EXPLANATION-could-possible
	VIDEO LINK: https://www.youtube.com/watch?v=eMSfBgbiEjk
	*/
	vector<int> prices = {7, 1, 5, 3, 6, 4};
	cout << bestTimeToSellStock(prices);
}