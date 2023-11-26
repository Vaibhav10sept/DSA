#include <bits/stdc++.h>
using namespace std;

long long int maxSum(int arr[], int n)
{
	// * NOTE: i wrote this no code no video
	vector<int> temp;
	sort(arr, arr + n);

	int i = 0;
	int j = n - 1;

	if (n % 2 == 1) { //if odd
		while (i <= j) {
			temp.push_back(arr[j--]);
			temp.push_back(arr[i++]);
		}
	}
	else { //else even
		while (i < j) {
			temp.push_back(arr[j--]);
			temp.push_back(arr[i++]);
		}
	}

	for (auto ele : temp) cout << ele << " ";
	cout << endl;

	long long int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		// int diff = abs(temp[i + 1] - temp[i]);
		// cout << "dif " << diff << endl;
		ans += abs(temp[i + 1] - temp[i]);
	}
	ans += abs(temp[n - 1] - temp[0]);
	return ans;
}
int main() {
	/*********************************
	 * NOTE: i wrote this no code no video
	// VIDEO LINK:
	// LEETCODE LINK: https://practice.geeksforgeeks.org/problems/swap-and-maximize5859/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
	//*********************************/
	// int n = 4;
	// int arr[] = {4, 2, 1, 8};
	int n = 9;
	int arr[] = {80, 40, 76, 100, 36, 20, 49, 92, 8};
	cout << "ans " << maxSum(arr, n);
}