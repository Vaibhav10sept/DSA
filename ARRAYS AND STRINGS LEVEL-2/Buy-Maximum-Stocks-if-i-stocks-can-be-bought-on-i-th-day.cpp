#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> a, pair<int, int> b) { //inc orddr of price
	if (a.first == b.first) { //price is same
		//dec order of quantity
		return a.second > b.second;
	}
	return a.first < b.first;
}

int buyMaximumProducts(int n, int k, int price[]) {
	// * NOTE: i wrote this no video no reading

	vector<pair<int, int>> arr; //value, quantity

	for (int i = 0; i < n; i++) {
		arr.push_back({price[i], i + 1});
	}

	sort(arr.begin(), arr.end(), comparator);

	int cntOfStocks = 0;
	for (int i = 0; i < arr.size(); i++) {
		int limit = arr[i].second;
		int val = arr[i].first;

		int canBuy = k / val;
		if (canBuy > limit) {
			canBuy = limit;
		}

		//update k
		cntOfStocks += canBuy;
		k = k - (val * canBuy);
	}

	return cntOfStocks;
}

int main() {
	/*********************************
	 * NOTE: i wrote this no video no reading
	// VIDEO LINK: https://www.youtube.com/watch?v=FkJZlZHWUyk&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=68
	QUESTION: https://practice.geeksforgeeks.org/problems/buy-maximum-stocks-if-i-stocks-can-be-bought-on-i-th-day/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
	//*********************************/
	int price[] = { 7, 10, 4 };
	int n = 3;
	int k = 100;
	cout << buyMaximumProducts(n, k, price);
}