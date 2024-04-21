#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeQueue(queue<int> &q) {
	//NOTE: I wrote it
	vector<int> temp;
	while (!q.empty()) {
		temp.push_back(q.front());
		q.pop();
	}
	// reverse(temp.begin(), temp.end());

	vector<int> ans;

	int j = temp.size() / 2;
	int i = 0;
	while (j < temp.size()) {
		ans.push_back(temp[i]);
		ans.push_back(temp[j]);
		i++;
		j++;
	}

	return ans;
}

int main()
{
	/*
	NOTE: I wrote it.
	STRONG PREQ:
	QUESTION: https://practice.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
	*/

	queue<int> q;


	q.push(3);
	q.push(7);
	// q.push(5);
	// q.push(6);
	// q.push(8);
	// q.push(9);


	vector<int> ans = rearrangeQueue(q);
	for (auto ele : ans) cout << ele << " ";
	cout << endl;
}

