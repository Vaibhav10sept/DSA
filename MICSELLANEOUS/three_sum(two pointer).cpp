#include <bits/stdc++.h>
using namespace std;

void fun(int arr[], int n, int tar) {
	sort(arr, arr + n);
	for (int i = 0; i < n; n++) {
		int ntar = tar - arr[i];
		int j = i + 1;
		int k = n - 1;
		while (j < k) {
			int curr = arr[j] + arr[k];
			if (ntar > curr) {
				j++;
			} else if (ntar == tar) {
				cout << "yes";
				return;
			} else {
				k--;
			}
		}
	}
	cout << "no";
	return;

}


int main() {
	int arr[] = {12, 3, 7, 1, 6, 9};
	int sum = 5;
	fun(arr, sizeof(arr) / sizeof(int), sum);
}