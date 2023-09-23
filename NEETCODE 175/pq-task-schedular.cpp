#include <bits/stdc++.h>
using namespace std;

int taskSchedular(vector<char> arr, int n) {
	// WV recommended
	// non intuative approach, hard to understand.
	string ans = "";
	//creating freq map
	map<char, int> mp; // char, frequency
	for (char ele : arr) {
		mp[ele]++;
	}

	//filling up the priority queue
	priority_queue<int> pq; //max heap --> default in cpp max heap hoti h
	// NOTE: pq contains the freq of every char
	for (auto it : mp) {
		pq.push(it.second); //it.second --> freq
	}

	// while (!pq.empty()) {
	// 	cout << pq.top().ch << " " << pq.top().freq << endl;
	// 	pq.pop();
	// }

	int time = 0;
	queue<pair<int, int>> q; //pair --> freq, available time(at what time this freq task is available to us).

	while (!pq.empty() or !q.empty()) {
		time++;

		if (!pq.empty()) {
			int newFreq = pq.top() - 1; //why -1: coz, ab hmne ek use kr lia na to count km krdo
			pq.pop();
			if (newFreq > 0) q.push(make_pair(newFreq, time + n));
		}

		if (!q.empty() and q.front().second == time) { //means, iss time me kya queue me koi aesa task h jo available h, to usse use krlo
			pq.push(q.front().first); //q.front().first-> we are adding the freq in priority queue
			q.pop();
		}
	}
	return time;
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=s8p8ukTyA2I&t=826s
	// LEETCODE LINK: https://leetcode.com/problems/task-scheduler/
	//*********************************
	// vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
	// int n = 0;

	// vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
	// int n = 2;

	vector<char> tasks = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
	int n = 2;

	cout << taskSchedular(tasks, n);
}