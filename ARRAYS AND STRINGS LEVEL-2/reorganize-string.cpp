#include <bits/stdc++.h>
using namespace std;

class Util {
public:
	char ch;
	int freq;
	Util(char ch, int freq) {
		this->ch = ch;
		this->freq = freq;
	}
};

bool operator< (const Util one, const Util two) {
	// this is max heap
	return one.freq < two.freq;
}

string reorganizeString(string str) {
	//creating map
	map<char, int> mp;
	for (char ele : str) {
		mp[ele]++;
	}

	//filling up the priority queue
	priority_queue<Util> pq;
	for (auto it : mp) {
		// cout << it.first << " " << it.second << endl;
		pq.push(Util(it.first, it.second));
	}

	//finding answer
	string ans = "";
	Util block = pq.top();
	pq.pop();
	ans += block.ch;
	block.freq--;
	while (!pq.empty()) {
		Util temp = pq.top();
		pq.pop();
		ans += temp.ch;
		temp.freq--;
		if (block.freq > 0) {
			pq.push(block);
		}
		//interchange temp and block
		block = temp;
	}
	if (ans.size() != str.size()) {
		return "";
	}

	return ans;
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=D_jE64CJ5UE&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=58
	// LEETCODE LINK: https://leetcode.com/problems/reorganize-string/
	//*********************************
	string str = "aaab";
	cout << reorganizeString(str);

}