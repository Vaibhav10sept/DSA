#include <bits/stdc++.h>
using namespace std;

void getSubsequenceApproach2(string ans, string ques) {
	if (ques.size() == 0) {
		cout << ans << endl;
		return;
	}
	int ch = ques[0];
	//remove 0th from ques
	string restOfQuestion = ques.substr(1);// bc
	string s(1, ch); //best way to make string from single char.
	getSubsequenceApproach2(ans + "_", restOfQuestion);
	getSubsequenceApproach2(ans + s, restOfQuestion);

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

	getSubsequenceApproach2("", "abc");
}