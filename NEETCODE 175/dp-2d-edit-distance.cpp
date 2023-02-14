#include <bits/stdc++.h>
using namespace std;

int editDistance(string word1, string word2) {
	//WV highly recommended
	vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
	//STORAGE: dp[i][j] stores the min no of operations requires to convert word1 to word2 for the substring from ith to end for word1 and jth to end for word2.
	//NOTE: the last row and last col are for base cases(initialization)(that's why the size of dp is one more than the word1 and word2 size)

	//initialization(WV)
	int n = word1.size();
	int m = word2.size();
	// for last row
	int tempm = m;
	for (int j = 0; j < m; j++) {
		dp[dp.size() - 1][j] = tempm;
		tempm--;
	}

	//for last col
	int tempn = n;
	for (int i = 0; i < n; i++) {
		dp[i][dp[0].size() - 1 ] = tempn;
		tempn--;
	}
	//initialization ends

	//this is bottom-up dp
	for (int i = dp.size() - 2; i >= 0; i--) {
		for (int j = dp[0].size() - 2; j >= 0; j--) {
			if (word1[i] == word2[j]) {
				dp[i][j] = dp[i + 1][j + 1];
			}
			else { // wv, there can be three things that we can do
				// insert,delete, replace(jo bhi hme min no of operations dega)
				// +1 becoz hm uper teen me ek operation krege
				// insert --> i, j+1
				// delete --> i+1, j
				// replace --> i+1, j+1   (think,WV)

				dp[i][j] = 1 + min(dp[i][j + 1], min(dp[i + 1][j], dp[i + 1][j + 1]));
			}
		}
	}
	// cout << "print" << endl;
	// for (auto vec : dp) {
	// 	for (auto ele : vec) {
	// 		cout << ele << " ";
	// 	}
	// 	cout << endl;
	// }
	return dp[0][0];
}

int main() {
	/*********************************
	 * STRONG PREREQUISITE: longest common subsequence
	 * NOTE: this question is the application of longest common subsequence.
	LEETCODE: https://leetcode.com/problems/edit-distance/
	VIDEO LINK: https://www.youtube.com/watch?v=XYi2-LPrwm4
	*********************************/
	string word1 = "horse";
	string word2 = "ros";

	cout << editDistance(word1, word2);
}