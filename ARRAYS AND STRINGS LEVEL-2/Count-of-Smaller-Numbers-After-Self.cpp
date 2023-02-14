#include<bits/stdc++.h>
using namespace std;

void mergeWithModification(vector<int> arr, int low, int mid, int high, vector<int> &ans) {
	//NOTE: here we are merging in decreasing order
	int inversionsCount = 0;
	int n1 = mid - low + 1; //size of left sorted array
	//NOTE: n2 = high - (mid + 1) + 1, after solving we get below.
	int n2 = high - mid; //size of right sorted array

	vector<pair<int, int>> leftSortedHalf(n1); //pair<int,int> coz, first--> value, second --> index in original array
	vector<pair<int, int>> rightSortedHalf(n2);

	//filling up the left sorted half vector and right sorted half vector.
	for (int i = 0; i < n1; i++) {
		leftSortedHalf[i] = {arr[low + i], low + i};
	}
	for (int i = 0; i < n2; i++) {
		rightSortedHalf[i] = {arr[mid + 1 + i], mid + 1 + i};
	}

	cout << "leftSortedHalf " << endl;
	for (auto ele : leftSortedHalf) cout << ele.first << " ";
	cout << endl;
	cout << "rightSortedHalf " << endl;
	for (auto ele : rightSortedHalf) cout << ele.first << " ";
	cout << endl;

	int i = 0, j = 0, k = 0;
	while (i < n1 and j < n2) {
		//REM: we are merging in decreasing order
		if (leftSortedHalf[i].first <= rightSortedHalf[j].first) {
			arr[k] = rightSortedHalf[j].first;
			j++;
			k++;
		}
		else { // leftSortedHalf[i] > rightSortedHalf[j]
			// main part, this is different than merge sort.
			ans[leftSortedHalf[i].second] += (n2 - j + 1);
			cout << "test " << n2 << endl;
			//from here, traditional merge sort but in decreasing order
			arr[k] = leftSortedHalf[i].first;
			k++;
			i++;
		}
	}

	//below code is for remaining ele, as in merge sort nothing new.
	while (i < n1) {
		arr[k] = leftSortedHalf[i].first;
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = rightSortedHalf[j].first;
		j++;
		k++;
	}
	return;
}

void mergeSort(vector<int> arr, int low, int high, vector<int> &ans) {
	if (low < high) {
		int mid = low + (high - low) / 2;
		mergeSort(arr, low, mid, ans);
		mergeSort(arr, mid + 1, high, ans);
		mergeWithModification(arr, low, mid, high, ans);
	}
	return;
}

int main() {
	/*
	NOTE: here we do merge sort in decreasing order(think, WV)
	PREREQUISITE: count inversion
	ANOTHER PREREQUISITE: merge sort
	NOTE: this is question is an application of merge sort
	VIDEO LINK: https://www.youtube.com/watch?v=_sA1xI4XK0c
	QUESTION: https://leetcode.com/problems/count-of-smaller-numbers-after-self/

	*/
	vector<int> arr = {0, 2, 1};
	vector<int> ans(arr.size(), 0);
	mergeSort(arr, 0, arr.size() - 1, ans);
	cout << "result" << endl;
	for (auto ele : ans) cout << ele << " ";
}