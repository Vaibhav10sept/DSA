#include <bits/stdc++.h>
using namespace std;
void fun(int arr[], int n , int x) {
	int sum = 0;
	int ans = INT_MAX;
	int i = 0, j = 0;
	while (j < n) {
		// if (sum < x)
		while (sum <= x and j < n) sum += arr[j++];
		while (sum > x and i < n) {
			ans = min(ans, j - i);
			sum -= arr[i++];
		}
	}
	cout << ans << endl;
}

int main() {
	// int arr[] = {2, 3, 1, 2, 4, 3};
	int arr[] = {1, 4, 4};

	int x = 4;
	fun(arr, 3, x);
}