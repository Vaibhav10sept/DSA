#include <bits/stdc++.h>
using namespace std;

int countOfOneInDigit(int dig) {
	string str = to_string(dig);
	int count = 0;
	for (auto ch : str) {
		if (ch == '1') count++;
	}
	return count;
}

int numberOfDigitOne(int n) {
	if (n == 0) return 0; //edge case

	//we are using dp
	vector<int> dp(n + 1);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i < dp.size(); i++) {

		//count the number of one in the number i;
		dp[i] = countOfOneInDigit(i) + dp[i - 1];
	}

	return dp[n];
}

int main()
{
	/***************************
	 * NOTE: this will give you TLE, an accept sol is not there(non intuitive)
	// video link: https://www.youtube.com/watch?v=ZOMKUPHcNRI
	LEETCODE: https://leetcode.com/problems/number-of-digit-one/description/
	//**************************************************/
	int n = 13;
	cout << numberOfDigitOne(n);

}