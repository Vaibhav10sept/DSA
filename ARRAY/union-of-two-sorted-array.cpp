#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr) {
	for (auto ele : arr) cout << ele << " ";
	cout << endl;
}

void unionOfSortedArray(vector<int> &arr1, vector<int> arr2) {
	int i = 0;
	int j = 0;
	while (i < arr1.size() and j < arr2.size()) {
		if (arr1[i] < arr2[j]) {
			cout << arr1[i] << " ";
			i++;
		}
		else if (arr1[i] > arr2[j]) {
			cout << arr2[j] << " ";
			j++;
		}
		else { // arr1[i] == arr2[j]
			cout << arr1[i] << " ";
			i++;
			j++;
		}
	}

	//remaining in arr1 and arr2(similar concept as in merging of merge sort)
	while (i < arr1.size()) {
		cout << arr1[i] << " ";
		i++;
	}
	while (j < arr2.size()) {
		cout << arr1[j] << " ";
		j++;
	}
}

int main()
{
	/*
	VIDEO LINK:
	QUESTION LINK:
	*/
	vector<int> arr1 = { 1, 2, 3, 4, 5};
	vector<int> arr2 = {1, 2, 3};
	unionOfSortedArray(arr1, arr2);
}