#include <bits/stdc++.h>
using namespace std;

int arithmaticSlice(vector<int> arr) {
	// WV highly recommended.
	vector<int> dp(arr.size(), 0);
	//storage: dp[i] --> no of subarrays ending at i which are AP(arithmatic progression) having lenght >= 3

	for (int i = 2; i < arr.size(); i++) {
		if (arr[i] - arr[i - 1] == arr[i - 1] - arr[i - 2]) {
			dp[i] = dp[i - 1] + 1; //think, WV
		}
	}

	int ans = 0;
	//ans hmare dp ke sare element ka sum hoga, think WV
	for (int ele : dp) ans += ele;

	return ans;
}

int main()
{
	//***************************
	// video link: https://www.youtube.com/watch?v=rSi4MpGEz1M
	// LEETCODE: https://leetcode.com/problems/arithmetic-slices/description/
	// NOTE: there is a second part of this question "arithmatic slice 2"
	//**************************************************
	vector<int> arr = {1, 2, 3, 4};
	cout << arithmaticSlice(arr);

}