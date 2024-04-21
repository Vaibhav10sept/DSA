#include <bits/stdc++.h>
using namespace std;

vector<int> candyStore(int arr[], int n, int k)
{
	sort(arr, arr + n);
	int ele = n - k;

	//min
	int min = 0;
	int max = 0;
	if (k == 0) {
		int sum = 0;
		for (int i = 0; i < n; i++) sum += arr[i];
		return {sum, sum};
	}

	int i = 0;
	int j = n - 1;
	while (true) {
		min += arr[i];
		i++;
		j -= k;
		if (j < i) {
			break;
		}
	}

	reverse(arr, arr + n);
	i = 0;
	j = n - 1;
	while (true) {
		max += arr[i];
		i++;
		j -= k;
		if (j < i) {
			break;
		}
	}


	return {min, max};
}

int main() {
	/*********************************
	 * NOTE: i wrote this no video no reading
	// VIDEO LINK: https://www.youtube.com/watch?v=2Sj6-5JFaAo
	QUESTION: https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1
	//*********************************/
	int N = 4;
	int K = 2;
	int candies[] = {3, 2, 1, 4};
	vector<int> ans = candyStore(candies, N, K);
	cout << ans[0] << " " << ans[1] << endl;
}