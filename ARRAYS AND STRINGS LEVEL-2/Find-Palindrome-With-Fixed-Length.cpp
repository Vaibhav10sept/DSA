#include <bits/stdc++.h>
using namespace std;

int helperFunction(int q, int n) {
	long long len = 0, pre = 0;
	if (n % 2 == 0) len = n / 2 - 1; //even
	else len = (n / 2); //odd
	pre = (int)pow(10, len);

	if (pre % 10 == 9) pre++; //this is for this compiler only, i think something is wrong with this(sublime text) compiler
	// cout << pre << " pre" << endl;
	pre += (q - 1);


	int orig = pre;
	if (n % 2 != 0) { //if odd
		pre /= 10;
	}
	string rev = to_string(pre);
	reverse(rev.begin(), rev.end());
	string ans = to_string(orig);
	if (rev != "0") //edge case
		ans += rev;

	return stoi(ans);
}

vector<int> findPallindromeWithFixedLength(vector<int> queries, int intLength) {
	vector<int> ans;
	for (int ele : queries) {
		ans.push_back(helperFunction(ele, intLength));
	}
	return ans;
}


int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=W8bpOKpPtPA
	// LINK: https://leetcode.com/contest/weekly-contest-286/problems/find-palindrome-with-fixed-length/
	//*********************************
	vector<int> queries = {2, 4, 6};
	int intLength = 4;
	vector<int> ans = findPallindromeWithFixedLength(queries, intLength);
	for (auto ele : ans) cout << ele << " ";

}