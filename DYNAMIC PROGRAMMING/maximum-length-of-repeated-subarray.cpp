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

int longestCommonSubstring(vector<int> arr1, vector<int> arr2) {
	//Please watch attached video(link) for more understanding.
	vector<vector<int>> dp(arr1.size() + 1, vector<int>(arr2.size() + 1));
	//STORAGE: dp[i][j] stores the length longest common suffix of the substring from 0 to ith of arr1 and the substring from 0th idx to jth idx of arr2.
	//initilization: if i==0 --> means arr1 is empty that means no longest common suffix hence value is zero
	// if j==0 --> means arr2 is empty that means the lenght of longest common substring is 0 hence we fill zero

	int lenLongestCommonSubstring = 0;
	for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j < dp[0].size(); j++) {
			if (i == 0 or j == 0) { //initialization
				dp[i][j] = 0;
			}
			else { //every other cells
				if (arr1[i - 1] == arr2[j - 1]) { //NOTE: index of dp is one more than the index of arr1 and arr2 that why we did i-1 and j-1.
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				else { // arr1[i-1] != arr2[j-1]
					dp[i][j] = 0; // agr last char equal nhi h to equal suffix nhi hoga(note hm longest common suffix dhundh rhe h(WV))
				}
			}
			lenLongestCommonSubstring = max(dp[i][j], lenLongestCommonSubstring);
		}
	}
	return lenLongestCommonSubstring;
}

int main()
{
	/***************************
	 * STRONG PREREQUISITE: longest common substring, code bilkul same rhega, no change.
	 * VIDEO LINK: https://www.youtube.com/watch?v=NvmJBCn4eQI
	 LEETCODE LINK: https://www.geeksforgeeks.org/longest-common-substring-dp-29/
	 * *****************************/
	vector<int> nums1 = {1, 2, 3, 2, 1};
	vector<int> nums2 = {3, 2, 1, 4, 7};
	cout << longestCommonSubstring(nums1, nums2);
}