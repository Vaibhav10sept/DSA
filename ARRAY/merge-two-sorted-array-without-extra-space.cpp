#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr) {
	for (auto ele : arr) cout << ele << " ";
	cout << endl;
}

void mergeSortedArray(vector<int> &arr1, vector<int> &arr2) {
	//refer to insertion sort first
	int n = arr1.size();
	int m = arr2.size();

	//i -> index for arr1
	//j -> index for arr2
	for (int j = m - 1; j >= 0; j--) {
		int i = n - 2; //i always starts form second last element of arr1
		int lastOfArr1 = arr1[n - 1];

		while (i >= 0 and arr1[i] > arr2[j]) {
			arr1[i + 1] = arr1[i];
			i--;
		}

		if (i != n - 2 or lastOfArr1 > arr2[j]) {
			//think
			arr1[i + 1] = arr2[j];
			arr2[j] = lastOfArr1;
		}
	}
}

int main()
{
	/*
	NOTE: WV highly recommended
	VIDEO LINK: https://www.youtube.com/watch?v=NWMcj5QFW74
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