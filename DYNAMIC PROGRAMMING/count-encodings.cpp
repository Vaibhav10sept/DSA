#include <bits/stdc++.h>
using namespace std;


int countEncodings(string str) {
	//Please watch attached video(link) for more understanding.

	vector<int> dp(str.size());
	dp[0] = 1;

	for (int i = 1; i < dp.size(); i++) {
		char currentChar = str[i];
		char oneBeforeChar = str[i - 1];

		//there would be four cases:
		if (currentChar == '0' and oneBeforeChar == '0') { //like: 00
			dp[i] = 0;
		}
		else if (currentChar == '0' and oneBeforeChar != '0') { //like: 10
			string bothStr;
			bothStr.push_back(oneBeforeChar);
			bothStr.push_back(currentChar);
			int bothInt = stoi(bothStr);
			if (bothInt <= 26) {
				dp[i] += dp[(i - 2) < 0 ? 0 : (i - 2)];
			}

		}
		else if (currentChar != '0' and oneBeforeChar == '0') { //like: 01
			dp[i] = dp[i - 1];
		}
		else { // both are non zero. //like: 11
			dp[i] = dp[i - 1];
			string bothStr;
			bothStr.push_back(oneBeforeChar);
			bothStr.push_back(currentChar);
			int bothInt = stoi(bothStr);
			if (bothInt <= 26) {
				dp[i] += dp[(i - 2) < 0 ? 0 : (i - 2)];
			}
		}
	}
	return dp[str.size() - 1];
}

int main()
{
	//***************************
	// video link: https://www.youtube.com/watch?v=jFZmBQ569So&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=486
	// there is a question "PRINT ENCODINGS" which prints all possible encodings
	// (you can search it using ctrl + p)
	// "print encoding" is recursive while "count encodings" is DP.
	//**************************************************
	string str = "21123";
	cout << "count is: " << countEncodings(str);
}