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
	return j - 1;
}


void quickSelect(vector<int> &arr,  int low, int high, int k) {
	//note: isme base case nhi hai(think)
	int pivot = partition(arr, low, high);
	if (k == pivot) {
		cout << "kth smallest elements is: " << arr[k] << endl;
		return;
	}
	else if (k < pivot) { //left me jaoge
		quickSelect(arr, low, pivot - 1, k);
	}
	else { // k > pivot, right me jaoge
		quickSelect(arr, pivot + 1, high, k);
	}

}

int main() {
	//**************************************
	// PREREQUISITE: quick sort
	// NOTE: this is an application for quick sort.
	//video link: https://www.youtube.com/watch?v=fnbImb8lo88&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=503
	//*******************************************
	vector<int> arr = {5, 3, 2, 8, 3, 6, 9, 0, 2, 56};
	int k = 4;
	k--; //logic: kth smallest element ka index k-1 hoga
	quickSelect(arr, 0, arr.size() - 1, k);
}

