#include <bits/stdc++.h>
using namespace std;

int countDistinctSubsequence(string str) {
	// WV recommended
	vector<int> dp(str.size() + 1);
	const int mod = 1e9 + 7;
	//STORAGE: dp[i] store the count of distinct subsequence from 0th indx to i-1 indx of str
	//NOTE: dp ka ith idx is str ka i-1 index se interact krega(WV).
	dp[0] = 1; //khali string bhi ek subsequence hoti h,islie count 1 hua

	map<char, int> mp; // vo char akhiri baar kis index me dekha gya tha
	for (int i = 1; i < dp.size(); i++) {
		char ch = str[i - 1];
		dp[i] = (2 * dp[i - 1]) % mod; // think,WV

		if (mp.find(ch) != mp.end()) { //found, means ye char pehle bhi aa chuka h, repitition
			int lastIndex = mp[ch];
			dp[i] = (dp[i] - dp[lastIndex - 1] + mod) % mod;
			//NOTE: upar +mod kyo kia ye nhi smjh aya
		}
		//map me bhi put krna h
		mp[ch] = i;
	}
	return (dp[dp.size() - 1] - 1) % mod; //-1 coz hme sirf non empty subsequence ka count return krna or isme ek empty subsequcne bhi h to uska -1 krdo.
}



int main()
{
	/***************************
	VIDEO LINK: https://www.youtube.com/watch?v=9UEHPiK53BA
	LEETCODE LINK: https://leetcode.com/problems/distinct-subsequences-ii/
	*****************************/
	string s = "aba";
	cout << countDistinctSubsequence(s);
}