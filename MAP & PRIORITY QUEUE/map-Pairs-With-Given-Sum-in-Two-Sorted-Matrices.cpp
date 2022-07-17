#include <bits/stdc++.h>
using namespace std;

int countPairsFromTwoSortedMatricesWithGivenSum(vector<vector<int>> arr1, vector<vector<int>> arr2, int k) {
	set<int> st;
	for (int i = 0; i < arr1.size(); i++) {
		for (int j = 0; j < arr1[0].size(); j++) {
			st.insert(arr1[i][j]);
		}
	}

	int count = 0;

	for (int i = 0; i < arr2.size(); i++) {
		for (int j = 0; j < arr2[0].size(); j++) {
			int complement = k - arr2[i][j];
			if (st.find(complement) != st.end()) { //found
				count++;
			}
		}
	}
	return count;
}

int main() {
	/*
	NOTE: this is target sum pair in matrix.
	PREREQUISITE: target sum pair
	VIDEO LINK: https://www.youtube.com/watch?v=LuonxZFwG90&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=42
	QUESTION LINK: https://www.geeksforgeeks.org/smallest-subarray-with-all-occurrences-of-a-most-frequent-element/#:~:text=Examples%3A,two%20times%2C%201%20and%202.
	*/
	vector<vector<int>> arr1 = { {1, 5, 6},
		{8, 10, 11},
		{15, 16, 18}
	};

	vector<vector<int>> arr2 = { {2, 4, 7},
		{9, 10, 12},
		{13, 16, 20}
	};

	int k = 21;
	cout << countPairsFromTwoSortedMatricesWithGivenSum(arr1, arr2, k);
}