#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	map<int, int> mp; //n-backlist.size() me jo val blacklist h uska idx --> n-blacklist.size() + 1 se end me jo non blacklist val h uska index
	int top;
	Solution(int n, vector<int>& blacklist) {
		//WV recommended
		top = n - blacklist.size();
		set<int> st; //contain all blacklist values
		//fill the set with all blacklist values
		for (int i = 0; i < blacklist.size(); i++) {
			st.insert(blacklist[i]);
		}

		n--;
		for (int i = 0; i < blacklist.size(); i++) {
			if (blacklist[i] < top) { //mapping is required
				while (st.find(n) != st.end()) { //found
					//means the n is already blacklisted, connot be mapped
					n--;
				}
				//now we found a "n" that is not blacklisted so put it in map(create mapping)
				mp[blacklist[i]] = n;
				n--; //"n" ko map kr dia to n--;
			}
		}
	}

	int pick() {
		int randIndex = rand() % top;
		if (mp.find(randIndex) != mp.end()) { //found
			return mp[randIndex];
		}
		return randIndex;
	}
};

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=6LN4uD346FQ&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=59
	QUESTION LINK: https://leetcode.com/problems/random-pick-with-blacklist/
	*/
	vector<int> blacklist = {0, 1};

	Solution obj(4, blacklist);
	cout << obj.pick() << endl;
	cout << obj.pick() << endl;
	cout << obj.pick() << endl;
	cout << obj.pick() << endl;
	cout << obj.pick() << endl;
	cout << obj.pick() << endl;
	cout << obj.pick() << endl;
	cout << obj.pick() << endl;
}