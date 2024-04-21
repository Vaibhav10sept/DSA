#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n) {
	// see count sets bits in an integer to understand this algo
	//right most set bit mask is the number & (twos complement)
	//note: -n and two complement(~n + 1) are same
	//twos complement --> ~n + 1; (add 1 to ones complement(~n))
	//ones complement --> ~n;

	int cnt = 0;
	while (n != 0) {
		int rightMostMask = n & -n; //for this go to strong preq;
		n = n - rightMostMask;
		cnt++;
	}
	return cnt;
}

vector<int> countBits(int n) {
	vector<int> ans;

	// iterating fromt 0 to n
	for (int i = 0; i <= n; i++)
	{
		int count = countSetBits(i);
		ans.push_back(count);
	}

	return ans;
}

int main()
{
	/***************************
	STRONG PREQ: count sets bits in an integer
	// NOTE: this is copied from leetcode, but smjh me aa gya h, no need to watch any video
	// LEETCODE: https://leetcode.com/problems/counting-bits/description/
	// VIDEO: https://www.youtube.com/watch?v=I475waWiTK4
	//**************************************************/
	// vector<int> stock = {11, 6, 7, 19, 4, 1, 6, 18, 4};
	int n = 5;
	vector<int> ans = countBits(n);
	for (auto ele : ans) cout << ele << " ";
	cout << endl;

}