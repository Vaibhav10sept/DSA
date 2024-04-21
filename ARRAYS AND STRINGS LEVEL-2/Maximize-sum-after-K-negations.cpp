#include <bits/stdc++.h>
using namespace std;

long long int maximizeSum(long long int arr[], int n, int k)
{
	// * NOTE: no video i write it myself
	// still video is available is you wanna watch

	sort(arr, arr + n);
	long long int sum = 0;
	long long int smallestPositive = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (k > 0 and arr[i] < 0) {
			sum += abs(arr[i]);
			k--;
		}
		else {

			sum += arr[i];
		}
		smallestPositive = min(smallestPositive, abs(arr[i]));

	}
	if (k % 2 == 1 and smallestPositive != INT_MAX) { //k is odd
// 		cout << smallestPositive << endl;
		sum -= smallestPositive * 2; //here
	}
	return sum;
}

int main() {
	/*********************************
	 * NOTE: no video i write it myself
	// still video is available is you wanna watch
	// VIDEO LINK: https://www.youtube.com/watch?v=8GDHYgbxTN4
	// QUESTION: https://practice.geeksforgeeks.org/problems/maximize-sum-after-k-negations1149/1
	//*********************************/
	int n = 5;
	int k = 5;
	long long int arr[] =  {1, 2, 3, 4, 5};
	cout << "ans " << maximizeSum(arr, n, k);
}