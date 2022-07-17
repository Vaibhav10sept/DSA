#include <bits/stdc++.h>
using namespace std;

int rabbitsinForest(vector<int> arr) {
	//WV recommended
	//this is my own solution
	map<int, int> mp; //color(represented by the value),count
	int ans = 0;
	for (int ele : arr) {
		if (ele == 0) {
			//edge case
			ans++;
			continue;

		}
		if (mp.find(ele) != mp.end()) { //found
			if (mp[ele] == 0) {
				cout << "0 " << ele << endl;
				ans += ele;
				mp[ele] = ele;
				ans++;
			}
			else
				mp[ele]--;

		}
		else { //not found
			ans++;
			mp[ele] = ele;
			ans += ele;
		}
	}

	for (auto it : mp) cout << it.first << " " << it.second << endl;
	return ans;
}

int main() {
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=bit4Jn-ZoyQ&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR
	QUESTION LINK: https://www.geeksforgeeks.org/find-number-of-employees-under-every-manager/
	*/
	// vector<int> arr = {1, 1, 2};
	// vector<int> arr = {0, 0, 1, 1, 1}; //6
	vector<int> arr = {0, 1, 0, 2, 0, 1, 0, 2, 1, 1}; //11
	cout << "res " << rabbitsinForest(arr);
}