#include <bits/stdc++.h>
using namespace std;

struct comp {
	bool operator()(pair<char, int> a, pair<char, int> b) {
		//max heap --> by second value of pair(int)
		return a.second < b.second;
	}
};

string sortCharByFreq(string str) {
	map<char, int> mp;
	// filling the frequecy map
	for (char ch : str) mp[ch]++;

	//max heap
	priority_queue < pair<char, int>, vector<pair<char, int>>, comp> pq;

	//filling the pq
	for (auto ele : mp) {
		pq.push({ele.first, ele.second});
	}

	string ans = "";
	while (!pq.empty()) {
		pair<char, int> p = pq.top();
		pq.pop();

		int cnt = p.second;
		while (cnt--) {
			ans += p.first;
		}
	}

	return ans;
}

int main()
{
	/***************************************
	 * LEETCODE LINK: https://leetcode.com/problems/sort-characters-by-frequency/description/
	 * NOTE: we use priority queue and map here.
	 * **************************************/
	string s = "tree";
	cout << sortCharByFreq(s);
}