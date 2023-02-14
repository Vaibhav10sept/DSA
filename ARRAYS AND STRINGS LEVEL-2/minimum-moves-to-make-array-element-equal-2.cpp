#include <bits/stdc++.h>
using namespace std;

/*

*/

string addBinary(string a, string b) {
	string res;
	int i = a.length() - 1;
	int j = b.length() - 1;
	int carry = 0;
	while (i >= 0 || j >= 0) {
		int sum = carry;
		if (i >= 0) sum += a[i--] - '0';
		if (j >= 0) sum += b[j--] - '0';
		carry = sum > 1 ? 1 : 0;
		res += to_string(sum % 2);
	}
	if (carry) res += to_string(carry);
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	//*********************************
	// NOTE: this is a mathematical problem
	// VIDEO LINK:
	// QUESTION: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/solutions/2215732/c-3-approaches-full-explanation/
	//*********************************/
	vector<int> nums = {1, 2, 3};
	cout << minMoves2(nums);

}



