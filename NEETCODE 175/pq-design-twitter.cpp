#include <bits/stdc++.h>
using namespace std;

class Twitter {
private:
	unordered_map<int, set<int>> follows; // userid --> set of ids which he follows
	unordered_map<int, vector<pair<int, int>>> tweet; // userid --> vector of pair containing time(for getting the most recent 10 tweet) and tweet id
	long long time;

public:
	/** Initialize your data structure here. */
	Twitter() {
		time = 0;
	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		tweet[userId].push_back({time++, tweetId});
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		priority_queue<pair<int, int>> maxHeap;

		for (auto it = tweet[userId].begin(); it != tweet[userId].end(); ++it)
			maxHeap.push(*it);

		for (auto it1 = follows[userId].begin(); it1 != follows[userId].end(); ++it1) {
			int usr = *it1; // get target user
			for (auto it2 = tweet[usr].begin(); it2 != tweet[usr].end(); ++it2)
				maxHeap.push(*it2);
		}

		vector<int> res;
		while (maxHeap.size() > 0) {
			res.push_back(maxHeap.top().second);
			maxHeap.pop();
			if (res.size() == 10) break;
		}
		return res;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		if (followerId != followeeId)
			follows[followerId].insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		follows[followerId].erase(followeeId);
	}
};

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=pNichitDD2E
	// LEETCODE LINK: https://leetcode.com/problems/design-twitter/
	//*********************************
	vector<int> ans;
	Twitter obj;
	obj.postTweet(1, 5);
	ans  = obj.getNewsFeed(1);
	for (auto ele : ans) cout << ele << " ";
	cout << endl;
	ans.clear();

	obj.follow(1, 2);
	obj.postTweet(2, 6);
	ans  = obj.getNewsFeed(1);
	for (auto ele : ans) cout << ele << " ";
	cout << endl;
	ans.clear();

	obj.unfollow(1, 2);
	ans  = obj.getNewsFeed(1);
	for (auto ele : ans) cout << ele << " ";
	cout << endl;
	ans.clear();
}