#include <bits/stdc++.h>
using namespace std;

int friendsPairing(int n) {
	//please refer to the video link below for better understanding.

	vector<int> dp(n + 1);
	dp[1] = 1;
	dp[2] = 2; //2 friends hai, to ya to dono sath me aega ya dono alag.

	for (int i = 3; i < dp.size(); i++) {
		dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
	}

	return dp[n];
}

vector<string> printFriendsPairing(string n) {
	if (n.size() == 0) {
		vector<string> bc;
		bc.push_back("");
		return bc;
	}
	if (n.size() == 1) {
		vector<string> bc;
		bc.push_back(n);
		return bc;
	}
	//bc ends

	vector<string> currAns;

	char ch = n[0];
	string removedFirst = n.substr(1);
	vector<string> singleAns = printFriendsPairing(removedFirst);

	for (string str : singleAns) {
		string s(1, ch);
		currAns.push_back(s + "-" + str);
	}

	for (int i = 1; i < n.size(); i++) {
		char secondRemove = n[i];
		string suffix(1, ch);
		suffix.push_back(secondRemove);
		string removedPair = n;
		removedPair.erase(removedPair.begin() + i);
		removedPair.erase(removedPair.begin());
		vector<string> pairAns = printFriendsPairing(removedPair);
		for (string str : pairAns) {
			currAns.push_back(suffix + "-" + str);
		}
	}

	return currAns;
}


int main()
{
	//***************************
	// video link: https://www.youtube.com/watch?v=SHDu0Ufjyk8&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=513
	// NOTE: there is also a DP ques "friendsPairing" similar to this one
	//**************************************************
	string n = "1234";
	int count = 4;
	cout << "no of ways in which n friends can be paired found using DP: " << friendsPairing(count);
	cout << endl;
	vector<string> ans = printFriendsPairing(n);
	for (auto ele : ans) cout << ele << endl;
}