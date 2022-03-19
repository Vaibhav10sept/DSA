#include <bits/stdc++.h>
using namespace std;

vector<string> getSubsequence(string str) {
	if (str.size() == 1) {
		char ch = str[0];
		std::string s;
		s = ch;
		vector<string> baseResult;
		baseResult.push_back("_");
		baseResult.push_back(s );
		return baseResult;
	}

	char currentChar = str[0];// a
	string restOfString = str.substr(1);// bc
	vector<string> recursionResult = getSubsequence(restOfString);
	//logic ye hai ki currentChar ek baar myResult(from recursionResult)
	//me include hoga and doosri baar
	//nhi include hoga.

	vector<string> myResult;
	for (string val : recursionResult) {
		//include nhi kro currentChar ko
		myResult.push_back("_" + val);

		//include kar do currentChar ko
		myResult.push_back(currentChar +  val);
	}
	return myResult;
}



int main()
{
	//********************************
	//LINK: https://www.geeksforgeeks.org/subarraysubstring-vs-subsequence-and-programs-to-generate-them/

	//NOTE: SUBSEQUENCE AND SUBSET BOTH ARE SAME THING
	//NOTE: SO TOTAL THERE ARE: 2^N SUBSEQUENCES/SUBSETS

	//NOTE: SUBSTRING AND SUBARRAY ARE ALMOST SAME THINGS(DOUBTFULL HAI)
	//NOTE: TOTAL THERE ARE N*(N+1)/2 SUBSTRING/SUBARRAY

	//DIFFERENCE BETWEEN SUBARRAY AND SUBSEQUENCE: SUBARRAY ARE
	//CONTINUES MEANS YOU CANNOT LEAVE ANY ELEMENT IN BETWEEN
	//WHILE SUBSEQUENCE ARE DISCONTINUOUS BUT THE SEQUENCE IS PRESERVED
	//IN BOTH.
	//***********************************
	vector<string> ans;
	ans = getSubsequence("abc");
	for (auto val : ans) cout << val << endl;
}