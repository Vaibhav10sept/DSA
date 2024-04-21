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
				ans.push_back(*set.rbegin());
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
	//NOTE: I WROTE IT MYSELF
	LEETCODE: https://leetcode.com/problems/sliding-window-maximum/description/
	NOTE: here we use set
	VIDEO LINK: https://www.youtube.com/watch?v=xFJXtB5vSmM&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=6
	*/
	vector<int> arr = {9, 10, 9, -7, -4, -8, 2, -6};
	int k = 5;
	vector<int> ans = Maximumofallsubarraysofsizek(arr, k);
	for (auto ele : ans)cout << ele << " ";
}