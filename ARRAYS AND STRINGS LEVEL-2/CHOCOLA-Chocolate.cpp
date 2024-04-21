#include <bits/stdc++.h>
using namespace std;

int minimumCostOfBreaking(vector<int> a, vector<int> b, int m, int n) {
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>()); //sort in decreasing order

	int verticalCutsCnt = 1;
	int horizontalCutsCnt = 1;

	//code pattern is similar to merge two sorted array
	int i = 0; //for a vector
	int j = 0; //for b vector
	int costOfCutting = 0;
	while (i < a.size() and j < b.size()) {
		if (a[i] > b[j]) {
			//vertically cut kro
			costOfCutting += a[i] * verticalCutsCnt;
			horizontalCutsCnt++;
			i++;
		}
		else {
			//horizontally cut kro
			costOfCutting += b[j] * horizontalCutsCnt;
			verticalCutsCnt++;
			j++;
		}
	}

	//for remaining as in case of merge two sorted array
	while (i < a.size()) {
		costOfCutting += a[i] * verticalCutsCnt;
		i++;
	}
	while (j < b.size()) {
		costOfCutting += b[j] * horizontalCutsCnt;
		j++;
	}

	return costOfCutting;
}

int main() {
	/*********************************
	NOTE: wv if required
	STRONG PREQ: min cost to cut a board into square
	SAME SOLUTION: min cost to cut a board into square
	// VIDEO LINK: https://www.youtube.com/watch?v=9DckVBRzuQU
	// QUESTION: https://www.spoj.com/problems/CHOCOLA/
	//*********************************/
	int M = 6;
	int N = 4;
	vector<int> x = {2, 1, 3, 1, 4};
	vector<int> y = {4, 1, 2};
	cout << minimumCostOfBreaking(x, y, M, N);
}