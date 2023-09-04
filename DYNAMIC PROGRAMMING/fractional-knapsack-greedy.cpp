#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int> v1, vector<int> v2) {
	double ratio = (double)v1[0] / (double)v1[1];
	double ratio2 = (double)v2[0] / (double)v2[1];

	//descending order
	return ratio > ratio2;
}

double fractionalKnapsack(vector<int> value, vector<int> weight, int capacity) {
	vector<vector<int>> arr; //0-> value, 1-> weight
	for (int i = 0; i < value.size(); i++) {
		arr.push_back({value[i], weight[i]});
	}

	//sort in descending order of value/weigth.
	sort(arr.begin(), arr.end(), comparator);

	int curWeight = 0;
	double totalProfit = 0.0;

	for (int i = 0; i < arr.size(); i++) {

		if (curWeight + arr[i][1] <= capacity) {
			curWeight += arr[i][1];
			totalProfit += arr[i][0];
		} else {
			int remain = capacity - curWeight;
			totalProfit += (arr[i][0] / (double)arr[i][1]) *  (double)remain;
			break;
		}
	}

	return totalProfit;
}

int main()
{
	//***************************
	// video link: https://www.youtube.com/watch?v=2i5pclQprGk
	// QUESTION: https://takeuforward.org/data-structure/fractional-knapsack-problem-greedy-approach/
	//**************************************************
	int capacity = 50;
	vector<int> value = {100, 60, 120};
	vector<int> weight = {20, 10, 30};
	cout << "maximum profit is: " << fractionalKnapsack(value, weight, capacity);
}