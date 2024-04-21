#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr) {
	for (auto ele : arr) cout << ele << " ";
	cout << endl;
}

void mergeSortedArray(vector<int> &arr1, vector<int> &arr2) {
	int i = arr1.size() - 1;
	int j = 0;

	while ( i > 0 and j < arr2.size()) {
		if (arr1[i] > arr2[j]) {
			swap(arr1[i], arr2[j]);
			i--;
			j++;
		}
		else {
			break;
		}
	}

	sort(arr1.begin() , arr1.end());
	sort(arr2.begin() , arr2.end());
}

int main()
{
	/*
	NOTE: this is less optimized approach, more optimized is also there.
	VIDEO LINK: https://www.youtube.com/watch?v=n7uwj04E0I4&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=39
	QUESTION LINK:
	*/
	vector<int> arr1 = { 1, 5, 9, 10, 15, 20 };
	vector<int> arr2 = { 2, 3, 8, 13 };
	print(arr1);
	print(arr2);
	cout << "after sorting" << endl;
	mergeSortedArray(arr1, arr2);
	print(arr1);
	print(arr2);
}