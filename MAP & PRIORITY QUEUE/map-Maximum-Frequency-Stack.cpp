#include <bits/stdc++.h>
using namespace std;

class FreqStack {
public:
	map<int, stack<int>> freqStack; //frequency value, stack(contains all values having that particular frequency)
	map<int, int> freqMap; //value,frequency
	int maxFreq;
	FreqStack() {
		maxFreq = 0;
	}

	void push(int val) {
		freqMap[val]++;

		//add in freq stack
		freqStack[freqMap[val]].push(val);

		//set max freq
		maxFreq = max(maxFreq, freqMap[val]);
	}

	int pop() {
		int ans = freqStack[maxFreq].top();
		freqStack[maxFreq].pop();

		//change in freqmap
		freqMap[ans]--;

		if (freqStack[maxFreq].size() == 0) { //think,WV
			maxFreq--;
		}
		return ans;
	}
};

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=KVg4Y0sI4Iw&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=53
	QUESTION LINK: https://leetcode.com/problems/maximum-frequency-stack/
	*/
	FreqStack obj;
	obj.push(10);
	obj.push(10);
	obj.push(10);
	obj.push(20);
	obj.push(20);
	obj.push(20);
	obj.push(20);
	obj.push(20);
	cout << obj.pop();
}