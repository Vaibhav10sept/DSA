#include<bits/stdc++.h>
using namespace std;


void insertionSort(vector<int> &arr) {
	for (int i = 1; i < arr.size(); i++) { // n-1 iterations(from 1 to end)
		// for (int j = i - 1; j >= 0; j--) {
		// 	if (arr[j] > arr[j + 1]) {
		// 		swap(arr[j], arr[j + 1]);
		// 	}
		// 	else {
		// 		break; // this will help minimize the time complexity
		// 	}
		// }

		//******************************************
		// NOTE: you can also you the above commented piece of code for this question.
		// below code is using while loop while the above one uses for loop, both are valid
		//*********************************************

		int j = i - 1;
		while (j >= 0 and arr[j] > arr[j + 1]) {
			swap(arr[j], arr[j + 1]);
			j--;
		}
	}
}

int main() {
	//**************************************
	//NOTE: isme left side se sorted array create hona suru hota hai
	//NOTE: insertion sort is better than bubble and selection sort as it
	//recognizes already sorted array. while in case of bubble and selection sort
	//time complexity remain n^2 for already sorted array.
	//*******************************************
	vector<int> arr = {5, 9, 8, 2, 1};
	insertionSort(arr);
	for (int ele : arr) cout << ele << " ";
}