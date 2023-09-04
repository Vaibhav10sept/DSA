#include<bits/stdc++.h>
using namespace std;

//*********************
//STRONG PREREQUISITE: merge sort(jo miscellaneous me hai, not the merge sort in sorting-algorithm.
//**********************

int mergeWithInversionCount(vector<int> arr, int low, int mid, int high) {
	int inversionsCount = 0;
	int n1 = mid - low + 1; //size of left sorted array
	//NOTE: n2 = high - (mid + 1) + 1, after solving we get below.
	int n2 = high - mid; //size of right sorted array

	vector<int> leftSortedHalf(n1);
	vector<int> rightSortedHalf(n2);
	//filling up the left sorted half vector and right sorted half vector.
	for (int i = 0; i < n1; i++) {
		leftSortedHalf[i] = arr[low + i];
	}
	for (int i = 0; i < n2; i++) {
		rightSortedHalf[i] = arr[mid + 1 + i];
	}

	int i = 0, j = 0, k = low;
	//NOTE: isme merge sort ko krne ke lie k should start from low, iss code me bug lgra mujhe
	//but maene ye change kr dia, k ko low se start kia, pehle k 0 se start ho rha tha
	while (i < n1 and j < n2) {
		if (leftSortedHalf[i] <= rightSortedHalf[j]) {
			arr[k] = leftSortedHalf[i];
			i++;
			k++;
		}
		else { // leftSortedHalf[i] > rightSortedHalf[j]
			// here, inversion happens(think,WV)
			// NOTE: two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
			arr[k] = rightSortedHalf[j];
			//below line of code is extra, as compare to traditional merge sort
			inversionsCount += n1 - i; //think, crucial part

			k++;
			j++;
		}
	}

	//below code is for remaining element, as in merge sort nothing new.
	while (i < n1) {
		arr[k] = leftSortedHalf[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = rightSortedHalf[j];
		j++;
		k++;
	}
	return inversionsCount;
}

int mergeSort(vector<int> &arr, int low, int high) {
	int inversionsCount = 0;

	if (low < high) {
		int mid = (low + high) / 2;
		inversionsCount += mergeSort(arr, low, mid);
		inversionsCount += mergeSort(arr, mid + 1, high);
		inversionsCount += mergeWithInversionCount(arr, low, mid, high);
	}

	return inversionsCount;
}

int main() {
	/*
	STRONG PREREQUISITE: merge-sort(jo miscellaneous me hai, not the merge sort in sorting-algorithm.
	NOTE: two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
	NOTE: this is question is an application of merge sort
	VIDEO LINK: https://www.youtube.com/watch?v=sV4RhDIIKO0
	QUESTION: https://www.geeksforgeeks.org/counting-inversions/
	*/

	vector<int> arr = {8, 2, 4, 1};
	cout << mergeSort(arr, 0, arr.size() - 1) << endl;
}