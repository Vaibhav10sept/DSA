#include <bits/stdc++.h>
using namespace std;

void printLine(int i, int j, vector<string> arr, int k, int wordCount, vector<string> &res) {
	int totalSpace = k - wordCount;
	int spaceCandidate = j - i - 1; //-1 coz, no of space candidate is one less than the no of words(think, WV)
	int leastSpace = spaceCandidate == 0 ? 0 : totalSpace / spaceCandidate;
	int extraSpace = spaceCandidate == 0 ? 0 : totalSpace % spaceCandidate;
	if (j == arr.size()) {
		leastSpace = 1;
		extraSpace = 0;
	}
	string ans = "";
	for (int k = i; k < j; k++) {
		ans += arr[k];
		if (k == j - 1) break;
		for (int s = 0; s < leastSpace; s++) ans += " ";

		if (extraSpace > 0) {
			ans += " ";
			extraSpace--;
		}
	}

	while (ans.size() < k) ans += " ";
	res.push_back(ans);
}

vector<string> textJustification(vector<string> arr, int k) {
	//******************
	// WV highly recommended
	//NOTE: this is code is not the exact copy of video's code I have done some modifications.
	//*********************
	vector<string> res;
	int i = 0;
	int j = 0;
	int n = arr.size();
	while (i < n) {
		int wordCount = 0;
		int space = 0;
		while (j < n and wordCount + space + arr[j].size() <= k) {
			wordCount += arr[j].size();
			space++;
			j++;
		}
		printLine(i, j, arr, k, wordCount, res);
		i = j;
	}
	return res;
}

int main() {
	/*********************************
	* SIMILAR CONCEPT: integer to english
	// VIDEO LINK: https://www.youtube.com/watch?v=Rsq1ObYg6ak
	// LEETCODE LINK: https://leetcode.com/problems/integer-to-roman/solutions/2681343/c-using-map/
	//*********************************/
	vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
	int maxWidth = 16;
	vector<string> res = textJustification(words, maxWidth);
	for (auto ele : res) cout << ele << " ";

}