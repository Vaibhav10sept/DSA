#include<bits/stdc++.h>
using namespace std;


void selectionSort(vector<int> &arr) {
	for (int i = 0; i < arr.size() - 1; i++) { //n-1 iterations
		int minElementIdx = i;
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[j] < arr[minElementIdx]) {
				minElementIdx = j;
			}
		}
		swap(arr[i], arr[minElementIdx]);
	}
}

int main() {
	//**************************************
	//NOTE: isme left side se sorted array create hona suru hota hai
	//*******************************************
	vector<int> arr = {5, 9, 8, 2, 1};
	selectionSort(arr);
	for (int ele : arr) cout << ele << " ";
}