#include<bits/stdc++.h>
using namespace std;

void insert ( int arr[], int ele, int ind) {
	int i = ind;
	while (i > 1 and ele > arr[i / 2] ) {
		arr[i ] = arr[i / 2];
		i = i / 2;
	}
	arr[i] = ele;
}

void createheap ( int arr[], int n) {
	for (int i = 2; i < n; i++) {
		insert(arr, arr[i], i);
	}
}

void deleteheap (int arr[], int n) {
	int temp = arr[1];
	arr[1] = arr[n - 1];
	int i = 1;
	int j = i * 2;
	while (j < n - 1) {
		if (arr[j]  < arr[j + 1]) {
			j = j + 1;
		}
		if (arr[i] < arr[j]) {
			swap(arr[i], arr[j]);
			i = j;
			j = j * 2;
		}
		else break;
	}
	arr[n - 1] = temp;

}
int main() {
	int arr[] = {0, 10, 20, 30, 25, 5, 40, 35};
	int n = 8;
	createheap(arr, n);

	for (auto i : arr) cout << i << " ";
	cout << endl;
	for ( int i = 8; i > 1; i--) {
		deleteheap(arr, i);
	}
	cout << "after heap sort: " << endl;
	for (auto i : arr) cout << i << " ";
	cout << endl;
}