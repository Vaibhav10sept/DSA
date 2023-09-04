#include <bits/stdc++.h>
using namespace std;
/*
	 * APPROACH: USING MAPS :
We are aware of the fact that for a pair to be counted as an answer , both the elements ( x and x+k ) , need to be in the array.
So we simply create a map and store the frequency of each element in the map.
Now we traverse the map and for each element 'x' , we check if 'x+k' exists in the map . If it does , then it means a unique pair can be formed and hence, we increment the answer.

EDGE CASE :
The only edge case is the situation wherek=0. If k=0 , instead of finding 'x+k' , we check if the frequency of 'x'>1. If it is , then weincrement the answer .
Else , we don't increment the answer , as the frequency of x=1 and hence it can't form a pair with itself.
*/
int kDiffPair(vector<int> arr, int k) {
	unordered_map<int, int> mp; //(val: freq)

	for (int ele : arr)
		mp[ele]++;

	int ans = 0;
	for (auto x : mp)
	{
		if (k == 0) { //edge case: see the approach above
			if (x.second > 1) //think: ans++ hi kyo hua, coz unique pair chahiye suppose map me 4 ka count(freq) 6 hoti to hm (4,4) ke teen pair thodi na btane sirf ek bnate for it to be unique(cs)
				ans++;
		}
		else if (mp.find(x.first + k) != mp.end()) //found
			ans++;
	}

	return ans;
}

int main() {
	/**************************
	 * APPROACH: USING MAPS :
	We are aware of the fact that for a pair to be counted as an answer , both the elements ( x and x+k ) , need to be in the array.
	So we simply create a map and store the frequency of each element in the map.
	Now we traverse the map and for each element 'x' , we check if 'x+k' exists in the map . If it does , then it means a unique pair can be formed and hence, we increment the answer.

	EDGE CASE :
	The only edge case is the situation wherek=0. If k=0 , instead of finding 'x+k' , we check if the frequency of 'x'>1. If it is , then weincrement the answer .
	Else , we don't increment the answer , as the frequency of x=1 and hence it can't form a pair with itself.

	 * LEETCODE LINK: https://leetcode.com/problems/k-diff-pairs-in-an-array/solutions/1756874/c-multiple-approaches-maps-two-pointer/
	 VIDEO LINK: https://www.youtube.com/watch?v=S1HZpd8Jhyw
	 * ******************************/
	vector<int> nums = {3, 1, 4, 1, 5};
	int k = 2;
	cout << kDiffPair(nums, k);
}