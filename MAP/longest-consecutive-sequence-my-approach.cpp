#include<bits/stdc++.h>
using namespace std;

void longestConsecutiveSequence(vector<int> arr) {
	sort(arr.begin(), arr.end());
	int idx = 0;
	int ans = INT_MIN;
	vector<int> ansvec;
	while (idx < arr.size()) {
		vector<int> temparr;
		temparr.push_back(arr[idx]);
		int temp = arr[idx] + 1;
		idx++;
		int cnt = 1;
		while (temp == arr[idx]) {
			temparr.push_back(temp);
			idx++;
			temp++;
			cnt++;
		}
		if (cnt > ans) {
			ans = cnt;
			ansvec = temparr;
		}
	}
	for (auto ele : ansvec) cout << ele << " ";
}



int main() {
	//NOTE: in my approach I am not using map
	//video link: https://www.youtube.com/watch?v=rb73tdVFjYE&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=498
	vector<int> arr = {10, 5, 9, 1, 11, 8, 6, 15, 3, 12, 2};
	longestConsecutiveSequence(arr);
}