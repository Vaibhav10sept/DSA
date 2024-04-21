#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr) {
	for (auto ele : arr) cout << ele << " ";
	cout << endl;
}

void mergeSortedArray(vector<int> &arr1, vector<int> &arr2) {
	//easy logic, wv if required
	int left = arr1.size() - 1;
	int right = 0;

	while (left >= 0 and right < arr2.size()) {
		if (arr1[left] > arr2[right]) {
			swap(arr1[left], arr2[right]);
			left--;
			right++;
		}
		else { //means arr1 ka max is lesser or equal then the arr2 ka min, means sorted h, to age check krne ki jrurt ni to break kr jao
			break;
		}
	}

	//now, individually sort both the arrays
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
}

int main()
{
	/*
	NOTE: WV highly recommended
	VIDEO LINK: https://www.youtube.com/watch?v=n7uwj04E0I4
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