#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr) {
	for (auto ele : arr) cout << ele << " ";
	cout << endl;
}

void moveNegInArray(vector<int> &arr) {
	int i = 0;
	int j = 0;
	while (i < arr.size()) {
		if (arr[i] > 0) {
			i++;
		}
		else {
			swap(arr[i], arr[j]);
			i++;
			j++;
		}
	}
}

int main()
{
	/*
	VIDEO LINK:
	QUESTION LINK: https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/
	*/
	vector<int> arr = { -1, 2, -3, 4, 5, 6, -7, 8, 9};
	print(arr);
	moveNegInArray(arr);
	print(arr);
}