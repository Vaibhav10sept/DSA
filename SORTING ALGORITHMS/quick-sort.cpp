#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
	// 0 to j-1 -> <= pivot
	// j to i-1 -> > pivot
	// i to end -> unknown or yet to be traversed
	int i = low;
	int j = low;
	int pivot = arr[high];
	while (i <= high) {
		if (arr[i] > pivot) {
			i++;
		}
		else { //arr[i] <= pivot
			swap(arr[i], arr[j]);
			i++;
			j++;
		}
	}
	return j - 1; //we are returning the index where pivot element is placed
}


void quickSort(vector<int> &arr,  int low, int high) {
	if (low < high) {
		int pivot = partition(arr, low, high);
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}

int main() {
	//**************************************
	//video link: https://www.youtube.com/watch?v=kdO5Q0nmPjU&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=502
	//*******************************************
	vector<int> arr = {5, 3, 2, 8, 3, 6, 9, 0, 2, 56};
	quickSort(arr, 0, arr.size() - 1);
	for (int ele : arr) cout << ele << " ";
}

