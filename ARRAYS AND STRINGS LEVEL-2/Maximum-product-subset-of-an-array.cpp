#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
void rec(long long product, int ind, vector<int> &arr, long long &ans, bool isProduct) {
	if (ind == arr.size() and isProduct) {
		ans = max(ans, product);
		return;
	}
	if (ind > arr.size()) return;
	//BC ends

	//2 calls for making the subset
	//first: include
	rec((product * arr[ind]) % mod, ind + 1, arr, ans, true);

	//second: exclude
	rec(product, ind + 1, arr, ans, isProduct);
}

long long int findMaxProduct(vector<int>&arr, int n) {
	int mod = 1e9 + 7;

	long long ans = INT_MIN;
	rec(1, 0, arr, ans);
	return ans;
}

int main() {
	/*********************************
	 * NOTE: this give TLE, one more optimized accepted sol is there.
	QUESTION: https://practice.geeksforgeeks.org/problems/maximum-product-subset-of-an-array/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
	//*********************************/
	vector<int> arr = { -1, -1, -2, 4, 3};
	cout << findMaxProduct(arr, 1);
}