#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr) {
	unordered_map<int, int> freqMap; // value --> freq
	unordered_map<int, int> end; // store the no of consecutive subsequence of size 3 or more ending at key,

	//filling up the freq map
	for (int ele : arr) {
		freqMap[ele]++;
	}


	for (int ele : arr) {
		if (freqMap[ele] == 0) continue;
		freqMap[ele]--;

		if (end[ele - 1] > 0) { //means ele - 1 end vala subsequence present h to ele kisi existing subsequence ka end bn skta h
			end[ele - 1]--;
			end[ele]++;
		}
		else if (freqMap[ele + 1] > 0 && freqMap[ele + 2] > 0) {
			//NOTE: hme sirf 3+ size ke consecutive subsequence chahie hoge.
			//isilie agr ele kisi consecutive subsequence ka end nhi bn skta
			//to hm uske lie ek naya subsequence bnane ka try krege
			//for this we need ele+1 and ele+1 coz consecutive subsequence ka size 3+ hona chahiye
			freqMap[ele + 1]--;
			freqMap[ele + 2]--;
			end[ele + 2]++;
		}
		else {
			//if ele kisi existing consecutive subsequence me nhi aya + ele se hm naya subsequence bhi nhi bna pae then we return false.
			return false;
		}
	}
	return true;
}



int main() {
	/*******************
	 * LEETCODE: https://leetcode.com/problems/split-array-into-consecutive-subsequences/
	 * *************/
	vector<int> arr =  {1, 2, 3, 3, 4, 5};
	bool ans = isPossible(arr);
	if (ans) cout << "true";
	else cout << "false";
}