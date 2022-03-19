#include <bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string str) {
	map<char, int> mp;
	vector<int> ans;
	for (int i = 0; i < str.size(); i++) {
		mp[str[i]] = i;
	}

	int maxImpact = 0;
	int prevMaxImpact = -1;
	for (int i = 0; i < str.size(); i++) {
		maxImpact = max(maxImpact, mp[str[i]]);

		if (maxImpact == i) {
			ans.push_back(i - prevMaxImpact);
			prevMaxImpact = i;
		}
	}
	return ans;
}

int main() {
	//*********************************
	// NOTE: prerequisite is "max-chunk-to-make-an-array-sorted" and "max-chunk-to-make-an-array-sorted-2"
	// VIDEO LINK: https://www.youtube.com/watch?v=_I9di3CUOx4&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=10
	// QUESTION:
	// 1. A string 's' of lowercase English letters is given.
	// 2. We want to partition this string into as many parts as possible so that each letter appears in at most one part.
	// 3. Return a list of integers representing the size of these parts.
	//*********************************
	string str = "ababcbacadefegdehijhklij";
	vector<int> ans = partitionLabels(str);
	for (auto ele : ans)cout << ele << " ";

}