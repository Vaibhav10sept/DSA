#include <bits/stdc++.h>
using namespace std;
void displayMatrix(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int longestCommonSubsequence(string str1, string str2) {
	//WV highly recommended
	//NOTE: this is not 2d DP solution, recursive solution is also there
	int n = str1.size();
	int m = str2.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	//STORAGE: dp[i][j] --> stores the max length of common subsequence using the str1 from 0th index to (i-1)th index and str2 from 0th index to (j-1)th index
	for (int i = 1; i < dp.size(); i++) {
		for (int j = 1; j < dp[0].size(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] += 1; // + 1 think, crucial
				dp[i][j] += dp[i - 1][j - 1];
			}
			else { // str1[i-1] != str2[j-1]
				dp[i][j] = max( dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[n][m];
}

int minInsertionDeletionToConvertStringAToB(string str1, string str2) {
	int lenghtOfLongestCommonSubsequence = longestCommonSubsequence(str1, str2);

	int minNoOfDeletions = str1.size() - lenghtOfLongestCommonSubsequence;
	int minNoOfInsertions = str2.size() - lenghtOfLongestCommonSubsequence;

	return minNoOfInsertions + minNoOfDeletions;

}

int main() {
	/*********************************
	 * NOTE: this is the extension question for longest commmon subsequence
	 * STRONG PREQ: longest commmon subsequence.
	QUESTION: https://www.codingninjas.com/studio/problems/can-you-make_4244510?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
	VIDEO LINK: https://www.youtube.com/watch?v=yMnH0jrir0Q&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=31
	*********************************/
	string str1 = "abcd";
	string str2 = "anc";

	cout << minInsertionDeletionToConvertStringAToB(str1, str2);
}