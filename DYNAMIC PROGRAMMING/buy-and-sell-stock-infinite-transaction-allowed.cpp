#include <bits/stdc++.h>
using namespace std;

int buyAndSellStockInfiniteTransactionAllowed(vector<int> arr) {
	int buy = 0; //this hold is index not value
	int sell = 0; //this hold is index not value
	int profit = 0;

	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] >= arr[i - 1]) {
			sell = i;
		}
		else {
			profit += arr[sell] - arr[buy];
			buy = sell = i;
		}
	}
	profit += arr[sell] - arr[buy];
	return profit;
}

int main()
{
	//***************************
	// video link: https://www.youtube.com/watch?v=HWJ9kIPpzXs&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=516
	// NOTE: this question is part of 6 questions series "buy and sell stock"
	// this is 2rd question in the series
	//**************************************************
	// vector<int> stock = {11, 6, 7, 19, 4, 1, 6, 18, 4};
	vector<int> stock = {1, 2, 3};
	cout << buyAndSellStockInfiniteTransactionAllowed(stock);

}