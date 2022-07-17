#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
	map<int, int> mp; //value, index in array
	vector<int> arr;
	RandomizedSet() {

	}

	bool insert(int val) {
		if (mp.find(val) != mp.end()) { //found
			//if already present return false
			return false;
		}
		//not present add and return true;
		mp[val] = arr.size(); //hmesa arr ke last ind me add hoga for time O(1)
		arr.push_back(val);
		return true;
	}

	bool remove(int val) {
		if (mp.find(val) == mp.end()) { //not found
			return false;
		}
		//present, so remove from map
		int removeIdx = mp[val];
		mp.erase(val);

		//remove from arr
		if (removeIdx == arr.size() - 1) { //last me h
			arr.pop_back();
			return true;
		}
		//last idx me nhi h to swap kroge last ele se fir last se remove kro
		//or jo last me tha uska idx change hue to use bhi map me update kro
		swap(arr[arr.size() - 1], arr[removeIdx]);
		//removing last index value
		arr.pop_back();
		//updating map with the index change
		mp[arr[removeIdx]] = removeIdx;
		return true;
	}

	int getRandom() {
		int randIndex = rand() % arr.size();
		return arr[randIndex];
	}
};

int main() {
	/*
	PREREQUISITE: Insert Delete GetRandom O(1) - Duplicates allowed
	VIDEO LINK: https://www.youtube.com/watch?v=UqrcuLv3BnA&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=57
	QUESTION LINK: https://leetcode.com/problems/insert-delete-getrandom-o1/
	*/

	RandomizedSet obj;
	int val = 1;
	cout << obj.insert(1) << endl;
	cout << obj.insert(2) << endl;
	cout << obj.insert(3) << endl;
	cout << obj.insert(4) << endl;
	// cout << obj.remove(val);
	cout << obj.getRandom() << endl;
	cout << obj.getRandom() << endl;
	cout << obj.getRandom() << endl;
	cout << obj.getRandom() << endl;
}