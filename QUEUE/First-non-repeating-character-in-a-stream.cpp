#include <bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string str) {
	// NOTE: I wrote it.
	unordered_map<char, int> mp;
	queue<char> q;
	string ans = "";

	for (char ch : str) {

		mp[ch]++;
		if (mp[ch] == 1) q.push(ch);

		while (!q.empty() and mp[q.front()] > 1) {
			q.pop();
		}


		if (!q.empty() and mp[q.front()] == 1) {
			ans.push_back(q.front());
		}
		else {
			ans.push_back('#');
		}

	}

	return ans;
}

int main()
{
	/*
	NOTE: I wrote it.
	QUESTION: https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
	*/
	string str = "zz";

	cout << FirstNonRepeating(str);
}

