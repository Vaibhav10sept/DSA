#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveSubsequence(vector<int> arr) {
	//we use map here.
	int ans = 1;
	map<int, int> mp; //value of array --> length of longest consecutive subsequence.
	for (int ele : arr) {
		if (mp.find(ele - 1) != mp.end()) { //found
			//a subsequence can be formed
			mp[ele] = mp[ele - 1] + 1;
			ans = max(ans, mp[ele]);
		}
		else { //ele - 1 not found, means, subsequence length is 1
			mp[ele] = 1;
		}
	}
	return ans;
}


int trickySortingCost(vector<int> arr) {
	int longestConsecutiveSubsequenceAns = longestConsecutiveSubsequence(arr);
	return arr.size() - longestConsecutiveSubsequenceAns;
}

int main() {
	/*
	PREREQUISITE: longest Consecutive Subsequence with a slight change
	NOTE: longest Consecutive Subsequence vala logic work nhi krega as iss quesetion me sequence matter krta h
	VIDEO LINK: https://www.youtube.com/watch?v=5WT9o2IzmZU&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=65
	QUESTION LINK: https://practice.geeksforgeeks.org/problems/morning-assembly3038/1
	*/
	vector<int> arr = {4, 3, 1, 2};
	cout << "result " << endl;
	cout << trickySortingCost(arr);
}