#include<bits/stdc++.h>
using namespace std;


void insertionSort(vector<int> &arr) {
	for (int i = 1; i < arr.size(); i++) { // n-1 iterations(from 1 to end)
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
			else {
				break; // this will help minimize the time complexity
			}
		}
	}
}

int main() {
	//**************************************
	//NOTE: isme left side se sorted array create hona suru hota hai
	//NOTE: insertion sort is better than bubble and selection sort as it
	//recognizes already sorted array. while bubble and selection sort
	//time complexity remain n^2 for already sorted array.
	//*******************************************
	vector<int> arr = {5, 9, 8, 2, 1};
	insertionSort(arr);
	for (int ele : arr) cout << ele << " ";
}