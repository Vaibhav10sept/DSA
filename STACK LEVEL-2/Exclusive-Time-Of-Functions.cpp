#include<bits/stdc++.h>
using namespace std;

class Util {
public:
	int id;
	int startTime;
	int timeTakenByChildren;
	Util(int id, int startTime, int timeTakenByChildren) {
		this->id = id;
		this->startTime = startTime;
		this->timeTakenByChildren = timeTakenByChildren;
	}
};

vector<int> exclusiveTimeOfFunctions(int n, vector<string> arr) {
	//meditate, think why we use stack here
	stack<Util> st;
	vector<int> ans(n);

	for (string log : arr) {
		//split kro log ko.
		auto find1 = log.find(":");
		auto find2 = log.find(":", find1 + 1);
		int id = stoi(log.substr(0, find1));
		string type = log.substr(log.find(":") + 1, find2 - find1 - 1);
		int time = stoi(log.substr(find2 + 1));

		if (type == "start") {
			//directly stack me push krdo
			st.push(Util(id, time, 0));
		}
		else { //type == "end"
			//so, time --> end time hoga.(cs)
			Util obj = st.top();
			st.pop();
			int interval = time - obj.time + 1;
			//obj.time --> same id vale obj ka startime hoga
			//interval means total itna time lia uss obj ne
			//below, ham obj ke exact execution time ke lie, uske children ka time minue kr rhe h.
			int exactTime = interval - obj.timeTakenByChildren;

			//add kro iss id ke answer ko in ans array
			ans[obj.id] += exactTime;

			if (!st.empty()) { //means iska koi parent hai toh parent ke timeTakenByChildren me iska time add krdo
				st.top().timeTakenByChildren += interval;
			}
		}
	}
	return ans;
}

int main() {
	/*
	PREREQUISITE: concept is similar to evalutate infix expression
	VIDEO LINK: https://www.youtube.com/watch?v=dsusgzffTDA&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=16
	LEETCODE LINK: https://leetcode.com/problems/exclusive-time-of-functions/
	*/
	int n = 2;
	vector<string> logs = {"0:start:0", "1:start:2", "1:end:5", "0:end:6"};

	vector<int> ans = exclusiveTimeOfFunctions(n, logs);
	for (int ele : ans)cout << ele << " ";
}