#include <bits/stdc++.h>
using namespace std;

int minValue(string str, int k) {
	unordered_map<char, int> mp; //char, freq
	for (auto ele : str) {
		mp[ele]++;
	}

	priority_queue<int> pq; //frequency --> max heap by default in cpp

	//put all freq in pq;
	for (auto it : mp) {
		pq.push(it.second);
	}

	while (k--) {
		if (!pq.empty()) {
			int maxFreq = pq.top();
			pq.pop();
			maxFreq--;
			pq.push(maxFreq);
		}
	}

	//calculate ans from pq
	int ans = 0;
	while (!pq.empty()) {
		int rem = pq.top();
		pq.pop();
		ans += pow(rem, 2);
	}

	return ans;
}


int main() {
	/************************************
	 * QUESTION: https://practice.geeksforgeeks.org/problems/game-with-string4100/1
	 VIDEO: https://www.youtube.com/watch?v=oqzAnZ1JvIw
	//************************************/
	string s = "aabcbcbcabcc";
	int k = 3;
	cout << "ans " <<  minValue(s, k);
}


