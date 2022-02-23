#include<bits/stdc++.h>
using namespace std;

void longestConsecutiveSequence(vector<int> arr) {
	map<int, bool> mp;
	for (auto ele : arr) {
		mp[ele] = true;
	}
	for (auto ele : arr) {
		if (mp.find(ele - 1) != mp.end()) {
			mp[ele] = false;
		}
	}
	int maxConsecutiveSubsequence = INT_MIN;
	vector<int> ans;
	for (auto ele : arr) {
		if (mp[ele]) {
			int cnt = 1;
			int temp = ele + 1;
			vector<int> temparr;
			temparr.push_back(ele);
			while (mp.find(temp) != mp.end()) {
				cnt++;
				temparr.push_back(temp);
				temp++;
			}
			// cout << "cnt " << cnt << endl;
			if (cnt > maxConsecutiveSubsequence) {
				maxConsecutiveSubsequence = cnt;
				ans = temparr;
			}
		}
	}
	cout << "longest Consecutive Subsequence " << endl;
	for (auto ele : ans) cout << ele << " ";
	cout << endl;

}

int main() {
	//video link: https://www.youtube.com/watch?v=YWXbu5uyGXs&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=463
	vector<int> arr = {10, 5, 9, 1, 11, 8, 6, 15, 3, 12, 2};
	longestConsecutiveSequence(arr);
}