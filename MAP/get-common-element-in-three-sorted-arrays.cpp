#include<bits/stdc++.h>
using namespace std;

vector<int> getCommonElementInThreeSortedArray(vector<int> arr1, vector<int> arr2, vector<int> arr3) {
	int i = 0;
	int j = 0;
	int k = 0;
	vector<int> ans;

	while (i < arr1.size() and j < arr2.size() and k < arr3.size()) {
		if (arr1[i] == arr2[j] and arr2[j] == arr3[k]) { //we found the common 3 elements in the 3 arrays
			ans.push_back(arr1[i]);
			i++;
			j++;
			k++;
		}
		else if (arr1[i] < arr2[j]) {
			i++;
		}
		else if (arr2[j] < arr3[k]) {
			j++;
		}
		else {
			k++;
		}
	}

	return ans;
}

int main() {
	/*
	QUESTION LINK: https://practice.geeksforgeeks.org/problems/common-elements1132/1
	*/
	vector<int> A = {1, 5, 10, 20, 40, 80};
	vector<int> B = {6, 7, 20, 80, 100};
	vector<int> C = {3, 4, 15, 20, 30, 70, 80, 120};
	vector<int> ans = getCommonElementInThreeSortedArray(A, B, C);
	for (auto ele : ans) {
		cout << ele << " ";
	}
}