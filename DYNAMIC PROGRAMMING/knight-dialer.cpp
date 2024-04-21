#include <bits/stdc++.h>
using namespace std;

int knightDialer(int n) {
	//NOTE: not intuitive, wv recommended
	if (n == 1) return 10; //edge case: think, wv
	unordered_map<int, vector<int>> mp;
	mp[0] = {4, 6};
	mp[1] = {6, 8};
	mp[2] = {7, 9};
	mp[3] = {4, 8};
	mp[4] = {0, 3, 9};
	mp[6] = {0, 1, 7};
	mp[7] = {2, 6};
	mp[8] = {1, 3};
	mp[9] = {2, 4};

	vector<int> dp(10, 1); //this is for n=1(think, cs)--> agr n=1(n is lenght) hai to hm hr ek key ko ek hi baar daba skte hai(wv)
	//storage: dp[ind] -> ind(0 to 9) key se start krne pr n lenght ke kitne keypad combination bn skte hai

	for (int i = 2; i <= n; i++) {
		vector<int> temp(10);

		for (int initialKey = 0; initialKey <= 9; initialKey++) {
			vector<int> vec = mp[initialKey];
			for (int ele : vec) {
				temp[initialKey] = (temp[initialKey] + dp[ele]) % 1000000007;
			}
		}
		dp = temp;
	}


	//return sum of all values in dp
	int ans = 0;
	for (auto ele : dp) {
		ans = (ans + ele) % 1000000007;
	}
	return ans;
}

int main()
{
	/***************************
	//NOTE: not intuitive, wv recommended
	VIDEO LINK: https://www.youtube.com/watch?v=wRF40TQUpxg&t=1s
	LEETCODE LINK: https://leetcode.com/problems/knight-dialer/description/
	//**************************************************/
	int n = 3131;
	cout << knightDialer(n);
}