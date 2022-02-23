#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int r, int mid) {
	int n1 = mid - l + 1;
	int n2 = r - (mid + 1) + 1;
	int a[n1];
	int b[n2];
	for (int i = l; i <= mid; i++) {
		a[i - l] = arr[i];
	}
	for (int i = mid + 1; i <= r; i++) {
		b[i - (mid + 1)] = arr[i];
	}
//merging part
	int i = 0, j = 0, k = l;
	while (i < n1 and j < n2) {
		if (a[i] < b[j]) {
			arr[k++] = a[i++];
		}
		else {
			arr[k++] = b[j++];
		}
	}
	while (i < n1)  {
		arr[k++] = a[i++];
	}
	while ( j < n2) {
		arr[k++] == b[j++];
	}
}
void mergesort( int arr[], int l , int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		mergesort(arr, l, mid);
		mergesort(arr, mid + 1, r);
		merge(arr, l, r, mid);
	}
}

int main() {
	int arr[] = {12, 45, 87, 67, 80, 23, 80};
	mergesort(arr, 0, 6);
	for (int i : arr) cout << i << endl;
}