#include <bits/stdc++.h>
using namespace std;

vector<int> avoidFlood(vector<int>& arr) {
	//read question and WV recommended
	map<int, int> lastRain; //lake --> last index
	set<int> dry; //set --> contains the index when we can dry
	vector<int> ans(arr.size(), 0);

	for (int i = 0; i < arr.size(); i++) {
		int x = arr[i];
		if (x == 0) { //dry
			dry.insert(i);
			ans[i] = 1;
		}
		else { //rain
			if (lastRain.find(x) == lastRain.end()) { //not found
				//iss lake me kbhi rain nhi hua h
				//add in map(lastRain)
				lastRain[x] = i;
			}
			else { //iss lake me pehle rain ho chuka h
				//find the index jisme dry hua just higher then the last index of x
				//se we can use upper bound for this
				auto dryThisDay = dry.upper_bound(lastRain[x]);
				if (dryThisDay == dry.end()) { //means upper bound nhi h
					//means flood hoga to return empty vector
					vector<int> temp;
					return temp;
				}
				else { //there is a upper bound, a index just higher then the last index of x
					// drythisday is a pointer, upper bound return a pointer
					cout << "dry " << *dryThisDay << " " << x << " " << lastRain[x] << endl;
					ans[(*dryThisDay)] = x;
					dry.erase((*dryThisDay)); //remove from set.
				}
				lastRain[x] = i; //updating the last index of x(think , wv)
			}
			ans[i] = -1;
		}
	}
	return ans;
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=Q_90h1fxCSM&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=59
	QUESTION LINK: https://leetcode.com/problems/avoid-flood-in-the-city/
	*/
	// vector<int> rains = {1, 2, 3, 4};
	// vector<int> rains = {1, 2, 0, 0, 2, 1};
	vector<int> rains = {1, 0, 2, 0, 3, 0, 2, 0, 0, 0, 1, 2, 3};

	vector<int> ans = avoidFlood(rains);
	for (auto ele : ans) cout << ele << " ";
}