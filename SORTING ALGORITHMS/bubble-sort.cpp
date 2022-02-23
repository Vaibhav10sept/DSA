#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr) {
	for (int i = 1; i <= arr.size() - 1; i++) { // n-1 phases hote hai
		for (int j = 0; j < arr.size() - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j + 1], arr[j]);
			}
		}
	}
}



int main() {
	//**************************************
	//NOTE: isme right side se sorted array create hona suru hota hai
	//*******************************************
	vector<int> arr = {5, 9, 8, 2, 1};
	bubbleSort(arr);
	for (int ele : arr) cout << ele << " ";
}