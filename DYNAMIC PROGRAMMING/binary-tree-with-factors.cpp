#include <bits/stdc++.h>
using namespace std;


int binaryTreeWithFactor(vector<int> arr) {
	//Please watch attached video(link) for more understanding.
	map<int, long long int> mp; // value of array --> count of binary tree with root as the value;
	//NOTE: this map will works as a storage for DP.

	for (int ele : arr) {
		mp[ele] = 1;
		//coz, har value ko as a root mante hue hm ek binary tree bna skte h.
		//NOTE: all the values are unique in array, given in question.
	}
	sort(arr.begin(), arr.end());
	for (int i = 1; i < arr.size(); i++) {
		long long int count = 0; //no of ways
		for (int j = 0; j < i; j++) {
			if (arr[i] % arr[j] == 0) { //arr[j] is a factor of arr[i]
				//NOTE: arr[i]/arr[j] --> gives the another factor ie, if arr[j] * arr[i]/arr[j] = arr[i] (think, simple maths)
				auto it = mp.find(arr[i] / arr[j]);
				if (it != mp.end()) { //found, we found the other number using which we can get the product as arr[i]
					count += (mp[arr[j]] * it->second); //crucial part, WV
				}
			}
		}
		//update the DP(map) with the new value
		mp[arr[i]] += count;
	}

	//add all the values(ways of forming binary trees)
	long long int ans = 0;
	for (auto it : mp) {
		ans += it.second;
	}
	return (ans % 1000000007);
}

int main()
{
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=BRGz8ArRiPA
	LEETCODE LINK: https://leetcode.com/problems/binary-trees-with-factors/discuss/?currentPage=1&orderBy=most_votes&query=
	*/
	vector<int> arr = {2, 4, 5, 10};
	cout << binaryTreeWithFactor(arr);
}