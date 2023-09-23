#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n) {
//this is copied from leetcode, but smjh me aa gya h, no need to watch any video
	vector<int> ans;

	// iterating fromt 0 to n
	for (int i = 0; i <= n; i++)
	{
		// sum is initialised as 0
		int sum = 0;
		int num = i;
		// while num not equals zero
		while (num != 0)
		{
			// we have to count 1's in binary representation of i, therefore % 2
			sum += num % 2;
			num = num / 2;
		}
		// add sum to ans vector
		ans.push_back(sum);
	}

	return ans;
}

int main()
{
	//***************************
	// NOTE: this is copied from leetcode, but smjh me aa gya h, no need to watch any video
	// LEETCODE: https://leetcode.com/problems/counting-bits/description/
	//**************************************************
	// vector<int> stock = {11, 6, 7, 19, 4, 1, 6, 18, 4};
	int n = 5;
	vector<int> ans = countBits(n);
	for (auto ele : ans) cout << ele << " ";
	cout << endl;

}