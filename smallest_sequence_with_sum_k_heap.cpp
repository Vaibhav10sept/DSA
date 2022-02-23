#include<bits/stdc++.h>
using namespace std;
// Smallest subsequence with
//  the sum greater than or equal to the given sum K
void fun(int arr[], int k , int n) {
	priority_queue<int> q;
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) q.push(arr[i]);
	while (!q.empty() and sum < k) {
		sum += q.top();
		q.pop();
		cnt++;
	}
	if (sum < k) {
		cout << -1;
		return;
	}
	cout << cnt << endl;
}
int main() {
	int arr[] = {1, 1, 3, 2, 8};
	int k = 12;
	int n = sizeof(arr) / sizeof(int);
	fun(arr, k, n);
}