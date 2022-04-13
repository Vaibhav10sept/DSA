#include<bits/stdc++.h>
using namespace std;
int partition(int arr[], int l, int r) {
	int i = l - 1;

	int pivot = arr[r];

	for (int j = l; j < r; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[j], arr[i]);
		}
	}
	i++;
	swap(pivot, arr[i]);
	return i;

}


void quicksort(int arr[], int l , int r) {
	if (l < r) {
		int pi = partition(arr, l, r);
		quicksort(arr, l, pi - 1);
		quicksort(arr, pi + 1, r);
	}
}

int main() {
	int arr[] = {1, 2, 5, 4, 7, 4, 3, 5, 5};
	quicksort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	for (auto i : arr) cout << i << " ";
}