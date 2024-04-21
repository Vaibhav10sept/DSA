#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
long long int findMaxProduct(vector<int>&arr, int n) {

	int countNegatives = 0;
	int countZeros = 0;
	int maxNegative = INT_MIN;
	long long int product = 1;

	if (n == 1) return arr[0]; //edge case (simple hai)

	for (auto ele : arr) {
		if (ele == 0) {
			countZeros++;
			continue;
		}
		else if (ele < 0) {
			countNegatives++;
			maxNegative = max(maxNegative, ele);
		}
		product = (product * ele) % mod;
	}

	if (countNegatives % 2 == 1) { //negative ka count odd hai
		//remove the maxnegative from the product(think,cs, wv)
		product = abs(product) / abs(maxNegative);
	}

	//edges cases(think,wv)
	if (countNegatives == 1 and countZeros + 1 == n) return 0; //only one negative values and rest are 0 ex: {0,-1}, return 0
	if (countZeros == n) return 0; //all values in array are 0
	return product;
}

int main() {
	/*********************************
	 * NOTE: this is accepted greedy sol. one rec sol is also there, which gives TLE
	QUESTION: https://practice.geeksforgeeks.org/problems/maximum-product-subset-of-an-array/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
	VIDOE: https://www.youtube.com/watch?v=QLUg9v5NJc0
	//*********************************/
	// vector<int> arr = { -1, -1, -2, 4, 3};
	vector<int> arr = { -1, 0};
	cout << findMaxProduct(arr, 1);
}