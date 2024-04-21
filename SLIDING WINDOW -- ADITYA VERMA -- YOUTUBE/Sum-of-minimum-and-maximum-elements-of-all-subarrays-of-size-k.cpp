#include<bits/stdc++.h>
using namespace std;

vector<int> Maximumofallsubarraysofsizek(vector<int> arr, int k) {
	//NOTE: I WROTE IT MYSELF
	int i = 0;
	int j = 0;
	vector<int> ans;
	// i --> represent start of window
	// j --> represent end of window
	// j-i+1 --> is the size of window

	multiset<int> set; //increasing order multiset(default in cpp)
	while (j < arr.size()) {
		set.insert(arr[j]);
		if (j - i + 1 == k) {
			if (!set.empty()) {
				ans.push_back(*set.rbegin() + *set.begin());
			}

			//now,slide the window.
			if (set.find(arr[i]) != set.end()) { //found
				// cout << "he " << arr[i] << endl;
				set.erase(set.find(arr[i]));
			}
			i++;
		}
		j++;
	}
	return ans;
}

int main() {
	/*
	STRONG PREQ: sliding-window-maximum-Maximum-of-all-subarrays-of-size-k
	SAME QUESTION JUST 1 LINE CODE CHANGE: sliding-window-maximum-Maximum-of-all-subarrays-of-size-k
	//NOTE: I WROTE IT MYSELF
	LEETCODE: https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/
	NOTE: we use set here.
	*/
	vector<int> arr = {2, 5, -1, 7, -3, -1, -2};
	int k = 4;
	vector<int> ans = Maximumofallsubarraysofsizek(arr, k);
	for (auto ele : ans)cout << ele << " ";
}