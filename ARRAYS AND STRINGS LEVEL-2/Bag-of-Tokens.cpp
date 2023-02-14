#include <bits/stdc++.h>
using namespace std;

int bagofTokens(vector<int> tokens, int power) {
	//this code is copied from leetcode discussion
	//this is leetcode daily challenge question
	sort(tokens.begin(), tokens.end());
	int start = 0, end = tokens.size() - 1;
	int cscore = 0; int mscore = 0;
	while (start <= end)
	{
		if (power >= tokens[start])
		{	power -= tokens[start];
			cscore++;
			mscore = max(mscore, cscore);
			start++;
		}

		else if (cscore >= 1) {
			power += tokens[end];
			cscore --;
			end--;
		}
		else
			break;


	}

	return mscore;
}

int main() {
	//*********************************
	//LEETCODE LINK: https://leetcode.com/problems/bag-of-tokens/
	//this code is copied from leetcode discussion
	//this is leetcode daily challenge question
	//*********************************
	vector<int> tokens = {100, 200};
	int power = 150;
	cout << bagofTokens(tokens, power);
}